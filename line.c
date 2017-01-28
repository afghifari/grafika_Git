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
	int i, j, x, y;

	dX = abs(P2.x - P1.x);
	dY = abs(P2.y - P1.y);
	i = P1.x;
	j = P1.y;
	
	if (dX >= dY) {
		p = 2*dY - dX;
		printf("Based on X\n");
		for (x=P1.x; x<=P2.x; x++) {
			printf("%d %d\n", x, j);
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
	else {
		p = 2*dX - dY;
		printf("Based on Y\n");
		for (y=P1.y; y<=P2.y; y++) {
			printf("%d %d\n", i, y);
			if (p >= 0) {
				p += 2* (dX - dY);
				i++;
				j++;
			}
			else {
				p += 2*dX;
				j++;
			}
		}
	}
}

void plotSlopNegativeLine (Point P1, Point P2) {
	int dX, dY, p;
	int i, j, x, y;

	dX = abs(P2.x - P1.x);
	dY = abs(P2.y - P1.y);
	i = P1.x;
	j = P1.y;	

	if (dX >= dY) {
		p = 2*dY - dX;		
		printf("Based on X\n");
		for (x=P1.x; x<=P2.x; x++) {
			printf("%d %d\n", x, j);
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
	else {
		p = 2*dX - dY;
		printf("Based on Y\n");
		for (y=P2.y; y<=P1.y; y++) {
			printf("%d %d\n", i, y);
			if (p >= 0) {
				p += 2* (dX - dY);
				i++;
				j++;
			}
			else {
				p += 2*dX;
				j++;
			}
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
		printf("N Slope\n");
		plotSlopNegativeLine(P1,P2);
	}
	else if (P1.x == P2.x) {
		plotVerticalLine(P1,P2);;
	}
	else {
		printf("P Slope\n");
		plotSlopPositiveLine(P1,P2);
	}
}

int main() {
	Point P1, P2;
	printf("Input first point x & y position\n");
	scanf("%d %d", &P1.x, &P1.y);

	printf("Input second point x & y position\n");
	scanf("%d %d", &P2.x, &P2.y);

	drawBresenhamLine(P1, P2);
}
