int velocidad[]={1000,2000};
int posicion=0;
int ciclo=1;
void setup(){
  Serial.begin(9600);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  for(int pin = 8;pin <13;pin++){
    pinMode(pin,OUTPUT);} }
void loop(){
  int boton1 = digitalRead(6);
  int boton2 = digitalRead(7);
  delay(200);
  if((boton1==0&&boton2==0)||(boton1==1&&boton2==1)){
    PORTB=0;}
  else{
    if(boton1==1){
      posicion=0;
      Serial.println("Velocidad 1");}
    if(boton2==1){
      posicion=1;
      Serial.println("Velocidad 2");}
    for(int i=0;i<3;i++){
      for(int pin = 8;pin <13;pin++){
         digitalWrite(pin,HIGH);
         delay(velocidad[posicion]);
         digitalWrite(pin,LOW);}
      for(int pin = 12;pin >7;pin--){
         digitalWrite(pin,HIGH);
         delay(velocidad[posicion]);
         digitalWrite(pin,LOW);}}
    for(int destello=0;destello<5;destello++){
      PORTB=31;
      delay(velocidad[posicion]);
      PORTB=0;
      delay(velocidad[posicion]);}
    Serial.print("Este es el ciclo numero:");
    Serial.println(ciclo);
    ciclo++;}}
