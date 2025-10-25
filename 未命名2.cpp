#include <stdio.h>
int main(){
	int starth = 0;
	int startm = 0;
	int final = 0;
	int fh = 0;
	int fm = 0;
	int casenum = 0;
	printf("请输入起始时间：");
	scanf("%d:%d",&starth,&startm);
	final = starth*60+startm+135;
	fh=final/60;
	fm=final%60;
	if (fh>=24){
		fh-=24;
	}
	if(fm==0){
		casenum=1;
	}
	if(fh==0){
		casenum==2;
	}
	if(fh==0 and fm==0){
			casenum=3;}
	switch (casenum){
		case 0:
		    printf ("到达时间：%d:%d",fh,fm);
		    break;
		case 1:
			printf ("到达时间：%d:00",fh);
			break;
		case 2:
			printf ("到达时间：00:%d",fm);
		case 3:
			printf ("到达时间：00:00");
	}
	return 0;
}
