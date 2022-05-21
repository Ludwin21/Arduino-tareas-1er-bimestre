int CONTADOR=0;
void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
}
void loop() {
  int BOTON1= digitalRead(2);
  int BOTON2= digitalRead(3);
  if(BOTON1==1){
    CONTADOR=CONTADOR+1;
    delay(500);
    Serial.print("El contador es de:");
    Serial.println(CONTADOR);}
  else if(BOTON2==0){
    CONTADOR=CONTADOR-1;
    delay(500);
    Serial.print("El contador es de:");
    Serial.println(CONTADOR);}
}
