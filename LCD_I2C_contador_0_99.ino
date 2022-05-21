#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0X27,16,2);
int CONTADOR=0;
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();}
void loop() {
   for(CONTADOR=0;CONTADOR<=99;CONTADOR++){
      lcd.setCursor(0,0);
      lcd.print("El conteo es:");
      lcd.setCursor(0,1);
      lcd.print(CONTADOR);
      delay(500);
      lcd.clear();}
   if(CONTADOR==100){
      lcd.setCursor(0,0);
      lcd.print("PRACTICA 5");
      lcd.setCursor(0,1);
      lcd.print("ELECTRONICAKINAL");
      delay(5000);
      lcd.clear();}}
