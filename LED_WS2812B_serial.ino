#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel tira = Adafruit_NeoPixel(5,10,NEO_GRB+NEO_KHZ800);
int rojo=0, verde=0, azul=0;
void setup(){
  Serial.begin(9600);
  tira.begin();
  tira.show();}
void loop(){
  if(Serial.available()>0){
    char letra= Serial.read();
    delay(500);
    if(letra=='R'){
      rojo=255; verde=0; azul=0;
      LED();}
    else if(letra=='G'){
      rojo=0; verde=255; azul=0;
      LED();}
    else if(letra=='B'){
      rojo=0; verde=0; azul=255;
      LED();}
    else if(letra=='L'){
      rojo=255; verde=105; azul=180;
      LED();}
    else if(letra=='O'){
      rojo=255; verde=69; azul=0;
      LED();}}}
void LED(){
  tira.clear();
  tira.setBrightness(20);
  for(int i=0; i<5;i++){
  tira.setPixelColor(i,rojo,verde,azul);
  tira.show();
  delayMicroseconds(10);}}  
