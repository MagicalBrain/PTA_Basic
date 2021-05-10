# 【PAT Basic】1054 求平均值 (20 分)

## 题目描述

本题的基本要求非常简单：给定 N 个实数，计算它们的平均值。但复杂的是有些输入数据可能是非法的。一个“合法”的输入是 [−1000,1000] 区间内的实数，并且最多精确到小数点后 2 位。当你计算平均值的时候，不能把那些非法的数据算在内。

输入格式：
输入第一行给出正整数 N（≤100）。随后一行给出 N 个实数，数字间以一个空格分隔。

输出格式：
对每个非法输入，在一行中输出 ERROR: X is not a legal number，其中 X 是输入。
最后在一行中输出结果：The average of K numbers is Y，其中 K 是合法输入的个数，Y 是它们的平均值，精确到小数点后 2 位。
如果平均值无法计算，则用 Undefined 替换 Y。如果 K 为 1，则输出 The average of 1 number is Y。

输入样例 1：
```
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
```
输出样例 1：
```
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
```
输入样例 2：
```
2
aaa -9999
```
输出样例 2：
```
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined
```

## 基本思路

分析：
输入的“数字”不合法的情况有：
1. 小数点不止一个
2. 含有除数字以外的字符
3. 小数点后面有多于2位的数字

写一个函数来判断。

## 代码

### 测试用例

```
10
0 0.0 0.000 1000 -1000 1.123 1.12 1.2.3 a& 1.000
```

```
10
. 0.0 0.000 1000 -1000 1.123 1.12 1.2.3 a& 1.000
```

### 自己的代码

#### 不使用库函数，手动编码判断逻辑

```cpp
/*
* 1054题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Islegal(char *in, float *num) {
    int i = 0;
    int dot_cnt = 0;
    int dot_loc = 0;
    int inlegal = 0;
    
    //判断非法字符
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
        else if (in[i] == '.') {
            dot_cnt++;
            dot_loc = i;
            if (i == 0) {
                inlegal = 1;
                break;
            }
        }
        else if (in[i] < '0' || in[i] > '9') {
            inlegal = 1;
            break;
        }
        i++;
    }

    //判断数值范围
    float re = (float)atof(in);
    if (re < -1000 || re > 1000)
        inlegal = 1;
    
    //判断小数点后面不超过2位
    if (dot_loc > 0 && i - dot_loc > 3)
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
    else if (K == 1) 
        printf("The average of 1 number is %.2f\n", sum);
    else {
        sum /= (float)K;
        printf("The average of %d numbers is %.2f\n", K, sum);
    }
    free(ouput);
    return 0;
}
```

#### 使用库函数

使用了```sscanf```函数和```sprintf```函数

```cpp
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
```

### 柳婼的代码

极强的库函数运用能力。

```cpp
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int main() {
    int n, cnt = 0;
    char a[50], b[50];
    double temp = 0.0, sum = 0.0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%s", a);
        sscanf(a, "%lf", &temp);
        sprintf(b, "%.2f",temp);
        int flag = 0;
        for(int j = 0; j < strlen(a); j++)
            if(a[j] != b[j]) flag = 1;
        if(flag || temp < -1000 || temp > 1000) {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        } else {
            sum += temp;
            cnt++;
        }
    }
    if(cnt == 1)
        printf("The average of 1 number is %.2f", sum);
    else if(cnt > 1)
        printf("The average of %d numbers is %.2f", cnt, sum / cnt);
    else
        printf("The average of 0 numbers is Undefined");
    return 0;
}
```

## 总结
