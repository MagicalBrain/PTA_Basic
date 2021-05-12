/*
* 1057题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100001];
    gets(str);

    int sum = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            sum += str[i] - 'A' + 1;
        if (str[i] >= 'a' && str[i] <= 'z')
            sum += str[i] - 'a' + 1;
        i++;
    }

    int cnt0 = 0, cnt1 = 0;
    while (sum / 2 != 0)
    {
        if (sum % 2 == 0) cnt0++;
        else cnt1++;
        sum /= 2;
    }
    if (sum == 1) cnt1++;
    
    printf("%d %d\n", cnt0, cnt1);
    return 0;
}