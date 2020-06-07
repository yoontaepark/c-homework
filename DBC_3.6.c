#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h> //���� ū ���� ���� �������� �˷��ִ� ��� 
#include <stdlib.h> //_itoa ������ ���Խ�Ų ���

int main()
{
	unsigned int i = 0b11111111111111111111111111111111; //0b�� 2������� �Ҹ���, 1�̶�� 2������ 32�� �Է��� 
	unsigned int u_max = UINT_MAX; //unsinged�� ���� ū ��, ���ñ��ϸ� ������Ŭ�� > go to definition ���� ���� ���ǵǾ� �ִ°� �� �� �ִ�. 
	unsigned int u_min = 0; //unsinged�� ���� ���� ��, ��ũ�� ���� �׳� 0��(�ּҰ�) 
	signed int x_max = INT_MAX;  //signed�� ���� ū �� 
	signed int x_min = INT_MIN;  //signed�� ���� ū �� 

	unsigned int y_max =0-1; //unsinged�� ���� ū ��, ���ñ��ϸ� ������Ŭ�� > go to definition ���� ���� ���ǵǾ� �ִ°� �� �� �ִ�. 

	char buffer[33];
	_itoa(y_max, buffer, 2);  

	printf("decimal: %u\n", y_max);
	printf("binary: %s\n", buffer); //2���������� ǥ�������� ���� �ʰ��Ǹ� �Ƿ� 11111 + 1 -> 0���� ������ , 0 - 1�̸� ����ū���� �Ǿ����  : �����÷ο� ���� 
	//�׳� ��ǻ�� ����� �̷��� �Ǵ°Ŵ� ��� �����ϱ� 
	printf("============================================\n");


	printf("max of uint = %u\n", u_max);
	printf("min of uint = %u\n", u_min);
	printf("max of int = %d\n", x_max);
	printf("min of int = %d\n", x_min);
	printf("============================================\n");

	printf("%u\n", i);  // %d�� ������ ������, unsigned�� u�� ������� ������ �ȳ�, �������� ������ �ȳ� 
	printf("%u\n", u_max); 
	printf("============================================\n");

	printf("%u\n", sizeof(unsigned int)); // sizeof�� Ŀ���� �����ٴ�� 4u �̷������� �ߴµ�, unsigned int�ڷ����� 4byte�� �����ϰ� �ִٴ� �Ҹ��� 
	//""���ٰ� �ڿ� ������ �Լ��� �ڷ����� ��ġ���Ѿ� ��. ���� "u"�� ����� 
	printf("%u", sizeof(i));  //���� ������ ǥ�� 

	return 0;
}