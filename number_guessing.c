#define _CRT_SECURE_NO_WARNINGS //define�� �ű��ϰԵ� �� ���� ���ƾ��ϴ��� 
#include <stdio.h>
#include <time.h>

/*���ڸ��߱� ������ ���� ������ */

int main()
{
	srand(time(NULL));
	int num = rand() % 100 + 1; // ������ 100���� ���� �������̹Ƿ� 0~99�� �����ϱ� �� �� ��ü�� +1�� ���ָ� 1~100�� ���� (��ȣ�� ���ֳ� ���� %�� ���� �����)
	printf("%d\n", num); //���� ������ �̸� ������(�̺κ��� ���� ���Ӽ���� �ּ�ó���ص� ������)
	int answer = 0;
	int chance = 5; 

	printf("[����]����...������ ��������.");

	while (chance > 0)
	{
		printf("��ȸ�� �� %d���̴�.\n", chance--);
		printf("[�ý���]���ڸ� ���纸���� (1~100), UP&DOWN : ");
		scanf("%d", &answer);

		if (answer > num)
		{
			printf("[����]��! DOWN�̾�!\n");
			printf("====================\n");

		}
		else if (answer < num)
		{
			printf("[����]��! UP�̾�\n");
			printf("====================\n");
		}
		else if (answer == num)
		{
			printf("\n\n[����]�ƴ� �̰� ���ߴٴ�....���� �¸���\n\n");
			break;
		}
		else
		{
			printf("[����]���� �߸��Է��� ����̱�, �˷��� ������ ���� ������\n");
			printf("====================\n");
		}
		if (chance == 0)
		{
			printf("[����]��ȸ�� ��� �����߱�, �ʴ� �й��ڴ� ��������\n");
		}
	}
	return 0;
}










/*break �� �̿��ؼ� case �Ϻο��� ��¹��� ���� ���� �ִ�  8~13�� �ʵ��л�, 14~16 ���л�, 17~19�� ����л�, �������� �̿� �� ���*/

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
//	case 13:printf("�ʵ��л���\n"); break;
//	case 14:
//	case 15:
//	case 16:printf("���л���\n"); break;
//	case 17: //���� �� 17�� �޾Ƽ� case 17�� ���������� break�� �����Ƿ� ���� ���� �� �Ʒ��� ������
//	case 18: //���� ����
//	case 19:printf("����л���\n"); break; //���⿡�� ����л����� ����ϰ� break �� �Լ��� �������� 
//	default:printf("�л��� �ƴ�\n"); break;
//	}
//	return 0;
//}




	/*����: 1������ 30������ �ִ� �ݿ��� 7�� �л��� ���ۼ� �Ἦ,
	  7���� �����ϰ� 6~10������ ���� ��ǥ�� �ϼ���. */

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
	  //				printf("%d�� �л��� �Ἦ�Դϴ�.\n", i);
	  //				continue;  // �� ��� ������ �����ϸ� �ٷ� ��� if���� ������������ �Ѿ(���� �Է¹��� ���� x) 
	  //			}
	  //			printf("%d�� �л��� ������ǥ�� �ϼ���.\n", i);
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
	  //				printf("%d�� �л��� �Ἦ�Դϴ�.\n", i);
	  //				break;  // �� ��� ������ �����ϸ� for���� Ż���� 
	  //			}
	  //			printf("%d�� �л��� ������ǥ�� �ϼ���.\n", i);
	  //		}
	  //
	  //	}
	  //
	  //	return 0;
	  //}
	  //���� &&�� and �����̰� ||�� or �����̴�. 

	  /* switch�� ����*/

	  //#include <time.h>
	  //
	  //int main()
	  //{
	  //	srand(time(NULL));
	  //	int i = rand() % 3;
	  //	switch(i)
	  //	{
	  //	case 0:printf("����\n"); break; //switch ���� ���� case ���� �Ʒ��κ��� �� �����ϱ� ������ break�� ���� �ɾ���� �ϳ��� ���� ���´�  
	  //	case 1:printf("����\n"); break;
	  //	case 2:printf("��\n"); break;
	  //	default:printf("�����\n"); break;
	  //	}
	  //	return 0;
	  //}


