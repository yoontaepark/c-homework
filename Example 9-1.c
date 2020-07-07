#include <stdio.h>
#include <stdlib.h> // 동적 할당 함수를 위한 헤더 파일
#include <string.h>
#pragma warning(disable:4996)

void main()
{
	char* str[3];
	char temp[100];
	int i, j, size;
	
	printf("문자열 3개 입력하시오. \n");
	for (i = 0; i < 3; i++)
	{
		printf(" %d 번째 문자열: ", i+1);
		gets(temp);
		size = strlen(temp);
		str[i] = (char*) malloc( (sizeof(char) * size) + 1);
		strcpy(str[i], temp);
	}
	printf("입력과 반대로 출력(문자열 순서도 반대로)\n");
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
