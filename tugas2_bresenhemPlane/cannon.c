#include <stdlib.h>
#include <stdio.h>
#include "line.c"

int cannonX;
int cannonY;
int destProjectile;

void buildHalfCannon(Point P, color C) {
	drawCircleHalf(30, P, 10, C);
	printSquare(12, P.x, P.y - 34, C);
} 

void buildCannon(int x, int y, color c) {
	cannonX = x;
	cannonY = y;
	destProjectile = 0;
	
	Point P1;
	P1.x = x-12;
	P1.y = y;
	Point P2;
	P2.x = x+10;
	P2.y = y;
	Point P3;
	P3.x = x;
	P3.y = y;
	Point P4;
	P4.x = x;
	P4.y = y-8;
	
	drawBresenhamLine(P1, P2, c, 6);
	drawBresenhamLine(P3, P4, c, 4);
}

void shootCannon(int x, int y, color c) {
	color black;
	black.R = 0;
	black.G = 0;
	black.B = 0;
	Point P1;
	P1.x = x;
	P1.y = y;
	Point P2;
	P2.x = x;
	P2.y = y - 8;
	
	while ((P1.y > 0) && (destProjectile == 0)) {
		drawBresenhamLine(P1, P2, c, 7);
		usleep(1000);
		drawBresenhamLine(P1, P2, black, 7);
		P1.y -= 4;
		P2.y -= 4;
	}
}
