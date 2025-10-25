#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int a = 0;
	srand (time(0));
	int R = rand();
	int r = R%10;
	int c = 0;
	c++;
	printf("give pls\n");
	while (scanf("%d",&a),a!=r){
		if (a<=r){printf("less\n");
		}else printf("more\n");
		c++;
	}
	printf("congratulation! just%dtimes",c);
	
	return 0;
}
