#include <stdio.h>

int main()
{
    int arr[5];
    int tem = 0;
    int min = 0;
    int i = 0;
    int id = 0;
    for (i = 0; i <= 4; i++)
    {
        printf("Enter No.%2d:", i + 1);
        scanf("%d", &arr[i]);
        for (id = i; id > 0; id--)
        {
            if (arr[id] < arr[id - 1])
            {
                tem = arr[id];
                arr[id] = arr[id - 1];
                arr[id - 1] = tem;
            }
            else break;
        }
    }


    for (i = 0; i <= 4; i++)
    {
        printf("%d", arr[i]);
    }


    return 0;
}
