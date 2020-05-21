//This source code is to clarify size of each data type
#include <stdio.h> //Include Header file needed to use function printf() and scanf()
#pragma warning(disable:4996) // Ignore non-preferred function warnings(ex. scanf)

void main() {
	printf("char 자료형 크기: %d byte \n", sizeof(char));
	printf("signed char 자료형 크기: %d byte \n", sizeof(signed char));
	printf("unsigned char 자료형 크기: %d byte \n", sizeof(unsigned char));
	printf("short 자료형 크기: %d byte \n", sizeof(short));
	printf("short int 자료형 크기: %d byte \n", sizeof(short int));
	printf("signed short 자료형 크기: %d byte \n", sizeof(signed short));
	printf("signed short int 자료형 크기: %d byte \n", sizeof(signed short int));
	printf("unsigned short 자료형 크기: %d byte \n", sizeof(unsigned short));
	printf("unsigned short int 자료형 크기: %d byte \n", sizeof(unsigned short int));
	printf("int 자료형 크기: %d byte \n", sizeof(int));
	printf("signed int 자료형 크기: %d byte \n", sizeof(signed int));
	printf("unsigned 자료형 크기: %d byte \n", sizeof(unsigned));
	printf("unsigned int 자료형 크기: %d byte \n", sizeof(unsigned int));
	printf("long 자료형 크기: %d byte \n", sizeof(long));
	printf("long int 자료형 크기: %d byte \n", sizeof(long int));
	printf("signed long 자료형 크기: %d byte \n", sizeof(signed long));
	printf("signed long int 자료형 크기: %d byte \n", sizeof(signed long int));
	printf("unsigned long 자료형 크기: %d byte \n", sizeof(unsigned long));
	printf("unsigned long int 자료형 크기: %d byte \n", sizeof(unsigned long int));
	printf("long long 자료형 크기: %d byte \n", sizeof(long long));
	printf("long long int 자료형 크기: %d byte \n", sizeof(long long int));
	printf("signed long long 자료형 크기: %d byte \n", sizeof(signed long long));
	printf("signed long long int 자료형 크기: %d byte \n", sizeof(signed long long int));
	printf("unsigned long long 자료형 크기: %d byte \n", sizeof(unsigned long long));
	printf("unsigned long long int 자료형 크기: %d byte \n", sizeof(unsigned long long int));
	printf("float 자료형 크기: %d byte \n", sizeof(float));
	printf("double 자료형 크기: %d byte \n", sizeof(double));
	printf("long double 자료형 크기: %d byte \n", sizeof(long double));
	}
