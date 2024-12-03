#ifndef _SCREEN_H
#define _SCREEN_H

#include "stm32f4xx.h"
#include "spi.h"
#include "tim.h"
#include "gpio.h"

//------ COLOR FOR RGB BIT_16 --------//
/* COLOR FOR 16 BITS ITS SET IN 2BYTE
 * EXAMPLE
 * GREEN IN 16 BITS IT'S 0X07E0
 * */
//------ COLOR FOR RGB BIT_18 -------//
/* COLOR FOR 18 BITS ITS SET IN 3BYTE
 * EXAMPLE
 * GREEN IN 16 BITS IT'S RGB 666 0X00,0XFC,00
 * WHERE {R,G,B}  R = 00 G = FC, B=00
 * G = 11111100 = 00FC00
 * */
#define WHITE					0xFFFF
#define BLACK					0x0000
#define BLUE 					0x001F
#define BRED 					0XF81F
#define GRED 					0XFFE0
#define GBLUE					0X07FF
#define RED  					0xF800
#define MAGENTA				0xF81F
#define GREEN					0x07E0
#define CYAN 					0x7FFF
#define YELLOW				0xFFE0
#define BROWN					0XBC40
#define BRRED					0XFC07
#define GRAY 					0X8430
#define DARKBLUE			0X01CF
#define LIGHTBLUE			0X7D7C
#define GRAYBLUE      0X5458
#define LIGHTGREEN    0X841F
#define LGRAY 			  0XC618
#define LGRAYBLUE     0XA651
#define LBBLUE        0X2B12

/*------------------------------------------*/
#define LCD_1IN28_HEIGHT 240
#define LCD_1IN28_WIDTH 240


class Screen
{
public:
	explicit Screen(SPI_HandleTypeDef *_spi):spi(_spi) {
	}
	typedef enum Orientation{
		DEGREE_0,
		DEGREE_90,
		DEGREE_180,
		DEGREE_270

	}Orientation_t;

	typedef enum ColorMode{
		BIT_12,
		BIT_16,
		BIT_18
	}ColorMode_t;
	volatile bool isBusy = false;

	int ModuleInit(void);
	void LCDInit(Orientation_t _orientation);
	void SetWindows(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend);
	void Clear(uint16_t Color);
	void SetBackLight(uint16_t Value);
	void WriteFrameBuffer(uint16_t x,uint16_t y,uint16_t w,uint16_t h, uint8_t *buffer,uint32_t len,bool _isAppend=false);
	void WriteColor(uint8_t *Color,uint32_t len);
	void WritePixel(uint16_t x, uint16_t y, uint16_t color);
	void WriteImage(uint16_t _x, uint16_t y, uint16_t width, uint16_t height,const unsigned char *image);
	void DEV_Module_Exit(void);
	void begin_Write();
	void end_Write();
private:
	SPI_HandleTypeDef* spi;
	Orientation_t orientation = DEGREE_0;
	ColorMode_t colorMode = BIT_16;

	void DEV_SPI_WRite(uint8_t _dat);
	void ChipSelect(bool _status);
	void DCPin(bool _status);
	void RstPin(bool _status);
	void Reset(void);
	void WriteCommand(uint8_t Reg);
	void WriteByte(uint8_t Data);
	void WriteData(uint8_t* data,uint32_t _len,bool _usedma=false);
	void InitReg(Orientation_t _orientation);
};

#endif
