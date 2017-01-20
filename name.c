#include "alphabets.c"
#define distance 50

void nameFahri (int x, int y, color c) {
	printF(x, y, c);
	printA(x+distance, y, c);
	printH(x+2*distance, y, c);
	printR(x+3*distance, y, c);
	printI(x+4*distance, y, c);
}

void nameSeptialoka (int x, int y, color c) {
	printS(x, y, c);
	printE(x+distance, y, c);
	printP(x+2*distance, y, c);
	printT(x+3*distance, y, c);
	printI(x+4*distance, y, c);
	printA(x+4*distance+20, y, c);
	printL(x+5*distance+20, y, c);
	printO(x+6*distance+20, y, c);
	printK(x+7*distance+20, y, c);
	printA(x+8*distance+20, y, c);
}

void nameGumi (int x, int y, color c) {
	printG(x, y, c);
	printU(x+distance, y, c);
	printM(x+2*distance, y, c);
	printI(x+3*distance+10, y, c);
}