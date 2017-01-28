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
    if (((loc_x)>=0) && ((loc_x + edge)<vinfo.xres) && ((loc_y)>=0) && ((loc_y + edge)<vinfo.yres)) {
		for (i = loc_x; i < (loc_x+edge); i++) {
			for (j = loc_y; j < (loc_y+edge); j++) {
				location = (i+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (j+vinfo.yoffset) * finfo.line_length;
				
				if (fbp + location) { //check for segmentation fault
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
				} else {
					return;
				}
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


