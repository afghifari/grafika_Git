#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

#define SIZE 10
int fbfd = 0;
struct fb_var_screeninfo vinfo;
struct fb_fix_screeninfo finfo;
long int screensize = 0;
char *fbp = 0;
int displayWidth, displayHeight;

/*color struct consists of Red, Green, and Blue */
typedef struct {
    int R;
    int G;
    int B;
} color;

/*
edge    : square size
loc_x   : x coordinate
loc_y   : y coordinate
C       : color struct (Red, Green, Blue)
*/
void printSquare (int edge, int loc_x, int loc_y, color C) {
    long int location;
    int i,j;
    for (i = loc_x; i < (loc_x+edge); i++) {
        for (j = loc_y; j < (loc_y+edge); j++) {
            location = (i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (j+vinfo.yoffset) * finfo.line_length;

            if (vinfo.bits_per_pixel == 32) {
                *(fbp + location) = C.B;            //Blue
                *(fbp + location + 1) = C.G;        //Green
                *(fbp + location + 2) = C.R;        //Red
                *(fbp + location + 3) = 0;          //Transparancy
            } else  { //assume 16bpp
                int r = C.R;     //Red
                int g = C.G;     //Green
                int b = C.B;     //Blue
                
                unsigned short int t = r<<11 | g << 5 | b;
                *((unsigned short int*)(fbp + location)) = t;
            }
        }
    }
}

void printBackground(color C) {
    long int location;
    int width = displayWidth - 6;
    int height = displayHeight - 6;
    int i,j;

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            location = (i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (j+vinfo.yoffset) * finfo.line_length;

            if (vinfo.bits_per_pixel == 32) {
                *(fbp + location) = C.B;         //Blue
                *(fbp + location + 1) = C.G;     //Green
                *(fbp + location + 2) = C.R;     //Red
                *(fbp + location + 3) = 0;       //No transparency
            } else  { //assume 16bpp
                int r = C.R;     //Red
                int g = C.G;     //Green
                int b = C.B;     //Blue
                
                unsigned short int t = r<<11 | g << 5 | b;
                *((unsigned short int*)(fbp + location)) = t;
            }
        }
    }
}

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

 int main()
 {
     int x = 0, y = 0;
     long int location = 0;

     // Open the file for reading and writing
     fbfd = open("/dev/fb0", O_RDWR);
     if (fbfd == -1) {
         perror("Error: cannot open framebuffer device");
         exit(1);
     }
     printf("The framebuffer device was opened successfully.\n");

     // Get fixed screen information
     if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
         perror("Error reading fixed information");
         exit(2);
     }

     // Get variable screen information
     if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
         perror("Error reading variable information");
         exit(3);
     }

     printf("%dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);

     // Figure out the size of the screen in bytes
     screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

     // Map the device to memory
     fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED,
                        fbfd, 0);
     if ((int)fbp == -1) {
         perror("Error: failed to map framebuffer device to memory");
         exit(4);
     }
     printf("The framebuffer device was mapped to memory successfully.\n");
	displayWidth = vinfo.xres;
	displayHeight = vinfo.yres;
     x = 40; y = 50;       // Where we are going to put the pixel

     // Figure out where in memory to put the pixel
     color C;
     C.R = 255;
     C.G = 255;
     C.B = 10;
	
printA(50,50,C);	
printB(100,50,C);
printC(150,50,C);
printD(200,50,C);
printE(250,50,C);  
printF(300,50,C);
printG(350,50,C);
printH(400,50,C);
printI(450,50,C);
printJ(470,50,C);
printK(520,50,C);
printL(570,50,C);
printM(620,50,C);
printN(680,50,C);
printO(740,50,C);
printP(790,50,C);

     munmap(fbp, screensize);
     close(fbfd);
     return 0;
 }
