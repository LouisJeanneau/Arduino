#include <IRremote.h>
#include <Servo.h>

long bouton;
int IRpin = 9;
int moteur1=10;
int vitMoteur=0;
int angleRoue;
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
#define next 3293
#define previous 3292
#define faster 3301
#define slower 3300
#define enter 3302





void setup() {
  pinMode(moteur1,OUTPUT);
  irrecv.enableIRIn();
  servo1.attach(5);
  Serial.begin(9600);
}

void loop() {

if (irrecv.decode(&results) == 1)
{
bouton = results.value;
Serial.println(bouton, DEC);
action(bouton);
irrecv.resume();
}
}

void action(long token){
  if(token ==  next){ tourneDroite();}
  else if(token ==  previous){ tourneGauche();}
  else if(token == 3301){ accelere();}
  else if(token ==  slower){ ralenti();}
  else if(token ==  arret){ arret();}
}

void tourneDroite(){
  angleRoue=min(180,angleRoue+15);
  servo1.write(angleRoue);  }

void tourneGauche(){
  angleRoue = max(0,angleRoue-15);
  servo1.write(angleRoue);   }

void accelere(){
  analogWrite(moteur1,1);   }

void arret(){
  analogWrite(moteur1,0);   }
  
void ralenti(){}
