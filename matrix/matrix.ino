#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include <Vector.h>

#define PANEL_RES_X 64 // Number of pixels wide of each INDIVIDUAL panel module.
#define PANEL_RES_Y 64 // Number of pixels tall of each INDIVIDUAL panel module.
#define PANEL_CHAIN 1	 // Total number of panels chained one to another

int64_t f = 0;
int64_t startTime = millis();
int64_t lastTime = millis();

// MatrixPanel_I2S_DMA dma_display;
MatrixPanel_I2S_DMA *dma_display = nullptr;

void setup()
{
	Serial.begin(115200);

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
}

void drawShader()
{

	int64_t t = millis();
	int64_t st = startTime + millis();
	int64_t d = millis() - lastTime;
	lastTime = millis();

	for (int i = 0; i < PANEL_RES_X; i++)
	{
		for (int j = 0; j < PANEL_RES_Y; j++)
		{
			dma_display->drawPixel(i, j, fragmentShader(i, j, (float)i / (float)PANEL_RES_X, (float)j / (float)PANEL_RES_Y, f, t, st, d));
			Serial.println(millis() - lastTime);
		}
	}

	f++;
}

int64_t max_d = 1;

uint16_t fragmentShader(uint64_t x, uint64_t y, float u, float v, int64_t f, int64_t t, int64_t st, int64_t d)
{
	int8_t val = 0;

	if (u + sin((float)t * 0.001) > 0.0)
	{
		val = 255;
	}
	else
	{
		val = 0;
	}

	return dma_display->color565(val, val, val);
}