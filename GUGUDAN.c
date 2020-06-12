#include<stdio.h>
/* 구구단만들기 = 이중 for문을 쓰자 */

int i, j;

int main()
{
	for (int i = 1; i <= 9; i++) {
		printf("이건 %d단이란다\n", i);
		for (int j = 1; j <= 9; j++) {
			printf("\t%d * %d = %d\n", i, j, i * j);
		}
	}
	return 0;
}

//for문 쓸때, (선언; 조건; 증감){출력문 등}
//i=1일때, j=1~9를 수행, i=2일때 j=1~9를 수행
//해당 케이스는 이중 반복문(for문)으로 해결 

