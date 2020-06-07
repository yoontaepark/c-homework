#include <stdio.h>
#include <stdbool.h> // bool function을 선언할 수 있음
#include <complex.h> // 복소수형 관련 function 

int main()
{
	//복소수형 관련 기능을 일부 지원한다 정도만 알고 있자
	_Dcomplex z;
	z._Val[0] = 1.0;
	z._Val[1] = 1.0;


	//불리언형(논리계산할때 쓰는 형태임, 최근에 bool 타입이 추가되었음, 가질 수 있는 값은 T or F 만 있음)  

	printf("%u\n", sizeof(_Bool)); //1byte (최소단위이며 1bit를 사용하지만 표현되는단위가 1byte여서 7bit는 낭비되는 상황) 

	_Bool b1;
	b1 = 0; //false 
	b1 = 1; //true (이건 false아니면 나머지를 true로 봄)

	printf("%d\n", b1);

	bool b2, b3;
	b2 = true; //이렇게 문법을 쓸수는 있지만 숫자임 
	b3 = false;

	printf("%d %d\n", b2, b3); //따라서 %d로 표현함(%c 이런거 아님) 

	return 0;
}