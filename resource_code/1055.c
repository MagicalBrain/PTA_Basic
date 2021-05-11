/*
* 1055题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct man
{
    char name[10];
    int tall;
    int id;
}man;

int cmp(const void *A, const void *B) {
    man a = *(man*) A;
    man b = *(man*) B;
    //若身高相同，则按名字的字典序排序
    if (b.tall == a.tall) {
        return strcmp(a.name,b.name);
    }
    return b.tall - a.tall;
}

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    
    man *data = (man*) malloc(N * sizeof(man));
    for (int i = 0; i < N; i++)
    {
        scanf("%s%d", data[i].name, &data[i].tall);
        data[i].id = i;
    }
    
    qsort(data, N, sizeof(man), cmp);
    
    int n = 0;
    int N_cp = N;
    

    while (n < N)
    {
        //一共K排，每排pai个人
        int pai;
        if (N_cp % K == 0) pai = N_cp / K;
        else    pai = N_cp / K + 1;  
        //printf("pai = %d\n", pai);  

        //分配一个字符串的动态数组
        char **name = (char**) malloc(pai * sizeof(char*));
        //for (int j = 0; j < pai; j++)
          //  name[j] = (char*) malloc(20 * sizeof(char));

        /* 应该从中间向两边排 */
        
        int cnt = 0;    //该排人数计数器
        int top = pai / 2;  //先确定最高的站中间
        name[top] = data[n++].name;
        cnt += 1;

        int i = 1;
        while (cnt < pai)
        {
            name[top - i] = data[n++].name;
            cnt++;
            if (cnt < pai) name[top + i] = data[n++].name;
            else break;
            cnt++;
            i++;
        }
        
        //输出各个人的名字
        for (int j = 0; j < pai; j++)
        {
            if (j != pai - 1)   printf("%s ", name[j]);
            else    printf("%s\n", name[j]);
        }

        //释放内存
        //for (int j = 0; j < pai; j++)
          //  free(name[j]);
        free(name);

        N_cp -= pai;
        K--;
    }

    free(data);
    return 0;
}