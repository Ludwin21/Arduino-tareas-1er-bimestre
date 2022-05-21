void lcd_porcentaje(){                       //función void llamada
  porcentaje_calculado=calcular_porcentaje();//llamar a la funcion que calcula el porcentaje
  lcd.clear();                               //limpiar la pantalla
  lcd.setCursor(2,0);                        //fijar el cursor
  lcd.print("NIVEL DE AGUA");                //imprimir
  lcd.setCursor(5,1);                        //fijar el cursor
  lcd.print(porcentaje_calculado);           //imprimir el porcentaje calculado
  lcd.setCursor(10,1);                       //fijar el curso
  lcd.print("%");}                           //imprimir
