#include <OneWire.h>
#include <DallasTemperature.h>
#include <WiFi.h>
#include <WebServer.h>  
#include "SuperMon.h"   

#define ONE_WIRE_BUS 25

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

#define relay 33
#define ThermistorPin 32
float R1 = 10000,R2=0;
int incomingByte,indx=0;

#define LOCAL_SSID "ASUS_C0_2G"
#define LOCAL_PASS "R4c4c1un1!"
WebServer server(80);
String header;
unsigned long currentTime = millis();
unsigned long previousTime = 0; 
const long timeoutTime = 2000;

char XML[2048];
char buf[32];
IPAddress Actual_IP;
IPAddress ip;

bool statusRel=false;

void setup () {
  pinMode(relay, OUTPUT);

  Serial.begin(115200);
  
  sensors.begin();
  disableCore0WDT();
  
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

  server.on("/UPDATE_SLIDER", UpdateSlider);
  server.on("/BUTTON_0", ProcessButton_0);
  server.on("/BUTTON_1", ProcessButton_1);
  server.begin();
}

double GetCentralaTemperature(){
  sensors.requestTemperatures();
  return sensors.getTempCByIndex(0);
}

double GetPuferTemperature(){
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
  return tempC;
}
/*
  if(Serial.available() > 0){
    incomingByte = Serial.read();
    if(char(incomingByte)=='o')
    { 
      if(statusRel!=true){
        statusRel=true;
        digitalWrite(relay, HIGH);
      }
      delay(1000); 
      Serial.println("ON");
    }
    if(char(incomingByte)=='c')
    { 
      if(statusRel!=false){
        statusRel=false;
        digitalWrite(relay, LOW);
      }
      delay(1000); 
      Serial.println("OFF");
    }
  }
*/
double BitsA0,BitsA1;
void loop(){
  
  delay(50); 
  indx++;
  if(indx>=9){
    indx=0;
    Serial.print("Sensor 1 : "); 
    Serial.print(GetPuferTemperature());
    Serial.print(" - Sensor 2 :  ");
    Serial.print(GetCentralaTemperature());
    Serial.println();
  }
  if ((millis() - SensorUpdate) >= 50) {
    //Serial.println("Reading Sensors");
    SensorUpdate = millis();
    BitsA0 = GetPuferTemperature();
    BitsA1 = GetCentralaTemperature();
  }
  server.handleClient();
}
// code to send the main web page
// PAGE_MAIN is a large char defined in SuperMon.h
void SendWebsite() {

  Serial.println("sending web page");
  // you may have to play with this value, big pages need more porcessing time, and hence
  // a longer timeout that 200 ms
  server.send(200, "text/html", PAGE_MAIN);

}

void SendXML() {

  // Serial.println("sending xml");

  strcpy(XML, "<?xml version = '1.0'?>\n<Data>\n");

  // send bits0
  sprintf(buf, "<B0>%f</B0>\n", BitsA0);
  strcat(XML, buf);

  // send bits1
  sprintf(buf, "<B1>%f</B1>\n", BitsA1);
  strcat(XML, buf);

  else {
    strcat(XML, "<LED>0</LED>\n");
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
  Serial.println(XML);

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
