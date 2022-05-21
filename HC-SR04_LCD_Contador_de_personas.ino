#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0X27,16,2);
#define Trigger 2
#define Echo 3
int contador_personas=0;
byte cuerpo[8] = {B01110,B01110,B00100,B11111,B00100,B01010,B10001,B00000,};
void setup(){
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(Echo,INPUT);
  pinMode(Trigger,OUTPUT);
  digitalWrite(Trigger,LOW);
  lcd.createChar (7,cuerpo);}
void loop(){
  digitalWrite (Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite (Trigger, LOW);
  int sensor = pulseIn (Echo, HIGH);
  int distancia = sensor/59;
  if(distancia>=25&&distancia<=75){
     contador_personas++;
     lcd.setCursor(0,0);
     lcd.print("Han ingresado: ");
     lcd.setCursor(0,1);
     lcd.print(contador_personas);
     lcd.setCursor(3,1);
     lcd.write (byte (7));
     delay(3000);} }
