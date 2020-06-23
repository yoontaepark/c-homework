#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

//����Ⱑ 6������ �ִ�, �̵��� ���׿� ��� �ִµ� �縷��, �縷�� �ʹ� ������ ���� ���� ������ 
// ���� �� �����ϱ� ���� �������� ���׿� ���� �༭ ����⸦ ����ּ���
// ������ �ð��� �������� ���� Ŀ����...���߿���....�ȳ�..

int level;
int arrayFish[6];
int *cursor;

void initData();
void printfFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();

int main()
{
	long startTime = 0; //���� ���۽ð� 
	long totalElapsedTime = 0; //�� ��� �ð�
	long prevElapsedTime = 0;//���� ��� �ð�(�ֱٿ� ���� �� �ð� ����)

	int num; //��� ���׿� ���� �ٰ�����, ����� �Է�
	initData(); //�ʱ� ������ ��������

	cursor = arrayFish; // cursor[0], cursor[1],.... 

	startTime = clock();//���� �ð��� millisecond(1000���� 1��) ������ ��ȯ ex)4000�̸� 4��
	while (1) //���ѹݺ�
	{
		printfFishes(); //�ʱ� ���°��� ����ϴ� �Լ��� �����Ѵ�
		printf("�� �� ���׿� ���� �ֽðھ��? ");
		scanf("%d", &num);

		//�Է°� üũ 
		if (num < 1 || num>6)
		{
			printf("\n�Է°��� �߸��Ǿ����ϴ�\n");
			continue; // �ش� ������ ������ �ԷµǾ��� ��� ���� ������ ����ϰ�, �ٽ� while�Լ��� �ǵ��ư��� 
		}


		// �� ��� �ð� 
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC; //�ʷ� ��ȯ�ϱ�(�� ��쿡�� /1000�� ���� �ǹ���) 
		printf("�� ��� �ð�: %ld��\n", totalElapsedTime);

		//���� �� �� �ð�(���������� �� �� �ð�) ���ķ� �帥 �ð�
		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("�ֱ� ��� �ð�: %ld ��\n", prevElapsedTime);

		//������ ���� ���ҽ�Ŵ
		decreaseWater(prevElapsedTime);

		//����ڰ� �Է��� ���׿� ���� �ش�
		// 1. ������ ���� 0�̸�? ���� ���� �ʴ´�
		if (cursor[num - 1] <= 0)
		{
			printf("%d�� ������ �̹� �׾����ϴ�..���� ���� �ʽ��ϴ�\n", num);
		}
		//2. ������ ���� 0�� �ƴ� ���? ���� �ش�, �ٸ� 100�� ���� �ʴ��� üũ������ �־�� ��
		else if (cursor[num - 1] + 1 <= 100)
		{
			//���� �ش�
			printf("%d�� ���׿� ���� �ݴϴ�\n\n", num);
			cursor[num - 1] += 1; //cursor[num - 1] = cursor[num - 1] + 1
		}

		//�������� �� ���� Ȯ��(ex. �������� 20�ʸ��� �ѹ��� ����)
		if (totalElapsedTime / 20 > level - 1) //ex. 15�� ��������, 15/20�� 0���� �ν���, ������ 1���� �����ϴ� �̰��� 0>0�� �ƴϱ� ������ ������ ����, 21�ʸ� 1>0�̴ϱ� ������  
		{
			//������
			level++;
			printf(" ***�� ������! ���� %d�������� %d ������ ���׷��̵� ***", level - 1, level);

			//���� ����: 5
			if (level == 5)
			{
				printf("\n\n�����մϴ�. �ְ� ������ �޼��ϼ̽��ϴ�. ������ �����մϴ�\n\n");
				exit(0);
			}
			//getchar(); //�ӽ÷� ����� �Է� ��� 
		}

		//��� ����Ⱑ �׾����� Ȯ��
		if (checkFishAlive() == 0)
		{
			//����� ��� �Ф�
			printf("��� ����Ⱑ..�Ф� GG \n");
			exit(0);
		}
		else
		{
			//�ּ� �Ѹ��� �̻��� ����Ⱑ ����ִ� ���
			printf("����Ⱑ ���� ��� �־��!\n");
		}
		prevElapsedTime = totalElapsedTime;
		//�̰� �ִ� ������ ex. �� ����ð��� 10�� �� 15�� �� 25�� �̷��� ������, 
		// �� ����ð�(prev)�� ���� 10��(0��) , 15��(5��), 25��(prev 10�ʸ� ����ؾ��ϴµ�) �ε� ���� prev�� ������ 5�ʿ� �����Ǿ� ����
		// ���� prev�� 15�ʷ� �缳��(�Ѱ���ð�)�Ѵ����� ���� trail�� �Ѱ���ð����� �������ָ� 25��-15�� =10�ʸ� �� ���� prev ������ ������ �� ����
		// �� ���Ŀ��� �� �ٽ� prev ���� 25�ʷ� �缳�����ְ� �� ����ð�(new)���� 25�ʸ� ���ָ� �� ���ο� prev ���� ���� 
	}
	return 0;
}


void initData()
{
	level = 1; //���� ���� (1~5)
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] = 100; //������ �� ����(0~100)
	}
}

void printfFishes()
{
	printf("%3d�� %3d�� %3d�� %3d�� %3d�� %3d��\n", 1, 2, 3, 4, 5, 6); //%3d�� �̸� 3ĭ(%3d) +2ĭ(��) + 1ĭ(����)���� �� 6ĭ
	for (int i = 0; i < 6; i++)
	{
		printf("  %3d ", arrayFish[i]); //���⵵ ���������� 2(�հ���) +3(%3d) + 1(�ް���) ���� ������ �����ش�. 
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
			return 1; //�� true
	}
	return 0;
}




/*>>>> ������ ���� <<<<*/
//������ ������ �����Ϸ���: *����
//����, �����ͺ����� �����ߴٸ�, �ּҸ� ����������� �� 
// �̰����� ���� = &�ٸ�����(�̰� �ٸ������� �ּ�) 
//�����ͺ����� ���� ����ϰ��� �Ѵٸ�, *������ �Է��ϸ� ��. 
//�̿ͺ����� �׳� ������ �ּҸ� ����ϰ� ������ &����, �����ͺ����� ��� �׳� ������ �־��ָ� �ȴ�. 

/* �̼Ǹ� ���� */
//int ö�� = 1;
//printf("%d, %d\n", &ö��, ö��);
//
//int* �̼Ǹ�;
//�̼Ǹ� = &ö��;
//printf("�湮�ּ�: %d, %d\n", �̼Ǹ�, *�̼Ǹ�);
//
//*�̼Ǹ� += 2;  //��Ģ���굵 �����ϳ�, �����ͺ����� ��Ģ������ *����ä�� ��Ģ������ �����ؾ� 
//printf("�̼Ǹ� �ּҴ� %d\n", *�̼Ǹ�);

//�迭�� �������� ����: ���� ������ ����� �Ѵ�
//int arr[3] = { 5,10,15 };
//int* ptr = arr;
//for (int i = 0; i < 3; i++)
//{
//	printf("�迭 arr[%d]�� ��: %d\n", i, arr[i]);
//	printf("������ ptr[%d]�� ��: %d\n", i, ptr[i]);
//}
//
//ptr[0] = 100;
//ptr[1] = 200;
//ptr[2] = 300;  //*ptr = ptr[] = arr[] �� �����ϴٰ� ���� ��
//printf("\n");
//
//for (int i = 0; i < 3; i++)
//{
//	printf("�迭 arr[%d]�� ��: %d\n", i, arr[i]);
//	printf("�迭 arr[%d]�� ��: %d\n", i, *(arr + i)); //arr[i] == *(arr+i)  == ptr[i] == *(ptr+i)
//	printf("������ ptr[%d]�� ��: %d\n", i, ptr[i]);
//}
//
//// arr == arr�迭�� ù��° ���� �ּҿ� ���� == &arr[0]
//printf("�迭 arr���� arr[]�� �������� arr��ü�� �ּҷ� ���� ���´�: %d\n", arr);
//printf("arr[0]�� �ּ�: %d, ��: %d\n", &arr[0], arr[0]);
//
//printf("arr��ü�� ���� ��: %d\n", *arr); // ==*(arr+0)
//printf("arr[0]�� ��: %d\n", *&arr[0]);
//printf("arr[0]�� ��: %d\n", *&*&*&*&*&*&*&*&*&*&*&*&*&*&arr[0]);
//printf("arr[0]�� ��: %d\n", arr[0]);
////*&�� ���� ����. ��, �ƹ��͵� ���� �Ͱ� ����. &�� �ּ��̸� *�� �� �ּ��� ���̱� ������


//	/* call by value vs call by reference */
//	int a = 10;
//	int b = 20;
//	printf("a�� �ּ�: %d, b�� �ּ�: %d\n", &a, &b);
//
//
//	//printf("Swap �Լ� �� => a : %d, b : %d\n", a, b);
//	//swap(a, b); //call by value ��
//	//printf("Swap �Լ� �� => a : %d, b : %d\n", a, b);
//
//	//�ּҰ��� �ѱ�� ���̽�
//	printf("(�ּҰ� ����)Swap �Լ� �� => a : %d, b : %d\n", a, b);
//	swap_addr(&a, &b); //call by reference ��
//	printf("(�ּҰ� ����)Swap �Լ� �� => a : %d, b : %d\n", a, b);
//
//	return 0;
//}
//
////void swap(int a, int b)
////{
////	printf("Swap �Լ� �� =>  a�ּ�: %d, b�ּ� : %d\n", &a, &b);
////	
////	int temp = a;
////	a = b;
////	b = temp;
////	printf("Swap �Լ� �� =>  a : %d, b : %d\n", a, b);
////}
//
//void swap_addr(int* a, int* b)
//{
//	printf("Swap �Լ� �� =>  a�ּ�: %d, b�ּ� : %d\n", &a, &b);
//	printf("Swap �Լ� �� =>  a�ּ�: %d, b�ּ� : %d\n", a, b);
//
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//	printf("Swap �Լ� �� =>  a : %d, b : %d\n", *a, *b);
//}
