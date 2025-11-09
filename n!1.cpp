#include<stdio.h>
int main(){
	unsigned long long n,N= 1;
	scanf("%d",&n);
	while(n>0){
		N*=n;
		n-=1;
	}
	printf("%d",N);
	return 0;
}
