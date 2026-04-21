let serial; // variable for instance of the serialport library
let portName = 'COM7'; // fill in your serial port name
let options = { baudRate: 9600}; // change the baud rate to match your Arduino code

let rxFlag = false; // flag to indicate when new data has been received
let firstContact = false; // flag to indicate when the first contact has been made with the serial port
let sensors = [0, 0]; // declare array to hold incoming sensor data, and initialize with zeros
let pot = 0; // variable to hold potentiometer value
let button = 0; // variable to hold button value
let pattern = [1, 1, 1, 1, 1, 1, 1, 1];
let patternInUse = [1, 1, 1, 1, 1, 1, 1, 1];
let currentPoint = 0;
let previousMillis = 0;
let sensorReady = true;
let blinkSpeed = 1.0;
let pause = 0;

function setup() 
{
  createCanvas(600, 400);
  serial = new p5.SerialPort();             // make a new instance of the serialport library
  serial.on('list', printList);             // set a callback function for the serialport list event
  serial.on('connected', serverConnected);  // set callback for connecting to the server
  serial.on('open', portOpen);              // set callback for the port opening
  serial.on('data', serialEvent);           // set callback for when new data received
  serial.on('error', serialError);          // set callback for errors
  serial.on('close', portClose);            // set callback for closing the port
  serial.list();                            // list the serial ports
  serial.open(portName, options); 
  frameRate(60);
}

function draw() 
{
  background(220);
  fill(pattern[0] * 255);
  square(50, 200, 50);
  fill(pattern[1] * 255);
  square(110, 200, 50);
  fill(pattern[2] * 255);
  square(170, 200, 50);
  fill(pattern[3] * 255);
  square(230, 200, 50);
  fill(pattern[4] * 255);
  square(290, 200, 50);
  fill(pattern[5] * 255);
  square(350, 200, 50);
  fill(pattern[6] * 255);
  square(410, 200, 50);
  fill(pattern[7] * 255);
  square(470, 200, 50);

  if (pot == 0)
    blinkSpeed = 0.25;
  if (pot == 1)
    blinkSpeed = 0.5;
  if (pot == 2)
    blinkSpeed = 0.75;
  if (pot == 3)
    blinkSpeed = 1.0;
  if (pot == 4)
    blinkSpeed = 1.25;
  if (pot == 5)
    blinkSpeed = 1.5;
  if (pot == 6)
    blinkSpeed = 1.75;
  if (pot == 7)
    blinkSpeed = 2.0;
  fill(0);
  textSize(30)
  text("Blinking Speed = " + blinkSpeed, width/4, height/4);
  fill(255*!pause);
  square(455, 50, 100);
  fill(255*pause);
  text("Pause", 460, 115);
  let currentMillis = millis();
  if (currentMillis - previousMillis >= 500 / blinkSpeed)
  {
    previousMillis = currentMillis;
    print(patternInUse[currentPoint]);
    serial.write(patternInUse[currentPoint]);
    serial.write('\n');
    if (!pause)
      currentPoint++;
    if(currentPoint >= 8)
    {
      currentPoint = 0;
    }
  }
  if (button)
  {
    for (let i = 0; i < 8; i++)
    {
      patternInUse[i] = pattern[i];
    }
    currentPoint = 0;
  }
  if (sensorReady == true)
    serial.write('A');
}

function mouseReleased()
{
  if (mouseX > 50 && mouseX < 100 && mouseY > 200 && mouseY < 250) {
    if(pattern[0] == 1)
      pattern[0] = 0;
    else if(pattern[0] == 0)
      pattern[0] = 1;
  }
  if (mouseX > 110 && mouseX < 160 && mouseY > 200 && mouseY < 250) {
    if(pattern[1] == 1)
      pattern[1] = 0;
    else if(pattern[1] == 0)
      pattern[1] = 1;
  }
  if (mouseX > 170 && mouseX < 220 && mouseY > 200 && mouseY < 250) {
    if(pattern[2] == 1)
      pattern[2] = 0;
    else if(pattern[2] == 0)
      pattern[2] = 1;
  }
  if (mouseX > 230 && mouseX < 280 && mouseY > 200 && mouseY < 250) {
    if(pattern[3] == 1)
      pattern[3] = 0;
    else if(pattern[3] == 0)
      pattern[3] = 1;
  }
  if (mouseX > 290 && mouseX < 340 && mouseY > 200 && mouseY < 250) {
    if(pattern[4] == 1)
      pattern[4] = 0;
    else if(pattern[4] == 0)
      pattern[4] = 1;
  }
  if (mouseX > 350 && mouseX < 400 && mouseY > 200 && mouseY < 250) {
    if(pattern[5] == 1)
      pattern[5] = 0;
    else if(pattern[5] == 0)
      pattern[5] = 1;
  }
  if (mouseX > 410 && mouseX < 460 && mouseY > 200 && mouseY < 250) {
    if(pattern[6] == 1)
      pattern[6] = 0;
    else if(pattern[6] == 0)
      pattern[6] = 1;
  }
  if (mouseX > 470 && mouseX < 520 && mouseY > 200 && mouseY < 250) {
    if(pattern[7] == 1)
      pattern[7] = 0;
    else if(pattern[7] == 0)
      pattern[7] = 1;
  }
  if (mouseX > 460 && mouseX < 555 && mouseY > 50 && mouseY < 150) {
    if(pause == 1)
      pause = 0;
    else if (pause == 0)
      pause = 1;
  }
  if (mouseX)
  print(pattern);
}

function portOpen() //gets called when the serial port opens
{
  print("SERIAL PORT OPEN");
}

function portClose() //gets called when the serial port closes
{
  print("SERIAL PORT CLOSED");
}

function printList(portList) // gets called when the serial.list() function is called
{
  print("List of Available Serial Ports: ");
  for (var i = 0; i < portList.length; i++) 
  {
    print(i + portList[i]); //print list of available serial ports to console
  }
}

function serialEvent() // gets called when new serial data arrives
{
  let inString = serial.readStringUntil('\n');
  if (inString.length > 0) {
    sensors = split(inString, ',');
    if(sensors.length >= 2) {
      print(sensors);
      button = Number(sensors[0]);
      pot = Number(sensors[1]);
      print("Button = " + button + " Pot = " + pot);
    }
  }
}

function serialError(err) //gets called when there's an error
{
  print('SERIAL ERROR: ' + err);
}

function serverConnected() //gets called when we connect to the serial server
{
  print("CONNECTED TO SERIAL SERVER");
}