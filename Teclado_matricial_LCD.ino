#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0X27,16,2);
#include <Keypad.h>
const byte FILAS=4, COLUMNAS=4;
char keys[FILAS][COLUMNAS]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'} };
byte pinesFilas[FILAS]={9,8,7,6}, pinesColumnas[COLUMNAS]={5,4,3,2};
Keypad teclado= Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();}
void loop() {
  char TECLA=teclado.getKey();
  if(TECLA){
      lcd.setCursor(2,0);
      lcd.print("PRACTICA NO.7");
      lcd.setCursor(0,1);
      lcd.print("Tecla:");
      lcd.setCursor(6,1);
      lcd.print(TECLA);
      delay(500);}}
