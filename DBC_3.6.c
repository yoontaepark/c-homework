#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h> //가장 큰 값과 가장 작은값을 알려주는 헤더 
#include <stdlib.h> //_itoa 쓰려고 포함시킨 헤더

int main()
{
	unsigned int i = 0b11111111111111111111111111111111; //0b는 2진수라는 소리임, 1이라는 2진수를 32개 입력함 
	unsigned int u_max = UINT_MAX; //unsinged의 가장 큰 값, 더궁금하면 오른쪽클릭 > go to definition 가서 보면 정의되어 있는걸 볼 수 있다. 
	unsigned int u_min = 0; //unsinged의 가장 작은 값, 매크로 없고 그냥 0임(최소가) 
	signed int x_max = INT_MAX;  //signed의 가장 큰 값 
	signed int x_min = INT_MIN;  //signed의 가장 큰 값 

	unsigned int y_max =0-1; //unsinged의 가장 큰 값, 더궁금하면 오른쪽클릭 > go to definition 가서 보면 정의되어 있는걸 볼 수 있다. 

	char buffer[33];
	_itoa(y_max, buffer, 2);  

	printf("decimal: %u\n", y_max);
	printf("binary: %s\n", buffer); //2진수형으로 표현했을때 값이 초과되면 되려 11111 + 1 -> 0으로 가버림 , 0 - 1이면 가장큰값이 되어버림  : 오버플로우 개념 
	//그냥 컴퓨터 계산이 이렇게 되는거다 라고만 이해하기 
	printf("============================================\n");


	printf("max of uint = %u\n", u_max);
	printf("min of uint = %u\n", u_min);
	printf("max of int = %d\n", x_max);
	printf("min of int = %d\n", x_min);
	printf("============================================\n");

	printf("%u\n", i);  // %d로 넣으면 에러남, unsigned는 u로 맞춰줘야 에러가 안남, 작은값은 에러가 안남 
	printf("%u\n", u_max); 
	printf("============================================\n");

	printf("%u\n", sizeof(unsigned int)); // sizeof에 커서들 가져다대면 4u 이런식으로 뜨는데, unsigned int자료형이 4byte를 차지하고 있다는 소리임 
	//""에다가 뒤에 나오는 함수와 자료형을 일치시켜야 함. 따라서 "u"를 사용함 
	printf("%u", sizeof(i));  //위와 동일한 표현 

	return 0;
}