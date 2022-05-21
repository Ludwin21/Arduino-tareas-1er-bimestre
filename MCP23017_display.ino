H#include <Wire.h>   //libreria que me permite usar el i2c
#include <Adafruit_MCP23X17.h> //libreria que me permite usar el mcp23017
int no_cero[] ={1,2,3,4,5,6},  no_uno[]   ={2,3},     no_dos[]  ={1,2,4,5,7};
int no_tres[] ={1,2,3,4,7},    no_cuatro[]={2,3,6,7}, no_cinco[]={1,3,4,6,7};
int no_seis[] ={1,3,4,5,6,7},  no_siete[] ={1,2,3},   no_ocho[] ={1,2,3,4,5,6,7};
int no_nueve[]={1,2,3,6,7};
Adafruit_MCP23X17 mcp; //Objeto que me permite usar el mcp23017.
void setup(){
  mcp.begin_I2C();    
  for(int posicion=1;posicion<8;posicion++){
  mcp.pinMode(posicion, OUTPUT);}} //gpa1-7 como salida.
void loop(){
  for(int posicion= 0;posicion<6;posicion++){
    mcp.digitalWrite(no_cero[posicion], HIGH);}
    delay(1000);
  for(int posicion= 0;posicion<6;posicion++){
    mcp.digitalWrite(no_cero[posicion], LOW);}

  for(int posicion= 0;posicion<2;posicion++){
    mcp.digitalWrite(no_uno[posicion], HIGH);}
    delay(1000);
  for(int posicion= 0;posicion<2;posicion++){
    mcp.digitalWrite(no_uno[posicion], LOW);}

  for(int posicion= 0;posicion<5;posicion++){
    mcp.digitalWrite(no_dos[posicion], HIGH);}
    delay(1000);
  for(int posicion= 0;posicion<5;posicion++){
    mcp.digitalWrite(no_dos[posicion], LOW);}
    
  for(int posicion= 0;posicion<5;posicion++){
    mcp.digitalWrite(no_tres[posicion], HIGH);}
    delay(1000);
  for(int posicion= 0;posicion<5;posicion++){
    mcp.digitalWrite(no_tres[posicion], LOW);}

  for(int posicion= 0;posicion<4;posicion++){
    mcp.digitalWrite(no_cuatro[posicion], HIGH);}
    delay(1000);
  for(int posicion= 0;posicion<4;posicion++){
    mcp.digitalWrite(no_cuatro[posicion], LOW);}
    
  for(int posicion= 0;posicion<5;posicion++){
    mcp.digitalWrite(no_cinco[posicion], HIGH);}
    delay(1000);
  for(int posicion= 0;posicion<5;posicion++){
    mcp.digitalWrite(no_cinco[posicion], LOW);}

  for(int posicion= 0;posicion<6;posicion++){
    mcp.digitalWrite(no_seis[posicion], HIGH);}
    delay(1000);
  for(int posicion= 0;posicion<6;posicion++){
    mcp.digitalWrite(no_seis[posicion], LOW);}
    
  for(int posicion= 0;posicion<3;posicion++){
    mcp.digitalWrite(no_siete[posicion], HIGH);}
    delay(1000);
  for(int posicion= 0;posicion<3;posicion++){
    mcp.digitalWrite(no_siete[posicion], LOW);}

  for(int posicion= 0;posicion<7;posicion++){
    mcp.digitalWrite(no_ocho[posicion], HIGH);}
    delay(1000);
  for(int posicion= 0;posicion<7;posicion++){
    mcp.digitalWrite(no_ocho[posicion], LOW);}
    
  for(int posicion= 0;posicion<5;posicion++){
    mcp.digitalWrite(no_nueve[posicion], HIGH);}
    delay(1000);
  for(int posicion= 0;posicion<5;posicion++){
    mcp.digitalWrite(no_nueve[posicion], LOW);}}
