void setup(){
pinMode(5,OUTPUT);
Serial.begin(9600);
}
void loop(){
 float POT=analogRead(A5);
 int POTVOL=(POT*255)/1023;
 analogWrite(5,POTVOL);
 Serial.println(POTVOL);
 delay(100);
}
