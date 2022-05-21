void setup(){
  for(int pin = 5;pin <8;pin++){
    pinMode(pin,INPUT);}
  for(int pin = 8;pin <11;pin++){
    pinMode(pin,OUTPUT);}}
void loop(){
  int valorboton1 = digitalRead(5);
  int valorboton2 = digitalRead(6);
  int valorboton3 = digitalRead(7);
  if (valorboton1==1){
    digitalWrite(8,HIGH);
    digitalWrite(10,HIGH);}
  else if (valorboton2==1){
    digitalWrite(10,HIGH);
    digitalWrite(9,HIGH);}
  else if (valorboton3==1){
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);}
  else{
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);} }
