

// #include <Adafruit_MotorShield.h>
// #include <AFMotor.h>
#include <Servo.h>
#include <Arduino.h>

Servo myServo;
// Adafruit_MotorShield AFMS = Adafruit_MotorShield();

int servoPosition = 0;
int inputPosition = 0;
String inString = "";

  // put your setup code here, to run once:

void setup() {
 //   AFMS.begin();
    myServo.attach(9);
    Serial.begin(9600);
    while (!Serial){}
    Serial.println("Ready");
}


int input(){    
    int input;
    while (Serial.available() > 0) {
        int inChar = Serial.read();
        if (isDigit(inChar)) {
          // convert the incoming byte to a char and add it to the string:
          inString += (char)inChar;
        }
        // if you get a newline, print the string, then the string's value:
        if (inChar == '\n') {
          Serial.print("Value:");
          input = inString.toInt();
          Serial.println(inString.toInt());
          Serial.print("String: ");
          Serial.println(inString);
          // clear the string for new input:
          inString = "";
        }  
   }
   return input; 
}

void loop() {
    inputPosition = input();     
    myServo.write(inputPosition);
    /*
      for (servoPosition = 0; servoPosition < 180; servoPosition += 1){
          myServo.write(servoPosition);
          delay(10);
      }
      for ( servoPosition = 180; servoPosition >= 0; servoPosition -=1){
        myServo.write(servoPosition);
        delay(10);
      }
      */

}
