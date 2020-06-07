// #define _CRT_SECURE_NO_WARNINGS //define으로 에러메시지 자체를 잡는다
// 아니면 프로젝트> 오른쪽클릭> 속성> preprocessor > 에서 _CRT_SECURE_NO_WARNINGS; 이렇게 추가하면 된다

#include<stdio.h>

int main() 
{
	float won = 0.0f; //여기에도 실수형이니까 0.0f로 
	float dollar = 0.0f;

	printf("Input won\n");
	scanf("%f", &won);

	dollar = won * 0.00089f; //실수형이라서 곱할때도 f를 붙여주면 데이터 손실이 안남

	printf("Dollar = %f\n", dollar);

	printf("=========================================\n");


	int i = 0, j = 0; //변수는 무조건 초기화 하는걸 권장함(디버깅을 많이해보면 알게된다고 함) 
	int sum = 0; //변수들은 웬만하면 위에다 몰아서 정의하고+초기화도 시켜놓기 

	printf("Input two integers\n");

	scanf("%d%d", &i, &j); //& :ampersand , &가 붙는 이유는? 변수의 주소를 넘기는 개념임

	sum = i + j;  // 아래에 함수 수식을 구체적으로 적어놓는다

	printf("%d plus %d = %d\n", i, j, sum); //%랑 변수개수는 같아야 함  

	return 0;
}


// ctrl+shift+b 누르면 아래 에러메시지를 긁을 수 있다 
// 한편 위의 build 를 마우스로 누르면 error list 요렇게만뜸 