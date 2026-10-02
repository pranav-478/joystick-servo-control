#include <Servo.h>
Servo blackservo;
Servo whiteservo;
int blackservopin = 10;
int whiteservopin = 9;
int xval;
int yval;
int xpin = A0;
int ypin = A1;
float blackangle;
float whiteangle;
int jpin =2;
int del = 200;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  blackservo.attach(blackservopin);
  whiteservo.attach(whiteservopin);
  pinMode(jpin,INPUT);
  pinMode(blackservopin,OUTPUT);
  pinMode(whiteservopin,OUTPUT);
  pinMode(xpin,INPUT);
  pinMode(ypin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  xval = analogRead(xpin);
  yval = analogRead(ypin);
  Serial.print("Xval: ");
  Serial.print(xval);
  Serial.print("   ");
  Serial.print("Yval: ");
  Serial.print(yval);
  Serial.print("   ");
  blackangle = 0.166*xval;
  whiteangle = 0.166*yval;
  blackservo.write(blackangle);
  whiteservo.write(whiteangle);
  Serial.print("White servo angle: ");
  Serial.print(whiteangle);
  Serial.print("   ");
  Serial.print("Black servo angle: ");
  Serial.println(blackangle);
 delay(del);

  

}
