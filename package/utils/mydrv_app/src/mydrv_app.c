#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>

int main(int argc , char** argv)
{
	int fd;
	int num = 1;

	//打开驱动模块
	fd = open("dev/mydrv" , O_RDWR|O_NONBLOCK);
	if(fd < 0)
	{
		printf("can't open /dev/mydrv\n");
		return -1;
	}

	//函数测试
	write(fd,&num,1);
	read(fd,&num,1);
	ioctl(fd,1,1);
	close(fd);
	
	return 0;
}
