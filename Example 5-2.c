/* 재귀함수를 이용하여 factorial을 계산하는 프로그램
   재귀함수란 자기자신을 호출하는 함수를 말한다 */
#include<stdio.h>
#pragma warning(disable:4996)
unsigned int f, x, factorial(unsigned int a);
int main() {
    puts("Enter an integer value between 1 and 10 : ");
    scanf("%d", &x);
    if (x > 10 || x < 1) {
        printf("Only values from 1 to 10 are acceptable");
    }
    else {
        f = factorial(x);
        printf("%u factorial equals %u \n", x, f);
    }
    return 0;
}

unsigned int factorial(unsigned int a) {
    if (a == 1)
        return 1;
    else {
        a *= factorial(a-1);
        return a;
    }
}

/*
1. puts도 printf처럼 출력함수임, x<1, x>10 일경우에는 if문, 
1<=x<=10 이면 f를 팩토리얼 처리하고, x 팩토리얼은 f이다를 출력 

<여기서부터는 추가공부해야할듯...>
main함수 아래에다가 factorial(a) 값을 초기화 시킴
a가 1이면 1로, 1이 아닌경우에는 a-1을 a로 변환시켜서 a로 출력
*/
