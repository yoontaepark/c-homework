#include <stdio.h> //파일포함 선행처리기
#pragma warning(disable:4996) //scanf 오류 메시지를 제거하기 위한 명령어
struct entry { //entry형 구조체 선언
	char fname[20]; //구조체 멤버 fname을 문자형 배열로 선언하고 배열의 크기를 20으로 지정  
	char lname[20]; //구조체 멤버 lname을 문자형 배열로 선언하고 배열의 크기를 20으로 지정  
	char phone[10]; //구조체 멤버 phone을 문자형 배열로 선언하고 배열의 크기를 10으로 지정  
};
struct entry list[4]; //구조체 배열 list[]를 선언하고 배열의 크기를 4로 지정
int i; // 변수 i를 정수형으로 선언

void main() { //main()함수의 시작
	for (i = 0; i < 4; i++) { //i 값이 4보다 커지면 조건식이 거짓이 되어 루프를 빠져나옴 
		printf("Enter first name : ");  // Enter first name : 을 출력한다.
		scanf("%s", list[i].fname); //구조체 배열 list[]의 멤버 fname을 문자열로 입력받아 저장한다. 
		printf("Enter last name : "); // Enter last name : 을 출력한다.
		scanf("%s", list[i].lname); //구조체 배열 list[]의 멤버 lname을 문자열로 입력받아 저장한다. 
		printf("Enter phone number : "); // Enter phone number : 를 출력한다.
		scanf("%s", list[i].phone); // 구조체 배열 list[]의 멤버 phnoe을 문자열로 입력받아 저장한다. 
		printf("\n"); // 띄어쓰기를 출력한다. 
	}
	printf("\n"); // 띄어쓰기를 출력한다. 
	for (i = 0; i < 4; i++) { //i 값이 4보다 커지면 조건식이 거짓이 되어 루프를 빠져나옴 
		printf("Name : %s %s", list[i].fname, list[i].lname); //Name : %s %s 을 출력한다. 이때, %s %s에는 각각 구조체 배열 list[]의 멤버 fname, lname을 출력한다. 
		printf("\t\tPhone : %s \n", list[i].phone); // (tab)(tab) Phone : %s (띄어쓰기) 를 출력한다. 이때 %s에는 구조체 배열 list[]의 멤버 phone을 출력한다. 
	}
}

