#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

int main() {
	int numberOfRow, numberOfColumn;
	printf("Please type in the number of row (<100): ");
	scanf("%d", &numberOfRow);
	printf("Please type in the number of column (<100): ");
	scanf("%d", &numberOfColumn);
	system("cls");

	srand((unsigned)time(NULL));
	int currentRow = rand() % numberOfRow, currentColumn = rand() % numberOfColumn;
	int judgeRow = 1, judgeColumn = 1;
	int time = 0;

	char core[100][100] = { 0 };
	char screen[104][102] = { 0 };
	for (int i = 0; i < numberOfRow; i++)
		for (int j = 0; j < numberOfColumn; j++)
			core[i][j] = ' ';

	while (true) {
		if (currentRow == numberOfRow - 1)
			judgeRow = -1;
		else if (currentRow == 0)
			judgeRow = 1;
		if (currentColumn == numberOfColumn - 1)
			judgeColumn = -1;
		else if (currentColumn == 0)
			judgeColumn = 1;
		core[currentRow][currentColumn] = ' ';
		core[currentRow += judgeRow][currentColumn += judgeColumn] = '*';

		for (int i = 0; i < numberOfRow + 2; i++) {
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

		for (int i = 0; i < numberOfRow + 2; i++)
			printf("%s", screen[i]);
		printf("time: %d\n", time);

		time++;
		Sleep(70);
		system("cls");
	}
	return 0;
}
