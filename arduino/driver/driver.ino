// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
 
int val;    // variable to read the value from the analog pin 
int command;
char incomingByte;
int wheel;
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  Serial.begin(115200);
  wheel = 96;
} 

int getCommand(){
  if(Serial.available() > 0){
    
    incomingByte = Serial.read();
  
    if (incomingByte == 48){
      digitalWrite(4, HIGH); 
    }
    if (incomingByte == 49){
      digitalWrite(4, LOW);
    }
    
    if (incomingByte == 50){
      //incomingByte= Serial.read();
      //steer(incomingByte);
      wheel -=3;  
    }
  
    if (incomingByte == 51){
       wheel += 3;
    }
    if (incomingByte == 52){
      wheel -= 6;
    }
    if (incomingByte == 53){
      wheel += 6;
    }
    if (incomingByte == 54){
      wheel -=12;
    }
    if (incomingByte == 55){
      wheel += 12;
    }
    if (incomingByte == 56){
      wheel = 90;
    }
  }
  return 0;
}

void steer(int deg){
  myservo.write(deg);
}
 
void loop() 
{ 
 command = getCommand();
 myservo.write(wheel);            // sets the servo position according to the scaled value 
 delay(15);                           // waits for the servo to get there 
 return;
} 

void drive(int time){
  digitalWrite(4, HIGH);
  delay(time);
  //digitalWrite(3, LOW);
}

