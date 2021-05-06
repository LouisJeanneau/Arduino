

#include <LiquidCrystal.h>
#define RS 12
#define E 11
#define D4 5
#define D5 4
#define D6 3
#define D7 2
#define COLS 16
#define ROWS 2
LiquidCrystal lcd(RS,E,D4,D5,D6,D7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(COLS,ROWS);
  lcd.print("&é'(-è_çà");b 
  lcd.setCursor(0,1);
  lcd.print("Lets play a game");
}

void loop() {
  // put your main code here, to run repeatedly:

}
