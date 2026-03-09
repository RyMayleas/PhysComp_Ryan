const int potPin = 4;
const int ledPin1 = 1;
const int ledPin2 = 2;
const int ledPin3 = 42;
const int ledPin4 = 41;
const int ledPin5 = 40;
const int buttonPin = 6;
bool buttonState = 0; // current button state
bool lastButtonState = 0; // previous button state
bool toggle = 0; // toggle bool for rising edge
bool fallToggle = 0; // toggle bool for falling edge
const int numReads = 16;  // number of reading in rolling average
int reading[numReads];
int count = 0;
int loopCount = 0;
unsigned long previousMillis = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
int ledState = LOW;
int phase;
int phase2;
bool isHeld = 0;
float blinkSpeed = 1.0;
int mapVal = 255;
int mapVal2 = 3;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(115200);
  analogReadResolution(11); // reduce ADC bit depth to 11-bits
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = !digitalRead(buttonPin);

  // Rising edge detection
  if (buttonState && !lastButtonState) // if button went from LOW to HIGH...
  {
    toggle = !toggle;
    previousMillis3 = millis();
  }
  // Falling edge detection
  if (!buttonState && lastButtonState)
  {
    if (isHeld == 0){
    fallToggle = !fallToggle;
    loopCount++;
    previousMillis = 0;
    previousMillis2 = 0;
    phase = 1;
    phase2 = 1;
    }
    else
    isHeld = 0;
  }

  lastButtonState = buttonState;
  reading[count] = analogRead(potPin);
  count++;
  if (count >= numReads) {
    count = 0;
  }

  int sum = 0;

  for (int i = 0; i < numReads; i++){
    sum += reading[i];
  }
  
  int analogValue = sum / numReads;
  if (isHeld == 0)
  mapVal = map(analogValue, 0, 2047, 0, 255);
    if (buttonState && lastButtonState) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis3 >= 1000)
      isHeld = 1;
    if (isHeld == 1){
      mapVal2 = map(analogValue, 0, 2047, 0, 7);
    }
  }
  if (mapVal2 == 0)
  blinkSpeed = 0.25;
  if (mapVal2 == 1)
  blinkSpeed = 0.5;
  if (mapVal2 == 2)
  blinkSpeed = 0.75;
  if (mapVal2 == 3)
  blinkSpeed = 1.0;
  if (mapVal2 == 4)
  blinkSpeed = 1.25;
  if (mapVal2 == 5)
  blinkSpeed = 1.5;
  if (mapVal2 == 6)
  blinkSpeed = 1.75;
  if (mapVal2 == 7)
  blinkSpeed = 2;
  Serial.printf("mapVal2 = %i \n", mapVal2);
  if (loopCount == 0){
  analogWrite(ledPin1, 0);
  analogWrite(ledPin2, 0);
  analogWrite(ledPin3, 0);
  analogWrite(ledPin4, 0);
  }
  if (loopCount == 1){
  analogWrite(ledPin1, mapVal);
  analogWrite(ledPin2, mapVal);
  analogWrite(ledPin3, mapVal);
  analogWrite(ledPin4, mapVal);
  }
  if (loopCount == 2){
  unsigned long currentMillis = millis();
  //Serial.println(currentMillis - previousMillis);
  if (currentMillis - previousMillis >= 500 / blinkSpeed && phase == 1) {
    previousMillis = currentMillis;
    analogWrite(ledPin1, mapVal);
    analogWrite(ledPin2, mapVal);
    analogWrite(ledPin3, mapVal);
    analogWrite(ledPin4, mapVal);
    phase++;
    }
    else if (currentMillis - previousMillis >= 500 / blinkSpeed && phase == 2){
    previousMillis = currentMillis;
    analogWrite(ledPin1, 0);
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, 0);
    analogWrite(ledPin4, 0);
    phase = 1;
    }
  }
  if (loopCount == 3){
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= 500 / blinkSpeed && phase == 1) {
    previousMillis = currentMillis;
    analogWrite(ledPin1, mapVal);
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, 0);
    analogWrite(ledPin4, 0);
    phase++;
    }
    if (currentMillis - previousMillis >= 500 / blinkSpeed && phase == 2) {
    previousMillis = currentMillis;
    analogWrite(ledPin1, 0);
    analogWrite(ledPin2, mapVal);
    analogWrite(ledPin3, 0);
    analogWrite(ledPin4, 0);
    phase++;
    }
    if (currentMillis - previousMillis >= 500 / blinkSpeed && phase == 3) {
    previousMillis = currentMillis;
    analogWrite(ledPin1, 0);
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, mapVal);
    analogWrite(ledPin4, 0);
    phase++;
    }
    if (currentMillis - previousMillis >= 500 / blinkSpeed && phase == 4) {
    previousMillis = currentMillis;
    analogWrite(ledPin1, 0);
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, 0);
    analogWrite(ledPin4, mapVal);
    phase = 1;
    }
  }
  if (loopCount == 4){
    unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= 500 / blinkSpeed && phase == 1) {
    previousMillis = currentMillis;
    analogWrite(ledPin1, mapVal);
    analogWrite(ledPin2, mapVal);
    analogWrite(ledPin3, 0);
    analogWrite(ledPin4, 0);
    phase++;
    }
  if (currentMillis - previousMillis >= 500 / blinkSpeed && phase == 2) {
    previousMillis = currentMillis;
    analogWrite(ledPin1, 0);
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, mapVal);
    analogWrite(ledPin4, mapVal);
    phase = 1;
    }
  }
  if (loopCount == 5) {
  unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= 500 / blinkSpeed && phase == 1) {
    previousMillis = currentMillis;
    analogWrite(ledPin1, mapVal);
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, mapVal);
    analogWrite(ledPin4, 0);
    phase++;
    }
    if (currentMillis - previousMillis >= 500 / blinkSpeed && phase == 2) {
    previousMillis = currentMillis;
    analogWrite(ledPin1, 0);
    analogWrite(ledPin2, mapVal);
    analogWrite(ledPin3, 0);
    analogWrite(ledPin4, mapVal);
    phase = 1;
    }
  }
  if (loopCount == 6){
  unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= 100 / blinkSpeed && phase == 1){
    previousMillis = currentMillis;
    analogWrite(ledPin1, mapVal);
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, 0);
    analogWrite(ledPin4, 0);
    phase++;
    }
    if (currentMillis - previousMillis >= 250 / blinkSpeed && phase == 2){
    previousMillis = currentMillis;
    analogWrite(ledPin1, 0);
    phase++;
    }
    if (currentMillis - previousMillis >= 100 / blinkSpeed && phase == 3){
    previousMillis = currentMillis;
    analogWrite(ledPin1, mapVal);
    phase++;
    }
    if (currentMillis - previousMillis >= 250 / blinkSpeed && phase == 4){
    previousMillis = currentMillis;
    analogWrite(ledPin1, 0);
    phase++;
    }
    if (currentMillis - previousMillis >= 100 / blinkSpeed && phase == 5) {
    previousMillis = currentMillis;
    analogWrite(ledPin1, mapVal);
    analogWrite(ledPin2, mapVal);
    analogWrite(ledPin3, mapVal);
    analogWrite(ledPin4, mapVal);
    phase++;
    }
    if (currentMillis - previousMillis >= 500 / blinkSpeed && phase == 6){
    previousMillis = currentMillis;
    analogWrite(ledPin1, 0);
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, 0);
    analogWrite(ledPin4, 0);
    phase = 1;
    }
  }
  if (loopCount == 7){
  unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= 100 / blinkSpeed && phase == 1){
    previousMillis = currentMillis;
    analogWrite(ledPin1, mapVal);
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, 0);
    analogWrite(ledPin4, 0);
    phase++;
    }
    if (currentMillis - previousMillis >= 100 / blinkSpeed && phase == 2){
    previousMillis = currentMillis;
    analogWrite(ledPin1, 0);
    analogWrite(ledPin2, mapVal);
    phase++;
    }
    if (currentMillis - previousMillis >= 100 / blinkSpeed && phase == 3){
    previousMillis = currentMillis;
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, mapVal);
    phase++;
    }
    if (currentMillis - previousMillis >= 100 / blinkSpeed && phase == 4){
    previousMillis = currentMillis;
    analogWrite(ledPin3, 0);
    analogWrite(ledPin4, mapVal);
    phase++;
    }
    if (currentMillis - previousMillis >= 100 / blinkSpeed && phase == 5){
    previousMillis = currentMillis;
    analogWrite(ledPin4, 0);
    analogWrite(ledPin3, mapVal);
    phase++;
    }
    if (currentMillis - previousMillis >= 100 / blinkSpeed && phase == 6){
    previousMillis = currentMillis;
    analogWrite(ledPin3, 0);
    analogWrite(ledPin2, mapVal);
    phase = 1;
    }
  }
    if(loopCount == 8)
    loopCount = 0;
    if(loopCount != 0){
      unsigned long currentMillis = millis();
      if (currentMillis - previousMillis2 >= (loopCount * 100) && phase2 == 1){
      previousMillis2 = currentMillis;
      digitalWrite(ledPin5, 1);
      phase2++;
      }
      if (currentMillis - previousMillis2 >= (loopCount * 100) && phase2 == 2){
      previousMillis2 = currentMillis;
      digitalWrite(ledPin5, 0);
      phase2 = 1;
      }
    }
    else{
      digitalWrite(ledPin5, 0);
    }
  //Serial.printf("Button = %i _ Toggle = %i _ Falling = %i \n", buttonState, toggle, fallToggle);
  //Serial.printf("ADC raw = %i \ t ADC averaged = %i \t ADC mapped = %i \n", analogRead(potPin), analogValue, mapVal);
}