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
	// 위의 3가지 문법을 동일하게 사용함(방법만 다름)  

	size_t int_size4 = sizeof(a);  //이식성을 높이기 위해 쓰는 용어임(위의 unsigned int와 동일하긴 함) 
	size_t float_size = sizeof(float);

	printf("Size of int type is %u bytes.\n", int_size1);
	printf("Size of int type is %zu bytes.\n", int_size4);
	printf("Size of float type is %zu bytes.\n", float_size);


	/* 2. sizeof arrays */
	int int_arr[30]; //int_arr[0] = 1024; , 선언되는 순간 120 바이트임, 물론 주소의 대표만 보여줌 
	int* int_ptr = NULL; //선언을 먼저하고 나중에 결정됨(+메모지의 size만 나옴), 주소의 대표를 보여주는건 맞음   
	int_ptr = (int*)malloc(sizeof(int) * 30); //int_ptr[0] = 1024; , 

	printf("Size of array = %zu bytes\n", sizeof(int_arr)); //120 byte가 나옴, 
	printf("Size of pointer = %zu bytes\n", sizeof(int_ptr));//4 byte가 나옴 

	/* 3. sizeof character array */
	char c = 'a';
	char string[10]; // maximally 9 character + '\0'(null character) 로 구성이 됨

	size_t char_size = sizeof(char); //1바이트
	size_t str_size = sizeof(string); //10바이트 

	printf("Size of char type is %zu bytes.\n", char_size);
	printf("Size of strring type is %zu bytes.\n", str_size);
	
	/*4. size of structure */
	printf("%zu\n", sizeof(struct MyStruct)); //4(int)+4(float) = 8 임 


	/*
	char coffee_name; //문자 하나만 입력받음(banana로 써도 b만 출력될 것) 
	printf("What is your farovite coffee?\n");
	scanf("%c", &coffee_name); //아직은 scanf 쓸때는 &를 붙여서 쓴다 정도만, char 니까 %c로 씀  
	printf("You like %c!\n", coffee_name);
	*/

	/*
	char fruit_name[40]; //[40] 넣으면 배열로 바뀜(40개의 공간을 대표하는 주소 한가지만 알려줌 
	printf("What is your farovite fruit?\n"); 
	scanf("%s", fruit_name); // %c 는 %s(string)로 바꿔써주고, 놀랍게도 &를 빼서 쓴다. 왜?? 배열선언하면 배열자체가 주소가 되기 때문에 &를 넣을 필요가 없어짐 
	printf("You like %s!\n", fruit_name);
	*/

	return 0;
}