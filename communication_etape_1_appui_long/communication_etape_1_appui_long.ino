#include <IRremote.h>

long variable;
int IRpin = 10;
int pinLed = 4;
int essai;
int repet;
bool toucheTrouvee;

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




IRrecv irrecv(IRpin);
decode_results results;



void setup() {
Serial.begin(9600);
irrecv.enableIRIn();
pinMode(pinLed,OUTPUT);
}



void loop() {

unsigned long touches[21]={0xFFA25D,0xFF629D,0xFFE21D,0xFF22DD,0xFF02FD,0xFFC23D,0xFFE01F,0xFFA857,0xFF906F,0xFF6897,0xFF9867,0xFFB04F,0xFF30CF,0xFF18E7,0xFF7A85,0xFF10EF,0xFF38C7,0xFF5AA5,0xFF42BD,0xFF4AB5,0xFF52AD};
essai=0;
repet=0;
toucheTrouvee=false;


if (irrecv.decode(&results) == 1)
{
variable = results.value;
Serial.println(variable, HEX);
irrecv.resume(); 
}

while(toucheTrouvee == false && essai<21 && variable!=0){  
  if(touches[essai] == variable)
  {
    toucheTrouvee=true;
    Serial.println("touche trouvee");};   

essai++;
Serial.println(essai, DEC);
}



if (toucheTrouvee == true){
for(repet=0;repet<essai;repet++){
digitalWrite(pinLed, HIGH);
delay(100);
digitalWrite(pinLed, LOW);
delay(100);
}
}

variable=0;



}

