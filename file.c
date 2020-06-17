#define _CRT_SECURE_NO_WARNINGS  //프로그램 가장 위에 선언해야됨 
#include <stdio.h>

// 비밀번호를 입력 받아서 
// 맞는 경우? 비밀 일기를 읽어와서 보여주고, 계속 작성하도록 합니다. 
// 틀린 경우? 경고 메시지를 표시하고 종료합니다. 

#define MAX 10000

int main()
{
	//fgets, fputs 활용
	char line[MAX]; //파일에서 불러온 내용을 저장할 변수
	char contents[MAX]; //일기장에 입력할 내용
	char password[20]; //비밀번호 입력
	char c; //비밀번호 입력할 때 키값 확인용(마스킹) 

	printf("Welcome to secret diary\n");
	printf("input your password : ");

	//getchar() / getch()의 차이?
	//getchar() : 엔터를 입력받아야 동작을 한다
	//getch() : 키 입력 시 바로바로 동작을 한다 

	int i = 0;
	while (1)
	{
		c = getch(); //한자씩 비밀번호를 입력하고, 이에 바로바로 반응을 하도록 하기 위함
		if (c == 13) //Enter => 비밀번호 입력 종료 
		{
			password[i] = '\0';
			break;
		}
		else //비밀번호 입력중 
		{
			printf("*");
			password[i] = c;
		}
		i++;
	}

	// 비밀번호: 1234abcd 
	printf("\n\n === 비밀번호 확인중... ===\n\n");
	if (strcmp(password, "1234abcd") == 0) //비밀번호 일치, strcmp 를 써서 두문자를 비교하는 방식을 사용했음
	{
		printf("=== 비밀번호 확인 완료 === \n\n");
		char* fileName = "C:\\Users\\PC\\Desktop\\secretdiary.txt";
		FILE* file = fopen(fileName, "a+b"); //a+b의 의미는 파일이 없으면 생성, 파일이 있으면 append(뒤에서부터 내용을 추가) 한다는 뜻
		if (file == NULL)
		{
			printf("파일 열기 실패\n");
			return 1;
		}
		while (fgets(line, MAX, file) != NULL)
		{
			printf("%s", line);
		}

		printf("\n\n 내용을 계속 작성하세요! 종료하시려면 exit를 입력하세요\n\n");

		while (1)
		{
			scanf("%[^\n]", contents); //새 줄(\n)이 나오기 전까지 읽어들임 (한문장씩 작성)
			getchar(); //Enter 입력(\n) flush 처리(enter 무시하기)

			if (strcmp(contents, "exit") == 0)
			{
				printf("비밀일기 입력을 종료합니다\n\n");
				break;
			}
			fputs(contents, file);
			fputs("\n", file); //Enter를 위에서 무시처리했기 때문에 임의로 추가한다
		}
		fclose(file);
	}
	else //비밀번호 틀린 경우
	{
		printf("=== password is incorrect===\n\n");
		printf("Guards!!! Get him out of here\n\n\n");
	}

	return 0;
}



////파일 입출력
//	//파일에 어떤 데이터를 저장, 
//	//파일에 저장된 데이터를 불러오기
//
//	//fputs, fgets 쌍
//char line[MAX];
//
//
//
//////파일에 쓰기
////FILE* file = fopen("C:\\Users\\PC\\Desktop\\test1.txt", "wb"); 
//////해당 디렉토리에 있는 파일을 wb형태로 열겠다이고, \는 실제로 하나만 경로에 있지만, 코딩시에는 두개를 써줘야 함(암기) 
//////r 읽기전용, w 쓰기전용, a 이어쓰기, //t텍스트, b 바이너리 전용
//////파일을 만들지 않았더라도, 만들어줌 
//
////if (file == NULL)
////{
////	printf("파일 열기 실패\n");
////	return 1;
////}
//
////fputs("fputs 를 이용해서 글을 적어볼게요\n", file); //해당 파일에 내용을 적어넣기 
////fputs("잘 적히는지 확인해주세요\n", file);
//
//
////파일 읽기
//FILE* file = fopen("C:\\Users\\PC\\Desktop\\test1.txt", "rb");
//
//if (file == NULL)
//{
//	printf("파일 열기 실패\n");
//	return 1;
//}
//
//while (fgets(line, MAX, file) != NULL)
//{
//	printf("%s", line);
//}
//
//// 파일을 열고 나서 닫지 않은 상태에서 어떤 프로그램에 문제가 생기면, 
//// 데이터 손실 발생 가능! 그래서 항상 파일은 닫아주는 습관을 들여야함 
//fclose(file); //open을 했으면 close도 항상 pair로 선언하기 


////fprintf, fscanf 쌍
//
//	//printf("%d %d %s ...")
//	//scanf("%d %d", &num1, ...)
//int num[6] = { 0,0,0,0,0,0 }; //추첨번호
//int bonus = 0; //보너스 번호
//char str1[MAX];
//char str2[MAX];
//
//
//////파일에 쓰기 
////FILE* file = fopen("C:\\Users\\PC\\Desktop\\test2.txt", "wb");
////if (file == NULL)
////{
////	printf("파일 열기 실패\n");
////	return 1;
////}
//
//////로또 추첨번호 저장
////fprintf(file, "%s %d %d %d %d %d %d\n", "추첨번호", 1, 2, 3, 4, 5, 6);
////fprintf(file, "%s %d\n", "보너스번호", 7);
//
//
////파일에 읽기
//FILE* file = fopen("C:\\Users\\PC\\Desktop\\test2.txt", "rb");
//if (file == NULL)
//{
//	printf("파일 열기 실패\n");
//	return 1;
//}
//
//fscanf(file, "%s %d %d %d %d %d %d", str1, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
//printf("%s %d %d %d %d %d %d\n", str1, num[0], num[1], num[2], num[3], num[4], num[5]);
//
//fscanf(file, "%s %d", str2, &bonus);
//printf("%s %d\n", str2, bonus);
//
//
//return 0;