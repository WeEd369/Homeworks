#include <stdio.h>
void Str_insert (int p[], int x){
    int a[5] = {1,3,6,7,9};
	int i,insert=0;
	for(i=0;i<5;i++){
		if(i==4 && !insert){
			p[5] = x;
			p[4] = a[4];
			return ;
		}else{
		if(a[i]>x){
			if(!insert){
			p[i]=x;
			p[i+1]=a[i];
			insert = 1;
			}else p[i+1]=a[i];
		}else{
			p[i]=a[i];
		}
	}
	}
	return ;
}
int main()
{
	int x;
	int p[6];
	printf("insert data:");
	scanf("%d",&x);
	Str_insert(p,x);
	printf("Now array a:\n");
	for(x=0;x<6;x++){
		printf("%4d",p[x]);
	}


	return 0;
}
