#include "plane.c"
#include <termios.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

static int endSign = 0;

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

color colorBlack() {
	//black
	color X;
	X.R = 0;
	X.G = 0;
	X.B = 0;
	return X;
}

color colorYellow() {
	//yellow
	color C;
	C.R = 255;
	C.G = 255;
	C.B = 10;

	return C;
}

color colorBlue() {
	//blue 
	color B;
	B.R = 66;
	B.G = 134;
	B.B = 244;

	return B;
}


/* this function is run by the second thread */
void *inc_x(void *x_void_ptr) {    
	// int cmd = ' ';
	color C;
	C = colorYellow();

	
	// sleep(1);
	
	while(endSign == 0){
		
		shootCannon(C); 
	}
	// while (1) {
	// 	cmd = getch();
	// 	if (cmd == 10) {
	// 	   //peluru ditembak
	//    }
	// }
	/* the function must return something - NULL will do */
	return NULL;
}

 int main()
 {
     int x = 0, y = 0;
     int i, j;
     int sign;   
     long int location = 0;

     // Open the file for reading and writing
     fbfd = open("/dev/fb0", O_RDWR);
     if (fbfd == -1) {
         perror("Error: cannot open framebuffer device");
         exit(1);
     }
   //  printf("The framebuffer device was opened successfully.\n");

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
	X = colorBlack();	

	//yellow
	color C;
	C = colorYellow();

	//blue 
	color B;
	B = colorBlue();


	/*
	/////////////////////// ADA BUG KALO BIKIN TITIK BEGINI
	///////////////// START OF BUG ///
	Point P1[4];
	P1[0].x = 365;       
	P1[0].y = 243; 

	P1[1].x = 400; // titik x ke kanan dg y constant 
	P1[1].y = 243;         

	P1[2].x = 332; // titik x ke kanan dan y 
	P1[2].y = 400; 
 	
 	drawPolygon (3, &P1, C, 1);
 	//// Kalo di logika hasilnya nggak akan begini,, tapi ini jadi begini
 	//// dan alhasil ini berdampak pada pesawat yang aku bikin
 	//////////////////////////////// END OF BUG
*/ 

	// buildCannon(500, 600, C);
	// sleep(1);
	// shootCannon(C); 

	// P1[3].x = 765;   
	// P1[3].y = 243;
    
 
	 //this variable is our reference to the thread 
	pthread_t inc_x_thread;

	 //create a thread which executes inc_x(&x) 
	if(pthread_create(&inc_x_thread, NULL, inc_x, &x)) {
		fprintf(stderr, "Error creating thread\n");
		return 1;
	}

	// pesawat terbang disini
	int counter = 0;
	j = 240;
	sign = 0;
  	for (i = 1000 ; i > 20 ; i-=10){

  		buildPlaneToLeft(i, j, C); 

 	    if (j <= 100)
 	    	sign = 1;
 	    else if (j >= 340)
 	    	sign = 0;

 	    if (sign == 0)
 	    	j -= 10;
 	    else
 	    	j += 15;

 	    buildCannon(500, 600, C);

 	    if (counter==1){
 	    	printBackground(X);  
 	    	counter=0;
 	    }
 	    counter++;
  	}

  	counter=0;
  	for (i = 20; i < 1250 ; i+=10){

  		buildPlaneToRight(i, j, C); 

 	    if (j <= 100)
 	    	sign = 1;
 	    else if (j >= 340)
 	    	sign = 0;

 	    if (sign == 0)
 	    	j -= 10;
 	    else
 	    	j += 15;
 	    buildCannon(500, 600, C);


 	    if (counter==1){
 	    	printBackground(X);  
 	    	counter=0;
 	    }
 	    counter++;
  	}
	
	endSign = 1;
       
	//drawBresenhamLine (P1, P2, C, 3);
	//drawPolyline (2, &P1, C, 1); 
	

	
	// printf("Input first point x & y position\n");
	// scanf("%d %d", &P1.x, &P1.y);

	// printf("Input second point x & y position\n");
	// scanf("%d %d", &P2.x, &P2.y);

	// printf("Input line weight\n");
	// scanf("%d", &W);

	// buildCannon(500, 600, C);
	// sleep(1);
	// shootCannon(C); 
	// buildPlane(345, 512, B);
	//printBackground(X);

	// int n;
	// Point P[10];
	// printf("Input number of point(s)\n");
	// //scanf("%d", &n);
	// n = 2;
	// for (i = 0;i < n;i++) {
	// 	printf("Input point-%d x & y position\n", i+1);
	// 	//scanf("%d %d", &P[i].x, &P[i].y);
	// 	P[0].x = 1;
	// 	P[0].y = 2;
	// 	P[1].x = 10;
	// 	P[1].y = 20;
	// }
	// printf("Input line weight\n");
	// //scanf("%d", &W);
	// W= 1;
	//drawPolygon(n, P, C, W);
	munmap(fbp, screensize);
	close(fbfd);

}
