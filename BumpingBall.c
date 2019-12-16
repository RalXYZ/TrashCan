#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#define LENGTH 100
#define WAIT 50

int main() {
	/*用户输入*/
	//TODO 用户自定义地形
	int numberOfRow, numberOfColumn;
	printf("Please type in the number of row (<%d): ", LENGTH);
	scanf("%d", &numberOfRow);
	printf("Please type in the number of column (<%d): ", LENGTH);
	scanf("%d", &numberOfColumn);
	system("cls");

	/*一些必要的初始化*/
	srand((unsigned)time(NULL));
	int currentRow = rand() % numberOfRow + 1, currentColumn = rand() % numberOfColumn + 1; //在这里+1是因为棋盘中0号元素必为'#'
	int vectorRow = pow(-1, rand() % 2), vectorColumn = pow(-1, rand() % 2);
	int time = 0;
	char core[LENGTH + 2][LENGTH + 2] = { 0 };
	char screen[2 * (LENGTH + 2) + 1][2 * (LENGTH + 2) + 1] = { 0 };

	/*棋盘预处理*/
	for (int i = 0; i < numberOfRow + 2; i++) {
		if (i == 0 || i == numberOfRow + 1) //在首行和末行全置入'#'
			for (int j = 0; j < numberOfColumn + 2; j++)
				core[i][j] = '#';
		else //在其它行的开始与末尾置入'#'
			for (int j = 0; j < numberOfColumn + 2; j++)
				if (j == 0 || j == numberOfColumn + 1)
					core[i][j] = '#';
				else
					core[i][j] = ' ';
	}
		
	/*小球的每一次移动即为下面的每一次循环*/
	while (true) {
		/*小球换向*/
		if (core[currentRow + vectorRow][currentColumn] == '#')
			vectorRow = -vectorRow;
		if (core[currentRow][currentColumn + vectorColumn] == '#')
			vectorColumn = -vectorColumn;
		if (core[currentRow + vectorRow][currentColumn] != '#' 
			&& core[currentRow][currentColumn + vectorColumn] != '#' 
			&& core[currentRow + vectorRow][currentColumn + vectorColumn] == '#') {
			vectorRow = -vectorRow;
			vectorColumn = -vectorColumn;
		}

		/*小球移位并清除上一个位置的输出*/
		core[currentRow][currentColumn] = ' ';
		core[currentRow += vectorRow][currentColumn += vectorColumn] = '*';

		/*将要输出的数据统一放至screen[][]*/
		for (int i = 0; i < numberOfRow + 2; i++) {
			for (int j = 0; j < numberOfColumn + 2; j++) {
				screen[i][2 * j] = core[i][j];
				screen[i][2 * j + 1] = ' '; //注意，为了输出美观，考虑到字符所占像素，故在每一个元素后加一个空格
			}
			screen[i][2 * (numberOfColumn + 1) + 1] = '\n';
		}

		/*统一输出*/
		for (int i = 0; i < numberOfRow + 2; i++)
			printf("%s", screen[i]);
		printf("time: %d\n", time);

		/*计数，暂停与清屏*/
		time++;
		Sleep(WAIT);
		system("cls");
	}
	return 0;
}
