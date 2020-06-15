#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>


int answer; //사용자 입력값
int Showbottle = 0; //이번 게임에 보여줄 병 갯수
int prevShowbottle = 0; //앞 게임에 보여준 병 갯수
int bottle[4] = { 0, 0, 0, 0 };

// 서로 보여주는 병 갯수를 다르게 해보겠음(처음에 2개 → 다음엔 3개 → 다음엔 2개..)

int isincluded = 0; //보여줄 병 중에 발모제가 포함되어 있는지 확인하기 위한 변수

int main()
{
	srand(time(NULL));
	int treatment = rand() % 4; //발모제가 들어있는 병을 랜덤선택(0~3) 
	printf("\n\n ===My dad is bald T.T === \n\n");

	for (int i = 0; i < 3; i++) 	//3번의 기회를 부여 
	{
		 //보여지는 각 병들을 배열로 표현(a0, a1, a2, a3)
		do
		{
			Showbottle = rand() % 2 + 2; //보여줄 병의 갯수(0~1, +2 = 2~3) 
		} while (Showbottle == prevShowbottle);
		prevShowbottle = Showbottle;

		printf(" > %d 번째 시도 : ", i+1);

		for (int j = 0; j < Showbottle; j++)
		{
			int randbottle = rand() % 4; //병을 랜덤선택(0~3)
			
			if (bottle[randbottle] == 0) //아직 선택되지 않은 병이면 선택처리하자 
			{
				bottle[randbottle] = 1;
				if (randbottle == treatment)
				{
					isincluded = 1;
				}
			}
			else //이미 선택된 병이면, 중복이모로 다시 선택
			{
				j--;
			}
		}

		for (int k = 0; k < 4; k++)
		{
			if (bottle[k] == 1) 
				printf("%d ", k + 1);
		}
		printf("물약을 머리에 바릅니다\n\n");

		if (isincluded == 1)
		{
			printf(" >> success, my hair is growing!! \n");
		}
		else
		{
			printf(" >> fail, my hair is still bald!! \n");
		}
		printf("\n ...if you want to continue, press any button\n");
		getchar(); //입력받을때까지 대기함
	}

	printf("\n\nwhich bottle is a treatment(number 1~4)");
	scanf("%d", &answer);

	if (answer == treatment+1)
	{
		printf("\n >> Correct!!\n");
	}
	else
	{
		printf("\n >> Wrong, the correct answer is %d\n", treatment + 1);
	}

	return 0;
}



// 배열 사용시에 영어 1글자: 1byte, 한글 1글자: 2byte, char 크기: 1byte
//참고: 0~127 사이의 아스키코드 정수값에 해당하는 문자 확인하기

//for (int i = 0; i < 128; i++)
//{
//	printf("아스키코드 정수 %d : %c \n", i, i);
//}
//return 0;