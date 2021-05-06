#include <IRremote.h>
#include <Servo.h>

long bouton;
int IRpin = 9;
float vitMoteur=0;
int angleRoue;
int pin2=4;
int pin1=2;
int pinP=3;
IRrecv irrecv(IRpin);
decode_results results;
Servo servo1;


//telecommande robobox
#define channelMoins 0xFFA25D
#define channel 0xFF629D
#define channelPlus 0xFFE21D
#define prev 0xFF22DD 
#define next 0xFF02FD
#define playpause 0xFFC23D
#define volMoins 0xFFE01F
#define volPlus 0xFFA857
#define eq 0xFF906F
#define zero 0xFF6897
#define centPlus 0xFF9867
#define deuxCentPlus 0xFFB04F
#define un 0xFF30CF
#define deux 0xFF18E7
#define trois 0xFF7A85
#define quatre 0xFF10EF
#define cinq 0xFF38C7
#define six 0xFF5AA5
#define sept 0xFF42BD
#define huit 0xFF4AB5
#define neuf 0xFF52AD
//Telecommande 2 : radio réveil
#define next1 3293
#define next2 1245
#define previous1 3292
#define previous2 1244
#define faster1 3301
#define faster2 1253
#define slower1 3300
#define slower2 1252
#define enter1 3302
#define enter2 1254





void setup() {
  pinMode(pinP,OUTPUT);
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  irrecv.enableIRIn();
  servo1.attach(5);
  Serial.begin(9600);
}

void loop(){
  vitMoteur=min(255,vitMoteur+17);
  Serial.println(vitMoteur, DEC);
  analogWrite(pinP,vitMoteur);
  delay(500);
  digitalWrite(pinP,0);
  delay(500);
}

void ralenti(){
  
  vitMoteur=min(255,vitMoteur+17);
  Serial.println(vitMoteur, DEC);
  analogWrite(pinP,vitMoteur); 
  }

void arret(){
  vitMoteur=0;
  
  analogWrite(pinP,0);   }
  

