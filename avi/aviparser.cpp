#include "aviparser.h"


bool Avi::Init(){
	fresult = f_mount(&SDFatFS, SDPath, FA_READ);
	if(fresult == FR_OK){
		return true;
	}
	return false;
}

bool Avi::getFrame(uint8_t *_buffer,int &_length){
	UINT len;
	if(mMoviListLength == 0){
		return false;
	}
	ChunkHeader header;
	while(mMoviListLength > 0){
		offset = f_tell(&SDFile);
		readChunk(&header);
		if(strncmp(header.id,"00dc",4) == 0){
			fresult = f_read(&SDFile,_buffer,header.size,&len);
			_length = header.size;
			mMoviListLength -= header.size;

			if(header.size %2 != 0){
				offset = f_tell(&SDFile) + 1;
				mMoviListLength --;
				f_lseek(&SDFile, offset);
			}
			else{
				offset = f_tell(&SDFile);
				f_lseek(&SDFile, offset);
			}
			return true;
		}
		else if(header.size %2 !=0){
			offset = f_tell(&SDFile) + 1;
			f_lseek(&SDFile, offset);
			mMoviListLength -=header.size;
		}
		else{
			offset = f_tell(&SDFile);
			f_lseek(&SDFile, offset);
			mMoviListLength -=header.size;
		}
	}
	return false;

}

void Avi::readChunk(ChunkHeader *header){
		f_read(&SDFile,&header->id,4,&mybites);
		f_read(&SDFile,&header->size,4,&mybites);
}

bool Avi::isMoviList(uint32_t size){
	char type[4];
	f_read(&SDFile,type,4,&mybites);
	if(strncmp(type,"movi",4)==0){
		mMoviListPosition = f_tell(&SDFile);
		mMoviListLength = size;
		return true;
	}
	else{
		offset = f_tell(&SDFile) + size - 4;
		f_lseek(&SDFile, offset);
	}
	return false;
}

bool Avi::readMovi(const char *filename){
	ChunkHeader header;
	if(f_open(&SDFile,filename,FA_READ) == FR_OK){
		readChunk(&header);
		if(strncmp(header.id,"RIFF",4) != 0){
			return false;
		}
		char type[4];
		f_read(&SDFile,&type,4,&mybites);
		if(strncmp(type,"AVI ",4)!=0){
			return false;
		}

		while(!f_eof(&SDFile) && !f_error(&SDFile)){
			readChunk(&header);
			if(f_eof(&SDFile) || f_error(&SDFile)){
				break;
			}
			if(strncmp(header.id,"LIST",4)==0){
				if(isMoviList(header.size)){
					break;
				}
			}
			else{
				offset = f_tell(&SDFile) + header.size;
				f_lseek(&SDFile,offset);
			}
		}
		if(mMoviListLength == 0){
			return false;
		}
	}
	return true;
}

void Avi::Close()
{
	f_close(&SDFile);
}
