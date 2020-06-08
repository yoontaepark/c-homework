#include <stdio.h>

int main()
{
	int a = 1;
	int int_arr[10] = { 0,1,2,3,4,5,6,7,8,9 };  //배열선언 시 초기화함 

	printf("%i %i %i\n", int_arr[0], int_arr[1], int_arr[9]);

	// printf("%i\n", int_arr[10000]); 에러유형(배열개수 [9]를 초과해서 입력할 수 있음)

	char c = 'a';
	char str1[10] = "Hello"; //10칸을 다 내보내야되는거 아니냐?, null character 까지 나오면 stop함. 따라서 맨뒤에 \n을 추가해줘야함 
	char str2[10] = { 'H', 'i' };
	
	printf("%c\n",c);
	printf("%s\n", str1); // \n을 놓는 이유, null character까지 나오면 stop 시키려고 
	printf("%s\n", str2);

	printf("%hhi %hhi %hhi %hhi %hhi\n", str2[0], str2[1], str2[2], str2[3], str2[4]); //[2] 부터 null 값나오고 그 뒤값은 사실상 쓰레기 값이 나옴 

	//char str3[10] = "Hello, World"; //array size is not enough 
	char str3[20] = "Hello, \0World"; //배열크기는 어떻게 지정하냐? 일단은 알아서 넉넉하게 
	printf("%s\n", str3); //\0을 만나니 그 뒤는 출력을 안해버림 
	printf("%c\n", str3[10]); //실제로 값은 저장되어 있음
	printf("%c\n", str3[11]); //실제로 값은 저장되어 있음

	return 0;
	
}