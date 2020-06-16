#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// 10마리의 서로 다른 동물 (각 카드 2장씩)
// 사용자로부터 2개의 입력값을 받아서 -> 같은 동물 찾으면 카드 뒤집기
// 모든 동물 쌍을 찾으면 게임 종료
// 총 실패 횟수 알려주기

int arrayAnimal[4][5]; //카드 지도(20장의 카드)
int checkAnimal[4][5]; //카드가 뒤집혔는지 확인
char* strAnimal[10];

void initAnimalArray();
void initAnimalname();
void shuffleAnimal();
int getEmptyPostition();
int conv_pos_x(int x);
int conv_pos_y(int y);

void printAnimals();
void printQuestion();

int main()
{	
	srand(time(NULL));

	initAnimalArray();
	initAnimalname();

	shuffleAnimal();

	int failCount = 0; //실패 횟수

	while (1)
	{
		int select1 = 0; // 사용자가 선택한 처음 수 
		int select2 = 0; // 사용자가 선택한 두번째 수

		printAnimals(); // 동물 위치 출력
		printQuestion();// 문제 출력(카드 지도)
		printf("\n뒤집을 카드를 2개 고르세요: ");
		scanf("%d %d", &select1, &select2);

		if (select1 == select2) //같은 카드 선택 시 무효
			continue;

		//좌표에 해당하는 카드를 뒤집어 보고 같은지 안같은지 확인
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);


		//카드가 뒤집히지 않았고 & 같은 동물인 경우가 정답을 맞춤 
		if ((checkAnimal[firstSelect_x][firstSelect_y] == 0 
			&& checkAnimal[secondSelect_x][secondSelect_y] == 0)

			&&

			(arrayAnimal[firstSelect_x][firstSelect_y]			//같은 동물인 경우 
			== arrayAnimal[secondSelect_x][secondSelect_y])
			)
		{
			printf("\n\n빙고! : %s 발견\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1; //맞춘애들은 1로 변경시켜줌(뒤집어졌다)
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}
		else //다른 동물인 경우
		{
			printf("땡!! (틀렸거나, 이미 뒤집힌 카드입니다) \n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failCount++;
		}

		//모든 동물을 찾았는지 여부, 참이면 1, 아니면 0
		if (foundAllAnimals() == 1)
		{
			printf("\n\n 축하합니다!. 모든 동물을 다 찾았네요 \n");
			printf("지금까지 총 %d번 실수하였습니다\n", failCount);
			break; //이 문구로 탈출
		}
	}

	return 0;
}



//초기값 세팅
void initAnimalArray()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arrayAnimal[i][j] = -1; //-1로 일단 초기화함 
		}
	}
}

//동물 선언 
void initAnimalname()
{
	strAnimal[0] = "원숭이";
	strAnimal[1] = "하마";
	strAnimal[2] = "강아지";
	strAnimal[3] = "고양이";
	strAnimal[4] = "돼지";

	strAnimal[5] = "코끼리";
	strAnimal[6] = "기린";
	strAnimal[7] = "낙타";
	strAnimal[8] = "타조";
	strAnimal[9] = "호랑이";
}


//셔플해서 x,y에 각 동물값을 넣기 
void shuffleAnimal()
{
	// ㅁㅁㅁㅁㅁ
	// ㅁㅁㅁㅁㅁ
	// ㅁㅁㅁㅁㅁ
	// ㅁㅁㅁㅁㅁ


	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int pos = getEmptyPostition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);

			arrayAnimal[x][y] = i;
		}
	}
}

//좌표에서 빈공간 찾기
int getEmptyPostition()
{
	// ㅁㅁㅁㅁㅁ	 0  1  2  3  4  -> 5로 나누면 00000
	// ㅁㅁㅁㅁㅁ	 5  6  7  8  9               11111
	// ㅁㅁㅁㅁㅁ	10 11 12 13 14				 22222
	// ㅁㅁㅁㅁㅁ	15 16 17 18 19				 33333


	while (1) //계속 반복
	{
		int randPos = rand() % 20; //0~19사이의 숫자 반환 
		//19 -> (3,4)
		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);

		if (arrayAnimal[x][y] == -1) //빈공간이 나오면(초기값이 나오면) 다시 함수를 돌려라
		{
			return randPos;
		}
	}
	return 0;
}

int conv_pos_x(int x)
{
	//19 -> (3,4)
	return x / 5; //5로 나눈 몫
};

int conv_pos_y(int y)
{
	return y % 5; //5로 나눈 나머지
}


void printAnimals() //동물 위치 출력(정답용)
{
	// ㅁㅁㅁㅁㅁ	 0  1  2  3  4  
	// ㅁㅁㅁㅁㅁ	 5  6  7  8  9              
	// ㅁㅁㅁㅁㅁ	10 11 12 13 14           
	// ㅁㅁㅁㅁㅁ	15 16 17 18 19
	printf("\n==========비밀인데, 몰래 보여줌 =======\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%8s", strAnimal[arrayAnimal[i][j]]); 
		}
		printf("\n");
	}
	printf("\n==========================\n\n");
}


void printQuestion()
{
	printf("\n\n(문제)\n");
	int seq = 0; //칸들을 숫자로 수치화하기 위해 편의상 설정함

					//seq				 //checkAnimal
// ㅁㅁㅁㅁㅁ	 0  1  2  3  4            00010
// ㅁㅁㅁㅁㅁ	 5  6  7  8  9            10000  
// ㅁㅁㅁㅁㅁ	10 11 12 13 14            00000
// ㅁㅁㅁㅁㅁ	15 16 17 18 19			  00000

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//카드를 뒤집어서 정답을 맞췄으면 '동물 이름' 
			if (checkAnimal[i][j] != 0)
			{
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}
			//아직 뒤집지 못했으면 (정답을 맞추지 못했으면) 뒷면 -> 위치를 나타내는 숫자
			else
			{
				printf("%8d", seq);
			}
			seq++;
		}
		printf("\n");
	}
}

int foundAllAnimals()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkAnimal[i][j] == 0)
				return 0; //아직 못찾음 
		}
	}
	return 1; //모두 다 찾음
}




//다차원 배열 표현하는 방법
//
//int arr[5];
//ㅁㅁㅁㅁㅁ
//[0][1][2][3][4]
//
//int arr2[2][5]; //행x열이라고 생각하면 편할듯 
//ㅁㅁㅁㅁㅁ
//ㅁㅁㅁㅁㅁ
//[0,0][0,1][0,2][0,3][0,4]  -> arr2[0][0] 이렇게 표현하면 됨  
//[1,0][1,1][1,2][1,3][1,4]

//선언은 어떻게? 
//int arr2[2][5] = {{1,2,3,4,5}, {1,2,3,4,5}} 
//
//int arr2[2][5] = {
//	{1,2,3,4,5},
//	{1,2,3,4,5}
//}
//이런식으로 1행, 2행 순서대로 쭉 나열을 시켜주면 된다. 


//다차원 배열 접근하는 방법
//int arr4[3][3][3] = {
//	{
//	{1,2,3},
//	{4,5,6},
//	{7,8,9}
//	},
//	{
//	{11,12,13},
//	{14,15,16},
//	{17,18,19}
//	},
//	{
//	{21,22,23},
//	{24,25,26},
//	{27,28,29}
//	}
//};
//
//for (int i = 0; i < 3; i++)
//{
//	for (int j = 0; j < 3; j++)
//	{
//		for (int k = 0; k < 3; k++)
//		{
//			printf("3차원배열(%d %d %d)의 값: %d\n", i, j, k, arr4[i][j][k]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}