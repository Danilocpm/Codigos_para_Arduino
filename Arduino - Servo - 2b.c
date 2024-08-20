#include<Servo.h>
Servo motor1;
int b1;
int b2;
int pos = 0;

void setup()
{
motor1.attach(6);
motor1.write(0);
pinMode(3,INPUT);
pinMode(4,INPUT);
}

void loop()
{
  b1 = digitalRead(3); 
  b2 = digitalRead(4); 
  
  if (b1 == 1) {
 
    pos += 1;
    if (pos > 180) { 
      pos = 180;
    }
    motor1.write(pos); 
    delay(10); 
  }
  
  if (b2 == 1) {
    
    pos -= 1;
    if (pos < 0) { 
      pos = 0;
    }
    motor1.write(pos); 
    delay(10); 
  }}

// https://www.tinkercad.com/things/1dVQV4JNyOM-arduino-servo-2b/editel?returnTo=%2Fthings%2F1dVQV4JNyOM-arduino-servo-2b&sharecode=K7SYPceGQ9vSfxQknRhdchg26X1aUS5f3T0aOlnpAXs