

// #include <Adafruit_MotorShield.h>
// #include <AFMotor.h>
#include <Servo.h>
#include <Arduino.h>

Servo myServo;
// Adafruit_MotorShield AFMS = Adafruit_MotorShield();

int servoPosition = 0;
int inputPosition = 0;
String inString = "";
int startPosition = 0;

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
        if(digitalRead(A0)){
          startPosition = calibrate;
          Serial.println(startPosition);
          break;
        }      
    }
}


int input(){  
    int input = 0; 
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
          // clear the string for new input:
          inString = "";
        }  
   }
   return input; 
}

void loop() {
  if(Serial.available() > 0){
    inputPosition = input(); 
    if(inputPosition <= startPosition){  
       myServo.write(inputPosition);
    }
    else
      Serial.println("No");
  }

//  Serial.println(digitalRead(A0));
 // delay(100);

}
