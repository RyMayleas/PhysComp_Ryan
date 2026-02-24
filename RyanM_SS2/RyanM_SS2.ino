const int buttonPin = 9;
const int led1 = 1;
const int led2 = 2;
const int led3 = 42;
const int led4 = 0;
bool buttonState = 0; // current button state
bool lastButtonState = 0; // previous button state
bool toggle = 0; // toggle bool for rising edge
bool fallToggle = 0; // toggle bool for falling edge
int loopCount = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = !digitalRead(buttonPin);

  // Rising edge detection
  if (buttonState && !lastButtonState) // if button went from LOW to HIGH...
  {
    toggle = !toggle;
    loopCount++;
  }

  // Falling edge detection
  if (!buttonState && lastButtonState)
  {
    fallToggle = !fallToggle;
  }

  lastButtonState = buttonState;

  Serial.printf("Button = %i _ Toggle = %i _ Falling = %i \n", buttonState, toggle, fallToggle);

 if (loopCount == 0)
  {
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
  }

 if (loopCount == 1)
  {
    digitalWrite(led1, 1);
    digitalWrite(led2, 1);
    digitalWrite(led3, 1);
    digitalWrite(led4, 1);
  }

if (loopCount == 2)
  {
    digitalWrite(led1, 1);
    digitalWrite(led2, 0);
    digitalWrite(led3, 1);
    digitalWrite(led4, 0);
  }

  if (loopCount == 3)
  {
    digitalWrite(led1, 0);
    digitalWrite(led2, 1);
    digitalWrite(led3, 0);
    digitalWrite(led4, 1);
  }

  if (loopCount == 4)
  {
    digitalWrite(led1, 1);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 1);
  }

  if (loopCount == 5)
  {
    digitalWrite(led1, 0);
    digitalWrite(led2, 1);
    digitalWrite(led3, 1);
    digitalWrite(led4, 0);
  }
  
  if (loopCount == 6)
  {
    digitalWrite(led1, 1);
    digitalWrite(led2, 1);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
  }

  if (loopCount == 7)
  {
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 1);
    digitalWrite(led4, 1);
  }

  if (loopCount == 8)
  loopCount = 0;
}
