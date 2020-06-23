#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

//물고기가 6마리가 있다, 이들은 어항에 살고 있는데 사막임, 사막이 너무 더워서 물이 빨리 증발함 
// 물이 다 증발하기 전에 부지런히 어항에 물을 줘서 물고기를 살려주세요
// 물고기는 시간이 지날수록 점점 커져서...나중에는....냠냠..

int level;
int arrayFish[6];
int *cursor;

void initData();
void printfFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();

int main()
{
	long startTime = 0; //게임 시작시간 
	long totalElapsedTime = 0; //총 경과 시간
	long prevElapsedTime = 0;//직전 경과 시간(최근에 물을 준 시간 간격)

	int num; //몇번 어항에 물을 줄것인지, 사용자 입력
	initData(); //초기 레벨을 지정해줌

	cursor = arrayFish; // cursor[0], cursor[1],.... 

	startTime = clock();//현재 시간을 millisecond(1000분의 1초) 단위로 변환 ex)4000이면 4초
	while (1) //무한반복
	{
		printfFishes(); //초기 상태값을 출력하는 함수를 생성한다
		printf("몇 번 어항에 물을 주시겠어요? ");
		scanf("%d", &num);

		//입력값 체크 
		if (num < 1 || num>6)
		{
			printf("\n입력값이 잘못되었습니다\n");
			continue; // 해당 조건의 값들이 입력되었을 경우 위의 문장을 출력하고, 다시 while함수로 되돌아간다 
		}


		// 총 경과 시간 
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC; //초로 변환하기(이 경우에는 /1000과 같은 의미임) 
		printf("총 경과 시간: %ld초\n", totalElapsedTime);

		//직전 물 준 시간(마지막으로 물 준 시간) 이후로 흐른 시간
		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("최근 경과 시간: %ld 초\n", prevElapsedTime);

		//어항의 물을 감소시킴
		decreaseWater(prevElapsedTime);

		//사용자가 입력한 어항에 물을 준다
		// 1. 어항의 물이 0이면? 물을 주지 않는다
		if (cursor[num - 1] <= 0)
		{
			printf("%d번 물고기는 이미 죽었습니다..물을 주지 않습니다\n", num);
		}
		//2. 어항의 물이 0이 아닌 경우? 물을 준다, 다만 100을 넘지 않는지 체크로직을 넣어야 함
		else if (cursor[num - 1] + 1 <= 100)
		{
			//물을 준다
			printf("%d번 어항에 물을 줍니다\n\n", num);
			cursor[num - 1] += 1; //cursor[num - 1] = cursor[num - 1] + 1
		}

		//레벨업을 할 건지 확인(ex. 레벨업은 20초마다 한번씩 수행)
		if (totalElapsedTime / 20 > level - 1) //ex. 15초 지났으면, 15/20은 0으로 인식함, 레벨은 1에서 시작하니 이경우는 0>0이 아니기 때문에 레벨업 안함, 21초면 1>0이니까 레벨업  
		{
			//레벨업
			level++;
			printf(" ***축 레벨업! 기존 %d레벨에서 %d 레벨로 업그레이드 ***", level - 1, level);

			//최종 레벨: 5
			if (level == 5)
			{
				printf("\n\n축하합니다. 최고 레벨을 달성하셨습니다. 게임을 종료합니다\n\n");
				exit(0);
			}
			//getchar(); //임시로 사용자 입력 대기 
		}

		//모든 물고기가 죽었는지 확인
		if (checkFishAlive() == 0)
		{
			//물고기 모두 ㅠㅠ
			printf("모든 물고기가..ㅠㅠ GG \n");
			exit(0);
		}
		else
		{
			//최소 한마리 이상의 물고기가 살아있는 경우
			printf("물고기가 아직 살아 있어요!\n");
		}
		prevElapsedTime = totalElapsedTime;
		//이걸 넣는 이유는 ex. 총 경과시간이 10초 → 15초 → 25초 이렇게 지나면, 
		// 기 경과시간(prev)는 각각 10초(0초) , 15초(5초), 25초(prev 10초를 계산해야하는데) 인데 위의 prev는 이전값 5초에 고정되어 있음
		// 따라서 prev를 15초로 재설정(총경과시간)한다음에 다음 trail의 총경과시간에서 차감해주면 25초-15초 =10초를 그 다음 prev 값으로 설정할 수 있음
		// 그 이후에는 또 다시 prev 값을 25초로 재설정해주고 총 경과시간(new)에서 25초를 빼주면 또 새로운 prev 값이 나옴 
	}
	return 0;
}


void initData()
{
	level = 1; //게임 레벨 (1~5)
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] = 100; //어항의 물 높이(0~100)
	}
}

void printfFishes()
{
	printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6); //%3d번 이면 3칸(%3d) +2칸(번) + 1칸(공란)으로 총 6칸
	for (int i = 0; i < 6; i++)
	{
		printf("  %3d ", arrayFish[i]); //여기도 마찬가지로 2(앞공란) +3(%3d) + 1(뒷공란) 으로 간격을 맞춰준다. 
	}
}

void decreaseWater(long elapsedTime)
{
	for (int i = 0; i<6; i++)
	{
		arrayFish[i] -= (level * 5 * (int)elapsedTime);
		if (arrayFish[i] < 0)
		{
			arrayFish[i] = 0;
		}
	}
}

int checkFishAlive()
{
	for (int i = 0; i < 6; i++)
	{
		if (arrayFish[i] > 0)
			return 1; //참 true
	}
	return 0;
}




/*>>>> 포인터 변수 <<<<*/
//포인터 변수를 선언하려면: *변수
//한편, 포인터변수를 선언했다면, 주소를 대응시켜줘야 함 
// 이과정이 변수 = &다른변수(이건 다른변수의 주소) 
//포인터변수의 값을 출력하고자 한다면, *변수로 입력하면 됨. 
//이와별개로 그냥 변수의 주소를 출력하고 싶으면 &변수, 포인터변수의 경우 그냥 변수를 넣어주면 된다. 

/* 미션맨 예제 */
//int 철수 = 1;
//printf("%d, %d\n", &철수, 철수);
//
//int* 미션맨;
//미션맨 = &철수;
//printf("방문주소: %d, %d\n", 미션맨, *미션맨);
//
//*미션맨 += 2;  //사칙연산도 가능하나, 포인터변수의 사칙연산은 *붙인채로 사칙연산을 수행해야 
//printf("미션맨 주소는 %d\n", *미션맨);

//배열과 포인터의 관계: 거의 유사한 기능을 한다
//int arr[3] = { 5,10,15 };
//int* ptr = arr;
//for (int i = 0; i < 3; i++)
//{
//	printf("배열 arr[%d]의 값: %d\n", i, arr[i]);
//	printf("포인터 ptr[%d]의 값: %d\n", i, ptr[i]);
//}
//
//ptr[0] = 100;
//ptr[1] = 200;
//ptr[2] = 300;  //*ptr = ptr[] = arr[] 과 동일하다고 보면 됨
//printf("\n");
//
//for (int i = 0; i < 3; i++)
//{
//	printf("배열 arr[%d]의 값: %d\n", i, arr[i]);
//	printf("배열 arr[%d]의 값: %d\n", i, *(arr + i)); //arr[i] == *(arr+i)  == ptr[i] == *(ptr+i)
//	printf("포인터 ptr[%d]의 값: %d\n", i, ptr[i]);
//}
//
//// arr == arr배열의 첫번째 값의 주소와 동일 == &arr[0]
//printf("배열 arr에서 arr[]은 값이지만 arr자체는 주소로 값이 나온다: %d\n", arr);
//printf("arr[0]의 주소: %d, 값: %d\n", &arr[0], arr[0]);
//
//printf("arr자체의 실제 값: %d\n", *arr); // ==*(arr+0)
//printf("arr[0]의 값: %d\n", *&arr[0]);
//printf("arr[0]의 값: %d\n", *&*&*&*&*&*&*&*&*&*&*&*&*&*&arr[0]);
//printf("arr[0]의 값: %d\n", arr[0]);
////*&은 서로 상쇄됨. 즉, 아무것도 없는 것과 같다. &는 주소이며 *는 그 주소의 값이기 때문임


//	/* call by value vs call by reference */
//	int a = 10;
//	int b = 20;
//	printf("a의 주소: %d, b의 주소: %d\n", &a, &b);
//
//
//	//printf("Swap 함수 전 => a : %d, b : %d\n", a, b);
//	//swap(a, b); //call by value 임
//	//printf("Swap 함수 후 => a : %d, b : %d\n", a, b);
//
//	//주소값을 넘기는 케이스
//	printf("(주소값 전달)Swap 함수 전 => a : %d, b : %d\n", a, b);
//	swap_addr(&a, &b); //call by reference 임
//	printf("(주소값 전달)Swap 함수 후 => a : %d, b : %d\n", a, b);
//
//	return 0;
//}
//
////void swap(int a, int b)
////{
////	printf("Swap 함수 내 =>  a주소: %d, b주소 : %d\n", &a, &b);
////	
////	int temp = a;
////	a = b;
////	b = temp;
////	printf("Swap 함수 내 =>  a : %d, b : %d\n", a, b);
////}
//
//void swap_addr(int* a, int* b)
//{
//	printf("Swap 함수 내 =>  a주소: %d, b주소 : %d\n", &a, &b);
//	printf("Swap 함수 내 =>  a주소: %d, b주소 : %d\n", a, b);
//
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//	printf("Swap 함수 내 =>  a : %d, b : %d\n", *a, *b);
//}
