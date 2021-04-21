
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define TFT_DC 8
#define TFT_CS 10
#define TFT_RST 9
#define pn 0


Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
 int x=20; int y=120; int oldY=120;int oldX=20; int xStep=1;
 unsigned long  tStart=micros();
 int yMax=160; int yMin=80;
 int xMax=290; int xMin=20;
 
 int p[256]; int index=0; int c;float scaleFactor= 0.20;int offSet=0;
void setup() {
 
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
  delay(2000);
  tft.fillScreen(ILI9341_BLACK);
  box(10, 10, 300, 230,ILI9341_GREEN , 5);
  tft.setTextSize(2);
  tft.setTextColor(ILI9341_BLUE,ILI9341_BLACK );
}

void loop() {
  
  for(c=0; c<xStep; c++){
    tft.drawFastVLine(x+c, 35, 180, ILI9341_BLACK);
  }
  oldY=y;
  oldX=x;
  p[index]=analogRead(pn);
  y=240-p[index]*scaleFactor - offSet;
  y=y<yMin?yMin:y;
  y=y>yMax?yMax:y;
  x=x<xMax?x+xStep:xMin;
  if (x!=xMin){
  tft.drawLine(oldX, oldY, x, y, ILI9341_RED);
    if(index>=255){
      reScale(micros()-tStart);
      index=-1;
      tStart=micros();
    }
    index++;
  }
}


void reScale(unsigned long  interval){
  int pMax=p[0];int pMin=p[0];float peaks=0; int dip=1;
   for (c=0; c<256; c++){
     pMax=p[c]>pMax?p[c]:pMax;
     pMin=p[c]<pMin?p[c]:pMin;
     if ((p[c-1]>p[c-2])&&(p[c+1]>p[c+2])&& dip ){peaks++;dip=0;};
     if ((p[c-1]>p[c-2])&&(p[c+1]>p[c+2])&! dip ){dip=1;}
   }  
   int rate=(1000000*peaks/interval);
   scaleFactor=(yMax-yMin)/(pMax-pMin);
   offSet=-pMin*scaleFactor+yMin;
   
   tft.setCursor(20,20);
   
   tft.print(rate);tft.print("  ");
   tft.print(pMax);tft.print("  ");
   tft.print(pMin);tft.print("  ");
   //tft.print(1000000*peaks/interval);tft.print("  ");
}


void box(int xpos, int ypos, int w, int h, uint16_t color, uint16_t thickness) {
  tft.drawRect(xpos, ypos, w, h, color);
  tft.drawRect(xpos+thickness, ypos+thickness, w-2*thickness, h-2*thickness, color);
}
