#include<stdio.h>
int main()
{
	int ori = 0;
	int fin = 0;
	scanf("%d",&ori);
	fin = ori%10*100 + ori%100/10*10 + ori/100;
	
	printf("%d\n",fin);
	
	return 0;
}
