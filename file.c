#define _CRT_SECURE_NO_WARNINGS  //���α׷� ���� ���� �����ؾߵ� 
#include <stdio.h>

// ��й�ȣ�� �Է� �޾Ƽ� 
// �´� ���? ��� �ϱ⸦ �о�ͼ� �����ְ�, ��� �ۼ��ϵ��� �մϴ�. 
// Ʋ�� ���? ��� �޽����� ǥ���ϰ� �����մϴ�. 

#define MAX 10000

int main()
{
	//fgets, fputs Ȱ��
	char line[MAX]; //���Ͽ��� �ҷ��� ������ ������ ����
	char contents[MAX]; //�ϱ��忡 �Է��� ����
	char password[20]; //��й�ȣ �Է�
	char c; //��й�ȣ �Է��� �� Ű�� Ȯ�ο�(����ŷ) 

	printf("Welcome to secret diary\n");
	printf("input your password : ");

	//getchar() / getch()�� ����?
	//getchar() : ���͸� �Է¹޾ƾ� ������ �Ѵ�
	//getch() : Ű �Է� �� �ٷιٷ� ������ �Ѵ� 

	int i = 0;
	while (1)
	{
		c = getch(); //���ھ� ��й�ȣ�� �Է��ϰ�, �̿� �ٷιٷ� ������ �ϵ��� �ϱ� ����
		if (c == 13) //Enter => ��й�ȣ �Է� ���� 
		{
			password[i] = '\0';
			break;
		}
		else //��й�ȣ �Է��� 
		{
			printf("*");
			password[i] = c;
		}
		i++;
	}

	// ��й�ȣ: 1234abcd 
	printf("\n\n === ��й�ȣ Ȯ����... ===\n\n");
	if (strcmp(password, "1234abcd") == 0) //��й�ȣ ��ġ, strcmp �� �Ἥ �ι��ڸ� ���ϴ� ����� �������
	{
		printf("=== ��й�ȣ Ȯ�� �Ϸ� === \n\n");
		char* fileName = "C:\\Users\\PC\\Desktop\\secretdiary.txt";
		FILE* file = fopen(fileName, "a+b"); //a+b�� �ǹ̴� ������ ������ ����, ������ ������ append(�ڿ������� ������ �߰�) �Ѵٴ� ��
		if (file == NULL)
		{
			printf("���� ���� ����\n");
			return 1;
		}
		while (fgets(line, MAX, file) != NULL)
		{
			printf("%s", line);
		}

		printf("\n\n ������ ��� �ۼ��ϼ���! �����Ͻ÷��� exit�� �Է��ϼ���\n\n");

		while (1)
		{
			scanf("%[^\n]", contents); //�� ��(\n)�� ������ ������ �о���� (�ѹ��徿 �ۼ�)
			getchar(); //Enter �Է�(\n) flush ó��(enter �����ϱ�)

			if (strcmp(contents, "exit") == 0)
			{
				printf("����ϱ� �Է��� �����մϴ�\n\n");
				break;
			}
			fputs(contents, file);
			fputs("\n", file); //Enter�� ������ ����ó���߱� ������ ���Ƿ� �߰��Ѵ�
		}
		fclose(file);
	}
	else //��й�ȣ Ʋ�� ���
	{
		printf("=== password is incorrect===\n\n");
		printf("Guards!!! Get him out of here\n\n\n");
	}

	return 0;
}



////���� �����
//	//���Ͽ� � �����͸� ����, 
//	//���Ͽ� ����� �����͸� �ҷ�����
//
//	//fputs, fgets ��
//char line[MAX];
//
//
//
//////���Ͽ� ����
////FILE* file = fopen("C:\\Users\\PC\\Desktop\\test1.txt", "wb"); 
//////�ش� ���丮�� �ִ� ������ wb���·� ���ڴ��̰�, \�� ������ �ϳ��� ��ο� ������, �ڵ��ÿ��� �ΰ��� ����� ��(�ϱ�) 
//////r �б�����, w ��������, a �̾��, //t�ؽ�Ʈ, b ���̳ʸ� ����
//////������ ������ �ʾҴ���, ������� 
//
////if (file == NULL)
////{
////	printf("���� ���� ����\n");
////	return 1;
////}
//
////fputs("fputs �� �̿��ؼ� ���� ����Կ�\n", file); //�ش� ���Ͽ� ������ ����ֱ� 
////fputs("�� �������� Ȯ�����ּ���\n", file);
//
//
////���� �б�
//FILE* file = fopen("C:\\Users\\PC\\Desktop\\test1.txt", "rb");
//
//if (file == NULL)
//{
//	printf("���� ���� ����\n");
//	return 1;
//}
//
//while (fgets(line, MAX, file) != NULL)
//{
//	printf("%s", line);
//}
//
//// ������ ���� ���� ���� ���� ���¿��� � ���α׷��� ������ �����, 
//// ������ �ս� �߻� ����! �׷��� �׻� ������ �ݾ��ִ� ������ �鿩���� 
//fclose(file); //open�� ������ close�� �׻� pair�� �����ϱ� 


////fprintf, fscanf ��
//
//	//printf("%d %d %s ...")
//	//scanf("%d %d", &num1, ...)
//int num[6] = { 0,0,0,0,0,0 }; //��÷��ȣ
//int bonus = 0; //���ʽ� ��ȣ
//char str1[MAX];
//char str2[MAX];
//
//
//////���Ͽ� ���� 
////FILE* file = fopen("C:\\Users\\PC\\Desktop\\test2.txt", "wb");
////if (file == NULL)
////{
////	printf("���� ���� ����\n");
////	return 1;
////}
//
//////�ζ� ��÷��ȣ ����
////fprintf(file, "%s %d %d %d %d %d %d\n", "��÷��ȣ", 1, 2, 3, 4, 5, 6);
////fprintf(file, "%s %d\n", "���ʽ���ȣ", 7);
//
//
////���Ͽ� �б�
//FILE* file = fopen("C:\\Users\\PC\\Desktop\\test2.txt", "rb");
//if (file == NULL)
//{
//	printf("���� ���� ����\n");
//	return 1;
//}
//
//fscanf(file, "%s %d %d %d %d %d %d", str1, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
//printf("%s %d %d %d %d %d %d\n", str1, num[0], num[1], num[2], num[3], num[4], num[5]);
//
//fscanf(file, "%s %d", str2, &bonus);
//printf("%s %d\n", str2, bonus);
//
//
//return 0;