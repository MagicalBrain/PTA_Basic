/*
* 1060题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
    int n;      // 输入天数
    int *days;  // 存储每日骑车的里程
    int max = 0;    // 最大值
    int len;
    int *nums;

    scanf("%d", &n);

    days = (int*) malloc (n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &days[i]);
        if (i == 0)
            len = days[i];
        else {
            if (days[i] > len)
                len = days[i];
        }
    }

    //nums = (int*) malloc (len * sizeof(int));
    //memset(nums, 0, len * sizeof(int));
    int cnt;
    for(int i = 0; i < n; i++) { 
        //nums[days[i] - 1]++;
        cnt = 0;
        for (int j = 0; j < n; j++)
            if (days[j] > i + 1)
                cnt++;

        if (cnt == i + 1 && i + 1 > max)
            max = i + 1;
    }

    printf("%d", max);
    return 0;
}