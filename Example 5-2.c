/* ����Լ��� �̿��Ͽ� factorial�� ����ϴ� ���α׷�
   ����Լ��� �ڱ��ڽ��� ȣ���ϴ� �Լ��� ���Ѵ� */
#include<stdio.h>
#pragma warning(disable:4996)
unsigned int f, x, factorial(unsigned int a);
int main() {
    puts("Enter an integer value between 1 and 10 : ");
    scanf("%d", &x);
    if (x > 10 || x < 1) {
        printf("Only values from 1 to 10 are acceptable");
    }
    else {
        f = factorial(x);
        printf("%u factorial equals %u \n", x, f);
    }
    return 0;
}

unsigned int factorial(unsigned int a) {
    if (a == 1)
        return 1;
    else {
        a *= factorial(a-1);
        return a;
    }
}

/*
1. puts�� printfó�� ����Լ���, x<1, x>10 �ϰ�쿡�� if��, 
1<=x<=10 �̸� f�� ���丮�� ó���ϰ�, x ���丮���� f�̴ٸ� ��� 

<���⼭���ʹ� �߰������ؾ��ҵ�...>
main�Լ� �Ʒ����ٰ� factorial(a) ���� �ʱ�ȭ ��Ŵ
a�� 1�̸� 1��, 1�� �ƴѰ�쿡�� a-1�� a�� ��ȯ���Ѽ� a�� ���
*/
