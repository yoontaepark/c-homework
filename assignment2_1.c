#include <stdio.h> //파일포함 선행처리기
#pragma warning(disable:4996) //scanf 오류 메시지를 제거하기 위한 명령어
char upper(char ch); //upper 함수의 원형 선언 
char lower(char ch); //lower 함수의 원형 선언
void main() //main()함수의 시작
{
	char in_s[50], out_s[50];  //변수 in_s와 out_s를 문자형 배열로 선언하고, 배열의 크기를 50으로 지정
	char ch; //변수 ch를 문자형으로 선언
	int i = 0; //변수 i를 정수형으로 선언하고 0으로 값을 초기화 
	printf("문자열을 입력하시오. (50자 이내) : "); //문자열을 입력하시오. (50자 이내) : 라는 내용을 출력한다. 
	scanf("%s", in_s);// 문자열을 입력받아 배열 in_s에 저장  
	ch = in_s[i]; //while문 하단의 upper(char ch)와 lower(char ch) 함수를 사용하기 위해 배열 in_s의 각 요소를 ch로 변환한다
	while (ch != '\0') { //ch=in_s[i] 값이 '\0'(null)이 되면 조건식이 거짓이 되어 루프를 빠져나옴
		if (ch >= 'A' && ch <= 'Z') //ch 값이 대문자 A~Z(ASCII 코드값으로 십진수 65~90) 사이라면 다음줄 내용을 수행한다.  
			out_s[i] = lower(ch); // lower(ch)함수를 호출하고, 함수 수행결과를 넘겨받아 out_s[i]에 반영한다.   
		else if (ch >= 'a' && ch <= 'z') //ch 값이 소문자 a~z((ASCII 코드값으로 십진수 97~122)) 사이라면 다음줄 내용을 수행한다.
			out_s[i] = upper(ch); // upper(ch)함수를 호출하고, 함수 수행결과를 넘겨받아 out_s[i]에 반영한다.   
		else //ch 값이 위의 두가지 조건에 해당하지 않는 경우 다음줄 내용을 수행한다
			out_s[i] = ch; // ch값을 out_s[i]에 반영한다. 
		i++; //i값을 1 증가시켜 저장한다
		ch = in_s[i]; // in_s[i] 값을 ch에 반영한다. 이때 윗줄의 증가된 i += 1 값이 반영됨 
	}
	out_s[i] = '\0'; //while문을 빠져나온 경우, in_s[i]의 가장 마지막 배열(null) 값을 입력받았을 것이므로 이에 대응하여 '\0' 으로 값을 반영한다.  
	printf("변환된 결과 ==> %s \n", out_s); //out_s의 문자형 배열을 모두 출력한다.
}

char upper(char ch) { //상단에 선언했던 upper 함수의 정의
	return ch - 32; //ch값에서 -32를 한 값을 호출함수로 넘긴다. (예컨대 소문자 a~z였다면 정확히 대문자 A~Z로 변환됨) 
}

char lower(char ch) { //상단에 선언했던 lower 함수의 정의
	return ch + 32; //ch값에서 +32를 한 값을 호출함수로 넘긴다. (예컨대 대문자 A~Z였다면 정확히 소문자 a~z로 변환됨) 
}