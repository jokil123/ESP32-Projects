#include <Arduino.h>
#line 1 "c:\\GIT\\ESP32-Projects\\matrix\\matrix.ino"
#include <PxMatrix.h>

PxMATRIX display(64,64,GPIO_NUM_22,GPIO_NUM_16, GPIO_NUM_19,GPIO_NUM_23,GPIO_NUM_18, GPIO_NUM_5, GPIO_NUM_15);

#line 5 "c:\\GIT\\ESP32-Projects\\matrix\\matrix.ino"
void setup();
#line 12 "c:\\GIT\\ESP32-Projects\\matrix\\matrix.ino"
void loop();
#line 5 "c:\\GIT\\ESP32-Projects\\matrix\\matrix.ino"
void setup() {
  display.setPanelsWidth(1);
  display.setMuxPattern(BINARY);
  display.begin(32);
}

// the loop function runs over and over again forever
void loop() {
  //display.fillScreen(display.color565(rand() % 255,rand() % 255,rand() % 255));display.fillScreen(1);
  display.displayTestPattern(1);
  //display.fillScreen(display.color565());
}

