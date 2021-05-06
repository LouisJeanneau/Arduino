int pinSpeaker = 6;

void setup() {
  // put your setup code here, to run once:
pinMode(pinSpeaker, OUTPUT);
delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
 tone(pinSpeaker, 160, 300);
 delay(300);
 tone(pinSpeaker, 0, 300);
 delay(300);
}
