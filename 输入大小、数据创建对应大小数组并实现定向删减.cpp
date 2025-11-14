#include <stdio.h>

int Del(int a[], int account, int n);
int main()
{
    int i, n, account = 0;
    printf("请输入户数"); 
	scanf("%d", &n);
    if (n < 5 || n > 300)
    {
        printf("户数应多于5户且小于300户\n\t程序终止");
		return -1;
    }
    else
    {
        int a[n];
        for (i = 0; i < n; i++)
        {
            printf("请输入第%d户数据",i+1);
			scanf("%d", &a[i]);
        }
        printf("请输入要删除户的数据");
		scanf("%d", &account);
        Del(a, account, n);
    }
	return 0;}
    Del(int a[], int account, int n)
    {
        int i, tem = 0;
        for (i = 0; i < n; i++)
        {
            if (account == a[i])
            {
                tem = a[i];
                a[i] = a[n-1];
                a[n-1] = tem;
				for(;i<n-2;i++){
					tem = a[i];
					a[i] = a[i+1];
					a[i+1]=tem; 
				}
                for (i = 0; i < n - 1; i++)
                {
                    printf("%d ", a[i]);
                }
                return n - 1;
            }

        }
        printf("Error value!");
        return -1;
    }
