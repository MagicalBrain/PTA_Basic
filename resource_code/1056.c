/*
* 1056题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    int sum = 0;
    scanf("%d", &N);

    int *nums = (int*) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &nums[i]);
        sum += nums[i] * 10 * (N - 1);
        sum += nums[i] * (N - 1);
    }
    
    free(nums);

    printf("%d\n", sum);
    return 0;
}