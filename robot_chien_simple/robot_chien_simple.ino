#include <NewPing.h>
#include <Servo.h>

Servo servoAvant,servoArriere;
NewPing sonar(2,4,200);

char avant[]={60,100,100,100,100,60,60,60};
int distance=0;
int distMin=20;


void setup() {
 servoAvant.attach(6);
 servoArriere.attach(8);
}

void loop() {
distance=0;
while(distance==0)
  {
  distance=quelleDistance();
  }
if(distance>distMin)
  {
   avance();
  }
}

void avance(){
  for(int n=0;n<4;n++)
    {
      servoAvant.write(avant[2*n]);
      servoArriere.write(avant[(2*n)+1]);
      delay(250);
    }
}

int quelleDistance(){
  delay(70);
  unsigned int uS=sonar.ping();
  int cm=uS/US_ROUNDTRIP_CM;
  return cm;
}

