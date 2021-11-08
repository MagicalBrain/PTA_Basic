/*
* 1058�� ����浵
*/
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996)

typedef struct problem {
    int id;
    int Max_score;      // ��Ŀ�ķ�ֵ
    int choice_num;     // ѡ��ĸ���
    int correct_num;    // ��ȷѡ��ĸ���
    char ans[6];        // ������
    int wrong_cnt;      // �ش���������
}problem;

typedef struct stu {
    int ans_num;        // ����𰸵�ѡ�����
    char ans[6];        // ������
    int score;          // ѧ���÷�
}stu;

// ���ڿ��ŵıȽϺ���
int cmp(const void* A, const void* B) {
    problem a = *(problem*)A;
    problem b = *(problem*)B;
    if (a.wrong_cnt == b.wrong_cnt)
        return a.id - b.id;
    return b.wrong_cnt - a.wrong_cnt;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);

    problem* p = (problem*)malloc(M * sizeof(problem));
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d%d", &p[i].Max_score, &p[i].choice_num,
            &p[i].correct_num);

        int j = 0;
        for (; j < p[i].correct_num; j++)
            scanf(" %c", &p[i].ans[j]);
        p[i].wrong_cnt = 0;
        p[i].id = i + 1;
    }

    stu* s = (stu*)malloc(M * sizeof(stu));
    for (int k = 0; k < N; k++)
    {
        int sum_score = 0;
        for (int i = 0; i < M; i++)
        {
            scanf("(%d", &s[i].ans_num);

            int j = 0;
            for (; j < s[i].ans_num; j++)
            {
                scanf(" %c", &s[i].ans[j]);
                //if (stu[i].ans[j] != problem[i].ans[j])
            }
            scanf(")");
            s[i].score = 0;

            /*
            if (s[i].ans_num == problem[i].correct_ans) {
                int wrong_flag = 0;
                for (int cnt = 0; cnt < s[i].ans_num; cnt++)
                {
                    if (s[i].ans[cnt] != problem[i].ans[cnt]) {
                        problem[i].wrong++;
                        wrong_flag++;
                        break;
                    }
                }
                if (wrong_flag == 0)
                    sum_score += problem[i].score;
            }
            else    problem[i].wrong++;
            */

        }
        printf("%d\n", sum_score);
    }

    // ���Ŷ��������ݳ����������
    /*
    qsort(p, M, sizeof(problem), cmp);
    if (p[0].wrong == 0)  printf("Too simple\n");
    else {
        printf("%d", p[0].wrong);
        int i = 0;
        while (p[i].wrong == p[0].wrong)
        {
            printf(" %d", p[i].id);
            i++;
        }
        printf("\n");
    }
    */



    free(p);
    free(s);
    return 0;
}
