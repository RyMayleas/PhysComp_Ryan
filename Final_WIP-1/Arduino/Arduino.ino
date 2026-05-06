/*"Clean Up", a game created by Ryan Mayleas with Unity and Arduino. Contains Unity code modified from https://youtu.be/RYG8UExRkhA?si=XyW9FHpeyfaqTv6T.
Use the potentiometer to move the paddle on the screen. Press the button to have the ball served if it's not on screen yet.
If the game is over, press the button to start a new game.*/


#include <MapFloat.h>;
const int potPin = 5;
const int buttonPin = 1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(potPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
    float readPotValue = mapFloat(analogRead(potPin), 0, 4095, -3.25, 3.25);
  int readButtonValue = !digitalRead(buttonPin);
  Serial.print(readPotValue);
  Serial.print(",");
  Serial.println(readButtonValue);
  if (Serial.available()) {

  }
  delay(25);
}
