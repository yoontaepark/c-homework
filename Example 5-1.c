/*대문자를 소문자로, 소문자를 대문자로 변환하는 프로그램 */
#include<stdio.h>
#pragma warning(disable:4996)

char upper(ch) {
	return ch - 32;
}
char lower(ch) {
	return ch + 32;
}

int main() {
	char in_s[50], out_s[50];
	char ch;
	int i = 0;
	printf("문자열을 입력하시오. (50자 이내): ");
	scanf("%s", in_s);
	ch = in_s[i];
	while (ch != '\0') {
		if (ch >= 'A' && ch <= 'Z')
			out_s[i] = lower(ch);
		else if (ch >= 'a' && ch <= 'z')
			out_s[i] = upper(ch);
		else
			out_s[i] = ch;
		i++;
		ch = in_s[i];
	}
	out_s[i] = '\0';
	printf("변환된 결과 ==> %s \n", out_s);
	return 0;
}

/* 
1. out_s[i] = '\0'; : 문자열을 표현할 때는 문자열의 끝을 의미하는 \0을 넣어준다. 안넣으면 이상하게 디버깅이 됨
2. 입력받은 문자열 in_s를 ch로 변환하고, 이때 ch가 대문자(A~Z)면 lower(ch)를 out_s로 변환한다. 
   lower(ch)는 ch+32를 리턴함(즉, 대문자 → 소문자라는 소리, 아스키코드 기준으로 대문자+32=소문자임)
   다음줄에 printf 를 통해 변환된 결과값을 out_s로 출력하면, ch+32 로 문자가 변형되어 출력된다. 
   
   소문자(a~z)면 upper(ch)를 out_s로 변환한다. upper(ch)는 ch-32를 리턴하기 때문에, 소문자에서 대문자로 변형이 되고, 
   이 값을 out_s에 저장한 후 printf로 출력함 

   A~Z, a~z 둘다 아니라면 ch를 out_s로 변환한다. 즉, 값을 안바꾸기 때문에 입력한 그대로 값이 출력된다. 
   솔직히 책이 좀 설명이 부실하다;;;

3. lower랑 upper를 main 위에 표현하는 이유는 return 값을 넣어야하는데, 이걸 main에 넣으면 실행에러가 난다. 
   왜인지는 추가로 공부해봐야할듯
*/

