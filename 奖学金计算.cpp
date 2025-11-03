#include <stdio.h>
int main (){
    float mon = 0.00;
    double score = 0.00;
    scanf ("%lf",&score);
    double typ = score/10.00;
    int type = typ;
    switch (type){
        case 7: mon =(score - 70)*8;
        break;
        case 8: mon =(score -80)*11+10*8;
        break;
        case 9: if(score>95){
            mon =score*15;
        }else mon =(score - 90)*15+10*8+10*11;
        break;
        case 10:mon = 1500;
        break;
        default:mon =0.00;
        break; 

    }
    printf("%.2lf\n",mon);

        
    
    
    


    return 0;
}
