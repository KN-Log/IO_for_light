#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define way_file "/sys/class/power_supply/BAT1/capacity"
#define SIZE 3


int main(){
	
	char buff[SIZE];
	ssize_t read_bytes=0;	

	int fd=open(way_file,O_RDONLY);	
	
	if (fd < 0)
	{
		fprintf (stderr, "Cannot open file\n");
		exit (1);
	}	

	while ((read_bytes = read (fd, buff, 5)) > 0)
	{
		buff[read_bytes] = 0;
	}	
	
	if (read_bytes < 0)
	{
		fprintf (stderr, "Cannot read file\n");
		exit (1);
	}

	close(fd);
	
	
	printf("Заряд: %s",buff);
	

	return 0;
}
