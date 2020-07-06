#include <stdio.h>
#pragma warning(disable:4996)
#define MAXFILENAME 50
void main()
{
	char fname[MAXFILENAME];
	int c;
	FILE* fp = NULL;
	fprintf(stdout, "\n파일명을 입력하세요: ");
	scanf("%s", fname);
	fp = fopen(fname, "r");
	fseek(fp, 0, SEEK_END);
	if (ftell(fp) == 0)
		return;
	fseek(fp, -1, SEEK_CUR);
	while (1)
	{
		c = getc(fp);
		putchar(c);
		if (ftell(fp) == 1)
			break;
		fseek(fp, -2, SEEK_CUR);
	}
	fclose(fp);
}