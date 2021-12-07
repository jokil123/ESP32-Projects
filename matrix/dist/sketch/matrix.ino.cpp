#include <Arduino.h>
#line 1 "c:\\GIT\\ESP32-Projects\\matrix\\matrix.ino"
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>

#define PANEL_RES_X 64 // Number of pixels wide of each INDIVIDUAL panel module.
#define PANEL_RES_Y 64 // Number of pixels tall of each INDIVIDUAL panel module.
#define PANEL_CHAIN 1	 // Total number of panels chained one to another

// MatrixPanel_I2S_DMA dma_display;
MatrixPanel_I2S_DMA *dma_display = nullptr;

#line 10 "c:\\GIT\\ESP32-Projects\\matrix\\matrix.ino"
void setup();
#line 30 "c:\\GIT\\ESP32-Projects\\matrix\\matrix.ino"
void loop();
#line 36 "c:\\GIT\\ESP32-Projects\\matrix\\matrix.ino"
void drawShader();
#line 49 "c:\\GIT\\ESP32-Projects\\matrix\\matrix.ino"
uint16_t fragmentShader(uint64_t x, uint64_t y, float u, float v);
#line 10 "c:\\GIT\\ESP32-Projects\\matrix\\matrix.ino"
void setup()
{
	// Module configuration
	HUB75_I2S_CFG mxconfig(
			PANEL_RES_X, // module width
			PANEL_RES_Y, // module height
			PANEL_CHAIN	 // Chain length
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
	for (int i = 0; i < PANEL_RES_X; i++)
	{
		for (int j = 0; j < PANEL_RES_Y; j++)
		{
			dma_display->drawPixel(i, j, fragmentShader(i, j, (float)i / (float)PANEL_RES_X, (float)j / (float)PANEL_RES_Y));
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
