/*
* 1053题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, D;
    double e;
    int maybe_empty = 0, empty = 0;

    scanf("%d%lf%d", &N, &e, &D);

    for (int i = 0; i < N; i++)
    {
        int K;
        int day_e = 0;
        scanf("%d", &K);

        int flag_e = K / 2;

        for (int j = 0; j < K; j++)
        {
            double num;
            scanf("%lf", &num);
            if (num < e)    day_e++;
        }
    
        if (day_e > flag_e && K > D)     empty++;
        else if (day_e > flag_e)  maybe_empty++;
    }
    
    double maybe_precent = (double) maybe_empty / (double)N;
    double empty_precent = (double) empty / (double)N;
    printf("%.1f%% ", maybe_precent * 100);
    printf("%.1f%%\n", empty_precent * 100);
    return 0;
}