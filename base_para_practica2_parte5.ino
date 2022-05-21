void setup(){
  for(int pin = 2;pin <4;pin++){
    pinMode(pin,INPUT);}
  for(int pin = 4;pin <14;pin++){
    pinMode(pin,OUTPUT);}}
void loop(){
 int valorboton1 = digitalRead(2);
 int valorboton2 = digitalRead(3);
 int valorboton3 = valorboton1 * valorboton2;
  if(valorboton3==1){
    for(int pin = 11;pin <14;pin++){
      digitalWrite(pin,HIGH);
      delay(2000);
      digitalWrite(pin,LOW);
      delay(1000);}}
  else if(valorboton1==1){
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    delay(1000); 
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    delay(1000);
    digitalWrite(5,LOW);}
  else if (valorboton2==1){
    for(int pin = 6;pin <11;pin++){
      digitalWrite(pin,HIGH);
      delay(500);
      digitalWrite(pin,LOW);}
    for(int pin = 10;pin >5;pin--){
    digitalWrite(pin,HIGH);
    delay(500);
    digitalWrite(pin,LOW);}}
  else{
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);}}
