#include "alphabets.c"
#define distance 50

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

void nameFahri (int x, int y, color c) {
	printF(x, y, c);
	printA(x+distance, y, c);
	printH(x+2*distance, y, c);
	printR(x+3*distance, y, c);
	printI(x+4*distance, y, c);
}

void nameMalvin (int x, int y, color c) {
	printM(x, y, c);
	printA(x+distance+20, y, c);
	printL(x+2*distance+20, y, c);
	printV(x+3*distance+20, y, c);
	printI(x+4*distance+40, y, c);
	printN(x+4*distance+60, y, c);
}

void nameJoshua (int x, int y, color c) {
	printJ(x, y, c);
	printO(x+distance, y, c);
	printS(x+2*distance, y, c);
	printH(x+3*distance, y, c);
	printU(x+4*distance, y, c);
	printA(x+5*distance, y, c);
}

void nameRaihan (int x, int y, color c) {
	printR(x, y, c);
	printA(x+distance, y, c);
	printI(x+2*distance, y, c);
	printH(x+2*distance+20, y, c);
	printA(x+3*distance+20, y, c);
	printN(x+4*distance+20, y, c);
}

void nameRaja (int x, int y, color c) {
	printR(x, y, c);
	printA(x+distance, y, c);
	printJ(x+2*distance, y, c);
	printA(x+3*distance, y, c);
}
