/* 이 프로그램은 두 수를 키보드로 입력받아 곱의 결과를 출력하는 프로그램이다 */
/* 도입부 */
#include <stdio.h> //printf() 와 scanf()를 사용하기 위한 헤더 파일 포함
#pragma warning(disable:4996) //권장하지 않는 함수 사용에 대한 경고 메시지 무시(or scanf_s 로 써도 됨)

int a, b, c; //정수를 저장하는 변수 선언
int product(int x, int y); //사용자 함수 원형

/*main() 함수*/
void main() {
	/*첫번째 수를 입력*/
	printf("Enter a number between 1 and 100: ");
	scanf("%d", &a);
	/*두번째 수를 입력*/
	printf("Enter another number between 1 and 100: ");
	scanf("%d", &b);
	/*함수 호출에 의해 두수를 곱하고 결과를 출력*/
	c = product(a, b);
	printf("%d * %d = %d \n", a, b, c);
}
/*두 수의 곱을 계산하여 돌려주는 사용자 함수*/
int product(int x, int y) {
	return(x * y);
}
