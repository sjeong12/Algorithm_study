#include <stdio.h>

int main(void)
{
	int x, y, w, h;
	int w_min, h_min, result;

	scanf("%d %d %d %d", &x, &y, &w, &h);
	if ((x - 0) <= (w - x))
		w_min = x - 0;
	else
		w_min = w - x;
	if ((y - 0) <= (h - y))
		h_min = y - 0;
	else
		h_min = h - y;
	if (w_min <= h_min)
		result = w_min;
	else
		result = h_min;
	printf("%d\n", result);
	return (0);
}