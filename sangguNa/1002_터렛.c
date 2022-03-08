#include <stdio.h>
#include <math.h>

int main(void)
{
	int x1, y1, r1, x2, y2, r2;
	double d;
	int T;

	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));//두 점 사이의 거리
		if (x1 == x2 && y1 == y2 && r1 == r2)//두 원이 완전히 겹치는 경우
			printf("-1\n");//교접이 무한대
		else if (abs(r2 - r1) < d && d < abs(r2 + r1))//두 원이 겹치는 경우
			printf("2\n");//교접이 2개
		else if ((abs(r2 - r1) == d) || (abs(r1 + r2) == d))//원이 내접, 외접하는 경우
			printf("1\n");//교접이 1개
		else//그 외의 경우는 만나지 못함
			printf("0\n");
	}
	return (0);
}