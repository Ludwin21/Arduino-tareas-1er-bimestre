#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_NeoPixel.h>
LiquidCrystal_I2C lcd(0X27,16,2);
Adafruit_NeoPixel tira = Adafruit_NeoPixel(5,10,NEO_GRB+NEO_KHZ800);
int rojo=0, verde=0, azul=0;
char tecla;
String texto_color, datos_alumno;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  tira.begin();
  tira.show();}
  
void loop() {
  while(Serial.available()){
    tecla=Serial.read();
    delay(200);
    if(tecla=='1'){
      rojo=255; verde=69; azul=0;
      texto_color="NARANJA";
      lcd_ws2812b();}
    else if(tecla=='2'){
      rojo=255; verde=255; azul=0;
      texto_color="AMARILLO";
      lcd_ws2812b();}
    else if(tecla=='3'){
      rojo=238; verde=130; azul=238;
      texto_color="VIOLETA";
      lcd_ws2812b();}
    else if(tecla=='4'){
      datos_alumno="Garcia 2021247";
      lcd_alumno();}
    else if(tecla=='5'){
      datos_alumno="Godoy 2020512";
      lcd_alumno();}}}
      
void lcd_ws2812b(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(texto_color);
  tira.clear();
  tira.setBrightness(20);
  for(int i=0; i<5;i++){
  tira.setPixelColor(i,rojo,verde,azul);
  tira.show();
  delayMicroseconds(10);}}

void lcd_alumno(){
  lcd.clear();
  for(int i=0; i<5;i++){
  tira.setPixelColor(i,0,0,0);
  tira.show();
  delayMicroseconds(10);}
  lcd.setCursor(3,0);
  lcd.print("PRACTICA 7");
  lcd.setCursor(1,1);
  lcd.print(datos_alumno);}
