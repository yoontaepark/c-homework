/* n���� �Ǽ��� Ű���带 ���� �޾Ƶ鿩 ��հ� ǥ�������� ���ϴ� ���α׷���. 
ǥ������ d = xi-avg,
i=1,2,...,n
xi�� �� ����, avg�� ��� */

#include<stdio.h>
#pragma warning(disable:4996)
void main() {
	int n, count;
	float avg, d, sum = 0;
	float list[100];
	printf("����� ������ �ϴ� �������� ������? ");
	scanf("d%", &n);
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