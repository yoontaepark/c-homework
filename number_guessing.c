#define _CRT_SECURE_NO_WARNINGS //define을 신기하게도 젤 위에 놓아야하더라 
#include <stdio.h>
#include <time.h>

/*숫자맞추기 게임을 직접 만들어보자 */

int main()
{
	srand(time(NULL));
	int num = rand() % 100 + 1; // 난수를 100으로 나눈 나머지이므로 0~99가 나오니까 그 값 전체에 +1을 해주면 1~100이 나옴 (괄호는 해주나 마나 %가 먼저 실행됨)
	printf("%d\n", num); //실제 정답을 미리 보여줌(이부분은 실제 게임수행시 주석처리해도 무방함)
	int answer = 0;
	int chance = 5; 

	printf("[몬스터]흐흐...게임을 시작하지.");

	while (chance > 0)
	{
		printf("기회는 단 %d번이다.\n", chance--);
		printf("[시스템]숫자를 맞춰보세요 (1~100), UP&DOWN : ");
		scanf("%d", &answer);

		if (answer > num)
		{
			printf("[몬스터]땡! DOWN이야!\n");
			printf("====================\n");

		}
		else if (answer < num)
		{
			printf("[몬스터]땡! UP이야\n");
			printf("====================\n");
		}
		else if (answer == num)
		{
			printf("\n\n[몬스터]아니 이걸 맞추다니....너의 승리다\n\n");
			break;
		}
		else
		{
			printf("[몬스터]뭔가 잘못입력한 모양이군, 알려줄 정보는 없다 껄껄껄\n");
			printf("====================\n");
		}
		if (chance == 0)
		{
			printf("[몬스터]기회를 모두 소진했군, 너는 패배자다 하하하하\n");
		}
	}
	return 0;
}










/*break 를 이용해서 case 일부에만 출력문을 넣을 수도 있다  8~13세 초등학생, 14~16 중학생, 17~19세 고등학생, 나머지는 이외 일 경우*/

//int age = 17;
//	int main()
//{
//	switch (age)
//	{
//	case 8:
//	case 9:
//	case 10:
//	case 11:
//	case 12:
//	case 13:printf("초등학생임\n"); break;
//	case 14:
//	case 15:
//	case 16:printf("중학생임\n"); break;
//	case 17: //위의 값 17을 받아서 case 17을 수행하지만 break가 없으므로 빈값을 받은 후 아래로 내려감
//	case 18: //위와 동일
//	case 19:printf("고등학생임\n"); break; //여기에서 고등학생임을 출력하고 break 로 함수를 빠져나감 
//	default:printf("학생이 아님\n"); break;
//	}
//	return 0;
//}




	/*할일: 1번부터 30번까지 있는 반에서 7번 학생은 아퍼서 결석,
	  7번을 제외하고 6~10번까지 조별 발표를 하세요. */

	  //int i = 0;
	  //
	  //int main()
	  //{
	  //	for (i = 1; i <= 30; i++)
	  //	{
	  //		if (i >= 6 && i <= 10)
	  //		{
	  //			if (i == 7 || i == 9)
	  //			{
	  //				printf("%d번 학생은 결석입니다.\n", i);
	  //				continue;  // 이 경우 조건을 만족하면 바로 상단 if문의 다음조건으로 넘어감(뒤의 입력문들 실행 x) 
	  //			}
	  //			printf("%d번 학생은 조별발표를 하세요.\n", i);
	  //		}
	  //
	  //	}
	  //
	  //	return 0;
	  //}

	  //int main()
	  //{
	  //	for (i = 1; i <= 30; i++)
	  //	{
	  //		if (i >= 6 && i <= 10)
	  //		{
	  //			if (i == 7)
	  //			{
	  //				printf("%d번 학생은 결석입니다.\n", i);
	  //				break;  // 이 경우 조건을 만족하면 for문을 탈출함 
	  //			}
	  //			printf("%d번 학생은 조별발표를 하세요.\n", i);
	  //		}
	  //
	  //	}
	  //
	  //	return 0;
	  //}
	  //참고 &&는 and 조건이고 ||는 or 조건이다. 

	  /* switch문 예시*/

	  //#include <time.h>
	  //
	  //int main()
	  //{
	  //	srand(time(NULL));
	  //	int i = rand() % 3;
	  //	switch(i)
	  //	{
	  //	case 0:printf("가위\n"); break; //switch 문은 실행 case 부터 아래부분을 다 실행하기 때문에 break를 각각 걸어줘야 하나만 값이 나온다  
	  //	case 1:printf("바위\n"); break;
	  //	case 2:printf("보\n"); break;
	  //	default:printf("몰라요\n"); break;
	  //	}
	  //	return 0;
	  //}


