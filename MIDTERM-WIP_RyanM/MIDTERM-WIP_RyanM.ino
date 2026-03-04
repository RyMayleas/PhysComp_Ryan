const int potPin = 4;
const int ledPin1 = 1;
const int ledPin2 = 2;
const int ledPin3 = 42;
const int ledPin4 = 41;
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
int ledState = LOW;
int phase;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
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
    loopCount++;
    previousMillis = 0;
    phase = 1;
  }

  // Falling edge detection
  if (!buttonState && lastButtonState)
  {
    fallToggle = !fallToggle;
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
  int mapVal = map(analogValue, 0, 2047, 0, 255);
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
  if (currentMillis - previousMillis >= 500 && phase == 1) {
    previousMillis = currentMillis;
    analogWrite(ledPin1, mapVal);
    analogWrite(ledPin2, mapVal);
    analogWrite(ledPin3, mapVal);
    analogWrite(ledPin4, mapVal);
    phase++;
    }
    else if (currentMillis - previousMillis >= 500 && phase == 2){
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
    if (currentMillis - previousMillis >= 500 && phase == 1) {
    previousMillis = currentMillis;
    analogWrite(ledPin1, mapVal);
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, 0);
    analogWrite(ledPin4, 0);
    phase++;
    }
    if (currentMillis - previousMillis >= 500 && phase == 2) {
    previousMillis = currentMillis;
    analogWrite(ledPin1, 0);
    analogWrite(ledPin2, mapVal);
    analogWrite(ledPin3, 0);
    analogWrite(ledPin4, 0);
    phase++;
    }
    if (currentMillis - previousMillis >= 500 && phase == 3) {
    previousMillis = currentMillis;
    analogWrite(ledPin1, 0);
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, mapVal);
    analogWrite(ledPin4, 0);
    phase++;
    }
    if (currentMillis - previousMillis >= 500 && phase == 4) {
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
  if (currentMillis - previousMillis >= 500 && phase == 1) {
    previousMillis = currentMillis;
    analogWrite(ledPin1, mapVal);
    analogWrite(ledPin2, mapVal);
    analogWrite(ledPin3, 0);
    analogWrite(ledPin4, 0);
    phase++;
    }
  if (currentMillis - previousMillis >= 500 && phase == 2) {
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
    if (currentMillis - previousMillis >= 500 && phase == 1) {
    previousMillis = currentMillis;
    analogWrite(ledPin1, mapVal);
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, mapVal);
    analogWrite(ledPin4, 0);
    phase++;
    }
    if (currentMillis - previousMillis >= 500 && phase == 2) {
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
    if (currentMillis - previousMillis >= 100 && phase == 1){
    previousMillis = currentMillis;
    analogWrite(ledPin1, mapVal);
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, 0);
    analogWrite(ledPin4, 0);
    phase++;
    }
    if (currentMillis - previousMillis >= 250 && phase == 2){
    previousMillis = currentMillis;
    analogWrite(ledPin1, 0);
    phase++;
    }
    if (currentMillis - previousMillis >= 100 && phase == 3){
    previousMillis = currentMillis;
    analogWrite(ledPin1, mapVal);
    phase++;
    }
    if (currentMillis - previousMillis >= 250 && phase == 4){
    previousMillis = currentMillis;
    analogWrite(ledPin1, 0);
    phase++;
    }
    if (currentMillis - previousMillis >= 100 && phase == 5) {
    previousMillis = currentMillis;
    analogWrite(ledPin1, mapVal);
    analogWrite(ledPin2, mapVal);
    analogWrite(ledPin3, mapVal);
    analogWrite(ledPin4, mapVal);
    phase++;
    }
    if (currentMillis - previousMillis >= 500 && phase == 6){
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
    if (currentMillis - previousMillis >= 100 && phase == 1){
    previousMillis = currentMillis;
    analogWrite(ledPin1, mapVal);
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, 0);
    analogWrite(ledPin4, 0);
    phase++;
    }
    if (currentMillis - previousMillis >= 100 && phase == 2){
    previousMillis = currentMillis;
    analogWrite(ledPin1, 0);
    analogWrite(ledPin2, mapVal);
    phase++;
    }
    if (currentMillis - previousMillis >= 100 && phase == 3){
    previousMillis = currentMillis;
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, mapVal);
    phase++;
    }
    if (currentMillis - previousMillis >= 100 && phase == 4){
    previousMillis = currentMillis;
    analogWrite(ledPin3, 0);
    analogWrite(ledPin4, mapVal);
    phase++;
    }
    if (currentMillis - previousMillis >= 100 && phase == 5){
    previousMillis = currentMillis;
    analogWrite(ledPin4, 0);
    analogWrite(ledPin3, mapVal);
    phase++;
    }
    if (currentMillis - previousMillis >= 100 && phase == 6){
    previousMillis = currentMillis;
    analogWrite(ledPin3, 0);
    analogWrite(ledPin2, mapVal);
    phase = 1;
    }
  }
    if(loopCount == 8)
    loopCount = 0;
  Serial.printf("Button = %i _ Toggle = %i _ Falling = %i \n", buttonState, toggle, fallToggle);
  //Serial.printf("ADC raw = %i \ t ADC averaged = %i \t ADC mapped = %i \n", analogRead(potPin), analogValue, mapVal);
}