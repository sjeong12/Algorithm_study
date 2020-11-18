#include <stdio.h>

int main(void)
{
    int a[10]; //입력값을 저장할 배열 A
    int b[10]; //입력값을 저장할 배열 B
    int count; //몇개의 테스트 케이스를 입력받을지 저장하는 변수 count

    scanf("%d", &count); //사용자로부터 테스트 케이스의 개수를 입력받음

    //입력받은 테스트 케이스만큼 배열에 입력값을 저장함
    for(int i = 0; i < count; i++)
    {
        scanf("%d,%d", &a[i], &b[i]);
    }

    //입력받은 테스트 케이스만큼 A + B를 출력함.
    //이때, 0 < A, B < 10 를 만족하지 않으면 조건이 맞지 않는다고 출력문을 만들었음.
    for(int i = 0; i < count; i++)
    {
        if((a[i] > 0 && a[i] < 10) && (b[i] > 0 && b[i] < 10))
            printf("%d\n", a[i] + b[i]);
        else
            printf("fail to meet the conditions.\n");
    }

    return(0);
}