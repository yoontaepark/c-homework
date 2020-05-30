/* 사용자로부터 양의 정수를 5개 입력받아 합을 구하시오
단, 음수를 입력했을 경우에는 재입력을 요구한다*/

#include<stdio.h>
#pragma warning(disable:4996)
void main() {
	int sum = 0, num = 0, i = 0;
	printf("양의 정수 5개를 입력해주세요. 음수를 입력했을 경우 해당 값은 무시됩니다. \n");
	while (i < 5) {
		while (num <= 0) {
			printf("양의 정수를 입력(%d번째): ", i + 1);
			scanf("%d", &num);
		}
		sum += num;
		num = 0;
		i++;
	}
	printf("총합: %d \n", sum);
}

/* 음수 입력시 재입력 로직은 num란에 음수가 들어가는 순간, while 조건문을 실행하지 않고 다시 올라가는 것으로 보임*/