// This code is based on a program called "Sweep"
// by BARRAGAN <http://barraganstudio.com> 
// (which is an example placed in the public domain found under the example menu of the Arduino IDE)
// and we also utilize the Servo.h Library

//Creative commons license for my modifications
//
//I created additional functions created for handling continuous-rotation-servos as motors
//Forward, Backward, RotateLeft, RotateRight, Stop, and attachServo
//by gskielian  < http://www.kielian.net > 

double ForwardSpeed = 30.0;
double RotateSpeed = 30.0;
double BackwardSpeed = 30.0;

#include <Servo.h> 
 
Servo LeftWheel;  // create servo object to control a servo 
Servo RightWheel;  // create servo object to control a servo 

// Note: a maximum of eight servo objects can be created 

int LWPin = 10; //set the pin number for your left servo-motors (just change the number if not pin 9)
int RWPin = 11; //right-wheel control pin



void setup() 
{ 
  LeftWheel.attach( LWPin );  //  Connects LeftWheel to the pin LWPin
  RightWheel.attach( RWPin );  // Connects another wheel to be controlled by the pin RWPin
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  Serial.begin(9600);
  
} 
 
 
void loop() 
{ 
  Serial.println(digitalRead(4));
  delay(1);
   if(digitalRead(4) == HIGH)
   {
   Forward(1);
   }
   else if(digitalRead(5) == HIGH)
   {
   Backward(1);
   }
   else if(digitalRead(6) == HIGH)
  {
   RotateLeft(0.5);
   }
   else if(digitalRead(7) == HIGH)
   {
   RotateRight(0.5);
   }
   else
   {
    Stop(0.001); 
   }

} 









void Forward(double seconds)
{
    double speed = ForwardSpeed;
    attachServos(); //in case we disconnected them
     
     //The CRS thinks it is always at 90 degrees
     //if you tell it to go to 180 degrees it will go really fast clock-wise
     //0 degrees really quickly counterclockwise
     // 95 really slowly clockwise
    speed = (speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    LeftWheel.write( (int) -speed);             
    RightWheel.write((int) speed); // Right wheel is backwards
  // casting   
   delay((int) (seconds*1000)); 
}



void Backward ( double seconds)
{
    attachServos(); //in case we disconnected them
    
    double speed = BackwardSpeed; 
    speed = (speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    LeftWheel.write((int) speed);             
    RightWheel.write((int) -speed); // Right wheel is backwards
    delay((int) (seconds*1000));
}



void RotateLeft (double seconds)
{
    double speed = RotateSpeed;
    attachServos(); //in case we disconnected them
     
    speed = (speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    LeftWheel.write((int) speed);             
    RightWheel.write((int) speed); // Right wheel is backwards 
    delay((int) (seconds*1000));
}

void RotateRight (double seconds)
{
    double speed = RotateSpeed;
    attachServos(); //in case we disconnected them
     
    speed =  (speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    LeftWheel.write((int) -speed);             
    RightWheel.write((int) -speed); // Right wheel is backwards 
    delay((int) (seconds*1000));
}


void Stop( double seconds)
{
  LeftWheel.detach();
  RightWheel.detach();
  delay((int) (seconds*1000));
}





void attachServos()
{
   LeftWheel.attach(LWPin);
   RightWheel.attach(RWPin);

}
