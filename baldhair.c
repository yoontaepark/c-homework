#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>


int answer; //����� �Է°�
int Showbottle = 0; //�̹� ���ӿ� ������ �� ����
int prevShowbottle = 0; //�� ���ӿ� ������ �� ����
int bottle[4] = { 0, 0, 0, 0 };

// ���� �����ִ� �� ������ �ٸ��� �غ�����(ó���� 2�� �� ������ 3�� �� ������ 2��..)

int isincluded = 0; //������ �� �߿� �߸����� ���ԵǾ� �ִ��� Ȯ���ϱ� ���� ����

int main()
{
	srand(time(NULL));
	int treatment = rand() % 4; //�߸����� ����ִ� ���� ��������(0~3) 
	printf("\n\n ===My dad is bald T.T === \n\n");

	for (int i = 0; i < 3; i++) 	//3���� ��ȸ�� �ο� 
	{
		 //�������� �� ������ �迭�� ǥ��(a0, a1, a2, a3)
		do
		{
			Showbottle = rand() % 2 + 2; //������ ���� ����(0~1, +2 = 2~3) 
		} while (Showbottle == prevShowbottle);
		prevShowbottle = Showbottle;

		printf(" > %d ��° �õ� : ", i+1);

		for (int j = 0; j < Showbottle; j++)
		{
			int randbottle = rand() % 4; //���� ��������(0~3)
			
			if (bottle[randbottle] == 0) //���� ���õ��� ���� ���̸� ����ó������ 
			{
				bottle[randbottle] = 1;
				if (randbottle == treatment)
				{
					isincluded = 1;
				}
			}
			else //�̹� ���õ� ���̸�, �ߺ��̸�� �ٽ� ����
			{
				j--;
			}
		}

		for (int k = 0; k < 4; k++)
		{
			if (bottle[k] == 1) 
				printf("%d ", k + 1);
		}
		printf("������ �Ӹ��� �ٸ��ϴ�\n\n");

		if (isincluded == 1)
		{
			printf(" >> success, my hair is growing!! \n");
		}
		else
		{
			printf(" >> fail, my hair is still bald!! \n");
		}
		printf("\n ...if you want to continue, press any button\n");
		getchar(); //�Է¹��������� �����
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



// �迭 ���ÿ� ���� 1����: 1byte, �ѱ� 1����: 2byte, char ũ��: 1byte
//����: 0~127 ������ �ƽ�Ű�ڵ� �������� �ش��ϴ� ���� Ȯ���ϱ�

//for (int i = 0; i < 128; i++)
//{
//	printf("�ƽ�Ű�ڵ� ���� %d : %c \n", i, i);
//}
//return 0;