// #define _CRT_SECURE_NO_WARNINGS //define���� �����޽��� ��ü�� ��´�
// �ƴϸ� ������Ʈ> ������Ŭ��> �Ӽ�> preprocessor > ���� _CRT_SECURE_NO_WARNINGS; �̷��� �߰��ϸ� �ȴ�

#include<stdio.h>

int main() 
{
	float won = 0.0f; //���⿡�� �Ǽ����̴ϱ� 0.0f�� 
	float dollar = 0.0f;

	printf("Input won\n");
	scanf("%f", &won);

	dollar = won * 0.00089f; //�Ǽ����̶� ���Ҷ��� f�� �ٿ��ָ� ������ �ս��� �ȳ�

	printf("Dollar = %f\n", dollar);

	printf("=========================================\n");


	int i = 0, j = 0; //������ ������ �ʱ�ȭ �ϴ°� ������(������� �����غ��� �˰Եȴٰ� ��) 
	int sum = 0; //�������� �����ϸ� ������ ���Ƽ� �����ϰ�+�ʱ�ȭ�� ���ѳ��� 

	printf("Input two integers\n");

	scanf("%d%d", &i, &j); //& :ampersand , &�� �ٴ� ������? ������ �ּҸ� �ѱ�� ������

	sum = i + j;  // �Ʒ��� �Լ� ������ ��ü������ ������´�

	printf("%d plus %d = %d\n", i, j, sum); //%�� ���������� ���ƾ� ��  

	return 0;
}


// ctrl+shift+b ������ �Ʒ� �����޽����� ���� �� �ִ� 
// ���� ���� build �� ���콺�� ������ error list �䷸�Ը��� 