#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void draw(int n); //ANSI function prototype declaration

int main()
{
	int i = 5;
	char c = '#';
	float f = 7.1f;

	draw(i);  //i에 대해 *을 찍고
	draw((int)c);  //c에 대해 *을 찍고
	draw((int)f);  //f에 대해 *을 찍자 

	/* Arguments vs. Parameters */
	//con) arguments(values: 값, 상수)
	// paremeters(variables: 변수) 

	return 0;
}

void draw(int n)
{
	while (n-- > 0)	
	printf("*"); //*을 해당하는 만큼 찍고 

	printf("\n");// while문은 나가서 줄바꿈시킴 
}
