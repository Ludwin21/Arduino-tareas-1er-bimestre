int ESTADO=0, LED=0;
void setup() {
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);}
void loop() {
 int SWITCH = digitalRead(2);
 if ((SWITCH==1)&&(ESTADO==0)){
    LED=1-LED;}
 ESTADO=SWITCH;
 if (LED==1){
    digitalWrite(3,HIGH);}
 else{
    digitalWrite(3,LOW);}}
