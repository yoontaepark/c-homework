#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*초를 시분초로 표현하는 프로그램임 */

int main()
{
	int seconds = 0, minutes = 0, hours = 0;

	printf("Input seconds : ");
	scanf("%d", &seconds); 
	//while문에서 원하지 않는 값이 나오면 추가메시지 없이 끝내려면 입력받는 부분을 while문 밖과 맨끝 중복으로 써줘야 함

	while (seconds >= 0)
	{
		minutes = seconds / 60;
		seconds %= 60; //seconds = seconds % 60 과 같은 의미 

		hours = minutes / 60;
		minutes %= 60; //minutes = minutes % 60 과 같은 의미 

		printf("%d hours, %d minutes, %d seconds\n", hours, minutes, seconds);

		printf("Input seconds : ");
		scanf("%d", &seconds);
	}
	printf("Good bye\n");

	//음수의 나머지를 구하는 경우, 음수이면 나머지도 뭐로 나누던 무관하게 음수, 양수이면 무관하게 양수로 나옴

	//int div, mod;

	//div = 11 / -5;
	//mod = 11 % -5;
	//printf("div = %d, mod = %d\n", div, mod);

	//div = -11 / -5; //요건 양수
	//mod = -11 % -5; //음수가 나옴
	//printf("div = %d, mod = %d\n", div, mod);

	//div = -11 / 5; //음수가 나옴
	//mod = -11 % 5; //음수가 나옴
	//printf("div = %d, mod = %d\n", div, mod);

	return 0;
}