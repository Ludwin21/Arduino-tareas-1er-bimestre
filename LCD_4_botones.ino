#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0X27,16,2);
int CONTADOR=0;
int d=0;
int i=10;
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("KINAL");
  lcd.setCursor(0,1);
  lcd.print("2021247");
  delay(10000);
  lcd.clear();
  for(int p=7;p<11;p++){
    pinMode(p,INPUT);}}
void loop() {
   int BOTON1=digitalRead(7);
   int BOTON2=digitalRead(8);
   int BOTON3=digitalRead(9);
   int BOTON4=digitalRead(10);
   if(BOTON1==1){
                 for(CONTADOR=0;CONTADOR<=99;CONTADOR++){
                    lcd.setCursor(0,0);
                    lcd.print("ASCENDENTE");
                    lcd.setCursor(0,1);
                    lcd.print(CONTADOR);
                    delay(500);
                    lcd.clear();}}
   else if(BOTON2==1){
                 for(CONTADOR=99;CONTADOR>=0;CONTADOR--){
                    lcd.setCursor(0,0);
                    lcd.print("DESCENDENTE");
                    lcd.setCursor(0,1);
                    lcd.print(CONTADOR);
                    delay(500);
                    lcd.clear();}}
   else if(BOTON3==1){
                 for(int c=0;c<11;c++){
                  lcd.setCursor(d,1);
                  lcd.print("Garcia");
                  lcd.setCursor(i,0);
                  lcd.print("Ludwin");
                  d++;
                  i--;
                  if(d==11){
                     d=0;}
                  if(i==-1){
                     i=10;}
                  delay(500);
                  lcd.clear();}}
  else if(BOTON4==1){
                 for(int c=0;c<50;c++){
                  int POT=analogRead(A0);
                  lcd.setCursor(0,0);
                  lcd.print("El valor es:");
                  lcd.setCursor(0,1);
                  lcd.print(POT);
                  delay(200);
                  lcd.clear();}}}
