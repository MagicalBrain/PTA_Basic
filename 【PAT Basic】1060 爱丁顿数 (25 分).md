# 【PAT Basic】1060 爱丁顿数 (25 分)

## 题目描述

英国天文学家爱丁顿很喜欢骑车。据说他为了炫耀自己的骑车功力，还定义了一个“爱丁顿数” E ，即满足有 E 天骑车超过 E 英里的最大整数 E。据说爱丁顿自己的 E 等于87。

现给定某人 N 天的骑车距离，请你算出对应的爱丁顿数 $E \leqslant N$。

输入格式：
输入第一行给出一个正整数 $N \leqslant 10^5$，即连续骑车的天数；第二行给出 N 个非负整数，代表每天的骑车距离。

输出格式：
在一行中给出 N 天的爱丁顿数。

输入样例：
```bash
10
6 7 6 9 3 10 8 2 7 8
结尾无空行
```

输出样例：
```bash
6
结尾无空行
```

## 基本思路

是否会存在多个爱丁顿数呢？

假设有满足爱丁顿数条件的有$n1 ,n2$且$n2 > n1$，则该集合里有：
1. $n2$个大于$n2$的数
2. $n1$个大于$n1$的数

$\because n2 > n1$ 
$\therefore$ 有$n2 + n1$个数大于$n1$
$\therefore n1$ 就不是爱丁顿数 

## 代码

### 测试数据

换一下数据试试

```bash
10
7 7 6 9 3 10 8 2 7 8
# 输出 0
```

思考一下边界条件

```bash
1
0
# 输出 0
```

```bash
6
7 7 7 7 7 7
# 输出 6
```

```bash
3
1 2 3
# 输出 0
```

```bash
3
2 3 4
# 输出 2
```


### 柳婼的代码

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
int a[1000000];
bool cmp1(int a, int b) {
    return a > b;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a+1, a+n+1, cmp1);
    int ans = 0, p = 1;
    while(ans <= n && a[p] > p) {
        ans++;
        p++;
    }
    printf("%d", ans);
    return 0;
}
```

### 我自己的代码

```cpp
/*
* 1060题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;      // 输入天数
    int *days;  // 存储每日骑车的里程
    int max = 0;    // 最大值
    int len;
    int *nums, *total;

    scanf("%d", &n);

    days = (int*) malloc (n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &days[i]);
        if (i == 0)
            len = days[i];
        else {
            if (days[i] > len)
                len = days[i];
        }
    }

    if (len != 0) {
        nums = (int*) malloc (len * sizeof(int));
        memset(nums, 0, len * sizeof(int));
        for(int i = 0; i < n; i++) {
            if (days[i] == 0)
                continue;
            nums[days[i] - 1]++;
        }

        total = (int*) malloc (len * sizeof(int));
        memset(total, 0, len * sizeof(int));
        int sum = 0;
        for(int i = len - 1; i >= 0; i--) { 
            total[i] = sum;
            //printf("%d %d\n", i + 1, total[i]);
            if (total[i] >= i + 1) {
                max = i + 1;
                break;
            }
            sum += nums[i];
        }
    }
    
    printf("%d", max);
    return 0;
}
```

## 总结

这个题不难，难在读题啊

最大 => ```>=```
