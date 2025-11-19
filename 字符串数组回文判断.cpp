#include <stdio.h>
#include <string.h>

void Be(char str[]){
	int i = 0;
	int a = strlen(str);
	while(i<a/2){
		if(str[i] != str[a-i-1]){
			printf("NO!\n");
			return;
		}
		i++;
		}
	printf("YES!\n");
	}

int main()
{
	char str[80];
	printf("Input a string:");
	fgets(str, 80, stdin);
    str[strcspn(str, "\n")] = '\0';
	Be(str);


	return 0;
}