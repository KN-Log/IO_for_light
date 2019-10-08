#include <stdio.h>
#include <unistd.h>

int main(){
	
	char buf[100];

	if(gethostname(buf,sizeof(buf)) < 0){
		return 1;
	}	
	printf("Имя Пользователя: %s\n",buf);
	return 0;
}
