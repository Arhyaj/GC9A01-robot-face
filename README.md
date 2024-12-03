I made robot face with micro-SD ! 
I used the board stm32f407vet6 the blue one, I used jpegdec to decode the video frame by frame, if you want to charge your own face you should try to reduce first the fps and quality this is my paremeters that i used 
"ffmpeg -i D:\path of the source.mp4 -vf "scale=240:240" -r 30 -c:v mjpeg -an -q:v 10 D:\path of where it will save it.avi" you should try new parameters if you want. 
The screen is LCD GC9A01.

![image](https://github.com/user-attachments/assets/e48da6f8-cdb0-41f7-8447-7f14f7e89342)

![image](https://github.com/user-attachments/assets/f4cee9bd-5d63-4df8-b6eb-38bb66c8bf92)
