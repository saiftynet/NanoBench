/* plotting a graph fromanalog input*/

#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define TFT_DC 8
#define TFT_CS 10
#define TFT_RST 9
#define pn 6     //pin to be read


Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
 int x=20; int y=120; int oldY=120; int xStep=1;
 int yMin=140; int yMax=110;float scaleFactor= 0.20;
void setup() {
  Serial.begin(9600);
  Serial.println("ILI9341 Pin Monitor Started"); 
 
  tft.begin();

  tft.setRotation(3);
  tft.fillScreen(ILI9341_BLACK);
  box(10, 10, 300, 230,ILI9341_YELLOW , 5);
  tft.setCursor(70,110);  
  tft.setTextSize(4);
  tft.setTextColor(ILI9341_GREEN,ILI9341_RED );
  tft.print("Plotter");
  tft.setTextSize(2);
  tft.setCursor(60,150);  
  tft.setTextColor(ILI9341_BLUE,ILI9341_RED );
  tft.print("   Saif Ahmed    ");
  delay(3000);
  tft.fillScreen(ILI9341_BLACK);

  box(10, 10, 300, 230,ILI9341_GREEN , 5);
}

void loop() {
  // put your main code here, to run repeatedly:
  tft.drawFastVLine(x+1, 20, 210, ILI9341_BLACK);
  oldY=y;
  y=240-analogRead(pn)*scaleFactor;
  tft.drawLine(x, oldY, x+xStep, y, ILI9341_RED);
  x=x<300?x+xStep:20;
  delay(30);
  

}

void box(int xpos, int ypos, int w, int h, uint16_t color, uint16_t thickness) {
  tft.drawRect(xpos, ypos, w, h, color);
  tft.drawRect(xpos+thickness, ypos+thickness, w-2*thickness, h-2*thickness, color);
}
