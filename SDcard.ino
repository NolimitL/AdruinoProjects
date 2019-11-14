#include <LiquidCrystal.h>
#include <SPI.h>
#include <SD.h>

File myfile;
LiquidCrystal lcd(13, 12, 11, 7, 9, 8);
int regim=1;
int flag=0;

void setup()
{
  Serial.begin(9600);
  Serial.print("Initializing card...");
  // объявить стандартный CS вывод как выход
   pinMode(10, OUTPUT);
   pinMode(4, INPUT);
   lcd.begin(16, 2);
  if (!SD.begin(1)) {
    Serial.println("initialization of the SD card failed!");
    return;
  }
  Serial.println("initialization of the SDcard is done.");
  SD.remove("textFile.txt");
  SD.remove("text2.txt");
  myfile = SD.open("textFile.txt", FILE_WRITE);
  if (myfile)
  {
    Serial.print("Writing to the text file...");
    myfile.println("I can do this!");
    myfile.close(); // закрыть файл
    Serial.println("done closing.");
  } 
  else // если файл не может быть открыт, то выдать сообщение об ошибке
  {    
    Serial.println("error opening the text file!");
  }
  // снова открыть текстовый файл для чтения
  myfile = SD.open("textFile.txt");
  if (myfile)
  {
    Serial.println("textFile.txt:");
    // прочитать весь текст, записанный в файле
    while (myfile.available()) 
    {
    	Serial.write(myfile.read());
    }
    // закрыть файл
    myfile.close();
  } 
  else // если файл не может быть открыт, то выдать сообщение об ошибке
  {
    Serial.println("error opening the text file!");
  }
}

void loop()
{
  if (digitalRead(4)==HIGH && flag == 0){
    regim++;
    flag=1;
    if (regim>2){
      regim = 1;
    }
  }
  if (digitalRead(4)==LOW && flag == 1){
    flag = 0;
  }
  if (regim==1){
    while(myfile.available()){
      SD.remove("textFile.txt");
    }
    tone(5, 800);
    delay(100);
    tone(5, 300);
  }
  if (regim==2){
    if(!SD.exists("text2.txt")){
      myfile = SD.open("text2.txt", FILE_WRITE);
      myfile.print("Second file");
    }else{
      Serial.write("File wurde schon geschafft");
    }
  }myfile.close();
}
