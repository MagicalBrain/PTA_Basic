# 【PAT Basic】1048 数字加密 (20 分)

## 题目描述

本题要求实现一种数字加密方法。首先固定一个加密用正整数 A，对任一正整数 B，将其每 1 位数字与 A 的对应位置上的数字进行以下运算：
对奇数位，对应位的数字相加后对 13 取余——这里用 J 代表 10、Q 代表 11、K 代表 12；
对偶数位，用 B 的数字减去 A 的数字，若结果为负数，则再加 10。这里令个位为第 1 位。

输入格式：
输入在一行中依次给出 A 和 B，均为不超过 100 位的正整数，其间以空格分隔。

输出格式：
在一行中输出加密后的结果。

输入样例：

```
1234567 368782971
```

输出样例：

```
3695Q8118
```

## 基本思路

思路其实不难，但是a,b长度不一致的情况考虑不够周全。

## 代码实现

```cpp
/*
* 1048题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char num1[101];
    char num2[101];
    char *re = NULL;

    scanf("%s %s", num1, num2);

    int len1, len2, min, max;
    len1 = strlen(num1), len2 = strlen(num2);

    if (len1 > len2) {
        min = len2;
        max = len1;
        re = num1;
    }else {
        min = len1;
        max = len2;
        re = num2;
    }

    int i = 1;
    while (i <= min)
    {
        //奇数位的处理
        if (i % 2 != 0) {
            int t = (num1[--len1] - '0') + (num2[--len2] - '0');
            t = t % 13;
            if (t == 10)    re[max - i] = 'J';
            else if (t == 11) re[max - i] = 'Q';
            else if (t == 12) re[max - i] = 'K';
            else re[max - i] = '0' + t;
        }
        //偶数位的处理
        else {
            int t = num2[--len2] - num1[--len1];
            if (t < 0)  t += 10;
            re[max - i] = '0' + t;
        }
        i++;
    }
    while (i <= max) {
        if (re == num1 && i % 2 == 0) {
            int t = re[max - i] - '0';
            if (t == 0)
                re[max - i] = '0';
            else
            re[max - i] = '0' + 10 - t;
        }
        i++;
    }
    puts(re);
    return 0;
}
```

### 测试数据

测试了几组数据，发现出错的数据为：

a、b
```
6666
666
```

a、b
```
6666666666
6
```

## 总结

测试程序之前先要想想有哪些特殊情况，分别设计一个测试用例再测试。
