#include<stdio.h>  //파일포함 선행처리기
#pragma warning(disable:4996) //scanf 오류 메시지를 제거하기 위한 명령어
void main() { //main()함수의 시작
	int n, count; //변수 n과 count를 정수형으로 선언 
	float avg, d, sum = 0; //변수 avg, d, sum 을 실수(float)형으로 선언하고 이중 sum은 0으로 값을 초기화 
	float list[100]; ////변수 list를 실수형 배열로 선언하고, 배열의 크기를 100으로 지정
	printf("평균을 내고자 하는 데이터의 개수는? "); // 평균을 내고자 하는 데이터의 개수는? 이라는 내용을 출력한다. 
	scanf("%d", &n); // 정수를 입력받아 변수 n에 저장한다. 
	for (count = 0; count < n; ++count) { //count 값이 n보다 커지면 조건식이 거짓이 되어 루프를 빠져나옴 
		printf("i = %d x =", count + 1); 
		/* i = %d x = 이라는 내용을 출력한다. 이때, %d 값은 1,2,3,...,n까지 출력한다. 
		(왜냐하면 count 는 n-1까지만 조건식을 수행하며, count가 n-1인 경우 %d는 n(count+1) 값이 출력됨) */
		scanf("%f", &list[count]); //실수를 입력받아 배열 list[count]에 저장한다. 
		sum += list[count]; // sum = sum + list[count] 
	}
	avg = sum / n; // sum/n 값을 avg에 반영한다. 
	printf("The average is %5.2f \n", avg); // The average is %5.2f를 출력한다. 이 때 %5.2f에 avg 를 총 5자리(소수점 포함), 소수점 이하 2자리 실수로 출력한다.

	for (count = 0; count < n; ++count) { //count 값이 n보다 커지면 조건식이 거짓이 되어 루프를 빠져나옴 
		d = list[count] - avg; // list[count] - avg 값을 d에 반영한다. 
		printf("i = %d x = %5.2f d = %5.2f \n", count + 1, list[count], d); 
		//i = %d x = %5.2f d = %5.2f (띄어쓰기) 를 출력한다. 이때 i값은 정수형으로, x와 d는 총 5자리(소수점 포함), 소수점 이하 2자리 실수로 출력한다.
	}
}