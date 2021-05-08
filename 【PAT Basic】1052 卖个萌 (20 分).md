# 【PAT Basic】1052 卖个萌 (20 分)

## 题目描述

萌萌哒表情符号通常由“手”、“眼”、“口”三个主要部分组成。简单起见，我们假设一个表情符号是按下列格式输出的：
```
[左手]([左眼][口][右眼])[右手]
```
现给出可选用的符号集合，请你按用户的要求输出表情。

输入格式：
输入首先在前三行顺序对应给出手、眼、口的可选符号集。每个符号括在一对方括号 []内。题目保证每个集合都至少有一个符号，并不超过 10 个符号；每个符号包含 1 到 4 个非空字符。

之后一行给出一个正整数 K，为用户请求的个数。随后 K 行，每行给出一个用户的符号选择，顺序为左手、左眼、口、右眼、右手——这里只给出符号在相应集合中的序号（从 1 开始），数字间以空格分隔。

输出格式：
对每个用户请求，在一行中输出生成的表情。若用户选择的序号不存在，则输出 Are you kidding me? @\/@。

输入样例：
```
[╮][╭][o][~\][/~]  [<][>]
[╯][╰][^][-][=][>][<][@][⊙]
[Д][▽][_][ε][^]  ...

4
1 1 2 2 2
6 8 1 5 5
3 3 4 3 3
2 10 3 9 3
```

输出样例：
```
╮(╯▽╰)╭
<(@Д=)/~
o(^ε^)o
Are you kidding me? @\/@
```

## 基本思路

符号集有3行，考虑用三个字符串来分别存储一个字符集。然后用个函数来查找对应的符号。

## 代码

```cpp
/*
* 1052题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(char *set, int id, char *re) {
    if (id <= 0)
        return 0;
    int i = 0, cnt = 0;
    while (set[i] != '\0')
    {
        if (cnt == id) break;
        if (set[i] == '[')  cnt++;
        i++;
    }
    if (set[i] == '\0')
    {
        return 0;
    }
    int j = 0;
    while (set[i] != ']')
    {
        re[j] = set[i];
        i++, j++; 
    }
    re[j] = '\0';
    
    return 1;
}

int main() {
    //定义符号集的存储字符串
    //一个符号集不超过10个符号，每个符号不超过4个字符
    char hand[100];
    char eye[100];
    char mouth[100];

    gets(hand);
    gets(eye);
    gets(mouth);

    char *symbol1, *symbol2, *symbol3, *symbol4, *symbol5;
    symbol1 = (char*) malloc(10 * sizeof(char));
    symbol2 = (char*) malloc(10 * sizeof(char));
    symbol3 = (char*) malloc(10 * sizeof(char));
    symbol4 = (char*) malloc(10 * sizeof(char));
    symbol5 = (char*) malloc(10 * sizeof(char));
    

    int K;
    scanf("%d", &K);

    int id[5] = {0};
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &id[j]);
        }   
        
        if (find(hand, id[0], symbol1) == 0)
        {  
            printf("Are you kidding me? @\\/@\n");
            continue;
        }
        if (find(eye, id[1], symbol2) == 0)
        {  
            printf("Are you kidding me? @\\/@\n");
            continue;
        }
        if (find(mouth, id[2], symbol3) == 0)
        {  
            printf("Are you kidding me? @\\/@\n");
            continue;
        }
        if (find(eye, id[3], symbol4) == 0)
        {  
            printf("Are you kidding me? @\\/@\n");
            continue;
        }
        if (find(hand, id[4], symbol5) == 0)
        {  
            printf("Are you kidding me? @\\/@\n");
            continue;
        }
        printf("%s(%s%s%s)%s\n", symbol1, symbol2, symbol3, symbol4, symbol5);
    }
    
    free(symbol1);
    free(symbol2);
    free(symbol3);
    free(symbol4);
    free(symbol5);
    
    return 0;
}
```

## 总结

要注意的是，三个测试点各有千秋。

测试点1：输入的字符集里有空格
测试点2：验证输入的字符序号是否合法（是否为正数）
测试点3：检查字符数组是否会越界
