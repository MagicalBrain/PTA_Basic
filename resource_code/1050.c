/*
* 1050题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* A, const void* B) {
    int a = *(int*) A;
    int b = *(int*) B;
    return a < b;
}

int main() {
    int N, m, n;
    int *data;
    scanf("%d", &N);
    data = (int*) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", &data[i]);
    
    //排序：
    qsort(data, N, sizeof(int), cmp);
    //检查排序结果
    //for (int i = 0; i < N; i++)
    //    printf("%d ", data[i]);
    

    //寻找符合题意的m和n
    int i = 1;
    for (; i * i < N; i++) ;
    m = n = i;
    //printf("%d %d\n", m, n);

    while (m * n != N)
    {
        if (m * n > N)
            n--;
        else m++;
        if (m <= n)
            m++;
    }
    //printf("%d %d\n", m, n);

    //根据m，n来分配内存
    int **mat = (int**) malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
        mat[i] = (int*) malloc(n * sizeof(int));
    

    //填充数进矩阵
    int top = 0;
    int level = m / 2 + m % 2;  //计算要螺旋几层（由外到内的）
    for (int i = 0; i < level; i++) {
        for (int j = i; j <= n - 1 - i && top <= N - 1; j++)
                mat[i][j] = data[top++];
        for (int j = i + 1; j <= m - 2 - i && top <= N - 1; j++)
                mat[j][n - 1 - i] = data[top++];
        for (int j = n - i - 1; j >= i && top <= N - 1; j--)
                mat[m - 1 - i][j] = data[top++];
        for (int j = m - 2 - i; j >= i + 1 && top <= N - 1; j--)
                mat[j][i] = data[top++];
    }

    //打印螺旋矩阵
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i == 0 && j > 0)
                printf("\n%d", mat[j][i]);
            else if (i == 0)
                printf("%d", mat[j][i]);
            else 
                printf(" %d", mat[j][i]);
        }
    }
    
    //销毁内存
    for (int i = 0; i < m; i++)
        free(mat[i]);
    free(mat);
    return 0;
}