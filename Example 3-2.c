#include<stdio.h>
#pragma warning(disable:4996)
void main() {
	int in_money, coin_500, coin_100, coin_50, coin_10;
	printf(" 동전으로 교환할 금액은? ");
	scanf("%d", &in_money);
	coin_500 = in_money/500;
	in_money = in_money%500;
	coin_100 = in_money/100;
	in_money = in_money%100;
	coin_50 = in_money/50;
	in_money = in_money%50;
	coin_10 = in_money / 10;
	in_money = in_money % 10;
	printf("\n 오백 원짜리 => %d 개 \n", coin_500);
	printf(" 백 원짜리 => %d 개 \n", coin_100);
	printf(" 오십 원짜리 => %d 개 \n", coin_50);
	printf(" 십 원짜리 => %d 개 \n", coin_10);
	printf(" 바꾸지 못한 잔돈 => %d 개 \n", in_money);
}
/*의문점: 
1) scanf 쓸때 &를 붙이는 이유? 
&: ampersand(앰퍼샌드)는 해당 변수의 주소를 가리키는 역할을 한다. -> 추후 포인터 개념과도 연결
무슨말이냐면, 현재 예시의 in_money는 정의할 때 변수의 주소를 모르기 때문에 주소값을 넣어줘야한다는 뜻
혹은, scanf는 변수의 주소를 이용하여 함수처리를 하기 때문에 주소값을 넣어줘야 한다로 받아들일 것
(다만, 여기에서도 문자열 같은애들은 & 안써도 됨(이미 주소값을 입력한 꼴이 되므로))

안넣으면 컴파일 에러남, 일단 초기화가 안되었음 에러가 뜸

그러면 초기화하면 되는거 아닌가? 초기화 해보고 in_money=0; 다시 돌려보자

오류 Expression : result_pointer != nullptr 가 뜸 
이건 무슨오류? 입력 받을 변수에 &을 붙이지 않았을 때 나는 오류 (포인터가 비어있다! 라는 소리) 

결론) 포인터쪽 하면서 추가 보완해보자, 일단은 scanf 쓸때 정수형은 변수 주소를 넣어야 한다(&변수) 


2) %500 이런거는 실제값을 치환하려고 붙인건가, /로 다시쓰면 안되나? 
%는 나누기가 아니라 나머지를 의미함, 따라서 나누고나서 나머지를 원값에 넣고 추가연산을 하기 위함
*/