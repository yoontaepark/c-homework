#include<stdio.h>

int main()
{
	unsigned int decimal = 4294967295; //10����
	unsigned int binary = 0b11111111111111111111111111111111; //2���� ǥ���� ���� 0b 
	unsigned int oct = 037777777777; // 0�� ���̸� 8������ 
	unsigned int hex = 0xffffffff; // 0x�� ���̸� 16������ , ã�� ��� 4294967295 to hex �̷������� ���۸��ϸ� ��ȯ�� �� �˻� ����

	/*10���� %u�� ����ϹǷ� �Ʒ� 4�� ���� ���� ���� */
	printf("%u\n", decimal);
	printf("%u\n", binary);
	printf("%u\n", oct);
	printf("%u\n", hex);
	
	printf("%o %x %#o %#x %#X", decimal, decimal, decimal, decimal, decimal);
	//8����, 16����, #�� �־��ָ� ��Ȯ�� 0�� �־ �������, 
	
	char c = 65;
	short s = 200;
	unsigned int ui = 3000000000U; //U�� �����ص� �˾Ƽ� �ν����� 
	long l = 65537L;
	long long ll = 12345678908642LL; // LL�� �����ص� �˾Ƽ� �ν����� 

	printf("char = %hhd, %d, %c\n", c, c, c);
	printf("short = %hhd, %hd, %d\n", s, s, s);
	printf("unsigned int = %u, %d\n", ui, ui);
	printf("long = %ld, %hd\n", l,l);
	printf("long long = %lld, %ld\n", ll,ll);
	
	return 0;
}

//�׳� ������ �� ���缭 ����� �����÷ο찡 �ȳ��� ������ �������� 