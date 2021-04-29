/*
* 1049题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num;
    double *data;
    double sum = 0.0;
    scanf("%d", &num);

    data = (double*) malloc(num * sizeof(double));
    for (int i = 0; i < num; i++)
    {
        scanf("%lf", &data[i]);
        //sum += data[i];
    }
    
    for (int i = 0; i < num; i++)
    {
        int t = (num - i) * (i + 1);
        sum += t * data[i];
        
    }
    
    
    printf("%.2lf\n", sum);
    free(data);
    return 0;
}