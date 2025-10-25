#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	while(1)
	{
	scanf("%d",&a);
	c = a;
	if (a<=0){
		printf("fault!\nplease give an avilible num\n");
		continue;
	}else {
		for (b=1;c>=10;b*=10){
			c/=10;
		}
		for (;b>=1;b/=10){
			printf("%d",a / b);
			if (b>=10){
				 printf("  ");
			};
			a%=b;
		}	
	}
}
	return 0;
}
