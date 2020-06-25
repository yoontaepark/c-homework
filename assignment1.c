#include <stdio.h> //파일포함 선행처리기
void main() //main()함수의 시작
{
	int x[10]; //대입할 값이 1~10이므로 배열 x[10]을 정수형으로 선언
	int* px = x; //포인터 px를 정수형으로 선언하고, 배열 x의 내용을 참조하도록 지정
	int sum_even_numbered = 0;
	// 짝수번 요소의 합(x[0], x[2],...x[8])을 sum_even_numbered라는 정수형 변수로 선언
	int sum_odd_numbered = 0;
	// 홀수번 요소의 합(x[1], x[3],...x[9]]을 sum_odd_numbered라는 정수형 변수로 선언
	for (int i = 0; i < 10; i++) //i를 0부터 9까지 반복시킴
	{
		x[i] = i + 1; //배열 x[0]부터 x[9]까지 각각 1~10을 대입하여 저장함

		if (i % 2 == 0) //i가 짝수라면 if문을, i가 홀수라면 else문을 수행한다
		{
			sum_even_numbered += *(px + i);
			//i가 짝수라면(즉, x[i]가 짝수번 요소라면), 요소의 값을 짝수번 요소의 합에 더해준다.(1+3+5+7+9 = 25)), *(px+i) == x[i]   	
		}
		else
		{
			sum_odd_numbered += *(px + i);
			//i가 홀수라면(즉, x[i]가 홀수번 요소라면, 해당 요소의 값을 홀수번 요소의 합에 더해준다.(2+4+6+8+10 = 30))
		}
	}
	printf("짝수번 요소의 합: %d, 홀수번 요소의 합: %d", sum_even_numbered, sum_odd_numbered); //짝수번 요소의 합과, 홀수번 요소의 합을 출력한다. 
}
