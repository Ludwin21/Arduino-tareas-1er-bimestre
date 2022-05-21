void setup(){
  pinMode(3,OUTPUT);
  pinMode(7,OUTPUT);}
void loop(){
  digitalWrite(3,HIGH);
  digitalWrite(7,LOW);
  delay(100); 
  digitalWrite(3,LOW);
  digitalWrite(7,HIGH);
  delay(100);  }
