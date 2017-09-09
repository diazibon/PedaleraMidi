#include <SoftwareSerial.h>

SoftwareSerial portOne(8, 9);

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
                        
  Serial.begin(9600);
  portOne.begin(31250);
}

void loop() {
  // put your main code here, to run repeatedly:
  //read the pushbutton value into a variable
  int Octava=2;
  
  int Tecla[12];
  for (int x=0;x=11;x++){
    Tecla[x]=digitalRead(x+2);
  }

  bool TeclaOn[] = {0,0,0,0,0,0,0,0,0,0,0,0};


  for (int x=0;x=11;x++){
    if (Tecla[x] == LOW) {
      if (TeclaOn[x]==false){  
        Serial.write(144);//send note on or note off command 
        Serial.write((Octava*12)+x+10);//send pitch data
        Serial.write(100);//send velocity data
        TeclaOn[x]=true;
        //Serial.println("144,46,100");
      }
  } else {
        Serial.write(144);//send note on or note off command 
        Serial.write((Octava*12)+x+10);//send pitch data
        Serial.write(byte(0));//send velocity data    
        if (TeclaOn[x]==true){
          TeclaOn[x]=false;
          //Serial.println("128,46,0");
        }
      }
  } 
}
