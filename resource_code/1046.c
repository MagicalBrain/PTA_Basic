/*
* 1046题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    int sum = 0;
    int a = 0, b = 0;
    int data[4] = {0};
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &data[j]);
        }
        sum = data[0] + data[2];
        if (data[1] == sum && data[3] != sum)
            b++;
        if (data[1] != sum && data[3] == sum)
            a++;
    }
    printf("%d %d\n", a, b);
    
    return 0;
}