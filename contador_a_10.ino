int CONTADOR=0;
void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(13,OUTPUT);
}
void loop() {
  int BOTON = digitalRead(2);
  if (CONTADOR>=10){
    delay(800);
    Serial.println("Ha alcanzado el limite de intentos");
    digitalWrite(13,HIGH);
  }
  else if(BOTON==1){
    CONTADOR=CONTADOR+1;
    delay(500);
    Serial.print("El boton ha sido presionado la cantidad de veces de:");
    Serial.println(CONTADOR);
  }
  else{
    digitalWrite(13,LOW);
  }
}
