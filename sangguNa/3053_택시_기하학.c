#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(void)
{
    int R;
    double n_result, t_result;

    scanf("%d", &R);
    n_result = M_PI * R * R;
    t_result = pow(R, 2) + pow(R, 2);
    printf("%.6lf\n", n_result);
    printf("%.6lf\n", t_result);
}