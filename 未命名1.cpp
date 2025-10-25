#include <stdio.h>
int main(){
	int as=0;
	int s=0;
	int casenum=0;
	scanf("%d:%d",&as,&s);
	as+=2;
	s+=15;
	if(s>=60){
		s-=60;
		as+=1;
	}
    if(as>=24){
		as-=24;
	}
	if(s==0){
		casenum=1;
	}
	if(as==0){
		casenum==2;
	}
	if(s==0 and as==0){
			casenum=3;}
	switch (casenum){
		case 0:
		    printf ("到达时间：%d:%d",as,s);
		    break;
		case 1:
			printf ("到达时间：%d:00",as);
			break;
		case 2:
			printf ("到达时间：00:%d",s);
		case 3:
			printf ("到达时间：00:00");
	}
	return 0;
}
