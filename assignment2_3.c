#include <stdio.h> //�������� ����ó����
#pragma warning(disable:4996) //scanf ���� �޽����� �����ϱ� ���� ��ɾ�
struct entry { //entry�� ����ü ����
	char fname[20]; //����ü ��� fname�� ������ �迭�� �����ϰ� �迭�� ũ�⸦ 20���� ����  
	char lname[20]; //����ü ��� lname�� ������ �迭�� �����ϰ� �迭�� ũ�⸦ 20���� ����  
	char phone[10]; //����ü ��� phone�� ������ �迭�� �����ϰ� �迭�� ũ�⸦ 10���� ����  
};
struct entry list[4]; //����ü �迭 list[]�� �����ϰ� �迭�� ũ�⸦ 4�� ����
int i; // ���� i�� ���������� ����

void main() { //main()�Լ��� ����
	for (i = 0; i < 4; i++) { //i ���� 4���� Ŀ���� ���ǽ��� ������ �Ǿ� ������ �������� 
		printf("Enter first name : ");  // Enter first name : �� ����Ѵ�.
		scanf("%s", list[i].fname); //����ü �迭 list[]�� ��� fname�� ���ڿ��� �Է¹޾� �����Ѵ�. 
		printf("Enter last name : "); // Enter last name : �� ����Ѵ�.
		scanf("%s", list[i].lname); //����ü �迭 list[]�� ��� lname�� ���ڿ��� �Է¹޾� �����Ѵ�. 
		printf("Enter phone number : "); // Enter phone number : �� ����Ѵ�.
		scanf("%s", list[i].phone); // ����ü �迭 list[]�� ��� phnoe�� ���ڿ��� �Է¹޾� �����Ѵ�. 
		printf("\n"); // ���⸦ ����Ѵ�. 
	}
	printf("\n"); // ���⸦ ����Ѵ�. 
	for (i = 0; i < 4; i++) { //i ���� 4���� Ŀ���� ���ǽ��� ������ �Ǿ� ������ �������� 
		printf("Name : %s %s", list[i].fname, list[i].lname); //Name : %s %s �� ����Ѵ�. �̶�, %s %s���� ���� ����ü �迭 list[]�� ��� fname, lname�� ����Ѵ�. 
		printf("\t\tPhone : %s \n", list[i].phone); // (tab)(tab) Phone : %s (����) �� ����Ѵ�. �̶� %s���� ����ü �迭 list[]�� ��� phone�� ����Ѵ�. 
	}
}

