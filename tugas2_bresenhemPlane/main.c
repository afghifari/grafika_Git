#include "cannon.c"
#include <termios.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

//read keypress
int getch(void) {
	struct termios oldattr, newattr;
	int ch;
	tcgetattr( STDIN_FILENO, &oldattr );
	newattr = oldattr;
	newattr.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
	return ch;
}


/* this function is run by the second thread */
void *inc_x(void *x_void_ptr) {    
	int cmd = ' ';
	while (1) {
		cmd = getch();
		if (cmd == 10) {
		   //peluru ditembak
	   }
	}
	/* the function must return something - NULL will do */
	return NULL;
}

 int main()
 {
     int x = 0, y = 0;
     int i;     
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


	//black
	color X;
	X.R = 0;
	X.G = 0;
	X.B = 0;

/** Print Name

     x = 40; y = 50;       // Where we are going to put the pixel

     //define color
	

    //yellow
    color C;
    C.R = 255;
    C.G = 255;
    C.B = 10;

    //blue 
    color B;
    B.R = 66;
    B.G = 134;
    B.B = 244;

     // Figure out where in memory to put the pixel
     i = 750;
     while (i > -750) {
		kelompok7(400, i, C);
		 nameFahri(400, 100+i, C);
		 nameGumi(400, 200+i, C);
		 nameJoshua(400, 300+i, C);
		 nameMalvin(400, 400+i, C);
		 nameRaihan(400, 500+i, C);
		 nameRaja(400, 600+i, C);
		 nameSeptialoka(400, 700+i, C);
		 i -= 10;
		printBackground(X);
	 }
*/


	color C;
	C.R = 255;
	C.G = 255;
	C.B = 10;
	int W;

/*	Point P1, P2;
	printf("Input first point x & y position\n");
	scanf("%d %d", &P1.x, &P1.y);

	printf("Input second point x & y position\n");
	scanf("%d %d", &P2.x, &P2.y);

	printf("Input line weight\n");
	scanf("%d", &W);

	buildCannon(500, 600, C);
	sleep(1);
	shootCannon(C);

	//printBackground(X);
*/
	int n;
	Point P[10];
	printf("Input number of point(s)\n");
	//scanf("%d", &n);
	n = 2;
	for (int i = 0;i < n;i++) {
		printf("Input point-%d x & y position\n", i+1);
		//scanf("%d %d", &P[i].x, &P[i].y);
		P[0].x = 1;
		P[0].y = 2;
		P[1].x = 10;
		P[1].y = 20;
	}
	printf("Input line weight\n");
	//scanf("%d", &W);
	W= 1;
	
	/* this variable is our reference to the second thread */
	pthread_t inc_x_thread;

	/* create a second thread which executes inc_x(&x) */
	if(pthread_create(&inc_x_thread, NULL, inc_x, &x)) {
		fprintf(stderr, "Error creating thread\n");
		return 1;
	} else {
		//masuk ke second thread
		
		//pesawat terbang disini
		
		drawPolygon(n, P, C, W);
		munmap(fbp, screensize);
		close(fbfd);
		return 0;
	}
}
