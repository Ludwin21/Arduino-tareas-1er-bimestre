#include <Keypad.h>
const byte FILAS=4, COLUMNAS=4;
char keys[FILAS][COLUMNAS]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'} };
byte pinesFilas[FILAS]={9,8,7,6}, pinesColumnas[COLUMNAS]={5,4,3,2};
Keypad teclado= Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);
char TECLA;
void setup() {
  Serial.begin(9600);}
void loop() {
   TECLA=teclado.getKey();
  if(TECLA){
      Serial.println(TECLA);
      delay(200);}}
