/* �ڷ� ���޹���� ���� ���� �ڷ� ���޹���� ������ ���� �ڷ����� ����� �������� ���̴� ���α׷��� */

#include<stdio.h>
void by_value(int a, int b, int c);
void by_ref(int *a, int *b, int *c);
void main() {
	int x = 2, y = 4, z = 6;
	printf("Before calling by_value() \t: ");
	printf("x=%d, y=%d, z=%d \n", x, y, z);
	by_value(x, y, z);
	printf("After calling by_value() \t: ");
	printf("x=%d, y=%d, z=%d \n", x, y, z);
	by_ref(&x, &y, &z);
	printf("After calling by_ref() \t: ");
	printf("x=%d, y=%d, z=%d \n", x, y, z);
}
void by_value(int a, int b, int c) {
	a = 0;
	b = 0;
	c = 0;
	}
void by_ref(int *a, int *b, int *c) {
	*a = 0;
	*b = 0;
	*c = 0;
}

/* by_value �� ����� �ϸ�, ������ ������ ����� ��. 
   by_ref�� ����� �ϸ�, �����ͷ� �ּҸ� ������ �Ͽ� �ּҿ� �ִ� ���� ���� ��. 
   by_value�� ��� x,y,z ���� ���� ����, by_ref�� ��� �ּ����� a,b,c ���� ������. 
   ��, &x, &y, &z �� *a, *b, *c�� ���� ��������� �ϴ� ������ 
   */