/* 자료 전달방법인 값에 의한 자료 전달방법과 참조에 의한 자료전달 방법의 차이점을 보이는 프로그램임 */

#include<stdio.h>
void by_value(int a, int b, int c);
void by_ref(int *a, int *b, int *c);
void main() {
	int x = 2, y = 4, z = 6;
	printf("Before calling by_value() \t: ");
	printf("x=%d, y=%d, z=%d \n", x, y, z);
	by_value(x, y, z);
	printf("After calling by_value() \t: ");
	printf("x=%d, y=%d, z=%d \n", x, y, z);
	by_ref(&x, &y, &z);
	printf("After calling by_ref() \t: ");
	printf("x=%d, y=%d, z=%d \n", x, y, z);
}
void by_value(int a, int b, int c) {
	a = 0;
	b = 0;
	c = 0;
	}
void by_ref(int *a, int *b, int *c) {
	*a = 0;
	*b = 0;
	*c = 0;
}

/* by_value 로 출력을 하면, 지정된 값으로 출력이 됨. 
   by_ref로 출력을 하면, 포인터로 주소를 지정을 하여 주소에 있는 값을 끌고 옴. 
   by_value의 경우 x,y,z 값을 끌고 오나, by_ref의 경우 주소지인 a,b,c 값을 가져옴. 
   즉, &x, &y, &z 는 *a, *b, *c의 값을 끌고오도록 하는 개념임 
   */