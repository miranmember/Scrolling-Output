
// 1- Miran Member 
// 2- Scrolling output
// 3- Description - Outputs the name and the favorite quote on the lcd panel.
// 4- Include any assumptions you may have made, what do you expect from the hardware, pinouts, particular Arduino versions, etc...
// 5- References - https://www.arduino.cc/en/Tutorial/LiquidCrystalScroll
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


String quote = "You Only Live Once.";
int start, stop = 0;
int scroll = 16;

void setup() {
  
  lcd.begin(16,2);
  
}

void loop() {
  lcd.print("Miran Member");
  lcd.setCursor(0, 1);
  lcd.print(quote.substring(start,stop));
  delay(300);
  lcd.clear();
  
  if(start == 0 && scroll > 0){
    scroll--;
    stop++;
  } else if (start == stop){
    start = stop = 0;
    scroll = 16;
  } else if (stop == quote.length() && scroll == 0) {
    start++; 
  } else {
    start++;
    stop++;
  }
}
