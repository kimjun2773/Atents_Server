#include "Util.h"

void gotoXY(int x, int y){
	COORD pos = { y * 2, x };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}