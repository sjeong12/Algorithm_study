#include <stdio.h>

int main(void)
{
    //c_count : 입력받을 갯수를 저장하는 변수
    int c_count;
    int a[10];
    int b[10];

    //몇개를 입력받을지 사용자에게 받음
    scanf("%d\n", &c_count);

    //입력받은 갯수 만큼 a, b를 입력받음
    //주의 : 현재 입력값보다 한번 더 입력해야 출력문으로 넘어감. 이유는 디버깅을 해야 아는데 디버깅을
    // 수행하지못함
    //해결 : scanf때 \n을 넣어놨기 때문에 마지막에 엔터를 두번해야 값이 출력됬던거임..
    // \n을 제거해서 이제 잘 됨
    for(int i = 0; i < c_count; ++i)
    {
        scanf("%d %d", &a[i], &b[i]);
    }

    //입력받은 갯수 만큼 a와 b의 합을 출력한다. 이때, 조건에 맞지않으면 경고문을 출력한다.
    for(int i = 0; i < c_count; i++)
    {
        if((a[i] > 0 && a[i] < 10) && (b[i] > 0 && b[i] < 10))
            printf("Case #%d: %d + %d = %d\n", i + 1, a[i], b[i], a[i] + b[i]);
    }
    return (0);
}