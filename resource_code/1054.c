/*
* 1054题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Islegal(char *in, float *num) {
    int i = 0;
    int dot_cnt = 0;
    int inlegal = 0;
    
    while (in[i] != '\0')
    {
        if (dot_cnt > 1) {
            inlegal = 1;
            break;
        }
        if (in[i] == '-' && i == 0) {
            i++;
            continue;
        }
        else if (in[i] == '.') dot_cnt++;
        else if (in[i] < '0' || in[i] > '9') {
            inlegal = 1;
            break;
        }
        i++;
    }

    float re = (float)atof(in);
    if (re < -1000 || re >1000)
        inlegal = 1;
    
    float tmp = (float)atof(in);
    tmp *= 1000;
    //printf("tmp = %f\n", tmp);
    if ((int)tmp % 10 != 0)
        inlegal = 1;
    if (inlegal == 1) {
        printf("ERROR: %s is not a legal number\n", in);
    }
    else *num = re;
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
    else {
        sum /= (float)K;
        printf("The average of %d numbers is %.2f\n", K, sum);
    }
    free(ouput);
    return 0;
}