#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include <ESP32-VirtualMatrixPanel-I2S-DMA.h>
#include <esp32_i2s_parallel_v2.h>
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include <ESP32-VirtualMatrixPanel-I2S-DMA.h>
#include <esp32_i2s_parallel_v2.h>

// Change these to whatever suits
#define R1_PIN GPIO_NUM_13
#define G1_PIN GPIO_NUM_27
#define B1_PIN GPIO_NUM_26
#define R2_PIN GPIO_NUM_25
#define G2_PIN GPIO_NUM_33
#define B2_PIN GPIO_NUM_32
#define A_PIN GPIO_NUM_19
#define B_PIN GPIO_NUM_23
#define C_PIN GPIO_NUM_18
#define D_PIN GPIO_NUM_5
#define E_PIN GPIO_NUM_15 // required for 1/32 scan panels, like 64x64. Any available pin would do, i.e. IO32
#define LAT_PIN GPIO_NUM_22
#define OE_PIN GPIO_NUM_16
#define CLK_PIN GPIO_NUM_14

HUB75_I2S_CFG::i2s_pins _pins={R1_PIN, G1_PIN, B1_PIN, R2_PIN, G2_PIN, B2_PIN, A_PIN, B_PIN, C_PIN, D_PIN, E_PIN, LAT_PIN, OE_PIN, CLK_PIN};
HUB75_I2S_CFG mxconfig(
	64, // Module width
	64, // Module height
	1, // chain length
	_pins, // pin mapping
);

MatrixPanel_I2S_DMA dma_display = new MatrixPanel_I2S_DMA(mxconfig);