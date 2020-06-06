#include<stdio.h>
//cppreference.com 참고해보기 (https://en.cppreference.com/w/c/keyword
int main()
{
	//print formatted의 약자임 (printf)
	
	printf("\"The truth is ... \nI am Ironman.\"\n");  // \n = escape sequence, 줄바꿈하고나서 뛰어쓰기 하고 싶겠지만 안띄어야 다음줄 처음부터 글자가 써짐 
	// 따옴표까지 같이 출력하고 싶다고 "" 이렇게 하면 그냥 출력이 끝나버림 "(빈칸)" 이런식으로
	// \이걸 넣어서 구분하면 됨

	int x, y, z; // 변수에 오른쪽클릭 + rename해서 바꿀수있음 (ctrl+r)
	x = 1;
	y = 2;

	z = x + y;
	
	printf("The answer is %i+%i = %i", x,y,z);
	printf("\a");  //소리를 내는 출력임(문자 출력이 아니고) 

	// 전체잡고 주석넣기(ctrl+k+c), 주석풀기(ctrl+k+u), 블럭만 잡으면 /*꼴로 잡힘(아닌 경우 모든줄에 각각 // 잡힘)
	return 0;
}