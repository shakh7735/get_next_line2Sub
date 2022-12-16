#include "get_next_line.h"

int main()
{
	int fd1;
	int fd2;
	int fd3;
	int i;

    i = 0;
    fd1 = open("normal.txt", O_RDONLY);
    fd2 = open("normal.txt", O_RDONLY);
    fd3 = open("normal.txt", O_RDONLY);
	while (i++ < 10)
	{
	    printf("fd = %d %s", fd1, get_next_line(fd1));
	    //printf("fd = %d %s", fd2, get_next_line(fd2));
	    //printf("fd = %d %s", fd3, get_next_line(fd3));
	}
	close (fd1);
    close (fd2);
    close (fd3);
    return 0;
}
