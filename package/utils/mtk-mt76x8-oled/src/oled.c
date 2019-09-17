#include "string.h"
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include "hal_oled.h"
#include <linux/i2c-dev.h>

int main(int argc,char **argv)
{
	int fd = -1;
	if(argc < 2)
	{
		printf("error: no found i2c device\n");
		return -1;
	}
	
	fd = open(argv[1],O_RDWR);
	
	if(fd < 0)
	{
		perror("error\n");
		return -1;
	}else
	{
		
		printf("success i2c device:%s,addr:0x%x\n",argv[1],I2C_OLED_ADDR);
		
			if(argc ==3)
			{
				printf("call ss1306SetMirror(1) \n");
		ss1306SetMirror(1);
			}
	else
	{
		printf("call ss1306SetMirror(0) \n");
		ss1306SetMirror(0);
	}
	}
	
	
	
	ioctl(fd,I2C_SLAVE,I2C_OLED_ADDR);
	HalOledInit(fd);
	HalOledShowString(0,0,"MOKO TECH",HAL_OLED_FONT_TYPE_SIZE_24);
    HalOledShowString(0,24, "0.96' OLED 16*8",HAL_OLED_FONT_TYPE_SIZE_16);  
 	HalOledShowString(0,40,"iic ssd1306",HAL_OLED_FONT_TYPE_SIZE_12);  
 	HalOledShowString(0,52,"ASCII:12*6",HAL_OLED_FONT_TYPE_SIZE_12);  
 	HalOledShowString(64,52,"CODE:12*6",HAL_OLED_FONT_TYPE_SIZE_12);  
    HalOledRefreshGram();
	close(fd);
}


