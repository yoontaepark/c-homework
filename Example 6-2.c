#include <stdio.h>
#define SIZE 5
int main()
{
	int row, col;
	int a[SIZE][SIZE] = { 0 };
	int i = SIZE / 2;
	int num = 1;
	for (row = 0; row < SIZE; row++)
	{
		for (col = 0; col < SIZE; col++)
		{
			if (row > col && row < SIZE - i)
				printf("%2d ", a[row][col]);
			else if(col + row >= SIZE && row < SIZE - i)
				printf("%2d ", a[row][col]);
			else if (row == i && row != col)
				printf("%2d ", a[row][col]);
			else if (col + row < SIZE-1 && row > i)
				printf("%2d ", a[row][col]);
			else if (row < col && row > i)
				printf("%2d ", a[row][col]);
			else
			{
				a[row][col] = num;
				printf("%2d ", a[row][col]);
				num++;
			}
		}
		printf("\n");
	}

}