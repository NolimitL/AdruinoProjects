#include <IRremote.h>
IRrecv irrecv(13); // Указываем пин, к которому подключен приемник
decode_results results;
int R_Pin(9);
int G_Pin(10);
int B_Pin(11);
boolean State_Color = true;
 
void setup()
{
  pinMode(B_Pin, OUTPUT);  // обозначаем сигнал красного, зеленого и синего цвета как выход
  pinMode(G_Pin, OUTPUT);
  pinMode(R_Pin, OUTPUT);
  Serial.begin(9600); // Выставляем скорость COM порта
  irrecv.enableIRIn(); // Запускаем прием
}
 
void loop() 
{
  if (irrecv.decode(&results)) // Если данные пришли 
  {
    digitalRead(State_Color);
    if (State_Color == HIGH){
      digitalWrite(G_Pin, HIGH);
      irrecv.resume(); // Принимаем следующую команду
    }else{
      delay(100);
      digitalWrite(G_Pin, LOW);
    }
  }
}
