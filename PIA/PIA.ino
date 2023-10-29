#include <SPI.h>
#include <MFRC522.h>
#include <Adafruit_GFX.h>    
#include <Adafruit_ST7735.h> 
#include <string.h>

//RFId
#define RFID_RST 22          
#define RFID_SS 15           

//TFT display
#define TFT_CS  5
#define TFT_RST 4
#define TFT_DC  2

//Pini pentru protocolul SPI
#define MISO_PIN  19 
#define MOSI_PIN  23 
#define SCK_PIN   18 

#define BTN_SUS 27
#define BTN_JOS 25
#define BTN_STG 33
#define BTN_DRP 26
#define BTN_YES 17
#define BTN_NOT 16

#define BUZZER  14
#define BUZZER2 32

/* Color code
ST77XX_MAGENTA - purple
ST77XX_BLUE - red
ST77XX_RED - blue
ST77XX_CYAN - yellow
ST7735_ORANGE - cyan
ST77XX_YELLOW - cyan
ST77XX_WHITE - whitte
ST77XX_BLACK - black
*/

int btnSusStare = 0,btnJosStare = 0,btnDrpStare = 0,btnStgStare = 0,btnYesStare = 0,btnNotStare = 0;
const int nrOptionsMenu=3;

int loadingScreenMultiplier=1;
bool sunet=true;
int gameSpeedBumpMultiplier=12;
int playgroundSize=15;
int selectedSize=5;
int presetGroundSize[10];


MFRC522 rfid(RFID_SS, RFID_RST);  
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

/*----------------------TFT DRAW-----------------------------*/

void writeTextGFX(char *text, uint16_t color, uint16_t poz_X, uint16_t poz_Y, bool wrap_text, uint16_t size_text) {
  if(poz_X>=0 && poz_X<tft.width() && poz_Y>=0 && poz_Y<tft.height())
    tft.setCursor(poz_X, poz_Y);
  else
    tft.setCursor(0, 0);
  tft.setTextColor(color);
  tft.setTextWrap(wrap_text);
  if(size_text>=0 && size_text<=6)
    tft.setTextSize(size_text);
  else 
    tft.setTextSize(1);
  tft.print(text);
}

/*------------------------MENU-------------------------------*/
void Menu(int select){
  tft.fillScreen(ST77XX_BLACK);
  
  char options[3][8];
  strcpy(options[0]," START ");
  strcpy(options[1],"DEV SET");
  strcpy(options[2],"GME SET");

  int errY=26;
  
  for(int i=0;i<nrOptionsMenu;i++){
    if(select==i){
      tft.fillRect(15, 20+errY*i, 99, 24,ST77XX_WHITE);
      writeTextGFX(options[i], ST77XX_BLACK, 22, 25+errY*i, true, 2);
    }
    else{
      tft.drawRect(15, 20+errY*i, 99, 24,ST77XX_WHITE);
      writeTextGFX(options[i], ST77XX_WHITE, 22, 25+errY*i, true, 2);
    }
    
  }
}
void InsertGameMenu(){
  tft.fillScreen(ST77XX_BLACK);
  writeTextGFX("INSERT", ST77XX_WHITE, 28, 9, true, 2);
  writeTextGFX(" GAME", ST77XX_WHITE, 28, 25, true, 2);
  tft.drawLine(0,45,128,45,ST77XX_WHITE);
  writeTextGFX("Waiting", ST77XX_BLUE, 22, 50, true, 2);
}
void DevOptionsMenu(int select){
  tft.fillRect(15,50,113,100,ST77XX_BLACK);

  if(select==0){
    tft.drawLine(110,67,115,72,ST77XX_WHITE);
    tft.drawLine(110,67,115,62,ST77XX_WHITE);
    tft.drawLine(110,67,120,67,ST77XX_WHITE);
  }
  if(select==1){
    tft.drawLine(110,97,115,102,ST77XX_WHITE);
    tft.drawLine(110,97,115,92,ST77XX_WHITE);
    tft.drawLine(110,97,120,97,ST77XX_WHITE);
  }
  writeTextGFX("SOUND", ST77XX_WHITE, 16, 50, true, 1);
  if(sunet==false){
    tft.fillRect(50,60,15,15,ST77XX_WHITE);//Off button - on
    tft.drawRect(16,60,15,15,ST77XX_WHITE);//On button - off
  }
  if(sunet==true){
    tft.drawRect(50,60,15,15,ST77XX_WHITE);//Off button - off
    tft.fillRect(16,60,15,15,ST77XX_WHITE);//On button - on
  }
  writeTextGFX("ON", ST77XX_WHITE, 35, 64, true, 1);
  writeTextGFX("OFF", ST77XX_WHITE, 70, 64, true, 1);
  
  writeTextGFX("LOADING TIME", ST77XX_WHITE, 16, 80, true, 1);

  if(loadingScreenMultiplier==0){
    tft.fillRect(16,90,15,15,ST77XX_WHITE);
    tft.drawRect(36,90,15,15,ST77XX_WHITE);
    tft.drawRect(56,90,15,15,ST77XX_WHITE);
  }
  if(loadingScreenMultiplier==1){
    tft.fillRect(16,90,15,15,ST77XX_WHITE);
    tft.fillRect(36,90,15,15,ST77XX_WHITE);
    tft.drawRect(56,90,15,15,ST77XX_WHITE);
  }
  if(loadingScreenMultiplier==2){
    tft.fillRect(16,90,15,15,ST77XX_WHITE);
    tft.fillRect(36,90,15,15,ST77XX_WHITE);
    tft.fillRect(56,90,15,15,ST77XX_WHITE);
  }
}
void DevSetMenu(){
  tft.fillScreen(ST77XX_BLACK);
  writeTextGFX(" DEVICE ", ST77XX_WHITE, 16, 9, true, 2);
  writeTextGFX("SETTINGS", ST77XX_WHITE, 16, 25, true, 2);
  tft.drawLine(0,45,128,45,ST77XX_WHITE);
  
  DevOptionsMenu(0);
}
void GmeOptionsMenu(int select){
  tft.fillRect(15,50,113,100,ST77XX_BLACK);
  if(select==0){
    tft.drawLine(110,67,115,72,ST77XX_WHITE);
    tft.drawLine(110,67,115,62,ST77XX_WHITE);
    tft.drawLine(110,67,120,67,ST77XX_WHITE);
  }
  if(select==1){
    tft.drawLine(110,97,115,102,ST77XX_WHITE);
    tft.drawLine(110,97,115,92,ST77XX_WHITE);
    tft.drawLine(110,97,120,97,ST77XX_WHITE);
  }
  writeTextGFX("GAME SPEED:", ST77XX_WHITE, 16, 50, true, 1);
  if(gameSpeedBumpMultiplier>=16){
    writeTextGFX("slow", ST77XX_WHITE, 82, 50, true, 1);
  }
  else if(gameSpeedBumpMultiplier<16&&gameSpeedBumpMultiplier>=10){
    writeTextGFX("normal", ST77XX_WHITE, 82, 50, true, 1);
  }
  else if(gameSpeedBumpMultiplier<10){
    writeTextGFX("fast", ST77XX_WHITE, 82, 50, true, 1);
  }
  for(int i=0;i<10;i++){
    if((i+2)*2<26-gameSpeedBumpMultiplier){
      tft.drawRect(16+(9-i)*8,60,8,15,ST77XX_WHITE);
    }
    else{
      tft.fillRect(16+(9-i)*8,60,8,15,ST77XX_WHITE);
    }
  }

  writeTextGFX("PLAY AREA:", ST77XX_WHITE, 16, 80, true, 1);
  int cp=playgroundSize,loc=0;
  char playSize[10];
  while(cp){
    playSize[loc++]=cp%10+'0';
    cp/=10;
  }
  for(int i=0;i<loc/2;i++){
    char aux=playSize[i];
    playSize[i]=playSize[loc-i-1];
    playSize[loc-i-1]=aux;
  }
  playSize[loc]=NULL;
  writeTextGFX(playSize, ST77XX_WHITE, 82, 80, true, 1);
  for(int i=0;i<10;i++){
    if(i<=selectedSize){
      tft.fillRect(16+i*8,90,8,15,ST77XX_WHITE);
    }
    else{
      tft.drawRect(16+i*8,90,8,15,ST77XX_WHITE);
    }
  }
}
void GmeSetMenu(){
  tft.fillScreen(ST77XX_BLACK);
  writeTextGFX("  GAME  ", ST77XX_WHITE, 16, 9, true, 2);
  writeTextGFX("SETTINGS", ST77XX_WHITE, 16, 25, true, 2);
  tft.drawLine(0,45,128,45,ST77XX_WHITE);
  
  GmeOptionsMenu(0);
}
void GameSelectMenu(int game){
  tft.fillRect(28, 9, 100, 30,ST77XX_BLACK);
  writeTextGFX(" GAME", ST77XX_WHITE, 28, 9, true, 2);
  writeTextGFX("INSERTED", ST77XX_WHITE, 16, 25, true, 2);
  if(game==1){
     tft.fillRect(22, 50, 106, 64,ST77XX_BLACK);
     writeTextGFX("Move it", ST77XX_BLUE, 22, 50, true, 2);
  }
  else if(game==2){
    tft.fillRect(22, 50, 106, 64,ST77XX_BLACK);
    writeTextGFX(" Snake", ST77XX_BLUE, 22, 50, true, 2);
  }
  else if(game==3){
    tft.fillRect(22, 50, 106, 64,ST77XX_BLACK);
    writeTextGFX(" Ships", ST77XX_BLUE, 22, 50, true, 2);
  }
}
int InsertGame(){
  String tag="";
  int game=1;

  if(!rfid.PICC_IsNewCardPresent())
    return 0;
  if(rfid.PICC_ReadCardSerial()){
    for (byte i = 0; i < 4; i++){
      tag += rfid.uid.uidByte[i];
    }
    Serial.println(tag);
    
    if(tag=="170176101152")
      game=2;
    if(tag=="17019818692")
      game=3;
    
    tag = "";
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
    return game;
  }
  return 0;
}

/*------------------------GAMES-------------------------------*/

int matrix[100][100];
int pozPlayerX,pozPlayerY;
int sizePlayer=8;
int head=0,tail=0;
const int errX=4;
const int errY=36;

class XY{
public:
  int x=playgroundSize/2;
  int y=playgroundSize/2;
}body[2520],directions[5],center;

/*-----------------------MOVE IT------------------------------*/

int MovePlayerFGFX(String mutare){

  tft.fillRect(errX+pozPlayerX*sizePlayer, errY+pozPlayerY*sizePlayer, sizePlayer, sizePlayer,ST7735_BLACK);//Stergem Player Vechi
  
  matrix[pozPlayerY][pozPlayerX]=0;
  if(mutare=="dreapta"){
    if(pozPlayerX<playgroundSize){
      pozPlayerX++;
    }
  }
  if(mutare=="stanga"){
    if(pozPlayerX>0){
      pozPlayerX--;
    }
  }
  if(mutare=="sus"){
    if(pozPlayerY<playgroundSize){
      pozPlayerY++;
    }
  }
  if(mutare=="jos"){
    if(pozPlayerY>0){
      pozPlayerY--;
    }
  }
  tft.fillRect(errX+pozPlayerX*sizePlayer, errY+pozPlayerY*sizePlayer, sizePlayer, sizePlayer,ST7735_YELLOW);//Punem player Nou
  if(matrix[pozPlayerY][pozPlayerX]==2){
      PlacePointFGFX(ST7735_BLUE,true);
      if(sunet==true){
        tone(BUZZER,4000,200);
      }
      matrix[pozPlayerY][pozPlayerX]=1;
      tft.fillRect(errX+pozPlayerX*sizePlayer, errY+pozPlayerY*sizePlayer, sizePlayer, sizePlayer,ST7735_YELLOW);//Punem player Nou
  return 1;
    }
  matrix[pozPlayerY][pozPlayerX]=1;
  tft.fillRect(errX+pozPlayerX*sizePlayer, errY+pozPlayerY*sizePlayer, sizePlayer, sizePlayer,ST7735_YELLOW);//Punem player Nou
  return 0;
}
void Game1GFX(char *score,bool generatePoint){
  tft.fillScreen(ST77XX_BLACK);
  writeTextGFX("Score: ", ST77XX_WHITE, 15, 5, true, 2);
  Serial.println(score);
  writeTextGFX(score, ST77XX_WHITE, 87, 5, true, 2);
  
  tft.fillRect(0, errY-errX, errX, 128,ST7735_WHITE);//Margine stanga
  tft.fillRect(0, 160-errX, 128, errX,ST7735_WHITE);//Margine jos
  tft.fillRect(124, errY-errX, errX, 160-(errY-errX),ST7735_WHITE);//Margine dreapta
  tft.fillRect(0, errY-errX, 128, errX,ST7735_WHITE);//Margine sus

  tft.fillRect(errX+pozPlayerX*sizePlayer, errY+pozPlayerY*sizePlayer, sizePlayer, sizePlayer,ST7735_YELLOW);

  PlacePointFGFX(ST7735_BLUE,generatePoint);
  matrix[pozPlayerY][pozPlayerX]=1;
}

/*-----------------------SNAKE--------------------------------*/

void DrawFaceGFX(int dir,int color,bool sterge){
  if(dir==1||sterge==true){
    tft.fillRect(5+body[head].x*sizePlayer, 37+body[head].y*sizePlayer, sizePlayer/4, sizePlayer/4,color);//Punem ochi
    tft.fillRect(9+body[head].x*sizePlayer, 37+body[head].y*sizePlayer, sizePlayer/4, sizePlayer/4,color);//Punem ochi
  }
  if(dir==2||sterge==true){
    tft.fillRect(9+body[head].x*sizePlayer, 37+body[head].y*sizePlayer, sizePlayer/4, sizePlayer/4,color);//Punem ochi
    tft.fillRect(9+body[head].x*sizePlayer, 42+body[head].y*sizePlayer, sizePlayer/4, sizePlayer/4,color);//Punem ochi
  }
  if(dir==3||sterge==true){
    tft.fillRect(5+body[head].x*sizePlayer, 42+body[head].y*sizePlayer, sizePlayer/4, sizePlayer/4,color);//Punem ochi
    tft.fillRect(9+body[head].x*sizePlayer, 42+body[head].y*sizePlayer, sizePlayer/4, sizePlayer/4,color);//Punem ochi
  }
  if(dir==4||sterge==true){
    tft.fillRect(5+body[head].x*sizePlayer, 37+body[head].y*sizePlayer, sizePlayer/4, sizePlayer/4,color);//Punem ochi
    tft.fillRect(5+body[head].x*sizePlayer, 42+body[head].y*sizePlayer, sizePlayer/4, sizePlayer/4,color);//Punem ochi
  }
}
void MoveSnakeFGFX(int dir,bool grow){
  if(head-tail!=0)
    DrawFaceGFX(dir,ST7735_GREEN,true);//Stergem Cap
    
  if(grow==false){
    tft.fillRect(errX+body[tail].x*sizePlayer, errY+body[tail].y*sizePlayer, sizePlayer, sizePlayer,ST7735_BLACK);//Stergem Coada
    tail++;
    if(tail>2500)
      tail=0;
  }

  head++;
  if(head>2500){
    body[0].x=body[head-1].x+directions[dir].x;
    body[0].y=body[head-1].y+directions[dir].y;
    head=0;
  }
  else{
    body[head].x=body[head-1].x+directions[dir].x;
    body[head].y=body[head-1].y+directions[dir].y;
  }
  tft.fillRect(errX+body[head].x*sizePlayer, errY+body[head].y*sizePlayer, sizePlayer, sizePlayer,ST7735_GREEN);//Punem Cap
  DrawFaceGFX(dir,ST7735_BLUE,false);//Desenam fata
}
bool UpdatePlayerFGFX(int dir,int &score){
  if(body[head].x+directions[dir].x>=0&&body[head].x+directions[dir].x<playgroundSize&&body[head].y+directions[dir].y>=0&&body[head].y+directions[dir].y<playgroundSize){
    if(matrix[body[head].y+directions[dir].y][body[head].x+directions[dir].x]==0){
        matrix[body[head].y+directions[dir].y][body[head].x+directions[dir].x]=1;
        matrix[body[tail].y][body[tail].x]=0;
        MoveSnakeFGFX(dir,false);
        return true;
    }
    else
    if(matrix[body[head].y+directions[dir].y][body[head].x+directions[dir].x]==2){
        matrix[body[head].y+directions[dir].y][body[head].x+directions[dir].x]=1;

        score++;
        ModifyScoreGFX(score);
        
        MoveSnakeFGFX(dir,true);

        PlacePointFGFX(ST7735_BLUE,true);
        return true;
    }
  }
  return false;
}
void GameOverSnakeGFX(){
  int mult=1;
  
  tft.fillRect(0, errY-errX, errX, 160-(errY-errX),ST7735_BLUE);//Margine stanga
  tft.fillRect(0, 160-errX, 128, errX,ST7735_BLUE);//Margine jos
  tft.fillRect(128-errX, errY-errX, errX, 160-(errY-errX),ST7735_BLUE);//Margine dreapta
  tft.fillRect(0, errY-errX, 128, errX,ST7735_BLUE);//Margine sus
  delay(1000*mult);
  tft.fillRect(0, errY-errX, errX, 160-(errY-errX),ST7735_RED);//Margine stanga
  tft.fillRect(0, 160-errX, 128, errX,ST7735_RED);//Margine jos
  tft.fillRect(128-errX, errY-errX, errX, 160-(errY-errX),ST7735_RED);//Margine dreapta
  tft.fillRect(0, errY-errX, 128, errX,ST7735_RED);//Margine sus
  delay(1000*mult);
  tft.fillRect(0, errY-errX, errX, 160-(errY-errX),ST7735_BLUE);//Margine stanga
  tft.fillRect(0, 160-errX, 128, errX,ST7735_BLUE);//Margine jos
  tft.fillRect(128-errX, errY-errX, errX, 160-(errY-errX),ST7735_BLUE);//Margine dreapta
  tft.fillRect(0, errY-errX, 128, errX,ST7735_BLUE);//Margine sus
  delay(1000*mult);
  tft.fillRect(0, errY-errX, errX, 160-(errY-errX),ST7735_RED);//Margine stanga
  tft.fillRect(0, 160-errX, 128, errX,ST7735_RED);//Margine jos
  tft.fillRect(128-errX, errY-errX, errX, 160-(errY-errX),ST7735_RED);//Margine dreapta
  tft.fillRect(0, errY-errX, 128, errX,ST7735_RED);//Margine sus
  delay(1000*mult);
}
void Game2GFX(char *score,int dir,bool generatePoint){
  tft.fillScreen(ST77XX_BLACK);
  writeTextGFX("Score: ", ST77XX_WHITE, 15, 5, true, 2);
  Serial.println(score);
  writeTextGFX(score, ST77XX_WHITE, 87, 5, true, 2);
  
  tft.fillRect(0, errY-errX, errX, 160-(errY-errX),ST7735_WHITE);//Margine stanga
  tft.fillRect(0, 160-errX, 128, errX,ST7735_WHITE);//Margine jos
  tft.fillRect(128-errX, errY-errX, errX, 160-(errY-errX),ST7735_WHITE);//Margine dreapta
  tft.fillRect(0, errY-errX, 128, errX,ST7735_WHITE);//Margine sus

  tft.fillRect(errX+body[head].x*sizePlayer, errY+body[head].y*sizePlayer, sizePlayer, sizePlayer,ST7735_GREEN);
  DrawFaceGFX(dir,ST7735_BLUE,false);
  
  PlacePointFGFX(ST7735_BLUE,generatePoint);
  matrix[body[head].y][body[head].x]=1;
}
void DebugSnake(){
  Serial.println("\n\n---------------\n\n");
  Serial.println(head);
  Serial.println(tail);
  for(int i=tail;i<head;i++){
    Serial.print(body[i].x);
    Serial.print(" ");
    Serial.print(body[i].y);
    Serial.print("\n");
  }
  for(int i=0;i<15;i++){
    for(int j=0;j<15;j++){
      Serial.print(matrix[i][j]);
      Serial.print(" ");
    }
    Serial.print("\n");
  }
  Serial.println("\n\n---------------\n\n");
}

/*-----------------COMMON GAME FUNCTIONS----------------------*/

void ModifyScoreGFX(int scor){
  char score[10];
  int len=0,cp=scor;
  if(cp==0)
  {
    len=1;
    score[0]='0';
  }
  while(cp){
    len++;
    cp/=10;
  }
  score[len--]=NULL;
  while(scor){
    score[len--]=scor%10+'0';
    scor/=10;
  }
  
  tft.fillRect(0, 0, 128, errY-errX,ST7735_BLACK);//Sterge Scor
  writeTextGFX("Score:", ST77XX_WHITE, 15, 5, true, 2);
  Serial.println(score);
  writeTextGFX(score, ST77XX_WHITE, 87, 5, true, 2);
}
void PlacePointFGFX(int color,bool generate){
  int pozPointX,pozPointY;
  if(generate==true){
    pozPointX=random(0,playgroundSize);
    pozPointY=random(0,playgroundSize);
    while(matrix[pozPointY][pozPointX]!=0){
      pozPointY=random(0,playgroundSize);
      pozPointX=random(0,playgroundSize);
    }
    matrix[pozPointY][pozPointX]=2;
    tft.fillRect(errX+pozPointX*sizePlayer, errY+pozPointY*sizePlayer, sizePlayer, sizePlayer,color);
  }
  for(int i=0;i<=playgroundSize;i++){
    for(int j=0;j<=playgroundSize;j++){
      if(matrix[i][j]==2)
      tft.fillRect(errX+j*sizePlayer, errY+i*sizePlayer, sizePlayer, sizePlayer,color);
    }
  }
}
void PauseGameMenu(int select){ 
  tft.fillScreen(ST77XX_BLACK);
  
  int errY=26;
  char options[3][8];
  strcpy(options[0],"RESUME");
  strcpy(options[1],"RESTART");
  strcpy(options[2]," QUIT");

   writeTextGFX(" GAME", ST77XX_WHITE, 28, 10, true, 2);
   writeTextGFX("PAUSED", ST77XX_WHITE, 28, 28, true, 2);


  for(int i=0;i<nrOptionsMenu;i++){
    if(select==i){
      tft.fillRect(15, 50+errY*i, 99, 24,ST77XX_WHITE);
      writeTextGFX(options[i], ST77XX_BLACK, 22, 55+errY*i, true, 2);
    }
    else{
      tft.drawRect(15, 50+errY*i, 99, 24,ST77XX_WHITE);
      writeTextGFX(options[i], ST77XX_WHITE, 22, 55+errY*i, true, 2);
    }
  }
}

void setup(){
  Serial.begin(921600);   
  while (!Serial);    
  
  pinMode(BTN_SUS, INPUT);
  pinMode(BTN_JOS, INPUT);
  pinMode(BTN_DRP, INPUT);
  pinMode(BTN_STG, INPUT);
  pinMode(BTN_YES, INPUT);
  pinMode(BTN_NOT, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(BUZZER2, OUTPUT);

  pozPlayerX=playgroundSize/2;
  pozPlayerY=playgroundSize/2;
  presetGroundSize[0]=5;presetGroundSize[1]=6;presetGroundSize[2]=8;presetGroundSize[3]=10;presetGroundSize[4]=12;
  presetGroundSize[5]=15;presetGroundSize[6]=20;presetGroundSize[7]=24;presetGroundSize[8]=30;presetGroundSize[9]=40;
  directions[1].x=0;directions[2].x=1;directions[3].x=0;directions[4].x=-1;
  directions[1].y=-1;directions[2].y=0;directions[3].y=1;directions[4].y=0;
  
  SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN);
  rfid.PCD_Init(); 
  
  tft.initR(INITR_GREENTAB);      
  tft.fillScreen(ST77XX_BLACK);
  
  Serial.println("Initialized");

  writeTextGFX("THE NEW", ST77XX_BLUE, 22, 30, true, 2);
  writeTextGFX("GAMEBOY", ST77XX_BLUE, 22, 46, true, 2);
  writeTextGFX("Made by:\nDulgheriu Bogdan\nRaicu Bianca", ST77XX_WHITE, 0, 135, true, 1);
  delay(5000*loadingScreenMultiplier);

  
  if(sunet==true){
    tone(BUZZER,2000,1000);
    tone(BUZZER2,4000,500);
  }
  Menu(0);
}

int selectMenu=0,menuPage=0;
int menu=0;
bool shown=false;
int score=0,headDirection=1;
long long value=0;
int color;

void loop(){
  btnSusStare = digitalRead(BTN_SUS);
  btnJosStare = digitalRead(BTN_JOS);
  btnDrpStare = digitalRead(BTN_DRP);
  btnStgStare = digitalRead(BTN_STG);
  btnYesStare = digitalRead(BTN_YES);
  btnNotStare = digitalRead(BTN_NOT);

  if(menu==0){//Meniu principal
    if(menuPage==0){//Meniu
      if(btnYesStare==HIGH){
        shown=false;
        menuPage=1+selectMenu;
        selectMenu=0;
        if(sunet==true)
          tone(BUZZER,2000,700);
        delay(1000*loadingScreenMultiplier);
      }
      else if(btnSusStare==HIGH){
        if(selectMenu<nrOptionsMenu-1)
          selectMenu++;
        Menu(selectMenu);
      }
      else if(btnJosStare==HIGH){
        if(selectMenu>0)
          selectMenu--;
        Menu(selectMenu);
      }
      delay(100);
    }
    else if(menuPage==1){//Start
      if(shown==false){
        InsertGameMenu();
        shown=true;
        value=0;
      }
      menu=InsertGame();
      if(menu!=0){
        shown=false;
        menuPage=0;
        GameSelectMenu(menu);
        delay(2000*loadingScreenMultiplier+1000);
      }
    }
    else if(menuPage==2){//Setari Dispozitiv
      if(shown==false){
        DevSetMenu();
        shown=true;
      }
    
      if(btnYesStare==HIGH){
        if(selectMenu==0){//Sunet
          if(sunet==false)
            sunet=true;
          else
            sunet=false;
        }
        else if(selectMenu==1){//Loading screen
          loadingScreenMultiplier++;
          if(loadingScreenMultiplier>2)
            loadingScreenMultiplier=0;
        }
        if(sunet==true)
          tone(BUZZER,2000,500);
        DevOptionsMenu(selectMenu);
        delay(400);
      }
      else if(btnSusStare==HIGH){
        if(selectMenu<1)
          selectMenu++;
        DevOptionsMenu(selectMenu);
      }
      else if(btnJosStare==HIGH){
        if(selectMenu>0)
          selectMenu--;
        DevOptionsMenu(selectMenu);
      }
      delay(100);
    }
    else if(menuPage==3){//Setari Jocuri
      if(shown==false){
        GmeSetMenu();
        shown=true;
      }
    
      if(btnDrpStare==HIGH){
        if(selectMenu==0){//Viteza jocului
          if(gameSpeedBumpMultiplier<21)
            gameSpeedBumpMultiplier+=2;
        }
        else if(selectMenu==1){//Dimensiune harta joc
          if(selectedSize<9)
            selectedSize++;
          playgroundSize=presetGroundSize[selectedSize];
          sizePlayer=120/playgroundSize;
          pozPlayerX=playgroundSize/2;
          pozPlayerY=playgroundSize/2;
        }
        GmeOptionsMenu(selectMenu);
        delay(200);
      }
      else if(btnStgStare==HIGH){
        if(selectMenu==0){//Viteza jocului
          if(gameSpeedBumpMultiplier>5)
            gameSpeedBumpMultiplier-=2;
        }
        else if(selectMenu==1){//Dimensiune harta joc
          if(selectedSize>0)
            selectedSize--;
          playgroundSize=presetGroundSize[selectedSize];
          sizePlayer=120/playgroundSize;
          pozPlayerX=playgroundSize/2;
          pozPlayerY=playgroundSize/2;
        }
        GmeOptionsMenu(selectMenu);
        delay(200);
      }
      else if(btnSusStare==HIGH){
        if(selectMenu<1)
          selectMenu++;
        GmeOptionsMenu(selectMenu);
      }
      else if(btnJosStare==HIGH){
        if(selectMenu>0)
          selectMenu--;
        GmeOptionsMenu(selectMenu);
      }
      delay(100);
    }

    if(btnNotStare==HIGH){
      shown=false;
      menuPage=0;
      selectMenu=0;
      Menu(0);
    }
  }
  else
  if(menu==1){//Joc 1 Move it
    if(menuPage==0){//Play
      if(shown==false){
        shown=true;
        score=0;
        Game1GFX("0",true); 
      }
      
      if(btnDrpStare==HIGH){
        if(MovePlayerFGFX("dreapta")==1){
          score++;
          ModifyScoreGFX(score);
        }
      }
      else if(btnJosStare==HIGH){
        if(MovePlayerFGFX("jos")==1){
          score++;
          ModifyScoreGFX(score);
        }
      }
      else if(btnStgStare==HIGH){
        if(MovePlayerFGFX("stanga")==1){
          score++;
          ModifyScoreGFX(score);
        }
      }
      else if(btnSusStare==HIGH){
        if(MovePlayerFGFX("sus")==1){
          score++;
          ModifyScoreGFX(score);
        }
      }
      
      if(btnNotStare==HIGH){
        selectMenu=0;
        PauseGameMenu(selectMenu);
        menuPage=1;
      }
      delay(10*gameSpeedBumpMultiplier);
    }
    else if(menuPage==1){//Pause 
      if(btnYesStare==HIGH){
        if(selectMenu==0){//Resume 
          Game1GFX("0",false);
          ModifyScoreGFX(score);
          menuPage=0;
          selectMenu=0;
          delay(2000*loadingScreenMultiplier+1000);
        }
        else
        if(selectMenu==1){//Restart
          score=0;
          for(int i=0;i<=playgroundSize;i++)
            for(int j=0;j<=playgroundSize;j++)
              matrix[i][j]=0;
          pozPlayerX=playgroundSize/2;
          pozPlayerY=playgroundSize/2;
          menuPage=0;
          selectMenu=0;
          Game1GFX("0",true);
        }
        else
        if(selectMenu==2){//Quit
          score=0;
          menu=0;
          Menu(0);
          for(int i=0;i<playgroundSize;i++)
            for(int j=0;j<playgroundSize;j++)
              matrix[i][j]=0;
          pozPlayerX=playgroundSize/2;
          pozPlayerY=playgroundSize/2;
          menuPage=0;
          selectMenu=0;
          delay(2000*loadingScreenMultiplier+1000);
        }
        if(sunet==true)
          tone(BUZZER,2000,700);
      }
      else if(btnSusStare==HIGH){
        if(selectMenu<nrOptionsMenu-1)
          selectMenu++;
        PauseGameMenu(selectMenu);
      }
      else if(btnJosStare==HIGH){
        if(selectMenu>0)
          selectMenu--;
        PauseGameMenu(selectMenu);
      }
      delay(100);
    }
  }
  else
  if(menu==2){//Joc 2 Snake
    if(menuPage==0){//Play
      if(shown==false){
        shown=true;
        value=0;
        score=0;
        headDirection=1;
        Game2GFX("0",headDirection,true);
      }
      if(btnJosStare==HIGH&&headDirection!=3)
        headDirection=1;
      if(btnDrpStare==HIGH&&headDirection!=4)
        headDirection=2;
      if(btnSusStare==HIGH&&headDirection!=1)
        headDirection=3;
      if(btnStgStare==HIGH&&headDirection!=2)
        headDirection=4;
        
      if(btnNotStare==HIGH){
        selectMenu=0;
        PauseGameMenu(selectMenu);
        menuPage=1;
      }
      
      if(value==gameSpeedBumpMultiplier-1){
        if(UpdatePlayerFGFX(headDirection,score)==false){//Game over
          headDirection=1;
          menu=0;
          shown=false;
          head=0;
          tail=0;
          headDirection=1;
          body[head].x=playgroundSize/2;
          body[tail].y=playgroundSize/2;
          for(int i=0;i<=playgroundSize;i++)
            for(int j=0;j<=playgroundSize;j++)
              matrix[i][j]=0;
          GameOverSnakeGFX();
          tft.fillScreen(ST77XX_BLACK);
          Menu(0);
        }
        value=0;
      }
      else
        value++;
  
      delay(30);
    }
    else if(menuPage==1){//Pause
      if(btnYesStare==HIGH){
        if(selectMenu==0){//Resume 
          Game2GFX("0",headDirection,false);
          ModifyScoreGFX(score);
          menuPage=0;
          selectMenu=0;
          delay(2000*loadingScreenMultiplier+1000);
        }
        else
        if(selectMenu==1){//Restart
          score=0;
          menuPage=0;
          selectMenu=0;
          for(int i=0;i<=playgroundSize;i++)
            for(int j=0;j<=playgroundSize;j++)
              matrix[i][j]=0;
          head=0;
          tail=0;
          body[head].x=playgroundSize/2;
          body[tail].y=playgroundSize/2;
          headDirection=1;
          tft.fillScreen(ST77XX_BLACK);
          Game2GFX("0",headDirection,true);
          delay(2000*loadingScreenMultiplier+1000);
        }
        else
        if(selectMenu==2){//Quit
          score=0;
          menu=0;
          menuPage=0;
          selectMenu=0;
          Menu(0);
          for(int i=0;i<=playgroundSize;i++)
            for(int j=0;j<=playgroundSize;j++)
              matrix[i][j]=0;
          headDirection=1;
          head=0;
          tail=0;
          for(int i=0;i<250;i++){
            body[i].x=playgroundSize/2;
            body[i].y=playgroundSize/2;
          }
          delay(2000*loadingScreenMultiplier+1000);
        }
        if(sunet==true)
          tone(BUZZER,2000,700);
      }
      else if(btnSusStare==HIGH){
        if(selectMenu<nrOptionsMenu-1)
          selectMenu++;
        PauseGameMenu(selectMenu);
      }
      else if(btnJosStare==HIGH){
        if(selectMenu>0)
          selectMenu--;
        PauseGameMenu(selectMenu);
      }
      delay(100);
    }
  }
}
