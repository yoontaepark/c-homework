#include<stdio.h>  //�������� ����ó����
#pragma warning(disable:4996) //scanf ���� �޽����� �����ϱ� ���� ��ɾ�
void main() { //main()�Լ��� ����
	int n, count; //���� n�� count�� ���������� ���� 
	float avg, d, sum = 0; //���� avg, d, sum �� �Ǽ�(float)������ �����ϰ� ���� sum�� 0���� ���� �ʱ�ȭ 
	float list[100]; ////���� list�� �Ǽ��� �迭�� �����ϰ�, �迭�� ũ�⸦ 100���� ����
	printf("����� ������ �ϴ� �������� ������? "); // ����� ������ �ϴ� �������� ������? �̶�� ������ ����Ѵ�. 
	scanf("%d", &n); // ������ �Է¹޾� ���� n�� �����Ѵ�. 
	for (count = 0; count < n; ++count) { //count ���� n���� Ŀ���� ���ǽ��� ������ �Ǿ� ������ �������� 
		printf("i = %d x =", count + 1); 
		/* i = %d x = �̶�� ������ ����Ѵ�. �̶�, %d ���� 1,2,3,...,n���� ����Ѵ�. 
		(�ֳ��ϸ� count �� n-1������ ���ǽ��� �����ϸ�, count�� n-1�� ��� %d�� n(count+1) ���� ��µ�) */
		scanf("%f", &list[count]); //�Ǽ��� �Է¹޾� �迭 list[count]�� �����Ѵ�. 
		sum += list[count]; // sum = sum + list[count] 
	}
	avg = sum / n; // sum/n ���� avg�� �ݿ��Ѵ�. 
	printf("The average is %5.2f \n", avg); // The average is %5.2f�� ����Ѵ�. �� �� %5.2f�� avg �� �� 5�ڸ�(�Ҽ��� ����), �Ҽ��� ���� 2�ڸ� �Ǽ��� ����Ѵ�.

	for (count = 0; count < n; ++count) { //count ���� n���� Ŀ���� ���ǽ��� ������ �Ǿ� ������ �������� 
		d = list[count] - avg; // list[count] - avg ���� d�� �ݿ��Ѵ�. 
		printf("i = %d x = %5.2f d = %5.2f \n", count + 1, list[count], d); 
		//i = %d x = %5.2f d = %5.2f (����) �� ����Ѵ�. �̶� i���� ����������, x�� d�� �� 5�ڸ�(�Ҽ��� ����), �Ҽ��� ���� 2�ڸ� �Ǽ��� ����Ѵ�.
	}
}