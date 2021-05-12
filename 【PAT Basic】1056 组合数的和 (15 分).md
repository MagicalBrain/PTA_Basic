# 【PAT Basic】1056 组合数的和 (15 分)

## 题目描述

给定 N 个非 0 的个位数字，用其中任意 2 个数字都可以组合成 1 个 2 位的数字。要求所有可能组合出来的 2 位数字的和。例如给定 2、5、8，则可以组合出：25、28、52、58、82、85，它们的和为330。

输入格式：
输入在一行中先给出 N（1 < N < 10），随后给出 N 个不同的非 0 个位数字。数字间以空格分隔。

输出格式：
输出所有可能组合出来的2位数字的和。

输入样例：
3 2 8 5
输出样例：
330

## 基本思路

一个简单的思路：
每个数字乘以十乘以$N - 1$倍，再加$N - 1$倍自身即可。

## 代码

```cpp
/*
* 1056题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    int sum = 0;
    scanf("%d", &N);

    int *nums = (int*) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &nums[i]);
        sum += nums[i] * 10 * (N - 1);
        sum += nums[i] * (N - 1);
    }
    
    free(nums);

    printf("%d\n", sum);
    return 0;
}
```

## 总结

没啥难度，找到规律超简单。
