#include<stdio.h>
//cppreference.com �����غ��� (https://en.cppreference.com/w/c/keyword
int main()
{
	//print formatted�� ������ (printf)
	
	printf("\"The truth is ... \nI am Ironman.\"\n");  // \n = escape sequence, �ٹٲ��ϰ��� �پ�� �ϰ� �Ͱ����� �ȶ��� ������ ó������ ���ڰ� ���� 
	// ����ǥ���� ���� ����ϰ� �ʹٰ� "" �̷��� �ϸ� �׳� ����� �������� "(��ĭ)" �̷�������
	// \�̰� �־ �����ϸ� ��

	int x, y, z; // ������ ������Ŭ�� + rename�ؼ� �ٲܼ����� (ctrl+r)
	x = 1;
	y = 2;

	z = x + y;
	
	printf("The answer is %i+%i = %i", x,y,z);
	printf("\a");  //�Ҹ��� ���� �����(���� ����� �ƴϰ�) 

	// ��ü��� �ּ��ֱ�(ctrl+k+c), �ּ�Ǯ��(ctrl+k+u), ���� ������ /*�÷� ����(�ƴ� ��� ����ٿ� ���� // ����)
	return 0;
}