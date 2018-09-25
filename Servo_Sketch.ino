

// #include <Adafruit_MotorShield.h>
// #include <AFMotor.h>
#include <Servo.h>
#include <Arduino.h>

Servo myServo;
// Adafruit_MotorShield AFMS = Adafruit_MotorShield();

int servoPosition = 0;
int inputPosition = 0;
String inString = "";
int startPosition = 180;

  // put your setup code here, to run once:

void setup() {
 //   AFMS.begin();
    myServo.attach(9);
    Serial.begin(9600);
    while (!Serial){}
    Serial.println("Ready");
    for(int calibrate = 0; calibrate <= 180; calibrate++){
        myServo.write(calibrate);
        Serial.println(calibrate);
        delay(200);
        if(analogRead(A0) > 1000){
          startPosition = calibrate;
          Serial.println(startPosition);
          break;
        }      
    }
}


int input(){  
    int inputNum = 0; 
    while (Serial.available() > 0) {
        int inChar = Serial.read();
        if (isDigit(inChar)) {
          // convert the incoming byte to a char and add it to the string:
          inString += (char)inChar;
        }
        // if you get a newline, print the string, then the string's value:
        if (inChar == '\n') {
          Serial.print("Value:");
          inputNum = inString.toInt();
          Serial.println(inString.toInt());
          // clear the string for new input:
          inString = "";
        }  
   }
   return inputNum; 
}

void loop() {
  if(Serial.available() > 0){
    inputPosition = input(); 
    if(inputPosition <= startPosition && inputPosition != 0){  
       myServo.write(inputPosition);
    }
    else{
      Serial.println("No");
    }
  }

//  Serial.println(digitalRead(A0));
 // delay(100);

}
