#include<stdio.h>  //������Լ�, ���ϰ��� �Լ��� ����ϱ� ���� ��� ���� ����(printf, scanf_s, typedef, if, else if, else, for, sprint_s ��)  
#include<stdlib.h> //��ġ��ȯ�Լ��� ����ϱ� ���� ��� ���� ����(atoi) 

typedef struct student { //student ����ü ����
	char name[50]; //�̸�
	char major[50]; //�а�
	char idno[50]; //�ֹε�Ϲ�ȣ
	char* yearhead; //���� �� 2�ڸ�
	char* nation; //�������(���ѹα�, �ܱ�)
	char* gender; //����(����, ����) 
	char* yuncheck; //����üũ 
	char buffer[256]; //�⵵ 4�ڸ� ���ڿ� (�ֹε�Ϲ�ȣ �� 7��° ���ڿ� �� 1,2��° ���ڸ� �����Ͽ� ����)
	int year; //�⵵ 4�ڸ� ������
}std;  //student ����ü�� �����ϰ�, ���ο� �̸� std�� ����

void main() { //main �Լ�
	int i = 0, j = 0; //������ i, j ���� 
	std member[3], *ptr[3], temp; //����ü std���� �迭 ����
		
	for (i = 0, i < 3; i++;) ptr[i] = &member[i]; //����ü�� ����Ű�� ������ �ʱ�ȭ

	printf("3���� �л� ������ �Է��Ͻÿ�. \n"); //��¹� 1��° ����

	for (i = 0; i < 3; i++) { //�ݺ����� ����Ͽ� 3���� ������ �Է¹���
		printf("---------------------------------------- \n"); //�ݺ����� ������ ���

		/*ù��° ���� �Է�*/
		printf("�̸� : "); 
		scanf_s("%s", &member[i].name, 20);

		/*�ι�° ���� �Է�*/
		printf("�а� : ");
		scanf_s("%s", &member[i].major, 20);
		
		/*����° ���� �Է�*/
		printf("�ֹε�Ϲ�ȣ : ");
		scanf_s("%s", &member[i].idno, 20);

		/*�ֹε�Ϲ�ȣ �� 7��° �ڸ��� 1�ΰ��, 1900��� ����� ���ѹα� ���ڷ� �Ǵ��Ͽ� ������ ���� */
		if (member[i].idno[6] == '1') {
			member[i].yearhead = "19";
			member[i].nation = "���ѹα�";
			member[i].gender = "����";
		}
		/*�ֹε�Ϲ�ȣ �� 7��° �ڸ��� 2�ΰ��, 1900��� ����� ���ѹα� ���ڷ� �Ǵ��Ͽ� ������ ���� */
		else if (member[i].idno[6] == '2') {
			member[i].yearhead = "19";
			member[i].nation = "���ѹα�";
			member[i].gender = "����";
		}
		/*�ֹε�Ϲ�ȣ �� 7��° �ڸ��� 3�ΰ��, 2000��� ����� ���ѹα� ���ڷ� �Ǵ��Ͽ� ������ ���� */
		else if (member[i].idno[6] == '3') {
			member[i].yearhead = "20";
			member[i].nation = "���ѹα�";
			member[i].gender = "����";
		}
		/*�ֹε�Ϲ�ȣ �� 7��° �ڸ��� 4�ΰ��, 2000��� ����� ���ѹα� ���ڷ� �Ǵ��Ͽ� ������ ���� */
		else if (member[i].idno[6] == '4') {
			member[i].yearhead = "20";
			member[i].nation = "���ѹα�";
			member[i].gender = "����";
		}
		/*�ֹε�Ϲ�ȣ �� 7��° �ڸ��� 5�ΰ��, 1900��� ����� �ܱ� ���ڷ� �Ǵ��Ͽ� ������ ���� */
		else if (member[i].idno[6] == '5') {
			member[i].yearhead = "19";
			member[i].nation = "�ܱ�";
			member[i].gender = "����";
		}
		/*�ֹε�Ϲ�ȣ �� 7��° �ڸ��� 6�ΰ��, 1900��� ����� �ܱ� ���ڷ� �Ǵ��Ͽ� ������ ���� */
		else if (member[i].idno[6] == '6') {
			member[i].yearhead = "19";
			member[i].nation = "�ܱ�";
			member[i].gender = "����";
		}
		/*�ֹε�Ϲ�ȣ �� 7��° �ڸ��� 7�ΰ��, 2000��� ����� �ܱ� ���ڷ� �Ǵ��Ͽ� ������ ���� */
		else if (member[i].idno[6] == '7') {
			member[i].yearhead = "20";
			member[i].nation = "�ܱ�";
			member[i].gender = "����";
		}
		/*�ֹε�Ϲ�ȣ �� 7��° �ڸ��� 8�ΰ��, 2000��� ����� �ܱ� ���ڷ� �Ǵ��Ͽ� ������ ���� */
		else if (member[i].idno[6] == '8') {
			member[i].yearhead = "20";
			member[i].nation = "�ܱ�";
			member[i].gender = "����";
		}
		/*�ֹε�Ϲ�ȣ �� 7��° �ڸ��� 9�ΰ��, 1800��� ����� ���ѹα� ���ڷ� �Ǵ��Ͽ� ������ ���� */
		else if (member[i].idno[6] == '9') {
			member[i].yearhead = "18";
			member[i].nation = "���ѹα�";
			member[i].gender = "����";
		}
		/*�ֹε�Ϲ�ȣ �� 7��° �ڸ��� 0�ΰ��, 1800��� ����� ���ѹα� ���ڷ� �Ǵ��Ͽ� ������ ���� */
		else if (member[i].idno[6] == '0') {
			member[i].yearhead = "18";
			member[i].nation = "���ѹα�";
			member[i].gender = "����";
		}
		/*���� ������ �ϳ��� ���� ��� ����*/
		else ("�������� �ʴ� ���Դϴ�");

		/*�⵵ 4�ڸ��� �����Ͽ� buffer ���ڿ��� ����*/
		sprintf_s(member[i].buffer, sizeof(member[i].buffer), "%s%c%c", member[i].yearhead, member[i].idno[0], member[i].idno[1]); 

		/*buffer ���ڿ��� �������·� ��ȯ*/
		member[i].year = atoi(member[i].buffer);

		/*�������·� ��ȯ�� �⵵ 4�ڸ��� ���⿩�� üũ�Ͽ� ���⿩�θ� ������ ����*/
		if ((member[i].year % 4 == 0 && member[i].year % 100 != 0) || member[i].year % 400 == 0) { member[i].yuncheck = "����"; }
		else { member[i].yuncheck = "����ƴ�"; }

		/*�̸�, �������, ���� ����, �������(���ѹα�, �ܱ�), ����(����, ����), �а��̸� ���*/
		printf("%s, %s%c%c�� %c%c�� %c%c��, %s, %s, %s, %s \n",
			member[i].name, member[i].yearhead, member[i].idno[0], member[i].idno[1], member[i].idno[2],
			member[i].idno[3], member[i].idno[4], member[i].idno[5], member[i].yuncheck, member[i].nation,
			member[i].gender, member[i].major);
	}

	/*������ �� ����('�Է� ���� 3���� ������ ������� �������� ������������ ���') ��� */
	printf("========================================\n");
	printf("�Է� ���� 3���� ������ ������� �������� ������������ ��� \n");
	printf("---------------------------------------- \n");

	/*�Է� ���� 3���� ������ ������� �������� �������� ����*/
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < i; j++) {
			if (member[i].year < member[j].year) {
				temp = member[i];
				member[i] = member[j];
				member[j] = temp;
			}
		}
	}
	/*������� �������� �������� ���ĵ� 3���� ������ ���*/
	for (i = 0; i < 3; i++){
		printf("%s, %s%c%c�� %c%c�� %c%c��, %s, %s, %s, %s \n",
			member[i].name, member[i].yearhead, member[i].idno[0], member[i].idno[1], member[i].idno[2],
			member[i].idno[3], member[i].idno[4], member[i].idno[5], member[i].yuncheck, member[i].nation, 
			member[i].gender, member[i].major);
		}

	/*�ϴ� �ٹٲ� �� ������ ���*/
	printf(" \n");
	printf("---------------------------------------- \n");
}
