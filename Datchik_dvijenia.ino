/*
 * PIR Sensor[PIN GND]  -> Arduino Nano[PIN GND]
 * PIR Sensor[PIN 5V]   -> Arduino Nano[PIN 5V]
 * PIR Sensor[PIN OUT]  -> Arduino Nano[PIN A0]
 * Relay Module[PIN IN] -> Arduino Nano[PIN 3]
 */
//relout - пин модуля реле
const int relout = 3;
//trigger - флаг срабатывания датчика движения
boolean trigger = false;
 
void setup() 
{
  /*Стандартная процедура инициализации порта на который подключен модуль реле.
  ВАЖНО!!! - чтобы модуль реле оставался в первоначально выключенном состоянии,нужно записать в порт входа/выхода значение HIGH, это позволит избежать ложных "перещелкиваний", 
и сохранит состояние реле таким, каким оно было до включения всей схемы в работу*/
  pinMode(relout, OUTPUT);
  digitalWrite(relout, HIGH);
  //задержка в минуту для инициализации датчика
  delay(30000);
  Serial.begin(9600);
}
 
void loop() {
  int y = analogRead(A0);
  Serial.println(y);
  delay(50);
  //Считать значение с аналогового порта А0
  //Если значение выше 500
  if(analogRead(A0) > 500)
  {
    //Установить флаг срабатывания датчика движения
    if(!trigger)
    {
      trigger = true;
    }
  }
  else 
  {
    //Снять флаг срабатывания датчика движения
    trigger = false;
    //Выключить реле
    digitalWrite(relout, HIGH);
  }
 
  //Пока флаг срабатывания датчика движения установлен
  while(trigger)
  {
    //Включить реле
    digitalWrite(relout, LOW);
    if(analogRead(A0) > 500)
    {
      //Установить флаг срабатывания датчика движения
      if(!trigger)
      {
        trigger = true;
      }
    }
    else 
    {
      //Снять флаг срабатывания датчика движения
      trigger = false;
      //Выключить реле
      digitalWrite(relout, HIGH);
    }
  }
}
