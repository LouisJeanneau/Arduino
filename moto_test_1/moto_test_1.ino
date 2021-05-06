digiint moteur1=10;
int vitMoteur=0;


void setup() {
  pinMode(moteur1,OUTPUT);
  Serial.begin(9600);
}

void loop() {

 vitMoteur=Serial.read()-48;

 if(vitMoteur>0){
  Serial.print(vitMoteur);
  int valeur=1;
  digitalWrite(moteur1, valeur);
  delay(2000);
  }

digitalWrite(moteur1,LOW);
}
