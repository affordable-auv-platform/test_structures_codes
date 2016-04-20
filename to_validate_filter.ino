#include <Servo.h> ;
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
int flag = 1;
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
 
void loop() 
{ 
  if(flag){
    myservo.write(45);              // tell servo to go to position in variable 'pos' 
    delay(5000);
    myservo.write(42);              // tell servo to go to position in variable 'pos' 
    delay(1000);
    flag =0;
  }
  
  for(pos = 42; pos < 121; pos += 1)  // 19,139
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(8);                       // waits 15ms for the servo to reach the position 
  } 
  delay(2500);
  for(pos = 121; pos>=42; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(8);                       // waits 15ms for the servo to reach the position 
  } 
  delay(2500);
}
