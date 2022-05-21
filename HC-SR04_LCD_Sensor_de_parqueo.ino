#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0X27,16,2);
int posicion_blink[]={0,1,2,3,4,5,6,9,10,11,12,13,14,15};       //posiciones en el LCD del blink
int distancia_vehiculo=0;                                       //distancia que mostrará en el centro
int posicion_inicio=0;                                          //posicion en la que iniciará el blink de acuerdo a la distancia
int posicion_final=0;                                           //posicion en la que terminará el blink de acuerdo a la distancia
int posicion_palabra=0;                                         //posicion en la que se situa la palabra en la linea 2 de acuerdo a la distancia
String seleccion_palabra[]={"CUIDADO","ALTO","  "};             //palabras de acuerdo a la distancia 
int palabra=0;                                                  //posicion de la palabra que mostrará de acuerdo a la distancia
byte cubo[8] = {B11111,B11111,B11111,B11111,B11111,B11111,B11111,B11111,};//un byte que en el LCD imprime un rectangulo
void setup(){
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(3,INPUT);
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);
  lcd.createChar (7,cubo);}               //crea el caracter
void loop(){
  digitalWrite (2, HIGH);
  delayMicroseconds(10);
  digitalWrite (2, LOW);
  int sensor = pulseIn (3, HIGH);
  int distancia = sensor/59;
  if     (distancia==50){
          distancia_vehiculo=50;          //establece valores de las varaibles mencionadas
          posicion_inicio=4;              //donde va el primer cuadro blink segun el array
          posicion_final=9;               //donde va el último cuadro blink segun el array
          palabra=2;                      //segun la el valor, escoge la palabra de advertencia en el array, este no lleva palabra pero como comparten función, debe imprimir espacios 
          parpadeos();}                   //llama a la función
  else if(distancia==30){                 //evalua si la distancia es mayor o igual a 11 pero menor o igual a 30
          distancia_vehiculo=30;          //lo mismo que el anterior if
          posicion_inicio=2;
          posicion_final=11;
          posicion_palabra=5;             //posiciona la palabra en la segunda fila y columna para que quede centrado
          palabra=0;                     
          parpadeos();} 
  else if(distancia==10){                 //evalua si la distancia es mayor o igual a 1 pero menor o igual a 10
          distancia_vehiculo=10;
          posicion_inicio=0;
          posicion_final=13;
          posicion_palabra=6;
          palabra=1;
          parpadeos();}}
void parpadeos(){                         //la función llamada en cualquira de los 3 casos anteriores
    lcd.clear();                          //limpia para evitar sobreponer palabras
    lcd.setCursor(7,0);                   //situa la posicion de la distancia del carro
    lcd.print(distancia_vehiculo);        //imprime 50, 30 o 10
    lcd.setCursor(posicion_palabra,1);    //de acuerdo al if 2 o al 3, tendrá un valor u otro donde situará la palabra de advertencia
    lcd.print(seleccion_palabra[palabra]);//del array selecciona la palabra según el valor que se dio en el if 2 o if 3
    for(posicion_inicio; posicion_inicio<posicion_final; posicion_inicio++){ //de acuerdo a los if, será el parametro en el que se moverá en el array
         lcd.setCursor(posicion_blink[posicion_inicio],0); //posiciona en el array,ejemplo: si es posicion2=4 en el array es el no.3, el cual se utilizará para situar el cursor
         lcd.write (byte (7));            //escribe el byte en el LCD
         lcd.blink();                     //hace el blink
         delayMicroseconds(10);}}         //esperar 10us
