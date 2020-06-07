#include<stdio.h>
#include<float.h>

int main()
{
	//round-off errors_1(사실 반올림에러는 아니지만 숫자 범위차이에 따른 에러가 남)
	float a, b;
	a = 1000.0f + 1.0f;
	b = a - 1000.0f; 
	printf("%f\n", b);  //숫자가 별로 안크면 에러가 안남
 
	float x, y;
	x = 1.0E20f + 1.0f;
	y = x - 1.0E20f;  
	printf("%f\n", y);  //숫자가 너무크면 1.0f를 못잡고 0.0으로 출력이 되어버림


	//round-off errors_2(0.01이 정확히 0.01이 아니고 0.09999976 이런애여서 계산에러가 날 수 있음) 
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

	printf("%f\n", z); //정확히 1이 안나옴(0.01f가 정확히 0.01이 아니라서 그럼) 
	
	
	printf("%u\n", sizeof(float));
	printf("%u\n", sizeof(double));
	printf("%u\n", sizeof(long double));

	float f = 123.456f; //float 형은 맨끝에 f를 붙여주는게 좋음
	double d = 123.456; //double 형은 안붙여줘도 됨 

	float f2 = 123.456f;  // f를 안쓰면 double이 메모리를 2배쓰는데, 8byte 짜리를 4byte에 쑤셔넣으려니 warning이 뜸 'initializing': truncation from 'double' to 'float' 
	double d2 = 123.456f; //float이 메모리가 더 적기때문에 이경우에는 큰 곳에 값을 넣으니 에러가 안뜸

	int i = 3;
	float f3 = 3.f; //3.0f 으로 소수점 표시 .을 넣어주는게 좋음(실수형이니까) 
	double d3 = 3.; //3.0 으로 꼬박꼬박 적어두는게 좋다 
	
	float f4 = 1.234e10f; //e나 E 무관하게 넣어라

	float f5 = 0xb.aP1; //0x: 16진수, e대신에 p를 넣어둔것임(바꿔도 상관없음)
	double d5 = 1.0625e0;

	printf("%f %F %e %E\n", f, f, f, f);
	printf("%f %F %e %E\n", d, d, d, d);
	printf("%a %A\n", f5, f5);  //%a는 16진수로 출력하기 
	printf("%a %A\n", d5, d5);

	return 0;
}