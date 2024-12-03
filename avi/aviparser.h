#ifndef _AVI_PARSER_H_
#define _AVI_PARSER_H_

#include "stdint.h"
#include "fatfs.h"
#include "string.h"
#include "stdlib.h"

class Avi
{
private:

	FRESULT fresult;
	UINT mybites;

	typedef struct {
		char id[4];
		int size;
	}ChunkHeader;


	int mMoviListPosition= 0;
	int mMoviListLength = 0;
	int offset = 0;
	//uint8_t *buffer;

	void readChunk(ChunkHeader *header);

public:
	Avi() = default;
	bool Init();
	bool readMovi(const char *filename);
	bool getFrame(uint8_t *_buffer,int &lenght);

	bool isMoviList(uint32_t size);
	void Close();
};



#endif
