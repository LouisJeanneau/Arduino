#include <IRremote.h>
#include <Servo.h>
#include <NewPing.h>
NewPing sonar(2, 4, 200);

long bouton;
int tampon;
int distance=0;
int IRpin = 5;
int moteur=6;
int vitesse=0;
int angleRoue=70;
int pinAvant=12;
int pinArriere=13;
bool avance=true;
IRrecv irrecv(IRpin);
decode_results results;
Servo servo;


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
  pinMode(moteur,OUTPUT);
  pinMode(pinAvant,OUTPUT);
  pinMode(pinArriere,OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
  servo.attach(3);
  servo.write(angleRoue);
}

void loop() {
  if (irrecv.decode(&results) == 1)
{
  bouton = results.value;
  action(bouton);
  Serial.println(vitesse, DEC);  
    if(vitesse>=0){analogWrite(moteur,vitesse);}
    else(analogWrite(moteur,-vitesse));  
  irrecv.resume();
}
  if((avance==true) & (vitesse!=0)){
    distance=50;
    for(int a=0; a<5;a++){
      tampon=quelleDistance();
      if(tampon!=0){distance=tampon;};
    }    
    if(distance<=15){arret();};
    }


}


void action(long token){
  if((token==next1) or (token==next2)){ tourneDroite();}
  else if((token==previous1) or (token==previous2)) { tourneGauche();}
  else if((token==faster1) or (token==faster2)){ accelere();}
  else if((token==slower1) or (token==slower2)){ ralenti();}
  else if((token==enter1) or (token==enter2)) { arret();}}

void tourneDroite(){
  angleRoue=min(120,angleRoue+5);
  servo.write(angleRoue);}

void tourneGauche(){
  angleRoue = max(20,angleRoue-5);
  servo.write(angleRoue);}

  
void accelere(){
  
  if(vitesse==0){
  vitesse=136;
  avance=true;
  digitalWrite(pinAvant,avance);
  digitalWrite(pinArriere,!avance);}
  if(vitesse==-153){
  vitesse=0;}    
  else{vitesse=min(255,vitesse+17);}
 
  }
  

void ralenti(){

  if(vitesse==0){
  vitesse=-136;
  avance=false;
  digitalWrite(pinAvant,avance);
  digitalWrite(pinArriere,!avance);  }
  if(vitesse==153){vitesse=0;}
  else{vitesse=max(-255,vitesse-17);}
  }

void arret(){  
  vitesse=0;  
  analogWrite(moteur,0);  
 }


int quelleDistance(){;
  unsigned int uS = sonar.ping();
  int cm = uS/US_ROUNDTRIP_CM;
  return cm;
}
