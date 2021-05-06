int led=3;


void setup(){
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led, OUTPUT);
}

// the loop function runs over and over again forever
void loop(){
  digitalWrite(led, HIGH); 
  delay(10000);
  digitalWrite(led, LOW); 
  delay(10000);
}
