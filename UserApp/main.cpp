#include "common_inc.h"
Screen LCD(&hspi1);
JPEGDEC mjpeg;
Avi avi;

uint8_t buffSdio[4608];
uint8_t buffSpi[4608];
int size = 0;
int sizeSpi = 0;
const uint16_t sizeA = 4096;
const uint16_t sizeB = 3584;
uint8_t bufferA[sizeA];
uint8_t bufferB[sizeB];

uint8_t select = 1;

const char *names[] = {"fe.avi","par.avi","mo.avi","de.avi","ab.avi","vde.avi","mo.avi"};

int DrawJpeg(JPEGDRAW *pfnDraw);

void jpeg(uint8_t *buffer,int length);

void Main()
{
	LCD.ModuleInit();
	LCD.SetBackLight(1000);
	LCD.LCDInit(Screen::DEGREE_0);
	LCD.Clear(BLACK);
	avi.Init();

	for(uint8_t i=0;i<8; i++)
	{
		avi.readMovi(names[i]);
		LCD.begin_Write();
		while(avi.getFrame(buffSdio, size)){
			sizeSpi = size;
			memcpy(buffSpi,buffSdio,sizeSpi);
			jpeg(buffSpi,sizeSpi);
			}
		LCD.end_Write();
		avi.Close();
	}
}

void jpeg(uint8_t *buffer,int length){
	if(mjpeg.openRAM(buffer,length, DrawJpeg))
	{
		mjpeg.setPixelType(RGB565_LITTLE_ENDIAN);
		mjpeg.decode(0, 0, 0);
	}
	mjpeg.close();
}

int DrawJpeg(JPEGDRAW *pfnDraw){
	//while (LCD.isBusy);
	uint16_t x = pfnDraw->x;
	uint16_t y = pfnDraw->y;
	uint16_t width = pfnDraw->iWidth;
	uint16_t height = pfnDraw->iHeight;
	uint32_t len = width * height * 2;

	uint8_t* activeBuffer = select ? bufferA : bufferB;
	uint16_t bufferSize = select ? sizeA : sizeB;

	uint32_t pixelsToTransfer = (len < bufferSize) ? len / 2 : bufferSize / 2;

	for (uint16_t i = 0; i < pixelsToTransfer; i++) {
		activeBuffer[i * 2] = (pfnDraw->pPixels[i] >> 8) & 0xFF;
	    activeBuffer[i * 2 + 1] = pfnDraw->pPixels[i] & 0xFF;
	    }

	select = (select == 0 ? 1 : 0); // ping pong buffer
	while (LCD.isBusy);
	LCD.WriteFrameBuffer(x, y, x + width-1, y + height-1, activeBuffer, bufferSize);

	return 1;
}

extern "C"
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi){
	LCD.isBusy = false;
}
