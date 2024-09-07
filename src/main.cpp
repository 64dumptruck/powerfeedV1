#include <Arduino.h>

//on/off/on toggle on pins 2,3
int forwardS = 3;
int reverseS = 2;
//red pushbutton
int pbnS = 4;
//coax jack for limits
int limitS = 5;
// outputs for driver
int dir = 6;
int pul = 7;
int enbl = 8;
//10k pot in on a0
int spd = A0;
//pulse delay variable
int pd = 500;
//input variables 
int forward = HIGH;
int reverse = HIGH;
int limit = HIGH;


void speed(){

  digitalWrite(enbl, HIGH);
  pd = map((analogRead(spd)),0,1023,200,2);
  digitalWrite(pul, HIGH);
  delayMicroseconds(pd);
  digitalWrite(pul, LOW);
  delayMicroseconds(pd);


  
}

void setup() {
  
  pinMode (forwardS, INPUT_PULLUP);
  pinMode (reverseS, INPUT_PULLUP);
  pinMode (pbnS, INPUT_PULLUP);
  pinMode (limitS, INPUT_PULLUP);
  pinMode (dir, OUTPUT);
  pinMode (pul, OUTPUT);
  pinMode (enbl, OUTPUT);
  


}

void loop() {

forward = digitalRead(forwardS);
reverse = digitalRead(reverseS);
limit = digitalRead(limitS);


if ((forward == LOW) && (limit == HIGH) ){
    digitalWrite(dir, HIGH);
    speed();
  
    }

else if ((reverse == LOW) && (limit == HIGH) ) {
    digitalWrite(dir, LOW);
    speed();
    
    }

else{
    digitalWrite(enbl, LOW);
    
    }

}