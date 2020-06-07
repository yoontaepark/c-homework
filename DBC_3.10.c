#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	char c = 'A';
	char d = '*';

	printf("%c %hhd\n", c, c);
	printf("%c %hhd\n", d, d);

	printf("%c \n", c + 1);

	//char a = '\a';  //escape = 7임 
	//printf("%c", a);
	printf("\07"); //07은 8진수 7을 의미함 
	printf("\x7"); //x7는 16진수 7을 의미함

	float salary;
	printf("$______\n");
	printf("$______\b\b\b\b\b\b"); //\b(백스페이스 기능 활용해서 저걸 쭉 쓰고, 백스페이스 6칸 뒤로 한다음에 입력을 대기하는 상황으로)
	scanf("%f", &salary);

	//\t, tab 기능 활용하기 
	printf("AB\tCDEF\n");
	printf("ABC\tDEF\n");

	//그외 \사용법

	printf("\\ \'HA+\' \"Hello\" \?\n"); //  \\: \를 출력하겠다, \': '를 출력하겠다, \" : "를 출력하겠다 등 \를 통해서 구분을 할 수 있다 

	return 0;
}