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
