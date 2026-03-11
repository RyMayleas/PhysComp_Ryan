let serial; // variable for an instance of serialport library
let portName = 'COM7';
let options = { baudRate: 9600};
let inData; // variable for storing incoming serial data

function setup() {
  // P5 SerialPort Setup
  serial = new p5.SerialPort();
  serial.on('list', printList);
  serial.on('connected', serverConnected);
  serial.on('open', portOpen);
  serial.on('error', serialError);
  serial.on('close', portClose);
  serial.list();
  serial.open(portName, options);

  // Typical p5.js setup
  createCanvas(800, 800);
  textSize(72);
  textAlign(CENTER, CENTER);
}

function draw() {
  serialEvent();
  background(200, 255, 255);
  fill(inData);
  let diameter = map(inData, 0, 255, 10, width - 10);
  circle(width/2, height/2, diameter);
  fill(0);
  text(inData, width/2, height - height/8);
}

function printList(portList){
  print("List of Available Serial Ports: ");
  for (let i = 0; i <portList.length; i++) {
    print(i + portList[i]);
  }
}

function serverConnected(){
  print("CONNECTED TO SERVER");
}

function portOpen(){
  print("SERIAL PORT OPEN");
}

function serialEvent() {
  inData = Number(serial.read());
  print(inData);
}

function serialError(err) {
  print('ERROR: ' + err);
}

function portClose(){
  print("*____SERIAL PORT CLOSED");
}