#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	char c = 'A';
	char d = '*';

	printf("%c %hhd\n", c, c);
	printf("%c %hhd\n", d, d);

	printf("%c \n", c + 1);

	//char a = '\a';  //escape = 7�� 
	//printf("%c", a);
	printf("\07"); //07�� 8���� 7�� �ǹ��� 
	printf("\x7"); //x7�� 16���� 7�� �ǹ���

	float salary;
	printf("$______\n");
	printf("$______\b\b\b\b\b\b"); //\b(�齺���̽� ��� Ȱ���ؼ� ���� �� ����, �齺���̽� 6ĭ �ڷ� �Ѵ����� �Է��� ����ϴ� ��Ȳ����)
	scanf("%f", &salary);

	//\t, tab ��� Ȱ���ϱ� 
	printf("AB\tCDEF\n");
	printf("ABC\tDEF\n");

	//�׿� \����

	printf("\\ \'HA+\' \"Hello\" \?\n"); //  \\: \�� ����ϰڴ�, \': '�� ����ϰڴ�, \" : "�� ����ϰڴ� �� \�� ���ؼ� ������ �� �� �ִ� 

	return 0;
}