#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);
void success();
void fail();

int main()
{
	//문이 5개가 있고, 각문마다 점점 어려운 수식 퀴즈가 출제(랜덤)
	//맞히면 통과, 틀리면 실패

	srand(time(NULL));
	int count = 0;
	for (int i = 1; i <= 5; i++)
	{
		int num1 = getRandomNumber(i);
		int num2 = getRandomNumber(i);
		showQuestion(i, num1, num2);  //질문부분 

		int answer = -1;
		scanf("%d", &answer);
		if (answer == -1)
		{
		printf("프로그램을 종료합니다\n");
		exit(0);  //바로 프로그램을 종료시킨다. 
		}
		else if (answer == num1 * num2)
		{
			success();
			count++;
		}
		else
		{
			fail();
		}
	}
	printf("\n\n 당신은 5개의 비밀번호 중 %d개를 맞췄습니다.\n", count);

	return 0; 
}


int getRandomNumber(int level)
{
	return rand() % (level * 10) + 1;
}

void showQuestion(int level, int num1, int num2)
{
	printf("\n\n\n###### %d번째 비밀번호 ######\n", level);
	printf("\n\t%d x %d는?\n\n", num1, num2);
	printf("###########################\n");
	printf("\n비밀번호를 입력하세요(종료: -1) >> ");
}

void success()
{
	printf("\n >> Good! 정답입니다.\n");
}
void fail()
{

	printf("\n >> fail! 오답입니다.\n");
}










//#include <stdio.h>
//
//void p(int num);
//void function_without_return();
//int function_with_return();
//void function_without_params(int num1, int num2, int num3); //파라미터(전달값)이 있는 함수 
//int apple(int num1, int num2);
//
//int main()
//{
//	//function_without_return();
//	//int ret = function_with_return();
//	//p(ret);
//
//	//function_without_params(33, 44, 55); //여기서 파라미터를(전달값을) 함수에 넘기면, 함수에서 그걸 받아서 main함수로 재전달해준다. 
//
//	printf("이건 앞단이여\n");
//	printf("사과 %d개 중에 %d개를 먹으면? %d개가 남아요\n", 10, 6, apple(10, 4));
//	printf("이건 뒷단이여\n");
//
//	return 0;
//}
//
//int apple(int num1, int num2)
//{
//	printf("전달값과 반환값이 있는 함수입니다.\n"); //main함수의 printf를 다 출력하기 전에 apple 함수를 수행하기 때문에 이값은 먼저 출력이 되어버림 
//	return num1 - num2; //리턴값을 main함수로 돌려주게 됨 
//}

//정의
//void p(int num)  //p는 함수이름, int num 은 변수에 대응 
//{
//	printf("num은 %d 입니다\n", num);
//}
//
//void function_without_return()
//{
//	printf("반환값이 없는 함수입니다\n");
//}
//
//int function_with_return()
//{
//	printf("반환값이 있는 함수입니다\n");
//	return 10;
//}
//
//void function_without_params(int num1, int num2, int num3)
//{
//	printf("파라미터를 다음과 같이 %d %d %d로 재전달합니다.", num1, num2, num3);
//}




//int main()
//{
//	int num = 2;
//	p(num);
//
//	num += 3;
//	p(num);
//
//	num -= 3;
//	p(num);
//
//	num *= 3;
//	p(num);
//
//	num /= 3;  //사직연산 간편하게 할때 이렇게 줄여서 사용한다 
//	p(num);
//
//
//	return 0;
//}





//반환형 함수이름(전달값)
//{
//
//}

//함수 종류 
//1. 반환값이 없는 함수 


//2. 반환값이 있는 함수 