/*
* 1061题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, M;
    int *scores, *right, *ans;
    scanf("%d%d", &N, &M);

    scores = (int*) malloc (M * sizeof(int));
    memset(scores , 0, M * sizeof(int));
    for (int i = 0; i < M; i++)
        scanf("%d", &scores[i]);

    right = (int*) malloc (M * sizeof(int));
    memset(right , 0, M * sizeof(int));
    for (int i = 0; i < M; i++)
        scanf("%d", &right[i]);
    
    ans = (int*) malloc (N * sizeof(int));
    memset(ans , 0, N * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", &ans[i]);

    

    return 0;
}