int regim=1;
int flag=0;

void setup()   
{
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, INPUT);
}
void loop()
{
     if(digitalRead(10)==HIGH&&flag==0)//если кнопка нажата   
     // и перемення flag равна 0 , то ...
     {
       regim++;
       flag=1;
       
        //это нужно для того что бы с каждым нажатием кнопки
        //происходило только одно действие
        // плюс защита от "дребезга"  100 
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
       digitalWrite(13, HIGH);
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
