#include<stdio.h>  //입출력함수, 파일관련 함수를 사용하기 위한 헤더 파일 선언(printf, scanf_s, typedef, if, else if, else, for, sprint_s 等)  
#include<stdlib.h> //수치변환함수를 사용하기 위한 헤더 파일 선언(atoi) 

typedef struct student { //student 구조체 선언
	char name[50]; //이름
	char major[50]; //학과
	char idno[50]; //주민등록번호
	char* yearhead; //연도 앞 2자리
	char* nation; //출생지역(대한민국, 외국)
	char* gender; //성별(남자, 여자) 
	char* yuncheck; //윤년체크 
	char buffer[256]; //년도 4자리 문자열 (주민등록번호 앞 7번째 숫자와 앞 1,2번째 숫자를 조합하여 생성)
	int year; //년도 4자리 정수형
}std;  //student 구조체를 선언하고, 새로운 이름 std로 정의

void main() { //main 함수
	int i = 0, j = 0; //정수형 i, j 선언 
	std member[3], *ptr[3], temp; //구조체 std형의 배열 선언
		
	for (i = 0, i < 3; i++;) ptr[i] = &member[i]; //구조체를 가르키는 포인터 초기화

	printf("3명의 학생 정보를 입력하시오. \n"); //출력문 1번째 라인

	for (i = 0; i < 3; i++) { //반복문을 사용하여 3명의 정보를 입력받음
		printf("---------------------------------------- \n"); //반복문의 구분줄 출력

		/*첫번째 값을 입력*/
		printf("이름 : "); 
		scanf_s("%s", &member[i].name, 20);

		/*두번째 값을 입력*/
		printf("학과 : ");
		scanf_s("%s", &member[i].major, 20);
		
		/*세번째 값을 입력*/
		printf("주민등록번호 : ");
		scanf_s("%s", &member[i].idno, 20);

		/*주민등록번호 앞 7번째 자리가 1인경우, 1900년대 출생한 대한민국 남자로 판단하여 변수에 저장 */
		if (member[i].idno[6] == '1') {
			member[i].yearhead = "19";
			member[i].nation = "대한민국";
			member[i].gender = "남자";
		}
		/*주민등록번호 앞 7번째 자리가 2인경우, 1900년대 출생한 대한민국 여자로 판단하여 변수에 저장 */
		else if (member[i].idno[6] == '2') {
			member[i].yearhead = "19";
			member[i].nation = "대한민국";
			member[i].gender = "여자";
		}
		/*주민등록번호 앞 7번째 자리가 3인경우, 2000년대 출생한 대한민국 남자로 판단하여 변수에 저장 */
		else if (member[i].idno[6] == '3') {
			member[i].yearhead = "20";
			member[i].nation = "대한민국";
			member[i].gender = "남자";
		}
		/*주민등록번호 앞 7번째 자리가 4인경우, 2000년대 출생한 대한민국 남자로 판단하여 변수에 저장 */
		else if (member[i].idno[6] == '4') {
			member[i].yearhead = "20";
			member[i].nation = "대한민국";
			member[i].gender = "여자";
		}
		/*주민등록번호 앞 7번째 자리가 5인경우, 1900년대 출생한 외국 남자로 판단하여 변수에 저장 */
		else if (member[i].idno[6] == '5') {
			member[i].yearhead = "19";
			member[i].nation = "외국";
			member[i].gender = "남자";
		}
		/*주민등록번호 앞 7번째 자리가 6인경우, 1900년대 출생한 외국 여자로 판단하여 변수에 저장 */
		else if (member[i].idno[6] == '6') {
			member[i].yearhead = "19";
			member[i].nation = "외국";
			member[i].gender = "여자";
		}
		/*주민등록번호 앞 7번째 자리가 7인경우, 2000년대 출생한 외국 남자로 판단하여 변수에 저장 */
		else if (member[i].idno[6] == '7') {
			member[i].yearhead = "20";
			member[i].nation = "외국";
			member[i].gender = "남자";
		}
		/*주민등록번호 앞 7번째 자리가 8인경우, 2000년대 출생한 외국 여자로 판단하여 변수에 저장 */
		else if (member[i].idno[6] == '8') {
			member[i].yearhead = "20";
			member[i].nation = "외국";
			member[i].gender = "여자";
		}
		/*주민등록번호 앞 7번째 자리가 9인경우, 1800년대 출생한 대한민국 남자로 판단하여 변수에 저장 */
		else if (member[i].idno[6] == '9') {
			member[i].yearhead = "18";
			member[i].nation = "대한민국";
			member[i].gender = "남자";
		}
		/*주민등록번호 앞 7번째 자리가 0인경우, 1800년대 출생한 대한민국 여자로 판단하여 변수에 저장 */
		else if (member[i].idno[6] == '0') {
			member[i].yearhead = "18";
			member[i].nation = "대한민국";
			member[i].gender = "여자";
		}
		/*참인 조건이 하나도 없는 경우 실행*/
		else ("존재하지 않는 값입니다");

		/*년도 4자리를 조합하여 buffer 문자열로 저장*/
		sprintf_s(member[i].buffer, sizeof(member[i].buffer), "%s%c%c", member[i].yearhead, member[i].idno[0], member[i].idno[1]); 

		/*buffer 문자열을 정수형태로 변환*/
		member[i].year = atoi(member[i].buffer);

		/*정수형태로 변환된 년도 4자리를 윤년여부 체크하여 윤년여부를 변수에 저장*/
		if ((member[i].year % 4 == 0 && member[i].year % 100 != 0) || member[i].year % 400 == 0) { member[i].yuncheck = "윤년"; }
		else { member[i].yuncheck = "윤년아님"; }

		/*이름, 생년월일, 윤년 여부, 출생지역(대한민국, 외국), 성별(남자, 여자), 학과이름 출력*/
		printf("%s, %s%c%c년 %c%c월 %c%c일, %s, %s, %s, %s \n",
			member[i].name, member[i].yearhead, member[i].idno[0], member[i].idno[1], member[i].idno[2],
			member[i].idno[3], member[i].idno[4], member[i].idno[5], member[i].yuncheck, member[i].nation,
			member[i].gender, member[i].major);
	}

	/*구분줄 및 문구('입력 받은 3명의 정보를 생년월일 기준으로 오름차순으로 출력') 출력 */
	printf("========================================\n");
	printf("입력 받은 3명의 정보를 생년월일 기준으로 오름차순으로 출력 \n");
	printf("---------------------------------------- \n");

	/*입력 받은 3명의 정보를 생년월일 기준으로 오름차순 정렬*/
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < i; j++) {
			if (member[i].year < member[j].year) {
				temp = member[i];
				member[i] = member[j];
				member[j] = temp;
			}
		}
	}
	/*생년월일 기준으로 오름차순 정렬된 3명의 정보를 출력*/
	for (i = 0; i < 3; i++){
		printf("%s, %s%c%c년 %c%c월 %c%c일, %s, %s, %s, %s \n",
			member[i].name, member[i].yearhead, member[i].idno[0], member[i].idno[1], member[i].idno[2],
			member[i].idno[3], member[i].idno[4], member[i].idno[5], member[i].yuncheck, member[i].nation, 
			member[i].gender, member[i].major);
		}

	/*하단 줄바꿈 및 구분줄 출력*/
	printf(" \n");
	printf("---------------------------------------- \n");
}
