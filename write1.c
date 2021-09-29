// Write function from User space for 1st device

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	int fd;
	char write_buf1[] = "Hello kernel, This is user buffer of dev1";
	fd = open("/dev/mycdev1",O_RDWR);
	if(fd < 0)
	{
		printf("Unable to open the file\n");
		return (-1);
	}
       
        write(fd,write_buf1, sizeof(write_buf1));
	close(fd);
	return 0;	
}
