/* n개의 실수를 키보드를 통해 받아들여 평균과 표준편차를 구하는 프로그램임. 
표준편차 d = xi-avg,
i=1,2,...,n
xi는 각 원소, avg는 평균 */

#include<stdio.h>
#pragma warning(disable:4996)
void main() {
	int n, count;
	float avg, d, sum = 0;
	float list[100];
	printf("평균을 내고자 하는 데이터의 개수는? ");
	scanf("%d", &n);
	for (count = 0; count < n; ++count) {
		printf("i=%d x=", count + 1);
		scanf("%f", &list[count]);
		sum += list[count];
	}
	avg = sum / n;
	printf("The average is %5.2f \n", avg);
	for (count = 0; count < n; ++count) {
		d = list[count] - avg;
		printf("i=%d x=%5.2f d=%5.2f \n", count + 1, list[count], d);
	}
}
