/* �� ���α׷��� �� ���� Ű����� �Է¹޾� ���� ����� ����ϴ� ���α׷��̴� */
/* ���Ժ� */
#include <stdio.h> //printf() �� scanf()�� ����ϱ� ���� ��� ���� ����
#pragma warning(disable:4996) //�������� �ʴ� �Լ� ��뿡 ���� ��� �޽��� ����(or scanf_s �� �ᵵ ��)

int a, b, c; //������ �����ϴ� ���� ����
int product(int x, int y); //����� �Լ� ����

/*main() �Լ�*/
void main() {
	/*ù��° ���� �Է�*/
	printf("Enter a number between 1 and 100: ");
	scanf("%d", &a);
	/*�ι�° ���� �Է�*/
	printf("Enter another number between 1 and 100: ");
	scanf("%d", &b);
	/*�Լ� ȣ�⿡ ���� �μ��� ���ϰ� ����� ���*/
	c = product(a, b);
	printf("%d * %d = %d \n", a, b, c);
}
/*�� ���� ���� ����Ͽ� �����ִ� ����� �Լ�*/
int product(int x, int y) {
	return(x * y);
}
