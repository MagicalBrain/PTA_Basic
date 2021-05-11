# 【PAT Basic】1055 集体照 (25 分)

## 题目描述

拍集体照时队形很重要，这里对给定的 N 个人 K 排的队形设计排队规则如下：

每排人数为 $\lfloor N \div K \rfloor$，多出来的人全部站在最后一排；

后排所有人的个子都不比前排任何人矮；

每排中最高者站中间（中间位置为 $\lfloor m \div 2 + 1 \rfloor$，其中 $m$ 为该排人数

每排其他人以中间人为轴，按身高非增序，先右后左交替入队站在中间人的两侧（例如5人身高为190、188、186、175、170，则队形为175、188、190、186、170。这里假设你面对拍照者，所以你的左边是中间人的右边）；

若多人身高相同，则按名字的字典序升序排列。这里保证无重名。

现给定一组拍照人，请编写程序输出他们的队形。

输入格式：
每个输入包含 1 个测试用例。每个测试用例第 1 行给出两个正整数 N（≤$10^4$​​ ，总人数）和 K（≤10，总排数）。随后 N 行，每行给出一个人的名字（不包含空格、长度不超过 8 个英文字母）和身高（[30, 300] 区间内的整数）。

输出格式：
输出拍照的队形。即K排人名，其间以空格分隔，行末不得有多余空格。注意：假设你面对拍照者，后排的人输出在上方，前排输出在下方。

输入样例：
```
10 3
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159
```

输出样例：
```
Bob Tom Joe Nick
Ann Mike Eva
Tim Amy John
```

## 基本思路

**分析：**
注意审题，我是摄影师，左右与拍照的人相反。即第一行输出高个子，后面几行输出矮个子，而且每排从中间最高的开始，先左后右。

当身高相同时，按名字的字典序来排序

---
**思路：**
先用快排按身高排序（注意在比较函数cmp里加入身高相同时按名字字典序排序的逻辑），然后计算好要排多少排。

## 代码

```cpp
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
```

## 总结

这题的比较规则稍微有点复杂，但其实只要用好```qsort```的```cmp```函数就很简单了。

**易错点：**

1、字符串数组分配空间时要注意，如果用一个字符串给其数组元素赋值，此时是不需要给这个字符指针分配内存空间的。因为其实赋值后这个内存空间分配是无效的，字符指针指向的就是字符串的内存空间，不需要再分配了；后面如果要free的话会导致释放没有分配的空间导致```bad free```错误
