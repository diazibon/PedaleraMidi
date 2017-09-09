#include <SoftwareSerial.h>

SoftwareSerial portOne(8, 9);

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
  portOne.begin(31250);
}

void loop() {
  // put your main code here, to run repeatedly:
  //read the pushbutton value into a variable
  int TeclaBb = digitalRead(2);

  if (TeclaBb == LOW) {
    portOne.write(144);//send note on or note off command 
    portOne.write(46);//send pitch data
    portOne.write(100);//send velocity data
    Serial.println("144,46,100");
  } else {
    portOne.write(144);//send note on or note off command 
    portOne.write(46);//send pitch data
    portOne.write(byte(0));//send velocity data
    Serial.println("128,46,0");
  }
}
