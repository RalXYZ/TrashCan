#include <iostream>
#include <windows.h>
#include <stdlib.h>
#define R 10
#define C 20
using namespace std;

char core[R][C+1]={0};
int r=2, c=7;
int rJudge=1, cJudge=1;
int time = 0;

int main () {
	for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            core[i][j] = ' ';
            
	printf("Please type in the row number: ");
	scanf("%d", &r);
	printf("Please type in the column number: ");
	scanf("%d", &c);
	system("cls");
    
    while (1) {
        if (r == R-1)
            rJudge = -1;
        else if (r == 0)
            rJudge = 1;
        if (c == C-1)
            cJudge = -1;
        else if (c == 0)
            cJudge = 1;
        core[r][c] = ' ';
        core[r+=rJudge][c+=cJudge] = '*';
        
        printf("**********************\n");
        for (int i=0; i<R; i++) {
        	cout<<'*'<<core[i]<<'*'<<'\n';
		}
        printf("**********************\n\ntimes: %d", time);       
        
        time++;
        Sleep(70);
        system("cls");
    }
    
    return 0;
}
