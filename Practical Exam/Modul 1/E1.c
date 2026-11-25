#include <stdio.h>

int main ()
{
    int vip, minutes, totalfee = 0;
    scanf ("%d %d", &minutes, &vip);

    int hours = (minutes + 59) / 60;

    if (hours == 1){
        totalfee = 3000;
    }
    else{
        totalfee = 3000 + (hours - 1) * 2000;
    }

    if (totalfee > 25000){
        totalfee = 25000;
    }
    else{
        totalfee = totalfee;
    }

    if (vip == 1){
        totalfee = totalfee + 1000;
    }
    else{
        totalfee = totalfee;
    }

    printf("%d\n", totalfee);

    return 0;
}

