# 【PAT Basic】1047 编程团体赛 (20 分)

## 题目描述

编程团体赛的规则为：每个参赛队由若干队员组成；所有队员独立比赛；参赛队的成绩为所有队员的成绩和；成绩最高的队获胜。

现给定所有队员的比赛成绩，请你编写程序找出冠军队。

输入格式：
输入第一行给出一个正整数 N（$\leqslant 10​^4$​​ ），即所有参赛队员总数。随后 N 行，每行给出一位队员的成绩，
格式为：队伍编号-队员编号 成绩，其中
队伍编号为 1 到 1000 的正整数，
队员编号为 1 到 10 的正整数，成绩为 0 到 100 的整数。

输出格式：
在一行中输出冠军队的编号和总成绩，其间以一个空格分隔。
注意：题目保证冠军队是唯一的。

输入样例：
```
6
3-10 99
11-5 87
102-1 0
102-3 100
11-9 89
3-2 61
```

输出样例：
```
11 176
```

## 基本思路

题目比较简单，直接用个1001长的数组累加就好了。

## 代码实现

```cpp
/*
* 1047题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, max_id = 0, max_score = 0;
    int champion_id;
    int sum[1001] = {0};

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int team_id, member_id, grade;
        scanf("%d-%d %d", &team_id, &member_id, &grade);
        if (max_id < team_id)  max_id = team_id;
        sum[team_id] += grade;
    }
    
    for (int i = 1; i <= max_id; i++)
    {
        if (max_score < sum[i]) {
            max_score = sum[i];
            champion_id = i;
        }
    }
    printf("%d %d\n", champion_id, max_score);
    return 0;
}
```

## 总结
