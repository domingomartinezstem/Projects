#include <SoftwareSerial.h>
int E1 = 5;
int M1 = 4;
int E2 = 6;
int M2 = 7;
SoftwareSerial BT(0, 1); //TX, RX respetively
String readdata;

void setup() {
 BT.begin(9600);
 Serial.begin(9600);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
}
//-----------------------------------------------------------------------// 
void loop() {
  while (BT.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = BT.read(); //Conduct a serial read
  readdata += c; //build the string- "forward", "reverse", "left" and "right"
  } 
  if (readdata.length() > 0) {
    Serial.println(readdata); // print data to serial monitor
// if data received as forward move robot forward
  if(readdata == "forward") 
  {
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  analogWrite(E1, 255);   //PWM Speed Control
  analogWrite(E2, 255);
    delay(100);
  }
  // if data received as reverse move robot reverse

  else if(readdata == "reverse")
  {
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  analogWrite(E1, 255);   //PWM Speed Control
  analogWrite(E2, 255);
    delay(100);
  }
// if data received as right turn robot to right direction.
  else if (readdata == "right")
  {
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  analogWrite(E1, 0);   //PWM Speed Control
  analogWrite(E2, 255);
      delay (100);
  }
// if data received as left turn robot to left direction
 else if ( readdata == "left")
 {
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  analogWrite(E1, 255);   //PWM Speed Control
  analogWrite(E2, 0);
   delay (100);
 }
 // if data received as stop, halt the robot

 else if (readdata == "stop")
 {
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  analogWrite(E1, 0);   //PWM Speed Control
  analogWrite(E2, 0);
   delay (100);
 }

  


readdata="";}} //Reset the variable
