#include<stdio.h>
/* �����ܸ���� = ���� for���� ���� */

int i, j;

int main()
{
	for (int i = 1; i <= 9; i++) {
		printf("�̰� %d���̶���\n", i);
		for (int j = 1; j <= 9; j++) {
			printf("\t%d * %d = %d\n", i, j, i * j);
		}
	}
	return 0;
}

//for�� ����, (����; ����; ����){��¹� ��}
//i=1�϶�, j=1~9�� ����, i=2�϶� j=1~9�� ����
//�ش� ���̽��� ���� �ݺ���(for��)���� �ذ� 

