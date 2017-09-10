#include <SoftwareSerial.h>

SoftwareSerial portOne(8, 9);

int tecla[12];
bool teclaOn[] = {0,0,0,0,0,0,0,0,0,0,0,0};
int teclaOnLength = 12;

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
  int octava=2;
  
  
  for (int x=0;x=teclaOnLength-1;x++){
    tecla[x]=digitalRead(x+2);
  }

  
  for (int x=0;x=teclaOnLength-1;x++){
    if (tecla[x] == LOW) {
      if (teclaOn[x]==false){  
        Serial.write(144);//send note on or note off command 
        Serial.write((octava*12)+x+10);//send pitch data
        Serial.write(100);//send velocity data
        teclaOn[x]=true;
        //Serial.println("144,46,100");
      }
  } else {  
        if (teclaOn[x]==true){
          Serial.write(144);//send note on or note off command 
          Serial.write((octava*12)+x+10);//send pitch data
          Serial.write(byte(0));//send velocity data
          teclaOn[x]=false;
          //Serial.println("128,46,0");
        }
      }
  } 
}
