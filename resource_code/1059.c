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
    memset(check, 0, n * sizeof(int));
    for (int i = 0;i < k;i++)
    {
        int id;
        int checked = 0;
        scanf("%d", &id);
        //printf("ids[i]: %d\n", ids[i]);
        for (int j = 0; j < n; j++) {
            if (ids[j] == id) {
                if (check[j] == 0) {
                    if (rewards[j] == 0)
                        printf("%d:Mystery Award\n", ids[j]); 
                    else if (rewards[j] == 1)
                        printf("%d:Minion\n", ids[j]); 
                    else
                        printf("%04d:Chocolate\n", ids[j]); 
                    check[j] = 1;
                    checked++;
                }
                else
                    printf("%d:Checked\n", id);        
            }
        }
        if (checked == 0 && i != k - 1)
            printf("%d:Are you kidding?\n", id);
        else if (checked == 0 )
            printf("%d:Are you kidding?", id);
    }

    free(ids);
    free(rewards);
    free(check);
    return 0;
}