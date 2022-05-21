void setup(){
  pinMode(7,INPUT);
  for(int pin = 8;pin <13;pin++){
    pinMode(pin,OUTPUT);} }
void loop(){
  int valorboton = digitalRead(7);
  if (valorboton==1){
    for(int pin = 8;pin <13;pin++){
      digitalWrite(pin,HIGH);
      delay(500);
      digitalWrite(pin,LOW);}
    for(int pin = 12;pin >7;pin--){
      digitalWrite(pin,HIGH);
      delay(500);
      digitalWrite(pin,LOW);}}
  else{
    for(int pin = 8;pin <13;pin++){
      digitalWrite(pin,LOW);} } }
