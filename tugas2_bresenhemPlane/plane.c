#include <stdlib.h>
#include <stdio.h>
#include "cannon.c"

int planeX;
int planeY;

void buildPlaneToRight(int x, int y, color c) {
	//making list of points
	Point PointList[7];

	//assign global variables with the assigned parameters
	planeX = x;
	planeY = y;

	PointList[0].x = planeX;
	PointList[0].y = planeY;
	
	PointList[1].x = planeX - 70;
	planeX -= 70;
	PointList[1].y = planeY - 45;
	planeY -= 45;
	
	PointList[2].x = planeX - 190;
	planeX -= 190;
	PointList[2].y = planeY;
	
	PointList[3].x = planeX - 60;
	planeX -= 60;
	PointList[3].y = planeY - 35;
	planeY -= 35;
	
	PointList[4].x = planeX - 20;
	planeX -= 20;
	PointList[4].y = planeY;
	
	PointList[5].x = planeX + 50;
	PointList[5].y = planeY + 80;
	planeY += 80;
	
	drawPolygon(6, &PointList, c, 2);

	Point circle;
	circle.x = planeX + 260;
	circle.y = planeY + 3;
	drawCircle(12, circle, 2, c);

	planeX = x - 100;
	planeY = y - 25;

	PointList[0].x = planeX;
	PointList[0].y = planeY;

	PointList[1].x = planeX - 100;
	planeX -= 100;
	PointList[1].y = planeY;

	PointList[2].x = planeX - 100;
	planeX -= 100;
	PointList[2].y = planeY + 45;
	planeY += 45;

	PointList[3].x = planeX + 50;
	planeX += 50;
	PointList[3].y = planeY;

	drawPolygon(4, &PointList, c, 2);

	planeX = x - 100;
	planeY = y - 45;

	PointList[0].x = planeX;
	PointList[0].y = planeY;

	PointList[1].x = planeX - 100;
	planeX -= 100;
	PointList[1].y = planeY;

	PointList[2].x = planeX - 100;
	planeX -= 100;
	PointList[2].y = planeY - 45;
	planeY -= 45;

	PointList[3].x = planeX + 50;
	planeX += 50;
	PointList[3].y = planeY;

	drawPolygon(4, &PointList, c, 2);	
}

void buildPlaneToLeft(int x, int y, color c){
	//making list of points
	Point PointList[7];

	//assign global variables with the assigned parameters
	planeX = x;
	planeY = y;

	PointList[0].x = planeX;
	PointList[0].y = planeY;
	
	PointList[1].x = planeX + 70;
	planeX += 70;
	PointList[1].y = planeY - 45;
	planeY -= 45;
	
	PointList[2].x = planeX + 190;
	planeX += 190;
	PointList[2].y = planeY;
	
	PointList[3].x = planeX + 60;
	planeX += 60;
	PointList[3].y = planeY - 35;
	planeY -= 35;
	
	PointList[4].x = planeX + 20;
	planeX += 20;
	PointList[4].y = planeY;
	
	PointList[5].x = planeX - 50;
	PointList[5].y = planeY + 80;
	planeY += 80;
	
	drawPolygon(6, &PointList, c, 2);

	Point circle;
	circle.x = planeX - 260;
	circle.y = planeY + 3;
	drawCircle(12, circle, 2, c);

	planeX = x + 100;
	planeY = y - 25;

	PointList[0].x = planeX;
	PointList[0].y = planeY;

	PointList[1].x = planeX + 100;
	planeX += 100;
	PointList[1].y = planeY;

	PointList[2].x = planeX + 100;
	planeX += 100;
	PointList[2].y = planeY + 45;
	planeY += 45;

	PointList[3].x = planeX - 50;
	planeX -= 50;
	PointList[3].y = planeY;

	drawPolygon(4, &PointList, c, 2);

	planeX = x + 100;
	planeY = y - 45;

	PointList[0].x = planeX;
	PointList[0].y = planeY;

	PointList[1].x = planeX + 100;
	planeX += 100;
	PointList[1].y = planeY;

	PointList[2].x = planeX + 100;
	planeX += 100;
	PointList[2].y = planeY - 45;
	planeY -= 45;

	PointList[3].x = planeX - 50;
	planeX -= 50;
	PointList[3].y = planeY;

	drawPolygon(4, &PointList, c, 2);	
}


// void buildPlaneSmall(int x, int y, color c){
// 	//assign global variables with the assigned parameters
// 	planeX = x;
// 	planeY = y;
	
// 	//making list of points
// 	Point PointList[1];

// 	PointList[0].x = planeX - 6;
// 	PointList[0].y = planeY + 1;
	
// 	PointList[1].x = planeX - 4;
// 	PointList[1].y = planeY - 1;
	
// 	PointList[2].x = planeX - 1;
// 	PointList[2].y = planeY - 1;
	
// 	PointList[3].x = planeX + 2;
// 	PointList[3].y = planeY - 5;
	
// 	PointList[4].x = planeX + 1;
// 	PointList[4].y = planeY - 1;
	
// 	PointList[5].x = planeX + 5;
// 	PointList[5].y = planeY - 1;
	
// 	PointList[6].x = planeX + 8;
// 	PointList[6].y = planeY - 4;
	
// 	PointList[7].x = planeX + 10;
// 	PointList[7].y = planeY - 4;
	
// 	PointList[8].x = planeX + 9;
// 	PointList[8].y = planeY - 1;
	
// 	PointList[9].x = planeX + 8;
// 	PointList[9].y = planeY;
	
// 	PointList[10].x = planeX + 9;
// 	PointList[10].y = planeY + 2;
	
// 	PointList[11].x = planeX + 5;
// 	PointList[11].y = planeY + 1;
	
// 	PointList[12].x = planeX + 1;
// 	PointList[12].y = planeY + 1;
	
// 	PointList[13].x = planeX + 2;
// 	PointList[13].y = planeY + 5;
	
// 	PointList[14].x = planeX - 1;
// 	PointList[14].y = planeY + 1;
	
// 	//building the polygon
// 	drawPolygon(1, &PointList, c, 4);
// }
