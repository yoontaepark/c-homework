#include <stdio.h>
#pragma warning(disable:4996)
struct BYTE {
	unsigned char l, h;
};

union body {
	struct BYTE byte;
	unsigned short word;
};

union body swap(union body x) {
	union body y;
	y.byte.l = x.byte.h;
	y.byte.h = x.byte.l;
	return(y);
}

void main(void) {
	union body a, b;
	printf("data ? ");
	scanf("%x", &a.word);
	b = swap(a);
	printf("%x -> %x \n", a.word, b.word);
}