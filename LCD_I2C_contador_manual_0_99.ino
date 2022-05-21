#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int CONTADOR=0;
void setup() {
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Conteo inicia en");
  lcd.setCursor(0,1);
  lcd.print(CONTADOR);}
void loop() {
   int BOTON1= digitalRead(8);
   int BOTON2= digitalRead(9);
   delay(250);
   if ((CONTADOR>=99&&BOTON1==1)||(CONTADOR<=0&&BOTON2==0)){
     delay(250);
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Rango de 0 a 99");}
  else if(BOTON1==1){
     delay(250);
     CONTADOR++;
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("AUMENTO");
     lcd.setCursor(0,1);
     lcd.print(CONTADOR);}
  else if(BOTON2==0){
     delay(250);
     CONTADOR--;
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("DECREMENTO");
     lcd.setCursor(0,1);
     lcd.print(CONTADOR);}}
