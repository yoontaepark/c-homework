#include <stdio.h>
#include <stdbool.h> // bool function�� ������ �� ����
#include <complex.h> // ���Ҽ��� ���� function 

int main()
{
	//���Ҽ��� ���� ����� �Ϻ� �����Ѵ� ������ �˰� ����
	_Dcomplex z;
	z._Val[0] = 1.0;
	z._Val[1] = 1.0;


	//�Ҹ�����(������Ҷ� ���� ������, �ֱٿ� bool Ÿ���� �߰��Ǿ���, ���� �� �ִ� ���� T or F �� ����)  

	printf("%u\n", sizeof(_Bool)); //1byte (�ּҴ����̸� 1bit�� ��������� ǥ���Ǵ´����� 1byte���� 7bit�� ����Ǵ� ��Ȳ) 

	_Bool b1;
	b1 = 0; //false 
	b1 = 1; //true (�̰� false�ƴϸ� �������� true�� ��)

	printf("%d\n", b1);

	bool b2, b3;
	b2 = true; //�̷��� ������ ������ ������ ������ 
	b3 = false;

	printf("%d %d\n", b2, b3); //���� %d�� ǥ����(%c �̷��� �ƴ�) 

	return 0;
}