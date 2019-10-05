#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define way_file "/sys/class/backlight/intel_backlight/brightness"
#define SIZE 3

void reverse(char str[]){
     
     int i, j;
     char ch;
 
     for (i = 0, j = strlen(str)-1; i<j; i++, j--) {
         ch = str[i];
         str[i] = str[j];
         str[j] = ch;
     }
}

void itoa(int size, char str[]){
     	
	int i, sign;
 
     	if ((sign = size) < 0)  
         	size = -size;         
     	i = 0;
     	do {       
        	str[i++] = size % 10 + '0';   
     	} while ((size /= 10) > 0);     
     
	if (sign < 0)
        	 str[i++] = '-';
     	str[i] = '\0';
     	reverse(str);
}

int main(){
	
	const double  max_power=187.0, handred=100.0;
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
		fprintf (stderr, "myread: Cannot read file\n");
		exit (1);
	}

	close(fd);
	
	
	double power = atof(buff);	
	power=(handred/max_power)*power;
	printf("Яркость: %.0lf\n",round(power));
	
	
	double prosen;
	scanf("%lf",&prosen);
        
	char in[SIZE];	
	double in_pow=(max_power/handred)*prosen;
	int convert_int=(int)in_pow;
	itoa(convert_int,in);
	
	
	fd=open(way_file,O_WRONLY);
	
	if (fd < 0)
	{
		fprintf (stderr, "Cannot open file\n");
		exit (1);
	}

	write(fd,in,sizeof(in));

	close(fd);

	return 0;
}
