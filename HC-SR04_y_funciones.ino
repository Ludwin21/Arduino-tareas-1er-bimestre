#define Trigger 4
#define Echo 5
float resultado_cm, resultado_pulg;
void setup(){
  Serial.begin(9600);
  pinMode(Echo, INPUT);
  pinMode(Trigger, OUTPUT);
  digitalWrite(Trigger, LOW);}
void loop(){
  resultado_cm   = distancia_cm();
  resultado_pulg = distancia_pulg();
  Serial.print ("La distancia en cm es: ");
  Serial.print (resultado_cm);
  Serial.println (" cm");
  Serial.print ("La distancia en pulgadas es: ");
  Serial.print (resultado_pulg);
  Serial.println (" pulgadas");
  Serial.println (" ");
  delay(1000);}
float distancia_cm (){
  digitalWrite (Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite (Trigger, LOW);
  float sensor = pulseIn (Echo, HIGH);
  float distancia = sensor/58.30;
  return distancia;}
float distancia_pulg (){
  float conversion = resultado_cm /2.54;
  return conversion;}
