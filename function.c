#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);
void success();
void fail();

int main()
{
	//���� 5���� �ְ�, �������� ���� ����� ���� ��� ����(����)
	//������ ���, Ʋ���� ����

	srand(time(NULL));
	int count = 0;
	for (int i = 1; i <= 5; i++)
	{
		int num1 = getRandomNumber(i);
		int num2 = getRandomNumber(i);
		showQuestion(i, num1, num2);  //�����κ� 

		int answer = -1;
		scanf("%d", &answer);
		if (answer == -1)
		{
		printf("���α׷��� �����մϴ�\n");
		exit(0);  //�ٷ� ���α׷��� �����Ų��. 
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
	printf("\n\n ����� 5���� ��й�ȣ �� %d���� ������ϴ�.\n", count);

	return 0; 
}


int getRandomNumber(int level)
{
	return rand() % (level * 10) + 1;
}

void showQuestion(int level, int num1, int num2)
{
	printf("\n\n\n###### %d��° ��й�ȣ ######\n", level);
	printf("\n\t%d x %d��?\n\n", num1, num2);
	printf("###########################\n");
	printf("\n��й�ȣ�� �Է��ϼ���(����: -1) >> ");
}

void success()
{
	printf("\n >> Good! �����Դϴ�.\n");
}
void fail()
{

	printf("\n >> fail! �����Դϴ�.\n");
}










//#include <stdio.h>
//
//void p(int num);
//void function_without_return();
//int function_with_return();
//void function_without_params(int num1, int num2, int num3); //�Ķ����(���ް�)�� �ִ� �Լ� 
//int apple(int num1, int num2);
//
//int main()
//{
//	//function_without_return();
//	//int ret = function_with_return();
//	//p(ret);
//
//	//function_without_params(33, 44, 55); //���⼭ �Ķ���͸�(���ް���) �Լ��� �ѱ��, �Լ����� �װ� �޾Ƽ� main�Լ��� ���������ش�. 
//
//	printf("�̰� �մ��̿�\n");
//	printf("��� %d�� �߿� %d���� ������? %d���� ���ƿ�\n", 10, 6, apple(10, 4));
//	printf("�̰� �޴��̿�\n");
//
//	return 0;
//}
//
//int apple(int num1, int num2)
//{
//	printf("���ް��� ��ȯ���� �ִ� �Լ��Դϴ�.\n"); //main�Լ��� printf�� �� ����ϱ� ���� apple �Լ��� �����ϱ� ������ �̰��� ���� ����� �Ǿ���� 
//	return num1 - num2; //���ϰ��� main�Լ��� �����ְ� �� 
//}

//����
//void p(int num)  //p�� �Լ��̸�, int num �� ������ ���� 
//{
//	printf("num�� %d �Դϴ�\n", num);
//}
//
//void function_without_return()
//{
//	printf("��ȯ���� ���� �Լ��Դϴ�\n");
//}
//
//int function_with_return()
//{
//	printf("��ȯ���� �ִ� �Լ��Դϴ�\n");
//	return 10;
//}
//
//void function_without_params(int num1, int num2, int num3)
//{
//	printf("�Ķ���͸� ������ ���� %d %d %d�� �������մϴ�.", num1, num2, num3);
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
//	num /= 3;  //�������� �����ϰ� �Ҷ� �̷��� �ٿ��� ����Ѵ� 
//	p(num);
//
//
//	return 0;
//}





//��ȯ�� �Լ��̸�(���ް�)
//{
//
//}

//�Լ� ���� 
//1. ��ȯ���� ���� �Լ� 


//2. ��ȯ���� �ִ� �Լ� 