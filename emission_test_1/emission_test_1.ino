#include <IRremote.h>
IRsend irsend;
unsigned int volUp[68] =
{4450,4500,500,1700,550,1700,550,550,500,650,500,550,550,600,500,1700,550,550,550,1700,550,1700,550,550,550,550,500,1750,550,550,550,1700,500,600,550,1700,500,1700,550,550,550,600,500,1700,550,1700,550,550,550,550,550,550,550,600,500,1750,500,1700,550,550,500,600,550,1700,500,1750,500};


void setup()
{
Serial.begin(9600);
}


void loop() {
irsend.sendRaw(volUp,68,38);
delay(100);}
