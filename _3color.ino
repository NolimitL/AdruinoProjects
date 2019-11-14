// обозначаем входные пины 
int Blue_Pin = 9;
int Red_Pin = 11;
int music = 5;
// обозначаем переменную отвечающую за состояние кнопки 

void setup() 
{  // обозначаем сигнал кнопки как вход
  pinMode(Blue_Pin, OUTPUT);  // обозначаем сигнал красного, зеленого и синего цвета как выход
  pinMode(music, OUTPUT);
  pinMode(Red_Pin, OUTPUT);
}

void loop() 
{ 
  tone(5, 400);
  digitalWrite(11, HIGH);
  delay(600);
  digitalWrite(11, LOW);
  tone(5, 100);
  digitalWrite(9, HIGH);
  delay(600);
  digitalWrite(9, LOW);
}
