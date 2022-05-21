int tiempo=200;
int bin[]={126,12,182,158,204,218,250,14,254,206};
void setup() {
   for(int pindisplay =1;pindisplay <8;pindisplay++) {
    pinMode(pindisplay,OUTPUT);}
  for(int pinboton =8;pinboton <11;pinboton++) {
    pinMode(pinboton,INPUT);}}
void loop() {
  int BOTON1 = digitalRead(8);
  int BOTON2 = digitalRead(9);
  int BOTON3 = digitalRead(10);
  delay(500);
  if(BOTON1==1){tiempo=1000;}
  if(BOTON2==1){tiempo=2000;}
  if(BOTON3==1){tiempo=3000;}
  if(((BOTON1==1&&BOTON2==1)&&BOTON3==1)||((BOTON1==0&&BOTON2==0)&&BOTON3==0)){
    PORTD=0;}
  else{
    for(int numero=0;numero<10;numero++){
      PORTD=bin[numero];
      delay(tiempo);}}}
