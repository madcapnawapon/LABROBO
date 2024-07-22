#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;
void setup() {
  Serial.begin(115200);
  matrix.begin();
}
uint8_t frame[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};


void loop(){
  int i,j;
  for(i=0;1<12;i++){
    for(j=0;j<8;j++){
      frame[j][i]=1;
      matrix.renderBitmap(frame, 8, 12);
      delay(100);
      frame[j][i]=0;
      matrix.renderBitmap(frame, 8, 12);
      delay(100);


    }
  }
  
}