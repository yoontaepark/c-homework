#include<stdio.h>

void say_hello(void);  
/*
prototyping, function declaration, 이런식으로 하면 링킹을 통해서 main > say_hello 실행 > 위에 정의되어있음+아래 자세한 함수를 링킹 > 함수호출 및 실행됨
*/


int main()
{	
	say_hello();

	return 0;
}

void say_hello(void)  //함수만들기 
{
	printf("Hello, World!\n");

	return;
}



/* 컴파일 시키면 main부터 무조건 시작함. 이때 say hello()라는 함수를 실행시키고, 
say_hello는 위에 함수정의식에 따라 printf를 실행시킴. 그걸 반복한 후에 main함수의 return 0 까지가면 끝남
함수를 main 함수 뒤로 정의하면 함수가 정의안되어있기 때문에 에러가남 
1) 함수자체를 main 위로 올린다 - main이 잘 안보임(안좋음)
2) 함수 한줄만 main 위로 올린다(함수의 선언부분만 변수선언하듯이 main 함수 위로 올림) 




*/