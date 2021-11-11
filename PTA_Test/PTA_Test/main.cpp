/*
* 1058�� ����浵
*/
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996)

// ��Ҫһ���ж��Ƿ��������ĺ���
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
    int n;  // ID�ĸ���
    int k;  // ��Ҫ��ѯID�ĸ���

    int* ids;   // ���ڴ��ID������
    int* rewards; // ���ڴ������������

    scanf("%d", &n);
    ids = (int*)malloc(n * sizeof(int));
    rewards = (int*)malloc(n * sizeof(int));
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
    int* check;
    check = (int*)malloc(k * sizeof(int));
    memset(check, 0, n * sizeof(int));
    for (int i = 0; i < k; i++)
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
