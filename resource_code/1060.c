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
    int *nums, *total;

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

    if (len != 0) {
        nums = (int*) malloc (len * sizeof(int));
        memset(nums, 0, len * sizeof(int));
        for(int i = 0; i < n; i++) {
            if (days[i] == 0)
                continue;
            nums[days[i] - 1]++;
        }

        total = (int*) malloc (len * sizeof(int));
        memset(total, 0, len * sizeof(int));
        int sum = 0;
        for(int i = len - 1; i >= 0; i--) { 
            total[i] = sum;
            //printf("%d %d\n", i + 1, total[i]);
            if (total[i] >= i + 1) {
                max = i + 1;
                break;
            }
            sum += nums[i];
        }
    }
    
    printf("%d", max);
    return 0;
}