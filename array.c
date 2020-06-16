#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// 10������ ���� �ٸ� ���� (�� ī�� 2�徿)
// ����ڷκ��� 2���� �Է°��� �޾Ƽ� -> ���� ���� ã���� ī�� ������
// ��� ���� ���� ã���� ���� ����
// �� ���� Ƚ�� �˷��ֱ�

int arrayAnimal[4][5]; //ī�� ����(20���� ī��)
int checkAnimal[4][5]; //ī�尡 ���������� Ȯ��
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

	int failCount = 0; //���� Ƚ��

	while (1)
	{
		int select1 = 0; // ����ڰ� ������ ó�� �� 
		int select2 = 0; // ����ڰ� ������ �ι�° ��

		printAnimals(); // ���� ��ġ ���
		printQuestion();// ���� ���(ī�� ����)
		printf("\n������ ī�带 2�� ������: ");
		scanf("%d %d", &select1, &select2);

		if (select1 == select2) //���� ī�� ���� �� ��ȿ
			continue;

		//��ǥ�� �ش��ϴ� ī�带 ������ ���� ������ �Ȱ����� Ȯ��
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);


		//ī�尡 �������� �ʾҰ� & ���� ������ ��찡 ������ ���� 
		if ((checkAnimal[firstSelect_x][firstSelect_y] == 0 
			&& checkAnimal[secondSelect_x][secondSelect_y] == 0)

			&&

			(arrayAnimal[firstSelect_x][firstSelect_y]			//���� ������ ��� 
			== arrayAnimal[secondSelect_x][secondSelect_y])
			)
		{
			printf("\n\n����! : %s �߰�\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1; //����ֵ��� 1�� ���������(����������)
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}
		else //�ٸ� ������ ���
		{
			printf("��!! (Ʋ�Ȱų�, �̹� ������ ī���Դϴ�) \n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failCount++;
		}

		//��� ������ ã�Ҵ��� ����, ���̸� 1, �ƴϸ� 0
		if (foundAllAnimals() == 1)
		{
			printf("\n\n �����մϴ�!. ��� ������ �� ã�ҳ׿� \n");
			printf("���ݱ��� �� %d�� �Ǽ��Ͽ����ϴ�\n", failCount);
			break; //�� ������ Ż��
		}
	}

	return 0;
}



//�ʱⰪ ����
void initAnimalArray()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arrayAnimal[i][j] = -1; //-1�� �ϴ� �ʱ�ȭ�� 
		}
	}
}

//���� ���� 
void initAnimalname()
{
	strAnimal[0] = "������";
	strAnimal[1] = "�ϸ�";
	strAnimal[2] = "������";
	strAnimal[3] = "�����";
	strAnimal[4] = "����";

	strAnimal[5] = "�ڳ���";
	strAnimal[6] = "�⸰";
	strAnimal[7] = "��Ÿ";
	strAnimal[8] = "Ÿ��";
	strAnimal[9] = "ȣ����";
}


//�����ؼ� x,y�� �� �������� �ֱ� 
void shuffleAnimal()
{
	// ����������
	// ����������
	// ����������
	// ����������


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

//��ǥ���� ����� ã��
int getEmptyPostition()
{
	// ����������	 0  1  2  3  4  -> 5�� ������ 00000
	// ����������	 5  6  7  8  9               11111
	// ����������	10 11 12 13 14				 22222
	// ����������	15 16 17 18 19				 33333


	while (1) //��� �ݺ�
	{
		int randPos = rand() % 20; //0~19������ ���� ��ȯ 
		//19 -> (3,4)
		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);

		if (arrayAnimal[x][y] == -1) //������� ������(�ʱⰪ�� ������) �ٽ� �Լ��� ������
		{
			return randPos;
		}
	}
	return 0;
}

int conv_pos_x(int x)
{
	//19 -> (3,4)
	return x / 5; //5�� ���� ��
};

int conv_pos_y(int y)
{
	return y % 5; //5�� ���� ������
}


void printAnimals() //���� ��ġ ���(�����)
{
	// ����������	 0  1  2  3  4  
	// ����������	 5  6  7  8  9              
	// ����������	10 11 12 13 14           
	// ����������	15 16 17 18 19
	printf("\n==========����ε�, ���� ������ =======\n");
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
	printf("\n\n(����)\n");
	int seq = 0; //ĭ���� ���ڷ� ��ġȭ�ϱ� ���� ���ǻ� ������

					//seq				 //checkAnimal
// ����������	 0  1  2  3  4            00010
// ����������	 5  6  7  8  9            10000  
// ����������	10 11 12 13 14            00000
// ����������	15 16 17 18 19			  00000

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//ī�带 ����� ������ �������� '���� �̸�' 
			if (checkAnimal[i][j] != 0)
			{
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}
			//���� ������ �������� (������ ������ ��������) �޸� -> ��ġ�� ��Ÿ���� ����
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
				return 0; //���� ��ã�� 
		}
	}
	return 1; //��� �� ã��
}




//������ �迭 ǥ���ϴ� ���
//
//int arr[5];
//����������
//[0][1][2][3][4]
//
//int arr2[2][5]; //��x���̶�� �����ϸ� ���ҵ� 
//����������
//����������
//[0,0][0,1][0,2][0,3][0,4]  -> arr2[0][0] �̷��� ǥ���ϸ� ��  
//[1,0][1,1][1,2][1,3][1,4]

//������ ���? 
//int arr2[2][5] = {{1,2,3,4,5}, {1,2,3,4,5}} 
//
//int arr2[2][5] = {
//	{1,2,3,4,5},
//	{1,2,3,4,5}
//}
//�̷������� 1��, 2�� ������� �� ������ �����ָ� �ȴ�. 


//������ �迭 �����ϴ� ���
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
//			printf("3�����迭(%d %d %d)�� ��: %d\n", i, j, k, arr4[i][j][k]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}