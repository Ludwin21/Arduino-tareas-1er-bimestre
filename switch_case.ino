int bin1[]={0,0,128,128,128,0};
int bin2[]={57,62,55,56,16,63};
int opcion_boton=0;
int i=0;
int ciclo=1;
void setup(){
  Serial.begin(9600);
  for(int pin = 2;pin <14;pin++){
    pinMode(pin,OUTPUT);}}
void loop(){
  int boton1=digitalRead(A5);
  int boton2=digitalRead(A4);
  int boton3=digitalRead(A3);
  int boton4=digitalRead(A2);
  delay(500);
  if((boton1==1&&boton3==1)||(boton2==1&&boton4==1)){
    opcion_boton=5;}
  else if(boton1==1){opcion_boton=1;}
  else if(boton2==1){opcion_boton=2;}
  else if(boton3==1){opcion_boton=3;}
  else if(boton4==1){opcion_boton=4;}
  switch(opcion_boton){
  case 1:
    Serial.println("Practica 4");
    break;
  case 2:
      for(int i=0;i<3;i++){
        for(int pin = 2;pin <7;pin++){
           digitalWrite(pin,HIGH);
           delay(250);
           digitalWrite(pin,LOW);}
        for(int pin = 6;pin >1;pin--){
           digitalWrite(pin,HIGH);
           delay(250);
           digitalWrite(pin,LOW);}}
      for(int destello=0;destello<5;destello++){
        PORTD=124;
        delay(250);
        PORTD=0;
        delay(250);}
       break;
  case 3:
      for(int i=0;i<3;i++){
        for(int pin = 2;pin <7;pin++){
           digitalWrite(pin,HIGH);
           delay(500);
           digitalWrite(pin,LOW);}
        for(int pin = 6;pin >1;pin--){
           digitalWrite(pin,HIGH);
           delay(500);
           digitalWrite(pin,LOW);}}
      for(int destello=0;destello<5;destello++){
        PORTD=124;
        delay(500);
        PORTD=0;
        delay(500);}
      Serial.print("Este es el ciclo numero:");
      Serial.println(ciclo);
      ciclo++;
       break;
   case 4:
       for(int numero=0;numero<6;numero++){
         PORTB=bin2[numero];
         PORTD=bin1[numero];
         delay(1000);
         PORTB=0;}
       break; 
   case 5:
       Serial.println("GRACIAS POR SU ATENCION");
       PORTD=252;
       PORTB=63;
       delay(1000);
       PORTD=0;
       PORTB=0;
       delay(1000);
       break; }
       opcion_boton=0;}
