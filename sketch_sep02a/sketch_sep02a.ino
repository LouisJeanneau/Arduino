#include <IRremote.h>

long variable;
int IRpin = 10;
int pinLed = 4;



IRrecv irrecv(IRpin);
decode_results results;



void setup() {
Serial.begin(9600);
irrecv.enableIRIn();
pinMode(pinLed,OUTPUT);
}



void loop() {
  
if (irrecv.decode(&results) == 1)
{
variable = results.value;
Serial.println(variable, DEC);
irrecv.resume();
}

if (variable == -484956645){
digitalWrite(pinLed, HIGH);
delay(1000);
digitalWrite(pinLed, LOW);
}
}

