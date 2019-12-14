#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

int main() {
	/*用户输入*/
	int numberOfRow, numberOfColumn;
	printf("Please type in the number of row (<100): ");
	scanf("%d", &numberOfRow);
	printf("Please type in the number of column (<100): ");
	scanf("%d", &numberOfColumn);
	system("cls");

	/*一些必要的初始化*/
	srand((unsigned)time(NULL));
	int currentRow = rand() % numberOfRow, currentColumn = rand() % numberOfColumn;
	int judgeRow = 1, judgeColumn = 1;
	int time = 0;
	char core[100][100] = { 0 };
	char screen[104][102] = { 0 };
	for (int i = 0; i < numberOfRow; i++)
		for (int j = 0; j < numberOfColumn; j++)
			core[i][j] = ' ';

	/*小球的每一次移动即为下面的一次循环*/
	while (true) {
		/*小球换向*/
		if (currentRow == numberOfRow - 1)
			judgeRow = -1;
		else if (currentRow == 0)
			judgeRow = 1;
		if (currentColumn == numberOfColumn - 1)
			judgeColumn = -1;
		else if (currentColumn == 0)
			judgeColumn = 1;

		/*小球移位并清除上一个位置的输出*/
		core[currentRow][currentColumn] = ' ';
		core[currentRow += judgeRow][currentColumn += judgeColumn] = '*';

		/*将要输出的数据统一放至screen[][]*/
		for (int i = 0; i < numberOfRow + 2; i++) {
			/*存入首行和末行的边框，其他情况下存入首列和末列的边框以及棋盘*/
			/*注意，为了输出美观，考虑到一个字符所占像素，故在core的每一个元素后加一个空格*/
			if (i == 0 || i == numberOfRow + 1) {
				for (int j = 0; j < numberOfColumn + 2; j++) {
					screen[i][2 * j] = '*';
					screen[i][2 * j + 1] = ' ';
				}
				screen[i][2 * (numberOfColumn + 1) + 1] = '\n';
				continue;
			}
			else {
				screen[i][0] = '*';
				screen[i][1] = ' ';
				for (int j = 1; j < numberOfColumn + 2; j++) {
					screen[i][2 * j] = core[i - 1][j - 1];
					screen[i][2 * j + 1] = ' ';
				}
				screen[i][2 * (numberOfColumn + 1)] = '*';
				screen[i][2 * (numberOfColumn + 1) + 1] = '\n';
			}
		}

		/*统一输出*/
		for (int i = 0; i < numberOfRow + 2; i++)
			printf("%s", screen[i]);
		printf("time: %d\n", time);

		/*计数，暂停与清屏*/
		time++;
		Sleep(70);
		system("cls");
	}
	return 0;
}
