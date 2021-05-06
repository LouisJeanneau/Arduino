 #include <NewPing.h>
int pin1Moteur1 = 12;
int pin2Moteur1 = 8;
int pinPMoteur1 = 11;
int pin1Moteur2 = 2;
int pin2Moteur2 = 4;
int pinPMoteur2 = 5;
int TRIG_PIN = 10;
int ECHO_PIN = 9;
int DIST_MAX = 200;
int i = 90;
int distActuelle = 0;
int cm;
int pinPhoto = A0;
int valeurPhoto;
int pinLed=3;
int luminositeLed;
NewPing sonar(TRIG_PIN, ECHO_PIN, 200);
  
  // le moteur gauche numéro 1. 
  // moteur droit 2




  
void setup() {
  // Setup des pins moteur
  pinMode(pin1Moteur1,OUTPUT);
  pinMode(pin2Moteur1,OUTPUT);
  pinMode(pinPMoteur1,OUTPUT);
  pinMode(pin1Moteur2,OUTPUT);
  pinMode(pin2Moteur2,OUTPUT);
  pinMode(pinPMoteur2,OUTPUT);
  delay(5000);
}

void loop(){
   distActuelle = lectureDistance();
  allumePhare();
  
    if (distActuelle > 20){
      avance();
    }

    if (distActuelle <= 20){
      recule();
      tourneDroite();
    }

    delay(300);
}


// FONCTION DIRMOTEUR : GENERALE



void dirMoteur(int moteur,int sens,int pc) {
int pin1,etat1,pin2,etat2,pinP,puissance;

  if(moteur==1){
    pin1=pin1Moteur1;
    pin2=pin2Moteur1;
    pinP=pinPMoteur1;
  }
  else{
    pin1=pin1Moteur2;
    pin2=pin2Moteur2;
    pinP=pinPMoteur2;
  }


  if(sens==1){
    etat1=1;
    etat2=0;
  }
  else if(sens==-1){
    etat1=0;
    etat2=1;
  }
  else{
    etat1=0;
    etat2=0;    
  }


  puissance=map(pc,0,100,0,255);
  analogWrite(pinP,puissance);
  digitalWrite(pin1,etat1);
  digitalWrite(pin2,etat2);
  }




// FONCTION AVANCE, RECULE, TOURNEDROITE


void avance(){
  dirMoteur(1,1,100);
  dirMoteur(2,1,90);
}


void recule(){
  dirMoteur(1,0,100);
  dirMoteur(2,0,100);
  delay(2000);
  dirMoteur(1,-1,100);
  dirMoteur(2,-1,90);
}


void tourneDroite(){
  delay(1000);
  dirMoteur(1,0,100);
  dirMoteur(2,0,100);
  delay(1000);
  dirMoteur(1,0,100);
  dirMoteur(2,-1,100);
  delay(400);
}



int lectureDistance(){
  delay(70);

  unsigned int uS = sonar.ping();
  cm = uS / US_ROUNDTRIP_CM;
  if(cm==0){
    lectureDistance();
  }
  else{
    return cm;
  }
}



// FONCTION PHARE AUTO

void allumePhare(){
  valeurPhoto=analogRead(pinPhoto);
  luminositeLed=max(map(valeurPhoto,0,300,255,0),0);
  analogWrite(pinLed, luminositeLed);
  delay(100);
}



