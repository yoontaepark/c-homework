#include<stdio.h>
#include<string.h>
void main() {
	char* s1 = "bbba";
	char* s2 = "bbb";
	int stat;
	stat = memcmp(s1, s2, 3);
	printf("%d", stat);
}