#include<stdio.h>

void say_hello(void);

int main()
{
	int x, y, z;

	x = 1;
	y = 20;
	z = 3;
	
	z = x + y;
	
	say_hello();

	return 0;
}

void say_hello(void) //function definition
{
	int x = 1;
	x = 10;

	printf("Hello, World\n");
	
	return;
}

/* ���� �亮��...������ ������ break point��� ������ �� �ִµ�, ���ϴ� �������� debug�� �����Ű�°Ŷ� �����ϸ� ��
f5�� ������ ���ϴ��������� debug�� ����ǰ�, �м��� �� �ִ� debug â�� ��. f11 ������ step into ������ ���پ� ������
�Լ��� �� �� ������ �Լ��� �Ѿ��, �ƴѳ���� �׳� ������. ������ ���� ���ȭ���� �� 
f10�� ������ step over �ε�, �Լ����� �ֵ��� ���� ������ �ʰ� �׳� �Ѿ ��. ������ ���� ���ȭ���� ��*/