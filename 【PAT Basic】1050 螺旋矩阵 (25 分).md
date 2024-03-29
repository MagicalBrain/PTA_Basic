# 【PAT Basic】1050 螺旋矩阵 (25 分)

## 题目描述

本题要求将给定的 N 个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，是指从左上角第 1 个格子开始，按顺时针螺旋方向填充。要求矩阵的规模为 m 行 n 列，满足条件：m×n 等于 N；m≥n；且 m−n 取所有可能值中的最小值。

输入格式：
输入在第 1 行中给出一个正整数 N，第 2 行给出 N 个待填充的正整数。所有数字不超过 $10​^4$​​ ，相邻数字以空格分隔。

输出格式：
输出螺旋矩阵。每行 n 个数字，共 m 行。相邻数字以 1 个空格分隔，行末不得有多余空格。

输入样例：

```
12
37 76 20 98 76 42 53 95 60 81 58 93
```

输出样例：
```
98 95 93
42 37 81
53 20 76
58 60 76
```

## 基本思路

注意审题：给定的N个正整数按**非递增**的顺序排序

1. 找出符合题意的m和n
2. 将N个整数排序（快排）
3. 将排好序的数填充进去

关键在于螺旋矩阵的模拟填充，还是看代码吧。
我这里是借鉴了柳婼的代码。

## 代码

```cpp
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
```

## 总结

重点和难点在于螺旋矩阵的模拟
