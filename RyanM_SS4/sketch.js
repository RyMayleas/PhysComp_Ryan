let serial;
let portName = 'COM7';
let options = { baudRate: 9600};
let inData = 0;
let sensors = [0, 0, 0, 0];

let l = 0;
let w = 0;
let m = 0;


function setup() {
  serial = new p5.SerialPort();
  serial.on('list', printList);
  serial.on('connected', serverConnected);
  serial.on('data', serialEvent);
  serial.on('error', serialError);
  //serial.on('close', portClose);
  serial.list();
  serial.open(portName, options);
  createCanvas(720, 720);
  textSize(64);
  textAlign(CENTER, CENTER);
  strokeWeight(10);
  stroke(0);
  rectMode(CENTER);
  frameRate(60);
}

function draw() {
  background(200);
  l = map(sensors[2], 0, 1023, 0, 720);
  w = map(sensors[3], 0, 1023, 0, 720);
  rect(360, 360, l, w);
  if(sensors[0])
    m += 0.1;
  if(sensors[1])
    m -= 0.1;
  circle(360+l, (w*m)+360, 50);
  circle(360-l, 360-(w*m), 50);
  fill(77, 195, 255);
  text(sensors, 360, 100);
}

function printList(portList) {
  print("List of Available Serial Ports: ") 
  for (var i = 0; i < portList.length; i++) {
    print(i + portList[i]);
  }
}

function serverConnected(){
  print("CONNECTED TO SERVER");
}

function portOpen() {
  print("SERIAL PORT OPEN - HELLO!");
}
function serialError(err) {
  print('ERROR: ' + err);
}

function serialEvent() {
  let inString = serial.readStringUntil('\n');

  if (inString.length > 0)
  {
    sensors = split(inString, ',');

    for (let i = 0; i < sensors.length; i++) {
      sensors[i] = Number(sensors[i]);
    }
    print(sensors);
  }
}