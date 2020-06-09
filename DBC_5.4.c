#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*복리 계산하는 프로그램 */
int main()
{
	float start_money = 0;
	float end_money = 0;
	float interest_rate = 0;   
	//초기화 묶어서 왜 안되는지 잘 모르겠음(2017년 버젼이라 그런지) 
	//실수형인 double로 정의했으나, float형도 상관은 없지 않나

	/*3가지 값 입력받기 */

	printf("Please enter your start money : ");
	scanf("%f", &start_money);

	printf("Please enter your end money : ");
	scanf("%f", &end_money);

	printf("Please enter your interest rate : ");
	scanf("%f", &interest_rate);

	/*while 반복문 쓰기전에 더 필요한 변수들 정의하기 */

	float fund = start_money;
	int year = 0;

	/* +=의 의미: L value에 R value를 더하고나서 다시 L value에 업데이트 쳐라
	   현재로직은 시작금액<끝금액이면 아래를 반복해라 
	   시작금액은 fund로 치환해서 복리곱연산을 수행
	   횟수를 카운팅하기 위한 year(1회씩 더하기)
	   초과되면 반복문을 빠져오면서 초과된 값을 출력한다. */
	while (fund < end_money)
	{
		fund += fund * interest_rate / 100;
		year += 1;
		printf("For %d year, fund amount is %f\n", year, fund);
	}

	printf("It takes %d years", year);

	return 0;
}