#include <Servo.h>

Servo monServo1;
Servo monServo2;
int posiMoteur = 0;
int boutonBase = 8;
int boutonBras = 12;
signed int monteeBras = 1;
signed int monteeBase = 1;
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
  while(digitalRead(boutonBase) == 0 and digitalRead(boutonBras) == 0)
  {
    while(digitalRead(boutonBase) == 0 and digitalRead(boutonBras) == 0)
    {
      if(monteeBase == 1)
      {
        monServo1.write(posiBase);
      posiBase ++; 
      }
      
      if(monteeBras == 1)
      { monServo2.write(posiBras);
      posiBras ++;              
      }

      if(monteeBase == -1)
      {
        monServo1.write(posiBase);
      posiBase --; 
      }
      
      if(monteeBras == -1)
      { monServo2.write(posiBras);
      posiBras --;
              
      }
    }
    monteeBras = !monteeBras;
    monteeBase = !monteeBase;
  }

}

  
  
 
