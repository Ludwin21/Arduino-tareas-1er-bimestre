int CONTADOR=0;
int i=1;
void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(3,INPUT);}
void loop() {
  int BOTON1= digitalRead(2);
  int BOTON2= digitalRead(3);
  while(i<2){
    Serial.print("El conteo inicial es de:");
    Serial.println(CONTADOR);
    i++;}
  if ((CONTADOR>=99&&BOTON1==1)||(CONTADOR<=0&&BOTON2==0)){
    delay(500);
    Serial.println("El conteo es de 0 a 99");}
  else if(BOTON1==1){
    delay(500);
    CONTADOR++;
    Serial.print("Aumento, el conteo ahora es de:");
    Serial.println(CONTADOR);}
  else if(BOTON2==0){
    delay(500);
    CONTADOR--;
    Serial.print("Decremento, el conteo ahora es de:");
    Serial.println(CONTADOR);}}
