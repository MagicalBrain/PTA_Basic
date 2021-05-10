/*
* 1054题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Islegal(char *in, float *num) {
    double temp;
    char t[50];
    int inlegal = 0;

    sscanf(in, "%lf", &temp);
    sprintf(t, "%.2f", temp);
    //比较原始输入in字符串和格式化结果t字符串
    for (int i = 0; in[i] != '\0'; i++)
    {
        if (in[i] != t[i]) {
            inlegal = 1;
            break;
        }
    }
    
    if (temp < -1000 || temp > 1000)    inlegal = 1;
    if (inlegal == 1) {
        printf("ERROR: %s is not a legal number\n", in);
    }
    else *num = (float)temp;
}

int main() {
    int K, K_cp;
    char input[50];
    float sum = 0.0;
    float *ouput = (float*) malloc(sizeof(float));
    

    scanf("%d", &K);

    K_cp = K;
    for (int i = 0; i < K_cp; i++)
    {
        *ouput = -1001;
        scanf("%s", input);
        Islegal(input, ouput);
        if (-1001 != *ouput)   sum += *ouput;
        else K--;
        //printf("%f\n", *ouput);
    }
    if (K == 0)
        printf("The average of 0 numbers is Undefined");
    else if (K == 1) 
        printf("The average of 1 number is %.2f\n", sum);
    else {
        sum /= (float)K;
        printf("The average of %d numbers is %.2f\n", K, sum);
    }
    free(ouput);
    return 0;
}