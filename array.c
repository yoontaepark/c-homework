#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// 10原軒税 辞稽 陥献 疑弘 (唖 朝球 2舌梢)
// 紫遂切稽採斗 2鯵税 脊径葵聖 閤焼辞 -> 旭精 疑弘 達生檎 朝球 及増奄
// 乞窮 疑弘 瞬聖 達生檎 惟績 曽戟
// 恥 叔鳶 判呪 硝形爽奄

int arrayAnimal[4][5]; //朝球 走亀(20舌税 朝球)
int checkAnimal[4][5]; //朝球亜 及増縛澗走 溌昔
char* strAnimal[10];

void initAnimalArray();
void initAnimalname();
void shuffleAnimal();
int getEmptyPostition();
int conv_pos_x(int x);
int conv_pos_y(int y);

void printAnimals();
void printQuestion();

int main()
{	
	srand(time(NULL));

	initAnimalArray();
	initAnimalname();

	shuffleAnimal();

	int failCount = 0; //叔鳶 判呪

	while (1)
	{
		int select1 = 0; // 紫遂切亜 識澱廃 坦製 呪 
		int select2 = 0; // 紫遂切亜 識澱廃 砧腰属 呪

		printAnimals(); // 疑弘 是帖 窒径
		printQuestion();// 庚薦 窒径(朝球 走亀)
		printf("\n及増聖 朝球研 2鯵 壱牽室推: ");
		scanf("%d %d", &select1, &select2);

		if (select1 == select2) //旭精 朝球 識澱 獣 巷反
			continue;

		//疎妊拭 背雁馬澗 朝球研 及増嬢 左壱 旭精走 照旭精走 溌昔
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);


		//朝球亜 及増備走 省紹壱 & 旭精 疑弘昔 井酔亜 舛岩聖 限茶 
		if ((checkAnimal[firstSelect_x][firstSelect_y] == 0 
			&& checkAnimal[secondSelect_x][secondSelect_y] == 0)

			&&

			(arrayAnimal[firstSelect_x][firstSelect_y]			//旭精 疑弘昔 井酔 
			== arrayAnimal[secondSelect_x][secondSelect_y])
			)
		{
			printf("\n\n桜壱! : %s 降胃\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1; //限秩蕉級精 1稽 痕井獣佃捜(及増嬢然陥)
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}
		else //陥献 疑弘昔 井酔
		{
			printf("強!! (堂携暗蟹, 戚耕 及増微 朝球脊艦陥) \n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failCount++;
		}

		//乞窮 疑弘聖 達紹澗走 食採, 凧戚檎 1, 焼艦檎 0
		if (foundAllAnimals() == 1)
		{
			printf("\n\n 逐馬杯艦陥!. 乞窮 疑弘聖 陥 達紹革推 \n");
			printf("走榎猿走 恥 %d腰 叔呪馬心柔艦陥\n", failCount);
			break; //戚 庚姥稽 纏窒
		}
	}

	return 0;
}



//段奄葵 室特
void initAnimalArray()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arrayAnimal[i][j] = -1; //-1稽 析舘 段奄鉢敗 
		}
	}
}

//疑弘 識情 
void initAnimalname()
{
	strAnimal[0] = "据周戚";
	strAnimal[1] = "馬原";
	strAnimal[2] = "悪焼走";
	strAnimal[3] = "壱丞戚";
	strAnimal[4] = "掬走";

	strAnimal[5] = "坪晦軒";
	strAnimal[6] = "奄鍵";
	strAnimal[7] = "開展";
	strAnimal[8] = "展繕";
	strAnimal[9] = "硲櫛戚";
}


//偲巴背辞 x,y拭 唖 疑弘葵聖 隔奄 
void shuffleAnimal()
{
	// けけけけけ
	// けけけけけ
	// けけけけけ
	// けけけけけ


	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int pos = getEmptyPostition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);

			arrayAnimal[x][y] = i;
		}
	}
}

//疎妊拭辞 朔因娃 達奄
int getEmptyPostition()
{
	// けけけけけ	 0  1  2  3  4  -> 5稽 蟹刊檎 00000
	// けけけけけ	 5  6  7  8  9               11111
	// けけけけけ	10 11 12 13 14				 22222
	// けけけけけ	15 16 17 18 19				 33333


	while (1) //域紗 鋼差
	{
		int randPos = rand() % 20; //0~19紫戚税 収切 鋼発 
		//19 -> (3,4)
		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);

		if (arrayAnimal[x][y] == -1) //朔因娃戚 蟹神檎(段奄葵戚 蟹神檎) 陥獣 敗呪研 宜形虞
		{
			return randPos;
		}
	}
	return 0;
}

int conv_pos_x(int x)
{
	//19 -> (3,4)
	return x / 5; //5稽 蟹勧 交
};

int conv_pos_y(int y)
{
	return y % 5; //5稽 蟹勧 蟹袴走
}


void printAnimals() //疑弘 是帖 窒径(舛岩遂)
{
	// けけけけけ	 0  1  2  3  4  
	// けけけけけ	 5  6  7  8  9              
	// けけけけけ	10 11 12 13 14           
	// けけけけけ	15 16 17 18 19
	printf("\n==========搾腔昔汽, 侯掘 左食捜 =======\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%8s", strAnimal[arrayAnimal[i][j]]); 
		}
		printf("\n");
	}
	printf("\n==========================\n\n");
}


void printQuestion()
{
	printf("\n\n(庚薦)\n");
	int seq = 0; //牒級聖 収切稽 呪帖鉢馬奄 是背 畷税雌 竺舛敗

					//seq				 //checkAnimal
// けけけけけ	 0  1  2  3  4            00010
// けけけけけ	 5  6  7  8  9            10000  
// けけけけけ	10 11 12 13 14            00000
// けけけけけ	15 16 17 18 19			  00000

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//朝球研 及増嬢辞 舛岩聖 限宙生檎 '疑弘 戚硯' 
			if (checkAnimal[i][j] != 0)
			{
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}
			//焼送 及増走 公梅生檎 (舛岩聖 限蓄走 公梅生檎) 急檎 -> 是帖研 蟹展鎧澗 収切
			else
			{
				printf("%8d", seq);
			}
			seq++;
		}
		printf("\n");
	}
}

int foundAllAnimals()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkAnimal[i][j] == 0)
				return 0; //焼送 公達製 
		}
	}
	return 1; //乞砧 陥 達製
}




//陥託据 壕伸 妊薄馬澗 号狛
//
//int arr[5];
//けけけけけ
//[0][1][2][3][4]
//
//int arr2[2][5]; //楳x伸戚虞壱 持唖馬檎 畷拝牛 
//けけけけけ
//けけけけけ
//[0,0][0,1][0,2][0,3][0,4]  -> arr2[0][0] 戚係惟 妊薄馬檎 喫  
//[1,0][1,1][1,2][1,3][1,4]

//識情精 嬢胸惟? 
//int arr2[2][5] = {{1,2,3,4,5}, {1,2,3,4,5}} 
//
//int arr2[2][5] = {
//	{1,2,3,4,5},
//	{1,2,3,4,5}
//}
//戚訓縦生稽 1楳, 2楳 授辞企稽 貸 蟹伸聖 獣佃爽檎 吉陥. 


//陥託据 壕伸 羨悦馬澗 号狛
//int arr4[3][3][3] = {
//	{
//	{1,2,3},
//	{4,5,6},
//	{7,8,9}
//	},
//	{
//	{11,12,13},
//	{14,15,16},
//	{17,18,19}
//	},
//	{
//	{21,22,23},
//	{24,25,26},
//	{27,28,29}
//	}
//};
//
//for (int i = 0; i < 3; i++)
//{
//	for (int j = 0; j < 3; j++)
//	{
//		for (int k = 0; k < 3; k++)
//		{
//			printf("3託据壕伸(%d %d %d)税 葵: %d\n", i, j, k, arr4[i][j][k]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}