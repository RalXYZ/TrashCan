#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <easyx.h>

#define WIDTH 512
#define MAP 64
#define PIXEL WIDTH/MAP

int color[] = { 0x311B92, 0x4527A0, 0x512DA8, 0x5E35B1, 0x673AB7, 0x7E57C2, 0x9575CD, 0xB39DDB, 0xD1C4E9, 0xEDE7F6 };
int map[MAP][MAP] = { 0 };

void print();

int main() {
	/*graphic init*/
	initgraph(WIDTH, WIDTH);
	setbkcolor(BGR(color[0]));
	clearrectangle(0, 0, WIDTH, WIDTH);

	/*random*/
	srand((unsigned)time(NULL));
	for (int i = 0; ; i++) { //an endless loop
		int x = rand() % MAP;
		int y = rand() % MAP;
		if (map[x][y] < 9) 
			map[x][y]++;
		if (i % 10 == 0) //improve display speed
			print();
	}
	//return 0;
}

void print() {
	for (int i = 0; i < MAP; i++)
		for (int j = 0; j < MAP; j++) {
			setfillcolor(BGR(color[map[i][j]]));
			solidrectangle(i * PIXEL, j * PIXEL, i * PIXEL + PIXEL, j * PIXEL + PIXEL);
		}
}
