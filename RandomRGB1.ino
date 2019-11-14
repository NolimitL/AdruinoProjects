#define G_Pin 11
#define R_Pin 12
#define B_Pin 13
int randNumber;
#define But_Pin 10
boolean St_Button = false;

void setup() 
{
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(10, INPUT);
}
void loop() 
{
 digitalRead(St_Button);
 do{
 randNumber = random(1, 4);
 if (randNumber == 1) {
  digitalWrite(11, HIGH);
 }delay(200);
 if (randNumber == 2) {
  digitalWrite(12, HIGH);
 }delay(200);
 if (randNumber == 3) {
  digitalWrite(13, HIGH);
 }delay(200);
 }while(St_Button == true);
}
