/*�빮�ڸ� �ҹ��ڷ�, �ҹ��ڸ� �빮�ڷ� ��ȯ�ϴ� ���α׷� */
#include<stdio.h>
#pragma warning(disable:4996)

char upper(ch) {
	return ch - 32;
}
char lower(ch) {
	return ch + 32;
}

int main() {
	char in_s[50], out_s[50];
	char ch;
	int i = 0;
	printf("���ڿ��� �Է��Ͻÿ�. (50�� �̳�): ");
	scanf("%s", in_s);
	ch = in_s[i];
	while (ch != '\0') {
		if (ch >= 'A' && ch <= 'Z')
			out_s[i] = lower(ch);
		else if (ch >= 'a' && ch <= 'z')
			out_s[i] = upper(ch);
		else
			out_s[i] = ch;
		i++;
		ch = in_s[i];
	}
	out_s[i] = '\0';
	printf("��ȯ�� ��� ==> %s \n", out_s);
	return 0;
}

/* 
1. out_s[i] = '\0'; : ���ڿ��� ǥ���� ���� ���ڿ��� ���� �ǹ��ϴ� \0�� �־��ش�. �ȳ����� �̻��ϰ� ������� ��
2. �Է¹��� ���ڿ� in_s�� ch�� ��ȯ�ϰ�, �̶� ch�� �빮��(A~Z)�� lower(ch)�� out_s�� ��ȯ�Ѵ�. 
   lower(ch)�� ch+32�� ������(��, �빮�� �� �ҹ��ڶ�� �Ҹ�, �ƽ�Ű�ڵ� �������� �빮��+32=�ҹ�����)
   �����ٿ� printf �� ���� ��ȯ�� ������� out_s�� ����ϸ�, ch+32 �� ���ڰ� �����Ǿ� ��µȴ�. 
   
   �ҹ���(a~z)�� upper(ch)�� out_s�� ��ȯ�Ѵ�. upper(ch)�� ch-32�� �����ϱ� ������, �ҹ��ڿ��� �빮�ڷ� ������ �ǰ�, 
   �� ���� out_s�� ������ �� printf�� ����� 

   A~Z, a~z �Ѵ� �ƴ϶�� ch�� out_s�� ��ȯ�Ѵ�. ��, ���� �ȹٲٱ� ������ �Է��� �״�� ���� ��µȴ�. 
   ������ å�� �� ������ �ν��ϴ�;;;

3. lower�� upper�� main ���� ǥ���ϴ� ������ return ���� �־���ϴµ�, �̰� main�� ������ ���࿡���� ����. 
   �������� �߰��� �����غ����ҵ�
*/

