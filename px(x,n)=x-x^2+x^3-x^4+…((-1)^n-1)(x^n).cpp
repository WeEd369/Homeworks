/*
请用递归的方法计算下列函数的值：px(x,n)=x-x^2+x^3-x^4+…((-1)^n-1)(x^n)  n>0
**输入格式要求："%lf%d" 提示信息："Enter X and N:"
**输出格式要求："px=%lf\n"
程序运行示例如下：
Enter X and N:4 6
px=-3276.000000                            //而小盘：定义递归函数，定义放外面 
*/
#include <stdio.h>
double X=0;
int er=-1;
double xx=1;
void px(double x,int n){
        if(n==0){
        	printf("px=%lf\n",X);
            return;
		}
    er*=(-1);
    xx*=x;
    X+=er*xx;
    px(x,n-1);
    }
int main(){
    int n;
    double x;
	scanf("%lf,%d",&x,&n);
	px(x,n);
    return 0;
}

