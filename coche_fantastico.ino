#define led1 13
#define led2 12
#define led3 11
#define led4 10
#define led5 9
#define boton 8
int valorboton = 0;
void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(boton,INPUT);
}
void loop() {
  valorboton = digitalRead (boton);
  if (valorboton == 1){
    digitalWrite(led1,HIGH);
    delay(500);
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    delay(500);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    delay(500);
    digitalWrite(led3,LOW);
    digitalWrite(led4,HIGH);
    delay(500);
    digitalWrite(led4,LOW);
    digitalWrite(led5,HIGH);
    delay(1000);
    digitalWrite(led5,LOW);
    digitalWrite(led4,HIGH);
    delay(500);
    digitalWrite(led4,LOW);
    digitalWrite(led3,HIGH);
    delay(500);
    digitalWrite(led3,LOW);
    digitalWrite(led2,HIGH);
    delay(500);
    digitalWrite(led2,LOW);
    digitalWrite(led1,HIGH);
    delay(1000);
  }else{
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
  }
}
