#include <stdio.h>
#include <time.h>

// 5������ ����̰� �ִ�
// �ƹ�Ű�� ������ �������� ����̸� �̵�, 
// 5���� ��� �� ������ �ؼ� ������ Ű��� �Ǵ� ���� 
// �ߺ� �߻����� 

// �����
// �̸�, ����, ����, Ű��� ���̵�(����) 
typedef struct {
	char* name; //�̸�
	int age; //����
	char* character; //����
	int level; //Ű��� ���̵�(1~5, 5�� ���� �����)
} CAT;

//������� ������ �����
int collection[5] = { 0, 0, 0, 0, 0 };

//��ü ����� ����Ʈ
CAT cats[5];

void initCats(); //����� ���� �ʱ�ȭ
void printCat(int selected); // ������ ����� ����� ��� �Լ� 

int main()
{
	srand(time(NULL)); //�����̱⸦ ���� ����

	initCats(); //����� �� �ʱ⼳�� 
	while (1) //�ݺ��� ���� ����
	{
		printf("��� ������� ���簡 �ɱ��? \n �ƹ�Ű�� ������ Ȯ���ϼ���~~!"); //��¹��� �ϴ� ��������
		getchar(); //���������� ��� 

		int selected = rand() % 5; //0~4������ ���ڸ� ��ȯ�Ѵ� 
		printCat(selected); //������ ����� ����� ��� 
		collection[selected] = 1; //����� �̱� ó��

		int collectAll = checkCollection(); //checkcollection�� ���ϰ��� 0 �ƴ� 1�� �� ����
		if (collectAll == 1) // 1�� ��� break�� ��������, �ƴ� ��� while���� �ǰ� �ݺ������� �� 
		{
			break;
		}
	}
	return 0;
}

void initCats()  //����� �� �ʱ⼳�� 
{
	cats[0].name = "�����0";
	cats[0].age = 5;
	cats[0].character = "�¼�";
	cats[0].level = 1;

	cats[1].name = "�����1";
	cats[1].age = 3;
	cats[1].character = "��ī��";
	cats[1].level = 2;

	cats[2].name = "�����2";
	cats[2].age = 2;
	cats[2].character = "�ò���";
	cats[2].level = 4;

	cats[3].name = "�����3";
	cats[3].age = 7;
	cats[3].character = "������";
	cats[3].level = 5;

	cats[4].name = "�����4";
	cats[4].age = 13;
	cats[4].character = "�����";
	cats[4].level = 3;

}

void printCat(int selected)  //������ ����̿� ���� ������� ������ش� 
{
	printf("\n\n === ����� �� ������� ���簡 �Ǿ����! ===\n\n");
	printf("�̸�: %s\n", cats[selected].name);
	printf("����: %d\n", cats[selected].age);
	printf("Ư¡: %s\n", cats[selected].character);
	printf("����: ");

	for (int i = 0; i < cats[selected].level; i++)
	{
		printf("%s", "��"); //������ŭ i�� �ݺ��ؼ� ���� �����, ������ŭ �������� ġȯ�ؼ� ��� 
	}
	printf("\n\n");
}

int checkCollection()
{
	// 1. ���� ������ ����� ��ϵ� ���
	// 2. �� ��Ҵ��� ���θ� ��ȯ 

	int collectAll = 1; 

	printf("\n\n === ������ ����� ����̿��� === \n\n");
	for (int i = 0; i < 5; i++)
	{
		if (collection[i] == 0) // ����� ���� X
		{
			printf("%10s", "(��ڽ�)");
			collectAll = 0; // �� ������ ���� ����
		}
		else // ����� ���� o
		{
			printf("%10s", cats[i].name);
		}
	}
	printf("\n=====================\n\n");

	if (collectAll)
	{
		printf("\n\n �����մϴ�. �� Ű���ּ���~~!");
	}

	return collectAll; //�������������� 0 ���� �־��༭, �������� case�� ���������� 0���� ���Ͻ����ش�(main �Լ����ٰ�) 
}



//struct Gameinfo {
//	char* name;
//	int year;
//	int price;
//	char* company;
//
//	struct Gameinfo* friendGame; //�̷������� ����ü�ȿ� ����ü�� �����Ҽ��� ����, �׳� �Ʒ� struct Gameinfo* gamePtr; �̷��� �����ѰŶ� ������ 
//};  //;�ڵ����� ���� 
//
//typedef struct Gameinfomation {  // Gameinfomation �̰Ŵ� �����ص� �����ϴ� 
//	char* name;
//	int year;
//	int price;
//	char* company;
//
//	struct Gameinfo* friendGame;
//}GAME_INFO;  // typedef struct Gameinfomation == GAME_INFO�� ������ 
//




////[�������]
//	//�̸�: �����ݷ�
//	//��ǥ�⵵: 2017��
//	//����: 50��
//	//���ۻ�: yoon's 
//
//	//����ü ���
//struct Gameinfo gameinfo1; //struct Gameinfo������ struct,  gameinfo1�� ����
//gameinfo1.name = "�����ݷ�"; //�̷������� ����.struct �� family�� �����ϸ� ��
//gameinfo1.year = 2017;
//gameinfo1.price = 50;
//gameinfo1.company = "yoon's";
//
////����ü ���
//printf("--\n����������� ==\n");
//printf(" ���Ӹ�   : %s\n", gameinfo1.name);
//printf(" �߸ų⵵ : %d\n", gameinfo1.year);
//printf(" ����     : %d\n", gameinfo1.price);
//printf(" ���ۻ�   : %s\n", gameinfo1.company);
//
//struct Gameinfo gameinfo2 = { "��Ŭ��", 2018, 100, "yoont's" };  //(����) ����ü�� �迭ó�� �ʱ�ȭ �Ҽ��� ����, ���� �մܿ� ���Ǵ� ����� �� 
//
//printf("--\n����������� ==\n");
//printf(" ���Ӹ�   : %s\n", gameinfo2.name);
//printf(" �߸ų⵵ : %d\n", gameinfo2.year);
//printf(" ����     : %d\n", gameinfo2.price);
//printf(" ���ۻ�   : %s\n", gameinfo2.company);
//
////����ü �迭: �׳� �������� �迭 ǥ���ϵ�, �߰�ȣ ������ ǥ���ϸ� ��
//struct Gameinfo gameArray[2] = {
//	{"1Ŭ��", 2018, 1000, "����ȸ��"},
//	{"2Ŭ��", 2019, 5000, "�ʵ�ȸ��"}
//};
//
////����ü ������
//struct Gameinfo* gamePtr; //�̼Ǹ�
//gamePtr = &gameinfo1;
//printf("--\n\n�̼Ǹ��� ����������� ==\n");
//printf(" ���Ӹ�   : %s\n", (*gamePtr).name);
//printf(" �߸ų⵵ : %d\n", (*gamePtr).year);
//printf(" ����     : %d\n", (*gamePtr).price);
//printf(" ���ۻ�   : %s\n", (*gamePtr).company); //�̷������� (*����)�ϰ��� .familyname�� �ٿ��� �ǰ�, 
//printf("\n");
//printf(" ���Ӹ�   : %s\n", gamePtr->name);
//printf(" �߸ų⵵ : %d\n", gamePtr->year);
//printf(" ����     : %d\n", gamePtr->price);
//printf(" ���ۻ�   : %s\n", gamePtr->company); //�̷������� ���� -> familyname�ص� �� (�����ͺ����ϴ븸 ȭ��ǥ����)


////typedef
//	//�ڷ����� ������ ����
//
//typedef int ����; //int��� �� �ƿ�'����'�� ġȯ����
//���� �������� = 3; //int i = 3�� ������ �ǹ̰� �� 
//
//GAME_INFO game2;
//game2.name = "�ѱ۰���2";
//game2.year = 2014; //�̷������� �� �մ��� struct ~~�� ġȯ�Ǿ��ٰ� �����ϸ� �ȴ�
//
