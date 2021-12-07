# 1 "c:\\GIT\\ESP32-Projects\\matrix\\matrix.ino"
# 2 "c:\\GIT\\ESP32-Projects\\matrix\\matrix.ino" 2

#define PANEL_RES_X 64 /* Number of pixels wide of each INDIVIDUAL panel module.*/
#define PANEL_RES_Y 64 /* Number of pixels tall of each INDIVIDUAL panel module.*/
#define PANEL_CHAIN 1 /* Total number of panels chained one to another*/

// MatrixPanel_I2S_DMA dma_display;
MatrixPanel_I2S_DMA *dma_display = nullptr;

void setup()
{
 // Module configuration
 HUB75_I2S_CFG mxconfig(
   64 /* Number of pixels wide of each INDIVIDUAL panel module.*/, // module width
   64 /* Number of pixels tall of each INDIVIDUAL panel module.*/, // module height
   1 /* Total number of panels chained one to another*/ // Chain length
 );

 mxconfig.gpio.e = 32;
 mxconfig.clkphase = false;
 mxconfig.driver = HUB75_I2S_CFG::FM6126A;

 // Display Setup
 dma_display = new MatrixPanel_I2S_DMA(mxconfig);
 dma_display->begin();
 dma_display->setBrightness8(90); // 0-255
 dma_display->clearScreen();
}

void loop()
{
 drawShader();
 delay(100);
}

void drawShader()
{
 for (int i = 0; i < 64 /* Number of pixels wide of each INDIVIDUAL panel module.*/; i++)
 {
  for (int j = 0; j < 64 /* Number of pixels tall of each INDIVIDUAL panel module.*/; j++)
  {
   dma_display->drawPixel(i, j, fragmentShader(i, j, (float)i / (float)64 /* Number of pixels wide of each INDIVIDUAL panel module.*/, (float)j / (float)64 /* Number of pixels tall of each INDIVIDUAL panel module.*/));
   // delay(10);
   // dma_display->clearScreen();
  }
 }
}

uint16_t fragmentShader(uint64_t x, uint64_t y, float u, float v)
{
 // dma_display->setCursor(0, 0);
 // dma_display->print(v);
 // dma_display->setCursor(0, 12);
 // dma_display->print(u);
 // return dma_display->color565(255, 255, 0);
 return dma_display->color565((int8_t)(u * (float)255), (int8_t)(v * (float)255.0), 0);
}
