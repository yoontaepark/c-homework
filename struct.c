#include <stdio.h>
#include <time.h>

// 5마리의 고양이가 있다
// 아무키나 눌러서 랜덤으로 고양이를 뽑되, 
// 5마리 모두 다 수집을 해서 열심히 키우면 되는 게임 
// 중복 발생가능 

// 고양이
// 이름, 나이, 성격, 키우기 난이도(레벨) 
typedef struct {
	char* name; //이름
	int age; //나이
	char* character; //성격
	int level; //키우기 난이도(1~5, 5가 가장 어려움)
} CAT;

//현재까지 보유한 고양이
int collection[5] = { 0, 0, 0, 0, 0 };

//전체 고양이 리스트
CAT cats[5];

void initCats(); //고양이 정보 초기화
void printCat(int selected); // 선택한 고양이 결과값 출력 함수 

int main()
{
	srand(time(NULL)); //랜덤뽑기를 위한 선언

	initCats(); //고양이 값 초기설정 
	while (1) //반복문 무한 수행
	{
		printf("어느 고양이의 집사가 될까요? \n 아무키나 눌러서 확인하세요~~!"); //출력문을 일단 만들어놓자
		getchar(); //누를때까지 대기 

		int selected = rand() % 5; //0~4사이의 숫자를 반환한다 
		printCat(selected); //선택한 고양이 결과값 출력 
		collection[selected] = 1; //고양이 뽑기 처리

		int collectAll = checkCollection(); //checkcollection의 리턴값은 0 아님 1이 될 것임
		if (collectAll == 1) // 1인 경우 break로 빠져나감, 아닌 경우 while문에 의거 반복수행을 함 
		{
			break;
		}
	}
	return 0;
}

void initCats()  //고양이 값 초기설정 
{
	cats[0].name = "고양이0";
	cats[0].age = 5;
	cats[0].character = "온순";
	cats[0].level = 1;

	cats[1].name = "고양이1";
	cats[1].age = 3;
	cats[1].character = "날카롭";
	cats[1].level = 2;

	cats[2].name = "고양이2";
	cats[2].age = 2;
	cats[2].character = "시끄럽";
	cats[2].level = 4;

	cats[3].name = "고양이3";
	cats[3].age = 7;
	cats[3].character = "냉혈한";
	cats[3].level = 5;

	cats[4].name = "고양이4";
	cats[4].age = 13;
	cats[4].character = "상냥함";
	cats[4].level = 3;

}

void printCat(int selected)  //선택한 고양이에 대한 결과값을 출력해준다 
{
	printf("\n\n === 당신은 이 고양이의 집사가 되었어요! ===\n\n");
	printf("이름: %s\n", cats[selected].name);
	printf("나이: %d\n", cats[selected].age);
	printf("특징: %s\n", cats[selected].character);
	printf("레벨: ");

	for (int i = 0; i < cats[selected].level; i++)
	{
		printf("%s", "★"); //레벨만큼 i를 반복해서 별을 출력함, 레벨만큼 별개수로 치환해서 출력 
	}
	printf("\n\n");
}

int checkCollection()
{
	// 1. 현재 보유한 고양이 목록도 출력
	// 2. 다 모았는지 여부를 반환 

	int collectAll = 1; 

	printf("\n\n === 보유한 고양이 목록이에요 === \n\n");
	for (int i = 0; i < 5; i++)
	{
		if (collection[i] == 0) // 고양이 수집 X
		{
			printf("%10s", "(빈박스)");
			collectAll = 0; // 다 모으지 못한 상태
		}
		else // 고양이 수집 o
		{
			printf("%10s", cats[i].name);
		}
	}
	printf("\n=====================\n\n");

	if (collectAll)
	{
		printf("\n\n 축하합니다. 잘 키워주세요~~!");
	}

	return collectAll; //수집못했을때는 0 값을 넣어줘서, 수집못한 case는 최종적으로 0값을 리턴시켜준다(main 함수에다가) 
}



//struct Gameinfo {
//	char* name;
//	int year;
//	int price;
//	char* company;
//
//	struct Gameinfo* friendGame; //이런식으로 구조체안에 구조체를 선언할수도 있음, 그냥 아래 struct Gameinfo* gamePtr; 이렇게 선언한거랑 동일함 
//};  //;자동으로 붙음 
//
//typedef struct Gameinfomation {  // Gameinfomation 이거는 생략해도 무관하다 
//	char* name;
//	int year;
//	int price;
//	char* company;
//
//	struct Gameinfo* friendGame;
//}GAME_INFO;  // typedef struct Gameinfomation == GAME_INFO로 선언함 
//




////[게임출시]
//	//이름: 세미콜론
//	//발표년도: 2017년
//	//가격: 50원
//	//제작사: yoon's 
//
//	//구조체 사용
//struct Gameinfo gameinfo1; //struct Gameinfo까지가 struct,  gameinfo1가 변수
//gameinfo1.name = "세미콜론"; //이런식으로 변수.struct 내 family를 기입하면 됨
//gameinfo1.year = 2017;
//gameinfo1.price = 50;
//gameinfo1.company = "yoon's";
//
////구조체 출력
//printf("--\n게임출시정보 ==\n");
//printf(" 게임명   : %s\n", gameinfo1.name);
//printf(" 발매년도 : %d\n", gameinfo1.year);
//printf(" 가격     : %d\n", gameinfo1.price);
//printf(" 제작사   : %s\n", gameinfo1.company);
//
//struct Gameinfo gameinfo2 = { "올클론", 2018, 100, "yoont's" };  //(참고) 구조체를 배열처럼 초기화 할수도 있음, 물론 앞단에 정의는 해줘야 함 
//
//printf("--\n게임출시정보 ==\n");
//printf(" 게임명   : %s\n", gameinfo2.name);
//printf(" 발매년도 : %d\n", gameinfo2.year);
//printf(" 가격     : %d\n", gameinfo2.price);
//printf(" 제작사   : %s\n", gameinfo2.company);
//
////구조체 배열: 그냥 다중차원 배열 표현하듯, 중괄호 복수로 표현하면 됨
//struct Gameinfo gameArray[2] = {
//	{"1클론", 2018, 1000, "나도회사"},
//	{"2클론", 2019, 5000, "너도회사"}
//};
//
////구조체 포인터
//struct Gameinfo* gamePtr; //미션맨
//gamePtr = &gameinfo1;
//printf("--\n\n미션맨의 게임출시정보 ==\n");
//printf(" 게임명   : %s\n", (*gamePtr).name);
//printf(" 발매년도 : %d\n", (*gamePtr).year);
//printf(" 가격     : %d\n", (*gamePtr).price);
//printf(" 제작사   : %s\n", (*gamePtr).company); //이런식으로 (*변수)하고나서 .familyname을 붙여도 되고, 
//printf("\n");
//printf(" 게임명   : %s\n", gamePtr->name);
//printf(" 발매년도 : %d\n", gamePtr->year);
//printf(" 가격     : %d\n", gamePtr->price);
//printf(" 제작사   : %s\n", gamePtr->company); //이런식으로 변수 -> familyname해도 됨 (포인터변수일대만 화살표가능)


////typedef
//	//자료형에 별명을 지정
//
//typedef int 정수; //int라는 걸 아예'정수'로 치환했음
//정수 정수변수 = 3; //int i = 3과 동일한 의미가 됨 
//
//GAME_INFO game2;
//game2.name = "한글게임2";
//game2.year = 2014; //이런식으로 걍 앞단의 struct ~~이 치환되었다고 생각하면 된다
//
