/*
* 1055题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct man
{
    char name[20];
    int tall;
}man;

int cmp(const void *A, const void *B) {
    man a = *(man*) A;
    man b = *(man*) B;
    return b.tall - a.tall;
}

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    
    man *data = (man*) malloc(N * sizeof(man));
    for (int i = 0; i < N; i++)
        scanf("%s%d", data[i].name, &data[i].tall);
    
    qsort(data, N, sizeof(man), cmp);

    int pai = N / K + 1;
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < pai; j++)
        {
            /* 应该从中间向两边排 */
        }
        N -= pai;
        pai = N / (i + 1);
    }
    

    free(data);
    return 0;
}