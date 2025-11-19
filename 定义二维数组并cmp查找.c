#include <stdio.h>
#include <string.h>
//查找字符串在字符串数组中的位置
//定义二维数组存储多个字符串"xxx"，
int main()
{
	char b[100];
	char a[7][10]= {
		"Sundy",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday"
	};
	printf("Please enter a string:\n");
	gets(b);
	for(int i = 0; i<7;i++){
		if(strcmp(b,a[i])==0){
			printf("%s is %d\n",b,i);
			return 0;
		}
	}
	printf("Not found!\n");


	return 0;
}