void setup() {
  for(int pin = 2;pin <7;pin++){
    pinMode(pin,OUTPUT);}
}
void loop() {
  int numero=0;
  while(numero<=124){
    PORTD=numero;
    delay(500);
    numero=numero+4;}
}
