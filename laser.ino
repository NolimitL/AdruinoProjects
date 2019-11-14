int Las_Pin = 13;  //обозначаем входной пин лазера
int But_Pin = 11;  //обозначаем входной пин кнопки
int State = 0;  //обозначаем переменную состояния кнопки

void setup()
{
  pinMode(Las_Pin, OUTPUT);
  pinMode(But_Pin, INPUT);  //обозначаем входы и выходы на пины
}
void loop() 
{
 //считываем значения кнопки
 State = digitalRead(But_Pin);
 //создаем условия
 if (State == HIGH) {
   digitalWrite(Las_Pin, LOW);
 }
 else
 {
   digitalWrite(Las_Pin, HIGH);
 }
}
