#include<stdio.h>
#include<float.h>

int main()
{
	//round-off errors_1(��� �ݿø������� �ƴ����� ���� �������̿� ���� ������ ��)
	float a, b;
	a = 1000.0f + 1.0f;
	b = a - 1000.0f; 
	printf("%f\n", b);  //���ڰ� ���� ��ũ�� ������ �ȳ�
 
	float x, y;
	x = 1.0E20f + 1.0f;
	y = x - 1.0E20f;  
	printf("%f\n", y);  //���ڰ� �ʹ�ũ�� 1.0f�� ����� 0.0���� ����� �Ǿ����


	//round-off errors_2(0.01�� ��Ȯ�� 0.01�� �ƴϰ� 0.09999976 �̷��ֿ��� ��꿡���� �� �� ����) 
	float z = 0.0f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;
	z = z + 0.01f;

	printf("%f\n", z); //��Ȯ�� 1�� �ȳ���(0.01f�� ��Ȯ�� 0.01�� �ƴ϶� �׷�) 
	
	
	printf("%u\n", sizeof(float));
	printf("%u\n", sizeof(double));
	printf("%u\n", sizeof(long double));

	float f = 123.456f; //float ���� �ǳ��� f�� �ٿ��ִ°� ����
	double d = 123.456; //double ���� �Ⱥٿ��൵ �� 

	float f2 = 123.456f;  // f�� �Ⱦ��� double�� �޸𸮸� 2�農�µ�, 8byte ¥���� 4byte�� ���ų������� warning�� �� 'initializing': truncation from 'double' to 'float' 
	double d2 = 123.456f; //float�� �޸𸮰� �� ���⶧���� �̰�쿡�� ū ���� ���� ������ ������ �ȶ�

	int i = 3;
	float f3 = 3.f; //3.0f ���� �Ҽ��� ǥ�� .�� �־��ִ°� ����(�Ǽ����̴ϱ�) 
	double d3 = 3.; //3.0 ���� ���ڲ��� ����δ°� ���� 
	
	float f4 = 1.234e10f; //e�� E �����ϰ� �־��

	float f5 = 0xb.aP1; //0x: 16����, e��ſ� p�� �־�а���(�ٲ㵵 �������)
	double d5 = 1.0625e0;

	printf("%f %F %e %E\n", f, f, f, f);
	printf("%f %F %e %E\n", d, d, d, d);
	printf("%a %A\n", f5, f5);  //%a�� 16������ ����ϱ� 
	printf("%a %A\n", d5, d5);

	return 0;
}