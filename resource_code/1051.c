/*
* 1051题 代码存档
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    double a1, b1, a2, b2;
    double a, b, R, P;
    //puts("输入两个复数的模长和幅角:")
    scanf("%lf%lf%lf%lf", &a1, &b1, &a2, &b2);
    R = a1 * a2, P = b1 + b2;
    a = R * cos(P);
    b = R * sin(P);
    if (a + 0.005 >= 0 && a < 0)
        printf("0.00");
    else
        printf("%.2f", a);
    if(b >= 0)
        printf("+%.2fi", b);
    else if (b + 0.005 >= 0 && b < 0)
        printf("+0.00i");
    else
        printf("%.2fi", b);
    return 0;
}