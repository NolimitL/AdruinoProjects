#define MOTOR_PIN 9
#define FIRST_BUTTON_PIN 5
#define BUTTON_COUNT 3
#define SPEED_STEP (255 / (BUTTON_COUNT - 1))
void setup() 
{
  pinMode(MOTOR_PIN, OUTPUT);
  for (int i = 0; i < BUTTON_COUNT; ++i)
  pinMode(i + FIRST_BUTTON_PIN, INPUT_PULLUP);
}

void loop() 
{
 for (int i = 0; i < BUTTON_COUNT; ++i) {
   if (digitalRead(i + FIRST_BUTTON_PIN))
   continue;
   int speed = i * SPEED_STEP;
   analogWrite(MOTOR_PIN, speed);
 }
}
