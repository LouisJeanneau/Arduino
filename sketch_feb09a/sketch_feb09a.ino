#include <IRremote.h>
#include <Servo.h>

long bouton;
int IRpin = 5;
int moteur=6;
int vitesse=0;
int angleRoue=0;
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
  // put your setup code here, to run once:
  pinMode(moteur,OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
  servo.attach(2);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results) == 1)
{
bouton = results.value;
action(bouton);
irrecv.resume();
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
  servo.write(angleRoue);  }

void tourneGauche(){
  angleRoue = max(20,angleRoue-5);
  servo.write(angleRoue);   }

  
void accelere(){

  if(vitesse==0){vitesse=68;}
  else{vitesse=min(255,vitesse+17);}

    
  Serial.println(vitesse, DEC);
  analogWrite(moteur,vitesse); 
  Serial.println(" ");
}

void ralenti(){
  
  vitesse=max(0,vitesse-17);
  if(vitesse==51){vitesse=0;}
  Serial.println(vitesse, DEC);
  analogWrite(moteur,vitesse); 
  Serial.println(" ");
  }

void arret(){
  vitesse=0;  
  analogWrite(moteur,0);   }

  
  
 
