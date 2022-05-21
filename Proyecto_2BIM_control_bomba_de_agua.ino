#include <Wire.h>                                        //libreria para I2C
#include <LiquidCrystal_I2C.h>                           //Libreria de LCD
LiquidCrystal_I2C lcd(0X27,16,2);                        //creacion de objeto
#define Trigger 4                                        //macro de pin 4 para ultrasonico
#define Echo 5                                           //macro de pin 5 para ultrasonico
float porcentaje_calculado, nivel=0;                     //variable para la funcion, establecer el nivel al que se apagará la bomba
float altura_max=13, altura_ultrasonico=3.48;            //la altura máxima a la que llega el agua, altura extra a la que se encuentra el ultrasonico
bool estado=true;                                        //variable para controlar while de la funcion comparacion_nivel
void setup() {
  lcd.init();                                            //inicializar lcd
  lcd.backlight();                                       //encender luces
  lcd.clear();                                           //limpiar pantalla
  pinMode(Echo, INPUT);                                  //programar entrada para ultrasonico
  pinMode(Trigger, OUTPUT);                              //programar salida para ultrasonico
  digitalWrite(Trigger,LOW);                             //evitar que trigger se active, por si algun codigo cargado lo tiene en HIGH
  pinMode(10,OUTPUT);                                    //pin que activa la bomba
  pinMode(11,OUTPUT);}                                   //pin que activa el buzzer
void loop() { 
  int boton1=digitalRead(A0);                            //leer los pines analogicos y guardar en variable
  int boton2=digitalRead(A1);
  int boton3=digitalRead(A2);
  int boton4=digitalRead(A3);
  delay(100);                                            //esperar para que la lectura de los pines sea correcta
  lcd_porcentaje();                                      //funcion que mostrará en la lcd el porcentaje
  if(porcentaje_calculado>=0&&porcentaje_calculado<=101){//if que solo se ejecutará si el porcentaje anteriormente calculado está entre 0 y 101
    if(porcentaje_calculado<25&&porcentaje_calculado>=0){//encenderá buzzer si el porcentaje está entre 0 y 25
      tone(11,1047);}                                    //activar buzzer a cierta frecuencia
    else{noTone(11);}                                    //sino se ejecuta el if mantiene apagado el buzzer, si estaba funcionando y supera el rango, lo apagará
    if(porcentaje_calculado<15&&porcentaje_calculado>=0){//rango de 0 a 15, es el encendido automatico
      nivel=100;                                         //el nivel al que llegará el agua será de 100                                 
      comparacion_nivel();}                              //llama a la funcion
    if     (boton1==1){                                  //si el botón es igual a uno ejecuta el if
      digitalWrite(10,HIGH);                             //enciende la bomba
      lcd_porcentaje();}                                 //llamará la funcion y se verá el porcentaje
    else if(boton2==1){                                  //si el if anterior no se ejecuta pasará a este, se ejecuta si es igual a 1
      nivel=51;                                          //establece el nivel a 51, el lcd mostrará 50 ya que cuando llegue a 51, se apagará y un poco del agua regresará
     comparacion_nivel();}                               //llama a la funcion
    else if(boton3==1){                                  //si no se ejecuta lo anterior, se ejecutará si es igual a 1
      nivel=76;                                          //establece el nivel a 76, el lcd mostrará 75 ya que cuando llegue a 76, se apagará y un poco del agua regresará
      comparacion_nivel();}                              //llama a la funcion
    else if(boton4==1){                                  //ultimo else if que se ejecuta solo si es igual a 1 y si ninguno de los anteriores se ejecutó
      nivel=100;                                         //establece el nivel a 100
      comparacion_nivel();}                              //llamar a la funcion
    else{                                                //else si ninguno de los else if y el if de los botones se ejecuta
      digitalWrite(10,LOW);                              //apaga la bomba
      estado=true;}}}                                    //establece la variable en true, reactivando para el while de la funcion comparacion_nivel
