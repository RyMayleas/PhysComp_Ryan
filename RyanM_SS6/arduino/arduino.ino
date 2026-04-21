const int adcPin = 4;
const int buttonPin = 1;
const int ledPin = 7;

bool buttonState = 0;

int adcRead = 0;
int inByte = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, 0);
  analogReadResolution(10);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) {
    inByte = Serial.read();
    if(inByte == 0 || inByte == 1)
    digitalWrite(ledPin, inByte);
    else if (inByte == 'A')
    {
    adcRead = analogRead(adcPin);
    adcRead = map(adcRead, 0, 1023, 0, 7);
    buttonState = !digitalRead(buttonPin);
    Serial.print(buttonState);
    Serial.print(',');
    Serial.print(adcRead);
    Serial.print('\n');
    }
  }
}
