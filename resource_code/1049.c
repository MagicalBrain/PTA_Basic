/*
* 1049题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num;
    double *data;
    long long sum = 0;
    scanf("%d", &num);

    data = (double*) malloc(num * sizeof(double));
    for (int i = 0; i < num; i++)
        scanf("%lf", &data[i]);
    
    for (int i = 0; i < num; i++)
    {
        long long t = (long long)(num - i) * (i + 1) * (data[i] * 1000);
        sum += t;
        
    }
    
    printf("%.2f\n", sum / 1000.0);
    return 0;
}