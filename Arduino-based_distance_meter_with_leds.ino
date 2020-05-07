// Arduino-based distance meter
// Developed by Maxim Bortnikov
// For more information visit: https://github.com/Northstrix/Arduino-based-distance-meter
#include "TM1637.h"
#define CLK 4//pins definitions for TM1637 and can be changed to other ports       
#define DIO 5
TM1637 tm1637(CLK,DIO);
int echoPin = 6; 
int trigPin = 7; 
 
void setup() { 
  Serial.begin (9600);
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
} 
 
void loop() { 
  void display(int8_t DispData[]);
  int duration, cm; 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH); 
  cm = duration / 58;
  Serial.print(cm); 
  Serial.println(" cm");
  tm1637.display(cm);
  if (cm >= 50) {
    digitalWrite(8, HIGH);
}
  else {
    digitalWrite(8,LOW);
  }
  if (cm >= 100) {
      digitalWrite(9, HIGH);
}
  else {
      digitalWrite(9, LOW);
  }
  if (cm >= 150) {
      digitalWrite(10, HIGH);
} 
  else {
    digitalWrite(10, LOW);
  }
  if (cm >= 200) {
    digitalWrite(11, HIGH);
}
  else {
    digitalWrite(11,LOW);
  }
  if (cm >= 250) {
    digitalWrite(12, HIGH);
}
  else {
    digitalWrite(12,LOW);
  }
  if (cm >= 300) {
    digitalWrite(13, HIGH);
}
  else {
    digitalWrite(13,LOW);
  }
  delay(100);
  }
