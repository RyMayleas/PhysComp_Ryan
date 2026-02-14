const int led1 = 4;
const int led2 = 5;
const int led3 = 6;
const int led4 = 7;
int loopCount = 0;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(115200);
}

void loop()
{
  if (loopCount >= 0 && loopCount <= 3)
  {
    digitalWrite(led1, 1);
    digitalWrite(led2, 1);
    digitalWrite(led3, 1);
    digitalWrite(led4, 1);
    delay(500);
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
    delay(500);
  }
  if (loopCount >= 4 && loopCount <= 7)
  {
    digitalWrite(led1, 1);
    delay(500);
    digitalWrite(led1, 0);
    digitalWrite(led2, 1);
    delay(500);
    digitalWrite(led2, 0);
    digitalWrite(led3, 1);
    delay(500);
    digitalWrite(led3, 0);
    digitalWrite(led4, 1);
    delay(500);
    digitalWrite(led4, 0);
  }
  if (loopCount >= 8 && loopCount <= 11)
  {
    digitalWrite(led1, 1);
    digitalWrite(led4, 1);
    delay(500);
    digitalWrite(led1, 0);
    digitalWrite(led4, 0);
    digitalWrite(led2, 1);
    digitalWrite(led3, 1);
    delay(500);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
  }
  if (loopCount >= 12 && loopCount <= 15)
  {
    digitalWrite(led1, 1);
    digitalWrite(led3, 1);
    delay(500);
    digitalWrite(led1, 0);
    digitalWrite(led3, 0);
    digitalWrite(led2, 1);
    digitalWrite(led4, 1);
    delay(500);
    digitalWrite(led2, 0);
    digitalWrite(led4, 0);
  }
  if (loopCount >= 16 && loopCount <= 19)
  {
    digitalWrite(led1, 1);
    delay(250);
    digitalWrite(led1, 0);
    delay(100);
    digitalWrite(led1, 1);
    delay(250);
    digitalWrite(led1, 0);
    delay(100);
    digitalWrite(led1, 1);
    digitalWrite(led2, 1);
    digitalWrite(led3, 1);
    digitalWrite(led4, 1);
    delay(500);
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
    delay(100);
  }
  if (loopCount >= 20 && loopCount <= 23)
  {
    digitalWrite(led1, 1);
    delay(100);
    digitalWrite(led1, 0);
    digitalWrite(led2, 1);
    delay(100);
    digitalWrite(led2, 0);
    digitalWrite(led3, 1);
    delay(100);
    digitalWrite(led3, 0);
    digitalWrite(led4, 1);
    delay(100);
    digitalWrite(led4, 0);
    digitalWrite(led3, 1);
    delay(100);
    digitalWrite(led3, 0);
    digitalWrite(led2, 1);
    delay(100);
    digitalWrite(led2, 0);
    digitalWrite(led1, 1);
  }
  loopCount++;
  Serial.println("loopCount++");
  if(loopCount == 24)
  {
    Serial.println("loop reset");
    loopCount = 0;
  }
}