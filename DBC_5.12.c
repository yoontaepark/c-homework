#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void draw(int n); //ANSI function prototype declaration

int main()
{
	int i = 5;
	char c = '#';
	float f = 7.1f;

	draw(i);  //i�� ���� *�� ���
	draw((int)c);  //c�� ���� *�� ���
	draw((int)f);  //f�� ���� *�� ���� 

	/* Arguments vs. Parameters */
	//con) arguments(values: ��, ���)
	// paremeters(variables: ����) 

	return 0;
}

void draw(int n)
{
	while (n-- > 0)	
	printf("*"); //*�� �ش��ϴ� ��ŭ ��� 

	printf("\n");// while���� ������ �ٹٲ޽�Ŵ 
}
