//This source code is to clarify size of each data type
#include <stdio.h> //Include Header file needed to use function printf() and scanf()
#pragma warning(disable:4996) // Ignore non-preferred function warnings(ex. scanf)

void main() {
	printf("char �ڷ��� ũ��: %d byte \n", sizeof(char));
	printf("signed char �ڷ��� ũ��: %d byte \n", sizeof(signed char));
	printf("unsigned char �ڷ��� ũ��: %d byte \n", sizeof(unsigned char));
	printf("short �ڷ��� ũ��: %d byte \n", sizeof(short));
	printf("short int �ڷ��� ũ��: %d byte \n", sizeof(short int));
	printf("signed short �ڷ��� ũ��: %d byte \n", sizeof(signed short));
	printf("signed short int �ڷ��� ũ��: %d byte \n", sizeof(signed short int));
	printf("unsigned short �ڷ��� ũ��: %d byte \n", sizeof(unsigned short));
	printf("unsigned short int �ڷ��� ũ��: %d byte \n", sizeof(unsigned short int));
	printf("int �ڷ��� ũ��: %d byte \n", sizeof(int));
	printf("signed int �ڷ��� ũ��: %d byte \n", sizeof(signed int));
	printf("unsigned �ڷ��� ũ��: %d byte \n", sizeof(unsigned));
	printf("unsigned int �ڷ��� ũ��: %d byte \n", sizeof(unsigned int));
	printf("long �ڷ��� ũ��: %d byte \n", sizeof(long));
	printf("long int �ڷ��� ũ��: %d byte \n", sizeof(long int));
	printf("signed long �ڷ��� ũ��: %d byte \n", sizeof(signed long));
	printf("signed long int �ڷ��� ũ��: %d byte \n", sizeof(signed long int));
	printf("unsigned long �ڷ��� ũ��: %d byte \n", sizeof(unsigned long));
	printf("unsigned long int �ڷ��� ũ��: %d byte \n", sizeof(unsigned long int));
	printf("long long �ڷ��� ũ��: %d byte \n", sizeof(long long));
	printf("long long int �ڷ��� ũ��: %d byte \n", sizeof(long long int));
	printf("signed long long �ڷ��� ũ��: %d byte \n", sizeof(signed long long));
	printf("signed long long int �ڷ��� ũ��: %d byte \n", sizeof(signed long long int));
	printf("unsigned long long �ڷ��� ũ��: %d byte \n", sizeof(unsigned long long));
	printf("unsigned long long int �ڷ��� ũ��: %d byte \n", sizeof(unsigned long long int));
	printf("float �ڷ��� ũ��: %d byte \n", sizeof(float));
	printf("double �ڷ��� ũ��: %d byte \n", sizeof(double));
	printf("long double �ڷ��� ũ��: %d byte \n", sizeof(long double));
	}
