#include <stdio.h>
#include <stdlib.h>

typedef struct	s_mat
{
	int x;
	int y;
}				t_mat;

int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    t_mat *num1 = (t_mat *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    t_mat *num2 = (t_mat *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1->x < num2->x)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    else if (num1->x > num2->x)    // a가 b보다 클 때는
        return 1;       // 1 반환
	else
	{
		if (num1->y < num2->y)
			return -1;
		else
			return 1;
	}
    return 0;    // a와 b가 같을 때는 0 반환
}

int main(void)
{
	int N;
	t_mat m[100000];

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &m[i].x, &m[i].y);
	
	qsort(m, N, sizeof(m[0]), compare);

	for (int i = 0; i < N; i++)
		printf("%d %d\n", m[i].x, m[i].y);
}