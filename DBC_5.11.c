#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//자료형 변환에 대한 내용
int main()
{
/* promotions in assignments
   진급개념으로, 하위자료형 값을 상위자료형에 넣으면 에러가 안난다 정도 */
	//short s = 64;
	//int i = s;

	//float f = 3.14f; //일단 뒤에 f안붙이면 double로 인식해서 f를 붙여주는 개념임 
	//double d = f;

/* demotion in assignments
   강등개념으로, 상위자료형 값을 하위자료형에 넣으면 에러가 나기 쉬움(웬만하면 이렇게 하지말자) */
	//d = 1.25;
	//f = 1.25; //0.25는 2^(-2)이어서 에러메시지를 굳이 내지는 않는 모습
	//f = 1.123; //double 형태를 float 형태에 넣으려니 warning 메시지 송출(일단 값은 나오긴 함) 

/* ranking of types in operations: 윗줄이 상위자료형이고, 같은 줄에 있으면 같은 랭킹이라고 생각하면 됨*/
	/*long double > double > float
	unsigned long long, long long 
	unsigned long, long
	unsigned, int
	short int, unsigned short int
	signed char, char, unsigned char 
	_Bool
	ref: Google 'Integer conversion rank'*/
	//d = f + 1.234; //f+d이기 때문에 f를 d로 바꿔주고 d자료형에 넣으니 에러 안남
	//f = f + 1.234; //f+d이기 때문에 f를 d로 바꿔주는데 f자료형에 넣으니 warning 남

	/* automatic promotion of function arguments: 예외들이라고는 하는데 지금은 그냥 그런게 있나보다만 
	1. Functions without prototypes
	2. Variadic functions
	*/

	/* casting operators */
	//d = (double)3.14f; //()를 통해 형변환을 시키고나서 d에 대입함 
	//i = 1.6 + 1.7; // 3.3나오고나서 절삭해서 3이 나옴
	//i = (int)1.6 + (int)1.7; // 각각 1이 되기 때문에 1+1 = 2가 됨

	/* more examples */
	char c;
	int i;
	float f;
	f = i = c = 'A'; // 65가 나올것이나 f로 변환되면서 자료손실이 있을 것이라는 에러가 뜸. 유효숫자 차이때문
	printf("%c %d %f\n", c, i, f);
	c += 2; //'C', 67이 나옴
	i = f + 2 * c; // 65.0f+2*67 = 199가 나옴
	printf("%c %d %f\n", c, i, f);
	c = 1106; //숫자가 짤림, 1106 = 0b10001010010 으로 변환한담에 앞 0b, 뒤 8자리빼고 다날림(8비트이므로) -> 0b01010010 = 82 = 1106 % 256 = 'R'
	// 뒤 8자리 빼고 짜른다는 의미가 256으로 나눈 나머지를 표현한다는 뜻임
	printf("%c\n", c); 

	c = 83.99;
	printf("%c\n", c); //83이 나옴 

	return 0;
}