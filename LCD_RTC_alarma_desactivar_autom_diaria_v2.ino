#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
LiquidCrystal_I2C lcd(0X27,16,2);
RTC_DS3231 rtc;
int alarmahora=17;
int alarmamin=14;
bool valorAlarma=true;
void setup() {
  lcd.init();
  lcd.backlight();
  rtc.begin();
  rtc.adjust(DateTime(__DATE__,__TIME__));
  pinMode(7,OUTPUT);}
void loop() {
  DateTime TIEMPO=rtc.now();
  if(TIEMPO.hour() == alarmahora && TIEMPO.minute() == alarmamin){
    if(valorAlarma==true){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("ALARMA");
      digitalWrite(7,HIGH);
      delay(30000);
      valorAlarma=false;}}
  digitalWrite(7,LOW);
  
  if(TIEMPO.day()>=10){
    lcd.setCursor(0,0);
    lcd.print(TIEMPO.day());}
  else{
    lcd.setCursor(0,0);
    lcd.print("0");
    lcd.setCursor(1,0);
    lcd.print(TIEMPO.day());}
  lcd.setCursor(2,0);
  lcd.print("/");
  if(TIEMPO.month()>=10){
    lcd.setCursor(3,0);
    lcd.print(TIEMPO.month());}
  else{
    lcd.setCursor(3,0);
    lcd.print("0");
    lcd.setCursor(4,0);
    lcd.print(TIEMPO.month());}
  lcd.setCursor(5,0);
  lcd.print("/");
  lcd.setCursor(6,0);
  lcd.print(TIEMPO.year());
  
  if(TIEMPO.hour()>=10){
    lcd.setCursor(0,1);
    lcd.print(TIEMPO.hour());}
  else{
    lcd.setCursor(0,1);
    lcd.print("0");
    lcd.setCursor(1,1);
    lcd.print(TIEMPO.hour());}
  lcd.setCursor(2,1);
  lcd.print(":");
  if(TIEMPO.minute()>=10){
    lcd.setCursor(3,1);
    lcd.print(TIEMPO.minute());}
  else{
    lcd.setCursor(3,1);
    lcd.print("0");
    lcd.setCursor(4,1);
    lcd.print(TIEMPO.minute());}
  lcd.setCursor(5,1);
  lcd.print(":");
  lcd.setCursor(6,1);
  lcd.print(TIEMPO.second());
  delay(1000);
  lcd.clear();
  if(TIEMPO.hour()==1 && TIEMPO.minute()==0){
    valorAlarma=true;}}
