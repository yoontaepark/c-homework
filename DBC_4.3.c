#include <stdio.h>

int main()
{
	int a = 1;
	int int_arr[10] = { 0,1,2,3,4,5,6,7,8,9 };  //�迭���� �� �ʱ�ȭ�� 

	printf("%i %i %i\n", int_arr[0], int_arr[1], int_arr[9]);

	// printf("%i\n", int_arr[10000]); ��������(�迭���� [9]�� �ʰ��ؼ� �Է��� �� ����)

	char c = 'a';
	char str1[10] = "Hello"; //10ĭ�� �� �������ߵǴ°� �ƴϳ�?, null character ���� ������ stop��. ���� �ǵڿ� \n�� �߰�������� 
	char str2[10] = { 'H', 'i' };
	
	printf("%c\n",c);
	printf("%s\n", str1); // \n�� ���� ����, null character���� ������ stop ��Ű���� 
	printf("%s\n", str2);

	printf("%hhi %hhi %hhi %hhi %hhi\n", str2[0], str2[1], str2[2], str2[3], str2[4]); //[2] ���� null �������� �� �ڰ��� ��ǻ� ������ ���� ���� 

	//char str3[10] = "Hello, World"; //array size is not enough 
	char str3[20] = "Hello, \0World"; //�迭ũ��� ��� �����ϳ�? �ϴ��� �˾Ƽ� �˳��ϰ� 
	printf("%s\n", str3); //\0�� ������ �� �ڴ� ����� ���ع��� 
	printf("%c\n", str3[10]); //������ ���� ����Ǿ� ����
	printf("%c\n", str3[11]); //������ ���� ����Ǿ� ����

	return 0;
	
}