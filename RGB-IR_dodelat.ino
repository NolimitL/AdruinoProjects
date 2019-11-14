#include <IRremote.h>
IRsend::Irsend(11); // Пин ИК-передатчика
decode_results results;
int regim=1; // Переменная режима кнопки
int flag=0; 

void setup()   
{
  Serial.begin(9600); // Ставим скорость СОМ порта
  irsend.enableIROut(); // Включаем передачу
    pinMode(11, OUTPUT); // Это ИК-светодиод передатчик 
    pinMode(10, INPUT); // Пин кнопки
}
void loop()
{
     if(digitalRead(10)==HIGH&&flag==0) // если кнопка нажата   
     // и перемення flag равна 0 , то ...
     {
       regim++;
       flag=1;
        //это нужно для того что бы с каждым нажатием кнопки
        //происходило только одно действие
        // плюс защита от "дребезга"  100% 
       if(regim>5)
       {
        regim = 1;
       } 
     }
      if(digitalRead(10)==LOW&&flag==1)//если кнопка НЕ нажата
     //и переменная flag равна - 1 ,то ...
     {     
        flag=0;//обнуляем переменную flag
     }
     
     if (regim==1)
     {
       irsend.sendNEC(result=1, 11);
     }
     if (regim==2)
     {
       digitalWrite(12, HIGH);
       digitalWrite(13, LOW);
     }
     if (regim==3)
     {
       digitalWrite(11, HIGH);
       digitalWrite(12, LOW);
     }
     if (regim==4)
     {
       digitalWrite(11, LOW);
     }
}
