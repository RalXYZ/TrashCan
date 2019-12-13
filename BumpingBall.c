#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

int main () {
    int numberOfRow = 10, numberOfColumn = 20;
    int currentRow = 2, currentColumn = 7;
    int judgeRow = 1, judgeColumn = 1;
    int time = 0;

    char core[200][200] = {0};
    char screen[404][202] = {0};
    for (int i = 0; i < numberOfRow; i++)
        for (int j = 0; j < numberOfColumn; j++)
            core[i][j] = ' ';

    printf("Please type in the row number: ");
    scanf("%d", &currentRow);
    printf("Please type in the column number: ");
    scanf("%d", &currentColumn);
    system("cls");

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
        core[currentRow +=judgeRow][currentColumn += judgeColumn] = '*';

        for (int i = 0; i < numberOfRow + 2; i++) {
            if (i == 0 || i == numberOfRow + 1 ) {
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
