#include "plane.c"
#include <termios.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_RIGHT 67
#define KEY_LEFT 68
#define KEY_ENTER 10

static int explode;
static Point P;
 
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

void *tothread(){
	color B;
	B = colorBlue();
	shootCannon(P.x, P.y, B);
}
 
/* this function is run by the second thread */ 
void *inc_x(void *x_void_ptr) {
	pthread_t thread1;
	
	color C, X;
	C = colorYellow();
	X = colorBlack();
	
	while(endSign == 0){	

		char c = getch();
		if (c == KEY_RIGHT){
			buildHalfCannon(P, X);
			if (P.x + 70 < vinfo.xres)
				P.x += 10;
		}
        else if (c == KEY_LEFT) {
        	buildHalfCannon(P, X);
        	if (P.x > 30)
        		P.x -= 10;
        }
        else if (c == KEY_ENTER) {
        	pthread_create(&thread1, NULL, &tothread, NULL);
			pthread_join(thread1, NULL);
        }
	}
	explode = 1;
	
	return NULL;
}

 int main()
 {
	int x = 0, y = 0;
	direction = 0;
	int sign;
	endSign = 0;
	explode = 0;
	long int location = 0;
	color X, C, B;

	X = colorBlack();	
	C = colorYellow();
	B = colorBlue();

	// Open the file for reading and writing
	fbfd = open("/dev/fb0", O_RDWR);
	if (fbfd == -1) {
	 perror("Error: cannot open framebuffer device");
	 exit(1);
	}

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

	// Figure out the size of the screen in bytes
	screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

	// Map the device to memory
	fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED,
	                fbfd, 0);
	if ((int)fbp == -1) {
	 perror("Error: failed to map framebuffer device to memory");
	 exit(4);
	}

	displayWidth = vinfo.xres;
	displayHeight = vinfo.yres;

	P.x = displayWidth / 2;
	P.y = 740; 
 
//	 this variable is our reference to the thread 
	pthread_t inc_x_thread, secondThread;

	 //create a thread which executes inc_x(&x) 
	if(pthread_create(&inc_x_thread, NULL, inc_x, &x)) {
		fprintf(stderr, "Error creating thread\n");
		return 1;
	}

	printBackground(X);	
	while (endSign == 0){
		// pesawat terbang disini 
		int counter = 0;
		indeksJPesawat = 240;
		sign = 0;
		indeksIPesawat = 1000;

		while(indeksIPesawat > 20 && endSign == 0){
			direction = 1;
	  		buildPlaneToLeft(indeksIPesawat, indeksJPesawat, C); 
	  		usleep(50000);
	  		buildPlaneToLeft(indeksIPesawat, indeksJPesawat, X);
	  		
	 	    if (indeksJPesawat <= 100)
	 	    	sign = 1;
	 	    else if (indeksJPesawat >= 340)
	 	    	sign = 0; 

	 	    if (sign == 0)
	 	    	indeksJPesawat -= 10;
	 	    else
	 	    	indeksJPesawat += 15;

	 	    buildHalfCannon(P, B);
	 	    

	 	    if (counter==1){
	 	    	counter=0;
	 	    }
	 	    counter++;
	 	    indeksIPesawat -= 10;
	  	}
	 
	  	counter=0;
	  	indeksIPesawat = 20;
	  	while (indeksIPesawat < 1250 && endSign == 0){
	  		direction = -1;
	  		buildPlaneToRight(indeksIPesawat, indeksJPesawat, C); 
	  		usleep(50000);
	  		buildPlaneToRight(indeksIPesawat, indeksJPesawat, X); 

	 	    if (indeksJPesawat <= 100)
	 	    	sign = 1;
	 	    else if (indeksJPesawat >= 340)
	 	    	sign = 0;

	 	    if (sign == 0)
	 	    	indeksJPesawat -= 10;
	 	    else
	 	    	indeksJPesawat += 15;

	 	    buildHalfCannon(P, B);
	
	 	    if (counter==1){
	 	    	counter=0;
	 	    }
	 	    counter++;
	 	    indeksIPesawat += 10;
	  	}
	}
	
	endSign = 1;
       
    pthread_join(inc_x_thread, NULL);
	munmap(fbp, screensize);
	close(fbfd);
	return 0;
}
