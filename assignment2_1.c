#include <stdio.h> //�������� ����ó����
#pragma warning(disable:4996) //scanf ���� �޽����� �����ϱ� ���� ���ɾ�
char upper(char ch); //upper �Լ��� ���� ���� 
char lower(char ch); //lower �Լ��� ���� ����
void main() //main()�Լ��� ����
{
	char in_s[50], out_s[50];  //���� in_s�� out_s�� ������ �迭�� �����ϰ�, �迭�� ũ�⸦ 50���� ����
	char ch; //���� ch�� ���������� ����
	int i = 0; //���� i�� ���������� �����ϰ� 0���� ���� �ʱ�ȭ 
	printf("���ڿ��� �Է��Ͻÿ�. (50�� �̳�) : "); //���ڿ��� �Է��Ͻÿ�. (50�� �̳�) : ��� ������ ����Ѵ�. 
	scanf("%s", in_s);// ���ڿ��� �Է¹޾� �迭 in_s�� ����  
	ch = in_s[i]; //while�� �ϴ��� upper(char ch)�� lower(char ch) �Լ��� ����ϱ� ���� �迭 in_s�� �� ��Ҹ� ch�� ��ȯ�Ѵ�
	while (ch != '\0') { //ch=in_s[i] ���� '\0'(null)�� �Ǹ� ���ǽ��� ������ �Ǿ� ������ ��������
		if (ch >= 'A' && ch <= 'Z') //ch ���� �빮�� A~Z(ASCII �ڵ尪���� ������ 65~90) ���̶�� ������ ������ �����Ѵ�.  
			out_s[i] = lower(ch); // lower(ch)�Լ��� ȣ���ϰ�, �Լ� �������� �Ѱܹ޾� out_s[i]�� �ݿ��Ѵ�.   
		else if (ch >= 'a' && ch <= 'z') //ch ���� �ҹ��� a~z((ASCII �ڵ尪���� ������ 97~122)) ���̶�� ������ ������ �����Ѵ�.
			out_s[i] = upper(ch); // upper(ch)�Լ��� ȣ���ϰ�, �Լ� �������� �Ѱܹ޾� out_s[i]�� �ݿ��Ѵ�.   
		else //ch ���� ���� �ΰ��� ���ǿ� �ش����� �ʴ� ��� ������ ������ �����Ѵ�
			out_s[i] = ch; // ch���� out_s[i]�� �ݿ��Ѵ�. 
		i++; //i���� 1 �������� �����Ѵ�
		ch = in_s[i]; // in_s[i] ���� ch�� �ݿ��Ѵ�. �̶� ������ ������ i += 1 ���� �ݿ��� 
	}
	out_s[i] = '\0'; //while���� �������� ���, in_s[i]�� ���� ������ �迭(null) ���� �Է¹޾��� ���̹Ƿ� �̿� �����Ͽ� '\0' ���� ���� �ݿ��Ѵ�.  
	printf("��ȯ�� ��� ==> %s \n", out_s); //out_s�� ������ �迭�� ��� ����Ѵ�.
}

char upper(char ch) { //��ܿ� �����ߴ� upper �Լ��� ����
	return ch - 32; //ch������ -32�� �� ���� ȣ���Լ��� �ѱ��. (������ �ҹ��� a~z���ٸ� ��Ȯ�� �빮�� A~Z�� ��ȯ��) 
}

char lower(char ch) { //��ܿ� �����ߴ� lower �Լ��� ����
	return ch + 32; //ch������ +32�� �� ���� ȣ���Լ��� �ѱ��. (������ �빮�� A~Z���ٸ� ��Ȯ�� �ҹ��� a~z�� ��ȯ��) 
}