#include <stdio.h>
#pragma warning(disable:4996)
#define SIZE 10

void bubble(int*, const int, int (*)(int, int));
int ascending(const int, const int);
int descending(const int, const int);

void main()
{
	int a[SIZE] = {2,6,4,8,10,12,89,68,45,37};
	int counter, order;
	printf("�������� ������ 1, �������� ������ 2�� �������� : ");
	scanf("%d", &order);
	printf("\n ���� ������ \n");
	for (counter = 0; counter <= SIZE - 1; counter++)
		printf("%4d", a[counter]);
	if (order == 1)
	{
		bubble(a, SIZE, ascending);
		printf("\n ������������ ������ ������ \n");
	}
	else
	{
		bubble(a, SIZE, descending);
		printf("\n ������������ ������ ������ \n");
	}
	for (counter = 0; counter <= SIZE - 1; counter++)
		printf("%4d", a[counter]);
	printf("\n");
}

void bubble(int *work, const int size, int (*compare)(int, int))
{
	int pass, count;
	void swap(int*, int*);
	for(pass = 1; pass <= size -1; pass++)
		for(count = 0; count <= size - 2; count++)
			if((*compare)(work[count], work[count + 1]))
				swap(&work[count], &work[count + 1]);
}

void swap(int* element1ptr, int* element2ptr)
{
	int temp;
	temp = *element1ptr;
	*element1ptr = *element2ptr;
	*element2ptr = temp;
}

int ascending(const int a, const int b)
{
	return b < a;
}

int descending(const int a, const int b)
{
	return b > a;
}