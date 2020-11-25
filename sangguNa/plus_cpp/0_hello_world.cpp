#include <iostream>

int main(void)
{
    //std 는 C++ 표준 라이브러리의 모든 함수, 객체 등이 정의된 이름 공간(namespace) 입니다.
    //이름 공간은 말그대로 어떤 정의된 객체에 대해 어디 소속인지 지정해주는 것과 동일합니다.

    //std::cout 사용법
    // std::cout << /* 출력할 것 */ << /* 출력할 것 */ << ... << /* 출력할 것 */;
    // std::endl : endl 은 화면에 출력해주는 '함수' 입니다. 
    // 아니면 화면에 엔터를 하나 출력해주는 것으로 기억하시면 됩니다
    std::cout << "Hello world!!!" << std::endl;
    return (0);
}