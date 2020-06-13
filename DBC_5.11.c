#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�ڷ��� ��ȯ�� ���� ����
int main()
{
/* promotions in assignments
   ���ް�������, �����ڷ��� ���� �����ڷ����� ������ ������ �ȳ��� ���� */
	//short s = 64;
	//int i = s;

	//float f = 3.14f; //�ϴ� �ڿ� f�Ⱥ��̸� double�� �ν��ؼ� f�� �ٿ��ִ� ������ 
	//double d = f;

/* demotion in assignments
   ���������, �����ڷ��� ���� �����ڷ����� ������ ������ ���� ����(�����ϸ� �̷��� ��������) */
	//d = 1.25;
	//f = 1.25; //0.25�� 2^(-2)�̾ �����޽����� ���� ������ �ʴ� ���
	//f = 1.123; //double ���¸� float ���¿� �������� warning �޽��� ����(�ϴ� ���� ������ ��) 

/* ranking of types in operations: ������ �����ڷ����̰�, ���� �ٿ� ������ ���� ��ŷ�̶�� �����ϸ� ��*/
	/*long double > double > float
	unsigned long long, long long 
	unsigned long, long
	unsigned, int
	short int, unsigned short int
	signed char, char, unsigned char 
	_Bool
	ref: Google 'Integer conversion rank'*/
	//d = f + 1.234; //f+d�̱� ������ f�� d�� �ٲ��ְ� d�ڷ����� ������ ���� �ȳ�
	//f = f + 1.234; //f+d�̱� ������ f�� d�� �ٲ��ִµ� f�ڷ����� ������ warning ��

	/* automatic promotion of function arguments: ���ܵ��̶��� �ϴµ� ������ �׳� �׷��� �ֳ����ٸ� 
	1. Functions without prototypes
	2. Variadic functions
	*/

	/* casting operators */
	//d = (double)3.14f; //()�� ���� ����ȯ�� ��Ű���� d�� ������ 
	//i = 1.6 + 1.7; // 3.3�������� �����ؼ� 3�� ����
	//i = (int)1.6 + (int)1.7; // ���� 1�� �Ǳ� ������ 1+1 = 2�� ��

	/* more examples */
	char c;
	int i;
	float f;
	f = i = c = 'A'; // 65�� ���ð��̳� f�� ��ȯ�Ǹ鼭 �ڷ�ս��� ���� ���̶�� ������ ��. ��ȿ���� ���̶���
	printf("%c %d %f\n", c, i, f);
	c += 2; //'C', 67�� ����
	i = f + 2 * c; // 65.0f+2*67 = 199�� ����
	printf("%c %d %f\n", c, i, f);
	c = 1106; //���ڰ� ©��, 1106 = 0b10001010010 ���� ��ȯ�Ѵ㿡 �� 0b, �� 8�ڸ����� �ٳ���(8��Ʈ�̹Ƿ�) -> 0b01010010 = 82 = 1106 % 256 = 'R'
	// �� 8�ڸ� ���� ¥���ٴ� �ǹ̰� 256���� ���� �������� ǥ���Ѵٴ� ����
	printf("%c\n", c); 

	c = 83.99;
	printf("%c\n", c); //83�� ���� 

	return 0;
}