/*
* 1052题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(char *set, int id, char *re) {
    //re = (char*) malloc(10 * sizeof(char));
    int i = 0, cnt = 0;
    while (set[i] != '\0')
    {
        if (cnt == id) break;
        if (set[i] == '[')  cnt++;
        i++;
    }
    if (set[i] == '\0')
    {
        return 0;
    }
    int j = 0;
    while (set[i] != ']')
    {
        re[j] = set[i];
        i++, j++; 
    }
    re[j] = '\0';
    //i += 1;
    
    return 1;
}

int main() {
    //定义符号集的存储字符串
    //一个符号集不超过10个符号，每个符号不超过4个字符
    char hand[100];
    char eye[100];
    char mouth[100];

    gets(hand);
    gets(eye);
    gets(mouth);

    char *symbol1, *symbol2, *symbol3, *symbol4, *symbol5;
    symbol1 = (char*) malloc(10 * sizeof(char));
    symbol2 = (char*) malloc(10 * sizeof(char));
    symbol3 = (char*) malloc(10 * sizeof(char));
    symbol4 = (char*) malloc(10 * sizeof(char));
    symbol5 = (char*) malloc(10 * sizeof(char));
    

    int K;
    scanf("%d", &K);

    int id[5] = {0};
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &id[j]);
        }   
        
        /*
        find(hand, id[0], symbol1); 
        find(hand, id[1], symbol2); 
        find(hand, id[2], symbol3); 
        find(hand, id[3], symbol4); 
        find(hand, id[4], symbol5); 
        */

        //if (symbol1 == NULL)
        if (find(hand, id[0], symbol1) == 0)
        {  
            printf("Are you kidding me? @\\/@\n");
            //free(symbol1);
            continue;
        }
        //if (symbol2 == NULL)
        if (find(eye, id[1], symbol2) == 0)
        {  
            printf("Are you kidding me? @\\/@\n");
            //free(symbol2);
            continue;
        }
        //if (symbol3 == NULL)
        if (find(mouth, id[2], symbol3) == 0)
        {  
            printf("Are you kidding me? @\\/@\n");
            //free(symbol3);
            continue;
        }
        //if (symbol4 == NULL)
        if (find(eye, id[3], symbol4) == 0)
        {  
            printf("Are you kidding me? @\\/@\n");
            //free(symbol4);
            continue;
        }
        //if (symbol5 == NULL)
        else if (find(hand, id[4], symbol5) == 0)
        {  
            printf("Are you kidding me? @\\/@\n");
            //free(symbol5);
            continue;
        }
        printf("%s(%s%s%s)%s\n", symbol1, symbol2, symbol3, symbol4, symbol5);
        
            
    }
    
    free(symbol1);
    free(symbol2);
    free(symbol3);
    free(symbol4);
    free(symbol5);
    
    return 0;
}