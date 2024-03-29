/*
* 1048题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char num1[101];
    char num2[101];
    char *re = NULL;

    scanf("%s %s", num1, num2);

    int len1, len2, min, max;
    len1 = strlen(num1), len2 = strlen(num2);

    if (len1 > len2) {
        min = len2;
        max = len1;
        re = num1;
    }else {
        min = len1;
        max = len2;
        re = num2;
    }

    int i = 1;
    while (i <= min)
    {
        //奇数位的处理
        if (i % 2 != 0) {
            int t = (num1[--len1] - '0') + (num2[--len2] - '0');
            t = t % 13;
            if (t == 10)    re[max - i] = 'J';
            else if (t == 11) re[max - i] = 'Q';
            else if (t == 12) re[max - i] = 'K';
            else re[max - i] = '0' + t;
        }
        //偶数位的处理
        else {
            int t = num2[--len2] - num1[--len1];
            if (t < 0)  t += 10;
            re[max - i] = '0' + t;
        }
        i++;
    }
    while (i <= max) {
        if (re == num1 && i % 2 == 0) {
            int t = re[max - i] - '0';
            if (t == 0)
                re[max - i] = '0';
            else
            re[max - i] = '0' + 10 - t;
        }
        i++;
    }
    puts(re);
    return 0;
}