#include <stdio.h>
void main()
{
	union shared_tag {
		char c;
		int i;
		long l;
		float f;
		double d;
	} shared;

	shared.c = '$';
	printf("\n char c = %c", shared.c);
	printf("\n int i = %d", shared.i);
	printf("\n long l = %1d", shared.l);
	printf("\n float f = %f", shared.f);
	printf("\n double d = %f", shared.d);

	shared.d = 123456789.8765;
	printf("\n\n char c = %c", shared.c);
	printf("\n int i = %d", shared.i);
	printf("\n long l = %ld", shared.l);
	printf("\n float f = %f", shared.f);
	printf("\n double d = %f", shared.d);
}