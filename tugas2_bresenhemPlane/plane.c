#include <stdlib.h>
#include <stdio.h>
#include "line.c"

int planeX;
int planeY;

void buildPlane(int x, int y, color c){
	//assign global variables with the assigned parameters
	planeX = x;
	planeY = y;
	
	//making list of points
	Point PointList[15];
	PointList[0].x = planeX - 6;
	PointList[0].y = planeY + 1;
	
	PointList[1].x = planeX - 4;
	PointList[1].y = planeY - 1;
	
	PointList[2].x = planeX - 1;
	PointList[2].y = planeY - 1;
	
	PointList[3].x = planeX + 2;
	PointList[3].y = planeY - 5;
	
	PointList[4].x = planeX + 1;
	PointList[4].y = planeY - 1;
	
	PointList[5].x = planeX + 5;
	PointList[5].y = planeY - 1;
	
	PointList[6].x = planeX + 8;
	PointList[6].y = planeY - 4;
	
	PointList[7].x = planeX + 10;
	PointList[7].y = planeY - 4;
	
	PointList[8].x = planeX + 9;
	PointList[8].y = planeY - 1;
	
	PointList[9].x = planeX + 8;
	PointList[9].y = planeY;
	
	PointList[10].x = planeX + 9;
	PointList[10].y = planeY + 2;
	
	PointList[11].x = planeX + 5;
	PointList[11].y = planeY + 1;
	
	PointList[12].x = planeX + 1;
	PointList[12].y = planeY + 1;
	
	PointList[13].x = planeX + 2;
	PointList[13].y = planeY + 5;
	
	PointList[14].x = planeX - 1;
	PointList[14].y = planeY + 1;
	
	//building the polygon
	drawPolygon(15, &PointList, c, 4);
}
