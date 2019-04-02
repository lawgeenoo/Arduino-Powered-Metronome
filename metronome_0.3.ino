#include <LiquidCrystal.h>
static volatile int tempo = 120;
static volatile float tick = 1;
int dtime;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  pinMode(4 , OUTPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Metronome");
  lcd.setCursor(0, 2);
  lcd.print("BPM");
  lcd.setCursor(13, 1);
  lcd.print(tempo);


}

void loop()
{
  int tno = 4;
  dtime = tempo / 60;
  tick = 1000 / dtime;
  for (tno = 1; tno <= 4; tno++)
  {
    lcd.setCursor(8, 1);
    lcd.print(tno);
    lcd.print("/4");
    while (tno == 1)
    {
      tone(4, 4650, 100);
      delay(tick);
      tno++;
      lcd.setCursor(8, 1);
      lcd.print(tno);
      break;
    }

    tone(4, 4000, 100);
    digitalWrite(4, LOW);
    delay(tick);

  }


}
