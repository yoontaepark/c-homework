#include <stdio.h>
#include <stdlib.h> // ���� �Ҵ� �Լ��� ���� ��� ����
#include <string.h>
#pragma warning(disable:4996)

void main()
{
	char* str[3];
	char temp[100];
	int i, j, size;
	
	printf("���ڿ� 3�� �Է��Ͻÿ�. \n");
	for (i = 0; i < 3; i++)
	{
		printf(" %d ��° ���ڿ�: ", i+1);
		gets(temp);
		size = strlen(temp);
		str[i] = (char*) malloc( (sizeof(char) * size) + 1);
		strcpy(str[i], temp);
	}
	printf("�Է°� �ݴ�� ���(���ڿ� ������ �ݴ��)\n");
	for (i = 2; i >= 0; i--)
	{
		size = strlen(str[i]);
		temp[size] = '/0';
		for (j = size - 1; j >= 0; j--)
			temp[size-1-j] = str[i][j];
		printf(" %d : %s \n", i+1, temp);
	}
	for (i = 0; i < 3; i++)
		free(str[i]);
}
