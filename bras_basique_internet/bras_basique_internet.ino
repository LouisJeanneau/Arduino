#include<Servo.h>
Servo servoAvant,servoArriere;


void setup()
{
servoAvant.attach(6);
servoArriere.attach(8);
}

void loop(){
servoAvant.write(90);
servoArriere.write(90);
}

