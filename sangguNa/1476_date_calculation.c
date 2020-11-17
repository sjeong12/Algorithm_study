#include <stdio.h>

int main(void)
{
    int e; //지구를 나타내는 수
    int s; //태양을 나타내는 수
    int m; //달을 나타내는 수
    int year = 1; //연도를 나타내는 수
    int is_true = 0;

    //사용자로부터 각각의 e, s, m을 입력받음
    scanf("%d %d %d", &e, &s, &m);

    // 입력값이 범위에 맞다면 프로그램이 동작하고, 아니면 종료되도록 만듬
    if((e >= 1 && e <= 15) && (s >= 1 && s <= 28) && (m >= 1 && m <= 19))
        is_true = 1;
    else
        return (0);
    
    while(is_true)
    {   
        //year은 (15 * n + e), (28 * m + s), (19 * o + m)으로 나타낼 수 있음
        //따라서 year에서 유저가 입력한 각각의 값을 빼고 셋다 나머지가 0이라면 해당년도를 구할 수 있음
        if(((year - e) % 15 == 0) && ((year - s) % 28 == 0) && ((year - m) % 19 == 0))
            break;
        year++; //조건에 안맞는다면 연도를 계속 증가시키면서 탐색함.
    }
    printf("%d\n", year);

    return (0);
}