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

    nums = (int*) malloc (len * sizeof(int));
    memset(nums, 0, len * sizeof(int));
    for(int i = 0; i < n; i++) { 
        nums[days[i] - 1]++;
    }

    for(int i = 0; i < len; i++) { 
        //printf("%d ", nums[i]);
        if (nums[i] == 0)
            continue;
        int sum = 0;
        int t = len - 1;
        //printf("%d %d\n", t, i);
        //printf("%d %d\n", nums[t], nums[i]);
        while (t > i) {
            sum += nums[t];
            //printf("%d\n", sum);
            t--;
        }
        if (sum > max && sum == i + 1)
            max = sum;
    }
    //printf("\n");

    printf("%d", max);
    return 0;
}