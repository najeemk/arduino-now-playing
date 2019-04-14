#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String song_title = "";
String artist = "";

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Waiting...");
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);  
}
 
void loop() {
  write();
}

void write() {
  if (Serial.available()) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    lcd.clear();
    while (Serial.available() > 0) {
      song_title = Serial.readStringUntil('*');
      artist = Serial.readStringUntil('*');
      lcd.print(song_title);
      lcd.setCursor(0,1);
      lcd.print(artist);
      lcd.setCursor(0,0);
    }
    digitalWrite(LED_BUILTIN, LOW);
  }
}
