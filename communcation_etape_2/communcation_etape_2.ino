#include <IRremote.h>
int RECV_PIN = 10;

IRrecv irrecv(RECV_PIN);
decode_results results;





void setup() {
Serial.begin(9600);
irrecv.enableIRIn();
}


void dump(decode_results *results) {
int count = results->rawlen;
Serial.println("Signal recu ! ");
Serial.print("Longueur du signal (");
Serial.print(count, DEC);
Serial.println("): ");
for (int i = 0; i < count; i++) {
if ((i % 2) == 1) {
Serial.println(results->rawbuf[i]*USECPERTICK, DEC);
}
else {
Serial.println(-(int)results->rawbuf[i]*USECPERTICK, DEC);
}
}
}


void loop() {
if (irrecv.decode(&results)) {
dump(&results);
irrecv.resume(); // Receive the next value
}
}

