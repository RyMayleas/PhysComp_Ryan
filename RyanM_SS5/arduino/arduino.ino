const int piezoPin = 1;
byte val;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    val = Serial.read();
  }
  if (val != 0)
  tone(piezoPin, val, 120);
  noTone(piezoPin);
}
