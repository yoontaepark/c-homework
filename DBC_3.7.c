#include<stdio.h>

int main()
{
	unsigned int decimal = 4294967295; //10진수
	unsigned int binary = 0b11111111111111111111111111111111; //2진수 표현을 위해 0b 
	unsigned int oct = 037777777777; // 0을 붙이면 8진수임 
	unsigned int hex = 0xffffffff; // 0x를 붙이면 16진수임 , 찾는 방법 4294967295 to hex 이런식으로 구글링하면 변환된 값 검색 가능

	/*10진수 %u로 출력하므로 아래 4줄 값이 같을 것임 */
	printf("%u\n", decimal);
	printf("%u\n", binary);
	printf("%u\n", oct);
	printf("%u\n", hex);
	
	printf("%o %x %#o %#x %#X", decimal, decimal, decimal, decimal, decimal);
	//8진수, 16진수, #을 넣어주면 정확히 0을 넣어서 출력해줌, 
	
	char c = 65;
	short s = 200;
	unsigned int ui = 3000000000U; //U는 생략해도 알아서 인식해줌 
	long l = 65537L;
	long long ll = 12345678908642LL; // LL은 생략해도 알아서 인식해줌 

	printf("char = %hhd, %d, %c\n", c, c, c);
	printf("short = %hhd, %hd, %d\n", s, s, s);
	printf("unsigned int = %u, %d\n", ui, ui);
	printf("long = %ld, %hd\n", l,l);
	printf("long long = %lld, %ld\n", ll,ll);
	
	return 0;
}

//그냥 포맷을 잘 맞춰서 써줘야 오버플로우가 안난다 정도만 인지하자 