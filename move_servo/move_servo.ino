// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 3; 

int inPin = 2;         // the number of the input pin for the switch 
int outPin = 13;       // the number of the output pin

int state = HIGH;      // the current state of the output pin
int reading;           // the current reading from the input pin
int previous = LOW;    // the previous reading from the input pin

// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers

int servo_angle = 0;   // define the initial servo angle
int counter = 0;       // set the counter 
// Create a servo object 
Servo Servo1; 

void setup() { 

   //pinMode(inPin, INPUT);
   pinMode(outPin, OUTPUT);
   pinMode(inPin, INPUT_PULLUP);
   
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin); 
}
void loop(){ 

   reading = digitalRead(inPin); // read the input from the pin for switch

   // When reading is LOW means the key was pressed
   if (reading == LOW) {
      Servo1.write(servo_angle + counter); 
      delay(100); 
      counter = counter + 1;
   }
   else {
      Servo1.write(0);
   }

}
  
