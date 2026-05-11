/*"Clean Up", a game created by Ryan Mayleas with Unity and Arduino. Contains Unity code modified from https://youtu.be/RYG8UExRkhA?si=XyW9FHpeyfaqTv6T.
Use the potentiometer to move the paddle on the screen. Press the button to have the ball served if it's not on screen yet.
If the game is over, press the button to start a new game.*/


#include <MapFloat.h>;
const int potPin = 5;
const int buttonPin = 1;
const int pot2Pin = 2;
const int buzzerPin = 4;
int inByte = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(potPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(pot2Pin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float readPotValue = mapFloat(analogRead(potPin), 0, 4095, -3.25, 3.25);
  int readButtonValue = !digitalRead(buttonPin);
  float readPot2Value = mapFloat(analogRead(pot2Pin), 0, 4095, -3.19, 0);
  Serial.print(readPotValue);
  Serial.print(",");
  Serial.print(readButtonValue);
  Serial.print(",");
  Serial.println(readPot2Value);
  if (Serial.available()) {
    inByte = Serial.read();
    if (inByte == 'P')
    tone(buzzerPin, 494, 100);
    if (inByte == 'R')
    tone(buzzerPin, 440, 100);
    if (inByte == 'O')
    tone(buzzerPin, 392, 100);
    if (inByte == 'Y')
    tone(buzzerPin, 349, 100);
    if (inByte == 'G')
    tone(buzzerPin, 330, 100);
    if (inByte == 'B')
    tone(buzzerPin, 294, 100);
    if (inByte == 'I')
    tone(buzzerPin, 440, 100);
    if (inByte == 'V' || inByte == 'W')
    tone(buzzerPin, 247, 100);
    if (inByte == 'F')
    tone(buzzerPin, 247, 500);
  }
  delay(25);
}
