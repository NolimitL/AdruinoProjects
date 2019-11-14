
//
// работа с температурным датчиком LM335
//
//

int lm335=0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  double val = analogRead(lm335);
  Serial.print("Analog 0: ");
  Serial.print(int(val));
  double voltage = val*5.0/1024;
  Serial.print(" : ");
  Serial.print(voltage);
  double temp = voltage*100 - 273.15;
  Serial.print(" : ");
  Serial.println(temp);
  delay(100);
}
