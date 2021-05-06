#include <Servo.h>

Servo monServo1;
Servo monServo2;
int posiMoteur = 0;
int boutonBase = 8;
int boutonBras = 12;
int monteeBras = 1;
int monteeBase = 1;
int posiBase = 50;
int posiBras = 50;
int mvtBase;
int mvtBras;

void setup() {
  // put your setup code here, to run once:
monServo1.attach(2);
monServo2.attach(4);
pinMode(boutonBase, INPUT);
pinMode(boutonBras, INPUT);
delay(100);
monServo1.write(posiBase);
monServo2.write(posiBras);
}

void loop() {
  // put your main code here, to run repeatedly:
  mvtBase = digitalRead(boutonBase); 
  mvtBras = digitalRead(boutonBras);

if(monteeBase == 1)
{
  if(mvtBase == 0)
  {
      monServo1.write(posiBase);
      posiBase ++;
      delay(10);
  }
}
if(monteeBras == 1)
{
   if(mvtBras == 0)
  {
      monServo2.write(posiBras);
      posiBras ++;
      delay(10);
  }
}


if(monteeBase == 0)
{
  if(mvtBase == 0)
  {
      monServo1.write(posiBase);
      posiBase --;
      delay(10);
  }
}

if(monteeBras == 0)
{
    if(mvtBras == 0)
  {
      monServo2.write(posiBras);
      posiBras --;
      delay(10);
  }

}

if(posiBras == 175)
{
  monteeBras = 0;
}
if(posiBras == 5)
{
  monteeBras = 1;
}

if(posiBase == 165)
{
  monteeBase = 0;
}
if(posiBase == 5)
{
  monteeBase = 1;
}
}
  
  
  
 
