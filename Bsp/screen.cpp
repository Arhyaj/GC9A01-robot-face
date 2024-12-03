#include <screen.h>

void Screen::DEV_SPI_WRite(uint8_t _dat)
{
	HAL_SPI_Transmit(spi, (uint8_t *)&_dat, 1, 500);
}

void Screen::ChipSelect(bool _status){
	_status ? HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET):
			HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET);
}

void Screen::DCPin(bool _status){
	_status ? HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_SET):
				HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_RESET);
}

void Screen::RstPin(bool _status){
	_status ? HAL_GPIO_WritePin(LCD_RES_GPIO_Port, LCD_RES_Pin, GPIO_PIN_SET):
					HAL_GPIO_WritePin(LCD_RES_GPIO_Port, LCD_RES_Pin, GPIO_PIN_RESET);
}

int Screen::ModuleInit(void)
{
	DCPin(true);
	ChipSelect(true);
	RstPin(true);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
	return 0;
}

void Screen::DEV_Module_Exit(void)
{

		DCPin(false);
		ChipSelect(false);
		RstPin(false);
	    HAL_TIM_PWM_Stop(&htim3,TIM_CHANNEL_2);

}

void Screen::Reset(void)
{
	RstPin(true);
    HAL_Delay(100);
    RstPin(false);
    HAL_Delay(100);
    RstPin(true);
    HAL_Delay(100);
}

void Screen::begin_Write(){
	ChipSelect(false);
}

void Screen::end_Write(){
	ChipSelect(true);
}

void Screen::WriteCommand(uint8_t _reg)
{
    DCPin(false);
    HAL_SPI_Transmit(spi, &_reg, sizeof(_reg), 500);
}

void Screen::WriteData(uint8_t* _data, uint32_t _len,bool _useDma)
{
    DCPin(true);
    _useDma ? HAL_SPI_Transmit_DMA(spi, _data, _len):
    		HAL_SPI_Transmit(spi, _data, _len, 100);

}

void Screen::WriteByte(uint8_t Data)
{
    WriteData(&Data,sizeof(Data));
}

void Screen::InitReg(Orientation_t _orientation)
{
	begin_Write();
	WriteCommand(0xEF);
	WriteCommand(0xEB);
	WriteByte(0x14);

  WriteCommand(0xFE);
	WriteCommand(0xEF);

	WriteCommand(0xEB);
	WriteByte(0x14);

	WriteCommand(0x84);
	WriteByte(0x40);

	WriteCommand(0x85);
	WriteByte(0xFF);

	WriteCommand(0x86);
	WriteByte(0xFF);

	WriteCommand(0x87);
	WriteByte(0xFF);

	WriteCommand(0x88);
	WriteByte(0x0A);

	WriteCommand(0x89);
	WriteByte(0x21);

	WriteCommand(0x8A);
	WriteByte(0x00);

	WriteCommand(0x8B);
	WriteByte(0x80);

	WriteCommand(0x8C);
	WriteByte(0x01);

	WriteCommand(0x8D);
	WriteByte(0x01);

	WriteCommand(0x8E);
	WriteByte(0xFF);

	WriteCommand(0x8F);
	WriteByte(0xFF);


	WriteCommand(0xB6);
	WriteByte(0x00);
	WriteByte(0x20);

	WriteCommand(0x36);
	switch (_orientation)
	    {
	        case DEGREE_0:
	        	WriteByte(0x08);
	            break;
	        case DEGREE_90:
	        	WriteByte(0x28);
	            break;
	        case DEGREE_180:
	        	WriteByte(0x48);
	            break;
	        case DEGREE_270:
	        	WriteByte(0x88);
	            break;
	    }
	//LCD_1IN28_SendData_8Bit(0x08);//Set as vertical screen

	WriteCommand(0x3A);
	switch (colorMode)
	    {
	        case BIT_12:
	        	WriteByte(0x03);
	            break;
	        case BIT_16:
	        	WriteByte(0x05);
	            break;
	        case BIT_18:
	        	WriteByte(0x06);
	            break;
	    }
	//LCD_1IN28_SendData_8Bit(0x05);


	WriteCommand(0x90);
	WriteByte(0x08);
	WriteByte(0x08);
	WriteByte(0x08);
	WriteByte(0x08);

	WriteCommand(0xBD);
	WriteByte(0x06);

	WriteCommand(0xBC);
	WriteByte(0x00);

	WriteCommand(0xFF);
	WriteByte(0x60);
	WriteByte(0x01);
	WriteByte(0x04);

	WriteCommand(0xC3);
	WriteByte(0x13);
	WriteCommand(0xC4);
	WriteByte(0x13);

	WriteCommand(0xC9);
	WriteByte(0x22);

	WriteCommand(0xBE);
	WriteByte(0x11);

	WriteCommand(0xE1);
	WriteByte(0x10);
	WriteByte(0x0E);

	WriteCommand(0xDF);
	WriteByte(0x21);
	WriteByte(0x0c);
	WriteByte(0x02);

	WriteCommand(0xF0);
	WriteByte(0x45);
	WriteByte(0x09);
	WriteByte(0x08);
	WriteByte(0x08);
	WriteByte(0x26);
 	WriteByte(0x2A);

 	WriteCommand(0xF1);
 	WriteByte(0x43);
 	WriteByte(0x70);
 	WriteByte(0x72);
 	WriteByte(0x36);
 	WriteByte(0x37);
 	WriteByte(0x6F);


 	WriteCommand(0xF2);
 	WriteByte(0x45);
 	WriteByte(0x09);
 	WriteByte(0x08);
 	WriteByte(0x08);
 	WriteByte(0x26);
 	WriteByte(0x2A);

 	WriteCommand(0xF3);
 	WriteByte(0x43);
 	WriteByte(0x70);
 	WriteByte(0x72);
 	WriteByte(0x36);
 	WriteByte(0x37);
 	WriteByte(0x6F);

	WriteCommand(0xED);
	WriteByte(0x1B);
	WriteByte(0x0B);

	WriteCommand(0xAE);
	WriteByte(0x77);

	WriteCommand(0xCD);
	WriteByte(0x63);


	WriteCommand(0x70);
	WriteByte(0x07);
	WriteByte(0x07);
	WriteByte(0x04);
	WriteByte(0x0E);
	WriteByte(0x0F);
	WriteByte(0x09);
	WriteByte(0x07);
	WriteByte(0x08);
	WriteByte(0x03);

	WriteCommand(0xE8);
	WriteByte(0x34);

	WriteCommand(0x62);
	WriteByte(0x18);
	WriteByte(0x0D);
	WriteByte(0x71);
	WriteByte(0xED);
	WriteByte(0x70);
	WriteByte(0x70);
	WriteByte(0x18);
	WriteByte(0x0F);
	WriteByte(0x71);
	WriteByte(0xEF);
	WriteByte(0x70);
	WriteByte(0x70);

	WriteCommand(0x63);
	WriteByte(0x18);
	WriteByte(0x11);
	WriteByte(0x71);
	WriteByte(0xF1);
	WriteByte(0x70);
	WriteByte(0x70);
	WriteByte(0x18);
	WriteByte(0x13);
	WriteByte(0x71);
	WriteByte(0xF3);
	WriteByte(0x70);
	WriteByte(0x70);

	WriteCommand(0x64);
	WriteByte(0x28);
	WriteByte(0x29);
	WriteByte(0xF1);
	WriteByte(0x01);
	WriteByte(0xF1);
	WriteByte(0x00);
	WriteByte(0x07);

	WriteCommand(0x66);
	WriteByte(0x3C);
	WriteByte(0x00);
	WriteByte(0xCD);
	WriteByte(0x67);
	WriteByte(0x45);
	WriteByte(0x45);
	WriteByte(0x10);
	WriteByte(0x00);
	WriteByte(0x00);
	WriteByte(0x00);

	WriteCommand(0x67);
	WriteByte(0x00);
	WriteByte(0x3C);
	WriteByte(0x00);
	WriteByte(0x00);
	WriteByte(0x00);
	WriteByte(0x01);
	WriteByte(0x54);
	WriteByte(0x10);
	WriteByte(0x32);
	WriteByte(0x98);

	WriteCommand(0x74);
	WriteByte(0x10);
	WriteByte(0x85);
	WriteByte(0x80);
	WriteByte(0x00);
	WriteByte(0x00);
	WriteByte(0x4E);
	WriteByte(0x00);

  WriteCommand(0x98);
	WriteByte(0x3e);
	WriteByte(0x07);

	WriteCommand(0x35);
	WriteCommand(0x21);

	WriteCommand(0x11);
	HAL_Delay(120);
	WriteCommand(0x29);
	HAL_Delay(20);

	end_Write();
}

void Screen::LCDInit(Orientation_t _orientation)
{

    //Hardware reset
    Reset();

    //Set the initialization register
    InitReg(_orientation);
}

void Screen::SetWindows(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend)
{
    WriteCommand(0x2A);
    WriteByte(0x00);
    WriteByte(Xstart);
	WriteByte(0x00);
    WriteByte(Xend);

    //set the Y coordinates
    WriteCommand(0x2B);
    WriteByte(0x00);
	WriteByte(Ystart);
	WriteByte(0x00);
    WriteByte(Yend);
}

void Screen::Clear(uint16_t Color)
{
	while(isBusy);
	uint32_t len = LCD_1IN28_HEIGHT * LCD_1IN28_WIDTH;
	begin_Write();
	uint8_t bufferclear[2];
	bufferclear[0] = (Color >> 8) & 0xFF;
	bufferclear[1] = Color & 0xFF;

	SetWindows(0, 0, 239, 239);
	WriteCommand(0x2C);
	for (uint32_t i = 0; i < len; i++) {
	        WriteColor(bufferclear, 2);
	    }
	end_Write();
}

void Screen::SetBackLight(uint16_t Value)
{
	TIM3->CCR1 = Value;
}

void Screen::WriteFrameBuffer(uint16_t xStart,uint16_t yStart,uint16_t w, uint16_t h ,uint8_t *buffer,uint32_t len,bool _isAppend){

	isBusy=true;

	SetWindows(xStart,yStart ,w, h);

	_isAppend ?
	WriteCommand(0x3C):
	WriteCommand(0x2C);
	WriteData(buffer, len,true);
}

void Screen::WriteColor(uint8_t *Color,uint32_t len){


	WriteData(Color,len);

}

void Screen::WritePixel(uint16_t x, uint16_t y, uint16_t color){

	begin_Write();
	uint8_t *buffer = (uint8_t *)color;
	WriteCommand(0x2C);
	WriteData(buffer,2,false);
	end_Write();
}

void Screen::WriteImage(uint16_t _x, uint16_t _y, uint16_t width, uint16_t height, const unsigned char *image){
	for(uint16_t y =0;y < height ;y++){
		for (uint16_t x = 0; x < width;x++) {
			if(_x+x < 240  &&  _y+y < 240)
			{
				//uint16_t pixelColor = image[y * width + x];
				uint16_t pixelColor = (*(image + y*width*2 + x*2+1))<<8 | (*(image + y*width*2 + x*2));
				while(isBusy);
				WritePixel(_x + x,_y + y, pixelColor);
			}
		}
	}
}
