int calcular_porcentaje (){                       //funcion para calcular el porcentaje del agua
  digitalWrite (Trigger, HIGH);                   //poner en alto el pin
  delayMicroseconds(10);                          //esperar 10us 
  digitalWrite (Trigger, LOW);                    //poner en bajo el pin
  float sensor = pulseIn (Echo, HIGH);            //calcula la distancia desde el ultrasonico hasta el fondo del vaso
  float distancia = sensor/58.30;                 //divide lo obtenido
  float distancia2 = distancia-altura_ultrasonico;//la distancia se le restará para que sea igual a la distancia maxima de la variable altura_max
  float porcentaje1=altura_max-distancia2;        //a la variable altura_max se le resta distancia2 para obtener el nivel del agua
  float porcentaje2=(porcentaje1*100)/altura_max; //se vuelve porcentaje con una regla de 3 y altura_max
  return porcentaje2;}                            //regresar el valor obtenido
