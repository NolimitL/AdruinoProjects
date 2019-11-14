// обозначаем входные пины 
int Button_Pin = 13;
int Blue_Pin = 11;
int Green_Pin = 10;
int Red_Pin = 9;
// обозначаем переменную отвечающую за состояние кнопки 
boolean State_But = true;

void setup() 
{
  pinMode(Button_Pin, INPUT);  // обозначаем сигнал кнопки как вход
  pinMode(Blue_Pin, OUTPUT);  // обозначаем сигнал красного, зеленого и синего цвета как выход
  pinMode(Green_Pin, OUTPUT);
  pinMode(Red_Pin, OUTPUT);
}

void loop() 
{ 
 // определяем состояние кнопки - считываем значение
 State_But = digitalRead(Button_Pin);
 // сознаем условия
 if (State_But == LOW)
 {
   digitalWrite(Red_Pin, HIGH);
 }
 State_But = digitalRead(Button_Pin);
 if (State_But == LOW)
 {
   digitalWrite(Green_Pin, HIGH);
 }
}
