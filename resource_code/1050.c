/*
* 1050题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* A, const void* B) {
    int a = *(int*) A;
    int b = *(int*) B;
    return a > b;
}

int main() {
    int N;
    int *data;
    scanf("%d", &N);
    data = (int*) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", &data[i]);
    
    //排序：
    qsort(data, N, sizeof(int), cmp);

    //寻找符合题意的m和n

    //填充数进矩阵
    
    return 0;
}