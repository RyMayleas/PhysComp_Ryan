let serial;
let portName = 'COM7';
let options = { baudRate: 9600};
let outByte = 0;

function setup() {
  createCanvas(800, 400);

  serial = new p5.SerialPort();             // make a new instance of the serialport library
  serial.on('list', printList);             // set a callback function for the serialport list event
  serial.on('connected', serverConnected);  // set callback for connecting to the server
  serial.on('open', portOpen);              // set callback for the port opening
  serial.on('data', serialEvent);           // set callback for when new data received
  serial.on('error', serialError);          // set callback for errors
  serial.on('close', portClose);            // set callback for closing the port
  serial.list();                            // list the serial ports
  serial.open(portName, options);           // open a serial port
}

function draw() {
  background(220);
  fill(255);
  if ((mouseX > 0 && mouseX < 75) || (mouseX > 75 && mouseX < 100 && mouseY > 200))
    fill(220);
  rect(0, 0, 100, 400); // C
  fill(255);
  if ((mouseX > 135 && mouseX < 175) || (mouseX > 100 && mouseX < 135 && mouseY > 200) || (mouseX < 175 && mouseX > 200 && mouseY > 200))
    fill(220);
  rect(100, 0, 100, 400); // D
  fill(255);
  if ((mouseX > 235 && mouseX < 300) || (mouseX > 200 && mouseX < 235 && mouseY > 200))
    fill(220);
  rect(200, 0, 100, 400); // E
  fill(255);
  if ((mouseX > 300 && mouseX < 375) || (mouseX > 375 && mouseX < 400 && mouseY > 200))
    fill(220);
  rect(300, 0, 100, 400); // F
  fill(255);
  if ((mouseX > 435 && mouseX < 475) || (mouseX > 400 && mouseX < 435 && mouseY > 200) || (mouseX > 475 && mouseX < 500 && mouseY > 200))
    fill(220);
  rect(400, 0, 100, 400); // G
  fill(255);
  if ((mouseX > 535 && mouseX < 575) || (mouseX > 500 && mouseX < 535 && mouseY > 200) || (mouseX > 575 && mouseX < 600 && mouseY > 200))
    fill(220);
  rect(500, 0, 100, 400); // A
  fill(255);
  if ((mouseX > 635 && mouseX < 700) || (mouseX > 600 && mouseX < 635 && mouseY > 200))
    fill(220);
  rect(600, 0, 100, 400); // B
  fill(255);
  if (mouseX > 700 && mouseX < 800)
    fill(220);
  rect(700, 0, 100, 400); // C
  fill(0);
  if (mouseX > 75 && mouseX < 135 && mouseY < 200)
    fill(220);
  rect(75, 0, 60, 200); // C#
  fill(0);
  if (mouseX > 175 && mouseX < 235 && mouseY < 200)
    fill(220);
  rect(175, 0, 60, 200); // D#
  fill(0);
  if (mouseX > 375 && mouseX < 435 && mouseY < 200)
    fill(220);
  rect(375, 0, 60, 200); // F#
  fill(0);
  if (mouseX > 475 && mouseX < 535 && mouseY < 200)
    fill(220);
  rect(475, 0, 60, 200); // G#
  fill(0);
  if (mouseX > 575 && mouseX < 635 && mouseY < 200)
    fill(220);
  rect(575, 0, 60, 200); // A#
}

function mousePressed()
{
  if (mouseX > 0 && mouseX < 100)
  {
    outByte = 65;
  }
  if (mouseX > 100 && mouseX < 200)
  {
    outByte = 73;
  }
  if (mouseX > 200 && mouseX < 300)
  {
    outByte = 82;
  }
  if (mouseX > 300 && mouseX < 400)
  {
    outByte = 87;
  }
  if (mouseX > 400 && mouseX < 500)
  {
    outByte = 98;
  }
  if (mouseX > 500 && mouseX < 600)
  {
    outByte = 110;
  }
  if (mouseX > 600 && mouseX < 700)
  {
    outByte = 123;
  }
  if (mouseX > 700 && mouseX < 800)
  {
    outByte = 131;
  }
  if (mouseX > 75 && mouseX < 135 && mouseY < 200)
  {
    outByte = 69;
  }
  if (mouseX > 175 && mouseX < 235 && mouseY < 200)
  {
    outByte = 78;
  }
  if (mouseX > 375 && mouseX < 435 && mouseY < 200)
  {
    outByte = 93;
  }
  if (mouseX > 475 && mouseX < 535 && mouseY < 200)
  {
    outByte = 104;
  }
  if (mouseX > 575 && mouseX < 635 && mouseY < 200)
  {
    outByte = 117;
  }
  print(outByte);
  serial.write(outByte);
}

function mouseReleased()
{
  outByte = 0;
  serial.write(outByte);
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
  //only sending data to microcontroller in this sketch, so not being used
}

function serialError(err) //gets called when there's an error
{
  print('ERROR: ' + err);
}

function serverConnected() //gets called when we connect to the serial server
{
  print("CONNECTED TO SERVER");
}