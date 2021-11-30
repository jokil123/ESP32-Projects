# 1 "c:\\GIT\\ESP32-Projects\\matrix\\matrix.ino"
# 2 "c:\\GIT\\ESP32-Projects\\matrix\\matrix.ino" 2

PxMATRIX display(64,64,GPIO_NUM_22,GPIO_NUM_16, GPIO_NUM_19,GPIO_NUM_23,GPIO_NUM_18, GPIO_NUM_5, GPIO_NUM_15);

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
