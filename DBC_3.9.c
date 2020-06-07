#include<stdio.h>
// #include<stdint.h> -int type들을 사용하기 위해 사용하는 헤더임 
#include<inttypes.h> // 이게 더 상위개념 헤더임

int main()
{
	int i;
	int32_t i32; //32 bit integer로 정수 고정을 시켜버림 
	int_least8_t i8; //smallest 8 bit
	int_fast8_t f8; // fastest minimum
	intmax_t imax; //biggest signed integers
	uintmax_t uimax; //biggest unsigned integers 

	i32 = 1004; 

	printf("me32 = %d\n", i32);
	printf("me32 = %" "d" "\n", i32); //따옴표를 3개로 나눌수 있음
	printf("me32 = %" PRId32 "\n", i32); // 매크로로도 넣을 수 있음, 이런건 나중에 멀티플랫폼 관련해서 업무할때 추가로 고민해보기 

	return 0;
}

// 고정너비정수 사용법