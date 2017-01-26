#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int x;
	int y;
} Point;

void swap (int *a, int *b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
void swapPoint (Point *P1, Point *P2) {
	swap(&P1->x, &P2->x);
	swap(&P1->y, &P2->y);
}

void plotSlopPositiveLine (Point P1, Point P2) {
	int dX, dY, p;
	int i, j, x;

	dX = abs(P2.x - P1.x);
	dY = abs(P2.y - P1.y);
	i = P1.x;
	j = P1.y;
	p = 2*dY - dX;

	for (x=P1.x; x<=P2.x; x++) {
		if (p >= 0) {
			p += 2* (dY - dX);
			i++;
			j++;
		}
		else {
			p += 2*dY;
			i++;
		}
	}
}

void plotSlopNegativeLine (Point P1, Point P2) {
	int dX, dY, p;
	int i, j, x;

	dX = abs(P2.x - P1.x);
	dY = abs(P2.y - P1.y);
	i = P1.x;
	j = P1.y;
	p = 2*dY - dX;

	for (x=P1.x; x<=P2.x; x++) {
		if (p >= 0) {
			p += 2* (dY - dX);
			i++;
			j--;
		}
		else {
			p += 2*dY;
			i++;
		}
	}
}

void plotVerticalLine (Point P1, Point P2) {
	int j;
	for(j = P1.y ; j <= P2.y; j++){
        printf("%d %d\n", P1.x , j);
	}
}

void drawBresenhamLine (Point P1, Point P2) {
	if (P1.x > P2.x) {
		swapPoint(&P1,&P2);
	}
	printf("%d %d\n", P1.x, P1.y);
	printf("%d %d\n", P2.x, P2.y);
	if ((P2.x >= P1.x && P1.y > P2.y)) {
		plotSlopNegativeLine(P1,P2);
	}
	else if (P1.x == P2.x) {
		plotVerticalLine(P1,P2);;
	}
	else {
		plotSlopPositiveLine(P1,P2);
	}
}

int main() {
	Point P1, P2;
	P1.x = 2;
	P1.y = 2;

	P2.x = 2;
	P2.y = 5;

	drawBresenhamLine(P1, P2);
}