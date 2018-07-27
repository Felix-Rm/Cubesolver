#include <TFT_ST7735.h> 
#include <SPI.h>

byte sx = 5;
byte sy = 5;

byte cube[5][5][5];
byte block_width = 12;
long block_color[] = {
  TFT_WHITE,TFT_RED,TFT_GREEN,TFT_BLUE,TFT_YELLOW,TFT_ORANGE
};

short del = 1000;



TFT_ST7735 lcd = TFT_ST7735();



void setup(){
  Serial.begin(9600);
  
  initCube();

  lcd.init();
  lcd.setRotation(3);
  lcd.fillScreen(0);

  drawCube();
  delay(5000);
  
  rotate_right_a();
  
  drawCube();
  delay(5000);
  
  //rotate_left_a();
  
  drawCube();
  delay(5000);
}

void loop(){
}

void serialWait(){
  while(!Serial.available());
  while(Serial.available()){
    delay(10);
    Serial.read();
  }
}















