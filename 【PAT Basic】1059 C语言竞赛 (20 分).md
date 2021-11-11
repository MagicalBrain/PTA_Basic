# 【PAT Basic】1059 C语言竞赛 (20 分)

## 题目描述

C 语言竞赛是浙江大学计算机学院主持的一个欢乐的竞赛。既然竞赛主旨是为了好玩，颁奖规则也就制定得很滑稽：

0、冠军将赢得一份“神秘大奖”（比如很巨大的一本学生研究论文集……）。
1、排名为素数的学生将赢得最好的奖品 —— 小黄人玩偶！
2、其他人将得到巧克力。

给定比赛的最终排名以及一系列参赛者的 ID，你要给出这些参赛者应该获得的奖品。

输入格式：
输入第一行给出一个正整数 N（$N \leqslant 10^4$ ），是参赛者人数。随后 N 行给出最终排名，每行按排名顺序给出一位参赛者的 ID（4 位数字组成）。接下来给出一个正整数 K 以及 K 个需要查询的 ID。

输出格式：
对每个要查询的 ID，在一行中输出 ID: 奖品，其中奖品或者是 Mystery Award（神秘大奖）、或者是 Minion（小黄人）、或者是 Chocolate（巧克力）。如果所查 ID 根本不在排名里，打印 Are you kidding?（耍我呢？）。如果该 ID 已经查过了（即奖品已经领过了），打印 ID: Checked（不能多吃多占）。

输入样例：
```bash
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222
```
结尾无空行

输出样例：

```bash
8888: Minion
0001: Chocolate
1111: Mystery Award
2222: Are you kidding?
8888: Checked
2222: Are you kidding?
```

## 基本思路

这个其实不难，根据输入顺序排序即可。

## 代码

```cpp
/*
* 1059题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 需要一个判断是否是素数的函数
int Is_premier(int num) {
    if (num < 2)
        return 0;
    if (num == 2)
        return 1;
    
    int tmp = 1;
    while (tmp * tmp < num) 
        tmp++;

    for (int i = 2; i <= tmp; i++)
    {
        if (num % i == 0)
            return 0;
    }
    
    return 1;
}

int main() {
    int n;  // ID的个数
    int k;  // 需要查询ID的个数

    int *ids;   // 用于存放ID的数组
    int *rewards; // 用于存放排名的数组
    
    scanf("%d", &n);
    ids = (int*) malloc (n * sizeof(int));
    rewards = (int*) malloc (n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &ids[i]);

        if (i == 0)
            rewards[i] = 0;
        else if (Is_premier(i + 1))
            rewards[i] = 1;
        else
            rewards[i] = 2;
    }

    scanf("%d", &k);
    int *check;
    check = (int*) malloc (k * sizeof(int));
    memset(check, 0, n * sizeof(int));
    for (int i = 0;i < k;i++)
    {
        int id;
        int finded = 0;
        scanf("%d", &id);
        //printf("ids[i]: %d\n", ids[i]);
        for (int j = 0; j < n; j++) {
            if (ids[j] == id) {
                if (check[j] == 0) {
                    if (rewards[j] == 0)
                        printf("%04d: Mystery Award\n", ids[j]); 
                    else if (rewards[j] == 1)
                        printf("%04d: Minion\n", ids[j]); 
                    else
                        printf("%04d: Chocolate\n", ids[j]); 
                    check[j] = 1;
                    finded++;
                }
                else {
                    printf("%04d: Checked\n", id);
                    finded++;
                }
            }
        }
        if (finded == 0) {
            if (i == k - 1)
                printf("%04d: Are you kidding?", id);
            else
                printf("%04d: Are you kidding?\n", id);
        }
        
    }

    free(ids);
    free(rewards);
    free(check);
    return 0;
}
```

## 总结

本来挺简单的一个题目，结果总是遇到**段错误**我就一脸懵逼了好吗。
