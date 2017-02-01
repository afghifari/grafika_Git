#include "square.c"

void printA(int x, int y, color C) {
    int i, j;
    for(i=0; i<4; i++){
        for(j=0; j<3; j++){
            if (!((i==0 && j==0) || (i==3 && j==0) || (i==1 && j==1) || (i==2 && j==1))){
                printSquare(SIZE, i*SIZE+x, j*SIZE+y, C);
            }
        }
    }

	printSquare(SIZE, x, 3*SIZE+y, C);
	printSquare(SIZE, x, 4*SIZE+y, C);
	printSquare(SIZE, 3*SIZE+x, 3*SIZE+y, C);
	printSquare(SIZE, 3*SIZE+x, 4*SIZE+y, C);
}

void printB(int x, int y, color C) {
	int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<5; j++){
            if (!((j%2 == 1) && (i>0))) {
                printSquare(SIZE, i*SIZE+x, j*SIZE+y, C);
            }
        }
    }
	printSquare(SIZE, 3*SIZE+x, SIZE+y, C);
	printSquare(SIZE, 3*SIZE+x, 3*SIZE+y, C);
}

void printC(int x, int y, color C) {
	int i, j;
    for(i=1; i<3; i++){
	printSquare(SIZE, i*SIZE+x, y, C);
	printSquare(SIZE, i*SIZE+x, 4*SIZE+y, C);
    }
    for(j=1; j<4; j++){
        printSquare(SIZE, x, j*SIZE+y, C);
	if (j!=2) printSquare(SIZE, 3*SIZE+x, j*SIZE+y, C);
    }
}

void printD(int x, int y, color C) {
	int i, j;
    for(i=0; i<4; i++){
        for(j=0; j<5; j++){
            if (!((i>0 && j>0) && (i<3 && j<4) || (i==3 && j==0) || (i==3 && j==4))){
            	printSquare(SIZE, i*SIZE+x, j*SIZE+y, C);
            }
        }
    }
}

void printE(int x, int y, color C) {
	int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<5; j++){
            if (!((j%2 == 1) && (i>0))) {
                printSquare(SIZE, i*SIZE+x, j*SIZE+y, C);
            }
        }
    }
}

void printF(int x, int y, color C) {
	int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<5; j++){
            if (!((j%2 == 1) && (i>0) || (j==4 && i>0))) {
                printSquare(SIZE, i*SIZE+x, j*SIZE+y, C);
            }
        }
    }
}

void printG(int x, int y, color C) {
	int i, j;
    for(i=1; i<4; i++){
        printSquare(SIZE, i*SIZE+x, y, C);
    }

    printSquare(SIZE, x, SIZE+y, C);
    
    for(i=0; i<4; i++){
    	if (!(i==1)) {
    		printSquare(SIZE, i*SIZE+x, 2*SIZE+y, C);
    	}
    }

    printSquare(SIZE, x, 3*SIZE+y, C);
    printSquare(SIZE, 3*SIZE+x, 3*SIZE+y, C);
    printSquare(SIZE, SIZE+x, 4*SIZE+y, C);
    printSquare(SIZE, 2*SIZE+x, 4*SIZE+y, C);
}

void printH(int x, int y, color C) {
	int i, j;
    for(i=0; i<4; i++){
        for(j=0; j<5; j++){
            if (!(i>0 && i<3)){
                printSquare(SIZE, i*SIZE+x, j*SIZE+y, C);
            }
   			else if (j==2) {
   				printSquare(SIZE, i*SIZE+x, j*SIZE+y, C);
   			}
        }
    }
}

void printI(int x, int y, color C) {
	int j;
	for(j=0;j<5;j++){
		printSquare(SIZE, x, j*SIZE+y, C);
	}
}

void printJ(int x, int y, color C) {
	int i, j;
	for(j=0;j<5;j++){
		if (j<4){
			if (j>2) printSquare(SIZE, x, j*SIZE+y, C);
			printSquare(SIZE, 3*SIZE+x, j*SIZE+y, C);
		}
		else {
			for(i=1;i<3;i++){
				printSquare(SIZE, i*SIZE+x, j*SIZE+y, C);
			}
		}
	}	
}

void printK(int x, int y, color C) {
	int i, j;
	for(j=0;j<5;j++){
		printSquare(SIZE, x, j*SIZE+y, C);
	}
	for(i=1;i<4;i++){
		printSquare(SIZE, i*SIZE+x, (3-i)*SIZE+y, C);
		printSquare(SIZE, i*SIZE+x, (1+i)*SIZE+y, C);
	}
}

void printL(int x, int y, color C) {
	int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<5; j++){
            if ((j==4) || (i==0)) {
                printSquare(SIZE, i*SIZE+x, j*SIZE+y, C);
            }
        }
    }
}

void printM(int x, int y, color C) {
	int i, j;
	for(j=0;j<5;j++){
		printSquare(SIZE, x, j*SIZE+y, C);
		printSquare(SIZE, 4*SIZE+x, j*SIZE+y, C);
	}
	for(i=1;i<3;i++){
		printSquare(SIZE, i*SIZE+x, i*SIZE+y, C);
	}
	printSquare(SIZE, 3*SIZE+x, SIZE+y, C);
}

void printN(int x, int y, color C) {
	int i, j;
	for(j=0;j<5;j++){
		printSquare(SIZE, x, j*SIZE+y, C);
		printSquare(SIZE, 4*SIZE+x, j*SIZE+y, C);
	}
	for(i=1;i<4;i++){
		printSquare(SIZE, i*SIZE+x, i*SIZE+y, C);
	}
}

void printO(int x, int y, color C) {
	int i, j;
    for(i=1; i<3; i++){
	printSquare(SIZE, i*SIZE+x, y, C);
	printSquare(SIZE, i*SIZE+x, 4*SIZE+y, C);
    }
    for(j=1; j<4; j++){
        printSquare(SIZE, x, j*SIZE+y, C);
	printSquare(SIZE, 3*SIZE+x, j*SIZE+y, C);
    }
}

void printP(int x, int y, color C) {
	int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<5; j++){
            if (!((j%2 == 1) && (i>0) || (j==4 && i>0))) {
                printSquare(SIZE, i*SIZE+x, j*SIZE+y, C);
            }
        }
    }
	printSquare(SIZE, 3*SIZE+x, 1*SIZE+y, C);
}

void printR(int x, int y, color C) {
    int i, j;
    for(i=0; i<5; i++){
        for(j=0; j<4; j++){
            if ((i==0 || i==2) && j!=3)
                printSquare(SIZE, j*SIZE+x, i*SIZE+y, C);
            else if ((i==1 || i==4) && j!=1 && j!=2)
                printSquare(SIZE, j*SIZE+x, i*SIZE+y, C);
            else if (i==3 && j!=1 && j!=3)
                printSquare(SIZE, j*SIZE+x, i*SIZE+y, C);
        }
    }
}

void printS(int x, int y, color C) {
    int i, j;
    for(i=0; i<5; i++){
        for(j=0; j<4; j++){
            if (i==0 && j!=0)
                printSquare(SIZE, j*SIZE+x, i*SIZE+y, C);
            else if (i==1 && j==0)
                 printSquare(SIZE, j*SIZE+x, i*SIZE+y, C);
            else if (i==2 && j!=0 && j!=3)
                printSquare(SIZE, j*SIZE+x, i*SIZE+y, C);
            else if (i==3 && j==3)
                printSquare(SIZE, j*SIZE+x, i*SIZE+y, C);
            else if (i==4 && j!=3)
                printSquare(SIZE, j*SIZE+x, i*SIZE+y, C);
        }
    }
}

void printT(int x, int y, color C) {
    int i, j;
    for(i=0; i<5; i++){
        for(j=0; j<3; j++){
            if (i==0)
                printSquare(SIZE, j*SIZE+x, i*SIZE+y, C);
            else if (i!=0 && j!=0 && j!=2)
                printSquare(SIZE, j*SIZE+x, i*SIZE+y, C);
        }
    }
}

void printU(int x, int y, color C) {
	int i, j;
	for(j=0;j<5;j++){
		if (j<4){
			printSquare(SIZE, x, j*SIZE+y, C);
			printSquare(SIZE, 3*SIZE+x, j*SIZE+y, C);
		}
		else {
			for(i=1;i<3;i++){
				printSquare(SIZE, i*SIZE+x, j*SIZE+y, C);
			}
		}
	}	
}

void printV(int x, int y, color C) {
    int i, j;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if ((i==0 || i==1) && (j==0 || j==4))
                printSquare(SIZE, j*SIZE+x, i*SIZE+y, C);
            else if ((i==2 || i==3) && (j==1 || j==3))
                printSquare(SIZE, j*SIZE+x, i*SIZE+y, C);
            else if (i==4 && j==2)
                printSquare(SIZE, j*SIZE+x, i*SIZE+y, C);
        }
    }
}

void print7(int x, int y, color C) {
	int i, j;
	for(i=0; i<4; i++){
		for(j=0; j<5; j++) {
			if (j==0) {
				printSquare(SIZE, i*SIZE+x, j*SIZE+y, C);
			} else if (j==1) {
				printSquare(SIZE, 3*SIZE+x, j*SIZE+y, C);
			} else if (j==2) {
				printSquare(SIZE, 2*SIZE+x, j*SIZE+y, C);
			} else {
				printSquare(SIZE, 1*SIZE+x, j*SIZE+y, C);
			}
		}
	}
}
