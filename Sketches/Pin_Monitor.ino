/* This a sketch for monitoring pins
 ****************************************************/  

#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define TFT_DC 8
#define TFT_CS 10
#define TFT_RST 9

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
 int x=0;
void setup() {
  Serial.begin(9600);
  Serial.println("ILI9341 Pin Monitor Started"); 
 
  tft.begin();

  // read diagnostics (optional but can help debug problems)
  uint8_t x = tft.readcommand8(ILI9341_RDMODE);
  Serial.print("Display Power Mode: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDMADCTL);
  Serial.print("MADCTL Mode: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDPIXFMT);
  Serial.print("Pixel Format: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDIMGFMT);
  Serial.print("Image Format: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDSELFDIAG);
  Serial.print("Self Diagnostic: 0x"); Serial.println(x, HEX); 
  tft.setRotation(3);
  tft.fillScreen(ILI9341_BLACK);
  box(10, 10, 300, 230,ILI9341_YELLOW , 5);
  tft.setCursor(30,110);  
  tft.setTextSize(4);
  tft.setTextColor(ILI9341_GREEN,ILI9341_RED );
  tft.print("PIN MONITOR");
  tft.setTextSize(2);
  tft.setCursor(60,150);  
  tft.setTextColor(ILI9341_BLUE,ILI9341_RED );
  tft.print("   Saif Ahmed    ");
  delay(3000);
  tft.fillScreen(ILI9341_BLACK);
  
  tft.setTextSize(2);
  yield();
  tft.setTextColor(ILI9341_RED,ILI9341_BLACK );
  tft.setCursor(20,5);
  tft.print("DigPin No   Mode   Value");
  tft.setCursor(20,130);
  tft.print("AnPin No    Value");
  tft.setTextColor(ILI9341_WHITE,ILI9341_BLACK );
}


void loop(void) {
  displayPins();
  delay(200);

}

void displayDigitalPin(int pn){
  tft.print("      ");
  tft.print(pn);
  tft.print("        ");
  tft.print(pinMode(pn));
  tft.print("       ");
  tft.println(digitalRead(pn));
}

void displayAnalogPin(int pn){
  tft.print("      ");
  tft.print(pn);
  tft.print("       ");
  tft.print(analogRead(pn));
  tft.println("   ");
}


void displayPins(){
  int x;
  tft.setCursor(0,5);
  tft.println();
  for(x=2; x<8; x++){ 
    displayDigitalPin(x) ;
  };
  tft.setCursor(0,130);
  tft.println();
  for(x=0; x<8; x++){
    if ((x==4)||(x==5)) {
          continue;
    }
    displayAnalogPin(x) ;
  };
}


void box(int xpos, int ypos, int w, int h, uint16_t color, uint16_t thickness) {
  tft.drawRect(xpos, ypos, w, h, color);
  tft.drawRect(xpos+thickness, ypos+thickness, w-2*thickness, h-2*thickness, color);
}

int pinMode(uint8_t pin)
{
  if (pin >= NUM_DIGITAL_PINS) return (-1);

  uint8_t bit = digitalPinToBitMask(pin);
  uint8_t port = digitalPinToPort(pin);
  volatile uint8_t *reg = portModeRegister(port);
  if (*reg & bit) return (OUTPUT);

  volatile uint8_t *out = portOutputRegister(port);
  return ((*out & bit) ? INPUT_PULLUP : INPUT);
}
