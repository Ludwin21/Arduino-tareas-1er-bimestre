void comparacion_nivel(){                                    //función void llamada
  digitalWrite(10,HIGH);                                     //encender pin de bomba
  while(estado){                                             //while que se ejecutará siempre que la variable sea true
    if(porcentaje_calculado>=nivel&&porcentaje_calculado>=0){//se ejecutará sólo si el porcentaje es igual al nivel establecido y sea mayor o igual a 0
        digitalWrite(10,LOW);                                //apaga el pin de la bomba
        estado=false;}                                       //reestablece el valor para cerrar el while
    if(porcentaje_calculado>=25&&porcentaje_calculado>=0){   //si está entre el rango de 0 a 25 se ejecutará
        noTone(11);}                                         //apagará el buzzer, se hace esto otra vez ya que mientras se ejecutan estas funciones no podrá apagarlo desde el otro if que lo apaga
    lcd_porcentaje();                                        //llama la funcion
    delay(100);}}                                            //esperar 100ms
