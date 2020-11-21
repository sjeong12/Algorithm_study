#include <stdio.h>

int main(void)
{
    int t;
    int n;
    int add[11];

    add[0] = 1; //0과 1의 합을 나타내는 방법의 수는 1이라 가정
    add[1] = 1;
    add[2] = 2; //2의 합을 나타내는 방법의 수는 1+1, 2, 즉 2가지
    add[3] = 4; //3의 합을 나타내는 방법의 수는 1+1+1, 1+2, 2+1, 3, 즉 4가지

    scanf("%d", &t); //테스트케이스 T를 입력받는다.

    for(int i = 0; i < t; i++) //테스트케이스 갯수 t만큼 for문을 반복한다
    {
        scanf("%d", &n); //경우의 수를 구하고싶은 n을 입력받는다
        if(n < 4)
        {
            printf("%d\n", add[n]); //4 미만의 경우, 위에 선언한 경우의 수를 출력해줌
        }
        else
        {
            for(int j = 4; j <= n; j++)
            {
                //4이상의 경우 규칙을 활용해서 배열을 채워가며 값을 구함
                add[n] = add[n - 1] + add[n - 2] + add[n - 3];
            }
            printf("%d\n", add[n]);
        }
    }
    return (0);
}
/*
    4는
        1 + 1 + 1 + 1
        1 + 1 + 2
        1 + 2 + 1
        1 + 3
        2 + 1 + 1
        2 + 2
        3 + 1
    의 경우의 수로 나타낼 수 있다. 
    '1 +' 로 시작하는 경우 3을 나타낼 수 있는 방법의 수와 같으므로 4가지
    '2 +' 로 시작하는 경우 2를 나타낼 수 있는 방법의 수와 같으므로 2가지
    '3 +' 로 시작하는 경우 1을 나타낼 수 있는 방법의 수와 같으므로 1가지이다.
    즉, 4는 3과 2와 1의 방법의 수를 합한 것과 같으므로 다음과 같은 공식을 구할 수 있다.
    add[n] = add[n -1] + add[n - 2] + add[n - 3]
*/