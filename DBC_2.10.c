#include<stdio.h>

void say_hello(void);

int main()
{
	int x, y, z;

	x = 1;
	y = 20;
	z = 3;
	
	z = x + y;
	
	say_hello();

	return 0;
}

void say_hello(void) //function definition
{
	int x = 1;
	x = 10;

	printf("Hello, World\n");
	
	return;
}

/* 왼쪽 긴벽돌...같은거 누르면 break point라고 지정할 수 있는데, 원하는 지점까지 debug를 실행시키는거라도 생각하면 됨
f5를 누르면 원하는지점까지 debug가 수행되고, 분석할 수 있는 debug 창이 뜸. f11 눌러서 step into 누르면 한줄씩 수행함
함수에 들어갈 수 있으면 함수로 넘어가고, 아닌놈들은 그냥 지나감. 끝까지 가면 출력화면이 뜸 
f10을 누르면 step over 인데, 함수같은 애들을 들어가서 보지는 않고 그냥 넘어만 감. 끝까지 가면 출력화면이 뜸*/