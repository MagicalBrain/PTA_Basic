/*
* 1047题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, max_id = 0, max_score = 0;
    int champion_id;
    int sum[1001] = {0};

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int team_id, member_id, grade;
        scanf("%d-%d %d", &team_id, &member_id, &grade);
        if (max_id < team_id)  max_id = team_id;
        sum[team_id] += grade;
    }
    
    for (int i = 1; i <= max_id; i++)
    {
        if (max_score < sum[i]) {
            max_score = sum[i];
            champion_id = i;
        }
    }
    printf("%d %d\n", champion_id, max_score);
    return 0;
}