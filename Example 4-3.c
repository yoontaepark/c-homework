/* �Է� ���ڿ� �� ����, ����, ������ ���� ����ϴ� ���α׷� */

#include<stdio.h>
#pragma warning(disable:4996)

void main() {
	char ch;
	int Nchar = 0, Nnum = 0, Nblank = 0;
	printf("���ڿ��� �Է��Ͻÿ� : ");
	while ((ch = getchar()) != '\n') {
		if (ch >= '0' && ch <= '9')
			++Nnum;
		else if (ch == ' ' || ch == '\t')
			++Nblank;
		else
			++Nchar;
	}
	printf("\n ***** ��� ***** \n");
	printf("����=%d \n", Nnum);
	printf("����=%d \n", Nblank);
	printf("����=%d \n", Nchar);
}