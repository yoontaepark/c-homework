#include<stdio.h>

void say_hello(void);  
/*
prototyping, function declaration, �̷������� �ϸ� ��ŷ�� ���ؼ� main > say_hello ���� > ���� ���ǵǾ�����+�Ʒ� �ڼ��� �Լ��� ��ŷ > �Լ�ȣ�� �� �����
*/


int main()
{	
	say_hello();

	return 0;
}

void say_hello(void)  //�Լ������ 
{
	printf("Hello, World!\n");

	return;
}



/* ������ ��Ű�� main���� ������ ������. �̶� say hello()��� �Լ��� �����Ű��, 
say_hello�� ���� �Լ����ǽĿ� ���� printf�� �����Ŵ. �װ� �ݺ��� �Ŀ� main�Լ��� return 0 �������� ����
�Լ��� main �Լ� �ڷ� �����ϸ� �Լ��� ���ǾȵǾ��ֱ� ������ �������� 
1) �Լ���ü�� main ���� �ø��� - main�� �� �Ⱥ���(������)
2) �Լ� ���ٸ� main ���� �ø���(�Լ��� ����κи� ���������ϵ��� main �Լ� ���� �ø�) 




*/