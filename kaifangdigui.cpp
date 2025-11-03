#include <stdio.h>
#include <math.h>
double g = 0;
void digui (int r, double h)
{
    if (r == 0)
    {   
        printf("y=%.2f", g);
        return;
    }
    g = sqrt(g + h);
    digui(r-1, h);
}
int main()
{
    int x=0;
    double n=0;
    printf("«Î ‰»Îx,n:\n");
    scanf("%lf,%d", &n, &x);
    digui(x, n);
    return 0;
}
