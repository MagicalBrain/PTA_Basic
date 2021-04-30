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
    {
        scanf("%lf", &data[i]);
        //sum += data[i];
    }
    
    for (int i = 0; i < num; i++)
    {
        long long t = (num - i) * (i + 1) * (long long)(data[i] * 1000);
        sum += t;
        
    }
    
    
    printf("%.2lf\n", sum / 1000.0);
    free(data);
    return 0;
}