#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0X27,16,2);
#define Trigger 4
#define Echo 5
void setup(){
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(Echo,INPUT);
  pinMode(Trigger,OUTPUT);
  digitalWrite(Trigger,LOW);}
void loop(){
  digitalWrite (Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite (Trigger, LOW);
  int sensor = pulseIn (Echo, HIGH);
  int distancia = sensor/59;
  if(distancia>=45){
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("FUERA DE ALCANCE");
     delay(1000);} 
  else if(distancia>=30&&distancia<=44){
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Persona / Objeto");
     lcd.setCursor(0,1);
     lcd.print("Acercandose");
     delay(1000);} 
  else if(distancia>=15&&distancia<=29){
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Cuidado, Espacio");
     lcd.setCursor(0,1);
     lcd.print("Privado");
     digitalWrite(10,HIGH);
     delay(5000);
     digitalWrite(10,LOW);}
  else if(distancia>=5&&distancia<=14){
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Invadiendo");
     lcd.setCursor(0,1);
     lcd.print("Espacio Privado");
     tone(11,1047,10000);
     digitalWrite(10,HIGH);
     delay(10000);
     digitalWrite(10,LOW);}}
