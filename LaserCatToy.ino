#include <Servo.h>

static const int LaserPin = 4;
static const int XServoPin = 17; 
static const int YServoPin = 14; 

Servo servoX;
Servo servoY;

void setup() {
  Serial.begin(115200);
  pinMode(LaserPin, OUTPUT);
  servoX.attach(XServoPin);
  servoY.attach(YServoPin);  
}

void loop() {
  digitalWrite(LaserPin, HIGH);
  
  for(int posDegrees = 0; posDegrees <= 135; posDegrees++){
    servoX.write(posDegrees);
    Serial.println(posDegrees);
    delay(20);
  }
    
  delay(1500); 

   for(int posDegrees = 0; posDegrees <= 180; posDegrees++){
    servoY.write(posDegrees);
    Serial.println(posDegrees);
    delay(20); 
   }

   delay(1500);

// Reverse

   for(int posDegrees = 135; posDegrees >= 0; posDegrees--){
    servoX.write(posDegrees);
    Serial.println(posDegrees);
    delay(20);
  }
    
  delay(1500); 

   for(int posDegrees = 180; posDegrees >= 0; posDegrees--){
    servoY.write(posDegrees);
    Serial.println(posDegrees);
    delay(20); 
   }
   Serial.println("one full loop finished");
   delay(1500);
}
