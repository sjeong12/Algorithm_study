#include <stdio.h>

int main(void)
{
    int x1, x2, x3, x4;
    int y1, y2, y3, y4;
    
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);
    x4 = x1 ^ x2 ^ x3;
    y4 = y1 ^ y2 ^ y3;
    printf("%d %d\n", x4, y4);
}