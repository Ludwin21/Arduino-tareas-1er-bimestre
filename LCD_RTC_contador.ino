#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
LiquidCrystal_I2C lcd(0X27,16,2);
RTC_DS3231 rtc;
void setup() {
  lcd.init();
  lcd.backlight();
  rtc.begin();
  rtc.adjust(DateTime(2022,4,22,8,58,0));}
void loop() {
  DateTime contador=rtc.now();
  lcd.setCursor(0,0);
  lcd.print("El conteo es:");
  lcd.setCursor(0,1);
  lcd.print(contador.second());
  delay(1000);
  if(contador.second()==50){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ELECTRONICA");
    lcd.setCursor(0,1);
    lcd.print("KINAL");
    delay(9000);
    lcd.clear();}}
