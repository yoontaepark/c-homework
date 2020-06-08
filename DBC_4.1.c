#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> //malloc()

struct MyStruct
{
	int i;
	float f;
};

int main()
{
	/* 1. sizeof baisc types */
	int a = 0;
	unsigned int int_size1 = sizeof a;
	unsigned int int_size2 = sizeof(int);
	unsigned int int_size3 = sizeof(a);
	// ���� 3���� ������ �����ϰ� �����(����� �ٸ�)  

	size_t int_size4 = sizeof(a);  //�̽ļ��� ���̱� ���� ���� �����(���� unsigned int�� �����ϱ� ��) 
	size_t float_size = sizeof(float);

	printf("Size of int type is %u bytes.\n", int_size1);
	printf("Size of int type is %zu bytes.\n", int_size4);
	printf("Size of float type is %zu bytes.\n", float_size);


	/* 2. sizeof arrays */
	int int_arr[30]; //int_arr[0] = 1024; , ����Ǵ� ���� 120 ����Ʈ��, ���� �ּ��� ��ǥ�� ������ 
	int* int_ptr = NULL; //������ �����ϰ� ���߿� ������(+�޸����� size�� ����), �ּ��� ��ǥ�� �����ִ°� ����   
	int_ptr = (int*)malloc(sizeof(int) * 30); //int_ptr[0] = 1024; , 

	printf("Size of array = %zu bytes\n", sizeof(int_arr)); //120 byte�� ����, 
	printf("Size of pointer = %zu bytes\n", sizeof(int_ptr));//4 byte�� ���� 

	/* 3. sizeof character array */
	char c = 'a';
	char string[10]; // maximally 9 character + '\0'(null character) �� ������ ��

	size_t char_size = sizeof(char); //1����Ʈ
	size_t str_size = sizeof(string); //10����Ʈ 

	printf("Size of char type is %zu bytes.\n", char_size);
	printf("Size of strring type is %zu bytes.\n", str_size);
	
	/*4. size of structure */
	printf("%zu\n", sizeof(struct MyStruct)); //4(int)+4(float) = 8 �� 


	/*
	char coffee_name; //���� �ϳ��� �Է¹���(banana�� �ᵵ b�� ��µ� ��) 
	printf("What is your farovite coffee?\n");
	scanf("%c", &coffee_name); //������ scanf ������ &�� �ٿ��� ���� ������, char �ϱ� %c�� ��  
	printf("You like %c!\n", coffee_name);
	*/

	/*
	char fruit_name[40]; //[40] ������ �迭�� �ٲ�(40���� ������ ��ǥ�ϴ� �ּ� �Ѱ����� �˷��� 
	printf("What is your farovite fruit?\n"); 
	scanf("%s", fruit_name); // %c �� %s(string)�� �ٲ���ְ�, ����Ե� &�� ���� ����. ��?? �迭�����ϸ� �迭��ü�� �ּҰ� �Ǳ� ������ &�� ���� �ʿ䰡 ������ 
	printf("You like %s!\n", fruit_name);
	*/

	return 0;
}