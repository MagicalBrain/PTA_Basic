# 【PAT Basic】1058 选择题 (20 分)

## 题目描述

批改多选题是比较麻烦的事情，本题就请你写个程序帮助老师批改多选题，并且指出哪道题错的人最多。

输入格式：
输入在第一行给出两个正整数 N（≤ 1000）和 M（≤ 100），分别是学生人数和多选题的个数。随后 M 行，每行顺次给出一道题的满分值（不超过 5 的正整数）、选项个数（不少于 2 且不超过 5 的正整数）、正确选项个数（不超过选项个数的正整数）、所有正确选项。注意每题的选项从小写英文字母 a 开始顺次排列。各项间以 1 个空格分隔。最后 N 行，每行给出一个学生的答题情况，其每题答案格式为 (选中的选项个数 选项1 ……)，按题目顺序给出。注意：题目保证学生的答题情况是合法的，即不存在选中的选项数超过实际选项数的情况。

输出格式：
按照输入的顺序给出每个学生的得分，每个分数占一行。注意判题时只有选择全部正确才能得到该题的分数。最后一行输出错得最多的题目的错误次数和编号（题目按照输入的顺序从 1 开始编号）。如果有并列，则按编号递增顺序输出。数字间用空格分隔，行首尾不得有多余空格。如果所有题目都没有人错，则在最后一行输出 Too simple。

输入样例：
```
3 4 
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (2 b d) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (2 b c) (4 a b c d)
```

输出样例：
```
3
6
5
2 2 3 4
```

## 基本思路

数据稍微有点复杂，用面向对象编程的思路会简单一点。

## 代码

```cpp
/*
* 1058题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct problem_ans{
    int id;
    int score;
    int choose_num;
    int correct_ans;
    char ans[6];
    int wrong;
}problem_ans;

typedef struct stu_ans{
    int ans_num;
    char ans[6];
    int score;
}stu_ans;

int cmp(const void *A, const void *B) {
    problem_ans a = *(problem_ans*)A;
    problem_ans b = *(problem_ans*)B;
    if (a.wrong == b.wrong)
        return a.id - b.id;
    return b.wrong - a.wrong;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);

    problem_ans *problem = (problem_ans*) malloc(M * sizeof(problem_ans));
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d%d", &problem[i].score, &problem[i].choose_num,
        &problem[i].correct_ans);
        
        int j = 0;
        for (; j < problem[i].correct_ans; j++)
            scanf(" %c", &problem[i].ans[j]);
        
        problem[i].wrong = 0;
        problem[i].id = i + 1;
    }

    
    stu_ans *stu = (stu_ans*) malloc(M * sizeof(stu_ans));
    for (int k = 0; k < N; k++)
    {
        getchar();
        int sum_score = 0;
        for (int i = 0; i < M; i++)
        {
            scanf("(%d", &stu[i].ans_num);
        
            int j = 0;
            for (; j < stu[i].ans_num; j++)
            {
                scanf(" %c", &stu[i].ans[j]); 
                //if (stu[i].ans[j] != problem[i].ans[j])
            }
            if (i < M - 1)
                scanf(") ");
            else
                scanf(")");
            
            stu[i].score = 0;

            if (stu[i].ans_num == problem[i].correct_ans) {
                int wrong_flag = 0;
                for (int cnt = 0; cnt < stu[i].ans_num; cnt++)
                {
                    if (stu[i].ans[cnt] != problem[i].ans[cnt]) {
                        problem[i].wrong++;
                        wrong_flag++;
                        break;
                    }
                }
                if (wrong_flag == 0)
                    sum_score += problem[i].score;
            }
            else    problem[i].wrong++;
        }
        printf("%d\n", sum_score);
    }
    
    qsort(problem, M, sizeof(problem_ans), cmp);
    if (problem[0].wrong == 0)  printf("Too simple\n");
    else {
        printf("%d", problem[0].wrong);
        int i = 0;
        while (problem[i].wrong == problem[0].wrong)
        {
            printf(" %d", problem[i].id);
            i++;
        }
        printf("\n");
    }

    
    free(problem);
    free(stu);
    return 0;
}
```

## 总结

这个题难度不大，难就难在格式化输入和输出。
