#include <OneWire.h>
#include <DallasTemperature.h>
#include <WiFi.h>
#include <WebServer.h>  
#include "SuperMon.h"  
#include "time.h" 

#define ONE_WIRE_BUS 25

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

#define relay 33
#define ThermistorPin 32
float R1 = 10000,R2=0;
int incomingByte,indx=0;
 
#define LOCAL_SSID "ASUS_C0_2G_EXT"//
#define LOCAL_PASS "R4c4c1un1!"
WebServer server(80);
String header;
unsigned long currentTime = millis();
unsigned long previousTime = 0; 
const long timeoutTime = 2000;
uint32_t SensorUpdate = 0;

int aux=0,nrVal=0;
double outTemp=0,vec[10];
double Pufer,Centrala,Zero=0;
long long timeAux=0,numar1=0,timeNewData=0;
bool firstTime=false;
struct sensorData{
  double c;
  double p; 
  String t;
}dataStored[50];
int loc=-1;
int afisNr=0,pozPrim=0;
bool showAll=true,maximAfis=false,newData=false;

char XML[2048];
char buf[32];
IPAddress Actual_IP;
IPAddress ip;

IPAddress local_IP(192, 168, 1, 29);
IPAddress gateway(192, 168, 1, 1);

IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(8, 8, 8, 8);   //optional
IPAddress secondaryDNS(8, 8, 4, 4); //optional

bool statusRel=false;

void setup () {
  pinMode(relay, OUTPUT);

  Serial.begin(115200);
  
  sensors.begin();
  disableCore0WDT();
  
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure");
  }
  
  WiFi.begin(LOCAL_SSID, LOCAL_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("IP address: "); Serial.println(WiFi.localIP());
  Actual_IP = WiFi.localIP();
  printWifiStatus();

  server.on("/", SendWebsite);

  server.on("/xml", SendXML);

  server.begin(); 
  
}

double GetPuferTemperature(){
  sensors.requestTemperatures();
  return sensors.getTempCByIndex(0);
}

double GetCentralaTemperature(){
  int adcS1 = analogRead(ThermistorPin);
  double voltage = (float)adcS1 / 4095.0 * 3.3;
  double R2 = 10.0 * (voltage/(3.3-voltage));
  double tempK = 1 / (1 / (273.15 + 25) + log(R2 / 10) / 3950.0); 
  double tempC = tempK - 273.15; 
  indx=0;
  int c=tempC;
  float p=tempC-c;
  tempC-=p;
  if(p>=0.25&&p<=0.75)
    tempC+=0.5;
  else if(p>0.75)
    tempC++; 
    
  tempC-=4;
  
  if(aux>9)
    aux=0;
  vec[aux]=tempC;
  aux++;
  if(nrVal<9)
    nrVal++;
  outTemp=0;
  for(int i=0;i<nrVal;i++){
    outTemp+=vec[i];
  }
  outTemp=(outTemp*1.0)/(nrVal);
  
  c=outTemp;
  p=outTemp-c;
  outTemp-=p;
  if(p>=0.25&&p<=0.75)
    outTemp+=0.5;
  else if(p>0.75)
    outTemp++; 
  return outTemp;
}

void loop(){
  timeAux++;
  timeNewData++;
  delay(50); 
  if ((millis() - SensorUpdate) >= 50) {
    //Serial.println("Reading Sensors");
    SensorUpdate = millis();
    Pufer = GetPuferTemperature();
    Centrala = GetCentralaTemperature();

    if(timeNewData==1){
      Serial.println("New data");
      newData=true;
      loc++;
      if(loc>47){
        maximAfis=true;
        loc=0;
        pozPrim=(loc+1)%48;
      }  
      dataStored[loc].c=Centrala;
      dataStored[loc].p=Pufer; // 0 5 6 7 3 1
    }
    else
    if(timeNewData>22500){//22500
      timeNewData=0;
    }

    if(abs(Pufer-Centrala)>6){
      if(statusRel==false){
        digitalWrite(relay, HIGH);
      }
      statusRel=true;
    }
    if(abs(Pufer-Centrala)<1){
      if(statusRel==true){
        digitalWrite(relay, LOW);
      }
      statusRel=false;
    }
  }
  server.handleClient();
}
// code to send the main web page
// PAGE_MAIN is a large char defined in SuperMon.h
void SendWebsite() {
  Serial.println("Reset show all");
  showAll=true;
  numar1=0;
  timeAux=0;
  if(maximAfis==true)
    afisNr=pozPrim;
  else 
    afisNr=0;
  Serial.println("sending web page");
  // you may have to play with this value, big pages need more porcessing time, and hence
  // a longer timeout that 200 ms
  server.send(200, "text/html", PAGE_MAIN);

}

void SendXML() {
  // Serial.println("sending xml");

  strcpy(XML, "<?xml version = '1.0'?>\n<Data>\n");

  // send bits0
  sprintf(buf, "<B0>%.1f</B0>\n", Pufer);
  strcat(XML, buf);

  // send bits1
  sprintf(buf, "<B1>%.1f</B1>\n", Centrala);
  strcat(XML, buf);

  if(showAll==true){
    /*Serial.println("-----------------");
    Serial.print("Printing saved: ");
    Serial.print(dataStored[afisNr].c);
    Serial.print("  -  ");
    Serial.print(dataStored[afisNr].p);*/
    sprintf(buf, "<C1>%.1f</C1>\n", dataStored[afisNr].c);
    strcat(XML, buf);
    sprintf(buf, "<C2>%.1f</C2>\n", dataStored[afisNr].p);
    strcat(XML, buf);
    
    /*Serial.println();
    Serial.println("-----------------STATS-----------------");
    Serial.print("afisNr: ");
    Serial.print(afisNr);
    Serial.println();
    Serial.print("maximAfis: ");
    Serial.print(maximAfis);
    Serial.println();
    Serial.print("loc: ");
    Serial.print(loc);
    Serial.println();*/
    afisNr++;
    if(maximAfis==true){
      if(afisNr>=47)
        afisNr=0;
      if(afisNr>loc){
        afisNr=0;
        showAll=false;
      }
    }
    else
    if(afisNr>loc&&maximAfis==false){
      afisNr=0;
      showAll=false;
    }
  }
  else
  if(newData==true){
    /*Serial.println("-----------------");
    Serial.print("Printing new: ");
    Serial.print(dataStored[loc].c);
    Serial.print("  -  ");
    Serial.print(dataStored[loc].p);*/
    sprintf(buf, "<C1>%.1f</C1>\n", dataStored[loc].c);
    strcat(XML, buf);
    sprintf(buf, "<C2>%.1f</C2>\n", dataStored[loc].p);
    strcat(XML, buf);
    newData=false;
  }
  else{
    sprintf(buf, "<C1>%.1f</C1>\n", Zero);
    strcat(XML, buf);
    sprintf(buf, "<C2>%.1f</C2>\n", Zero);
    strcat(XML, buf);
    sprintf(buf, "<Time>%s</Time>\n", "-1");
    strcat(XML, buf);
  }

  if (statusRel) {
    strcat(XML, "<SWITCH>1</SWITCH>\n");
  }
  else {
    strcat(XML, "<SWITCH>0</SWITCH>\n");
  }

  strcat(XML, "</Data>\n");
  // wanna see what the XML code looks like?
  // actually print it to the serial monitor and use some text editor to get the size
  // then pad and adjust char XML[2048]; above
  //Serial.println(XML);

  // you may have to play with this value, big pages need more porcessing time, and hence
  // a longer timeout that 200 ms
  server.send(200, "text/xml", XML);


}

// I think I got this code from the wifi example
void printWifiStatus() {

  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  // print where to go in a browser:
  Serial.print("Open http://");
  Serial.println(ip);
}
