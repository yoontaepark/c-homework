#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*�ʸ� �ú��ʷ� ǥ���ϴ� ���α׷��� */

int main()
{
	int seconds = 0, minutes = 0, hours = 0;

	printf("Input seconds : ");
	scanf("%d", &seconds); 
	//while������ ������ �ʴ� ���� ������ �߰��޽��� ���� �������� �Է¹޴� �κ��� while�� �۰� �ǳ� �ߺ����� ����� ��

	while (seconds >= 0)
	{
		minutes = seconds / 60;
		seconds %= 60; //seconds = seconds % 60 �� ���� �ǹ� 

		hours = minutes / 60;
		minutes %= 60; //minutes = minutes % 60 �� ���� �ǹ� 

		printf("%d hours, %d minutes, %d seconds\n", hours, minutes, seconds);

		printf("Input seconds : ");
		scanf("%d", &seconds);
	}
	printf("Good bye\n");

	//������ �������� ���ϴ� ���, �����̸� �������� ���� ������ �����ϰ� ����, ����̸� �����ϰ� ����� ����

	//int div, mod;

	//div = 11 / -5;
	//mod = 11 % -5;
	//printf("div = %d, mod = %d\n", div, mod);

	//div = -11 / -5; //��� ���
	//mod = -11 % -5; //������ ����
	//printf("div = %d, mod = %d\n", div, mod);

	//div = -11 / 5; //������ ����
	//mod = -11 % 5; //������ ����
	//printf("div = %d, mod = %d\n", div, mod);

	return 0;
}