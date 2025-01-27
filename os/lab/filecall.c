#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int fd,fd2;
	char wbuf[128];
	char rbuf[128];
	fd=open("file.txt",O_RDWR);
	printf("Enter the text to be written\n");
	scanf("%s",wbuf);
	printf("writing to file\n");
	write(fd,wbuf,strlen(wbuf));
	close(fd);
	fd2=open("file.txt",O_RDWR);
	printf("File contents are\n");
	read(fd2,rbuf,128);
	printf("%s\n",rbuf);
	close(fd2);
	return 0;
}
