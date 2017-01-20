#include "name.c"

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
     nameFahri(400, 500, C);
     nameSeptialoka(300, 230, B);
     nameGumi(600, 412, C);

// 	printSquare(SIZE, 3*SIZE+23, 7*SIZE+133, B);
// printA(50,100,C);	
// printB(100,100,C);
// printC(150,100,C);
// printD(200,100,C);
// printE(250,100,C);  
// printF(300,100,C);
// printG(350,100,C);
// printH(400,100,C);
// printI(450,100,C);
// printJ(470,100,C);
// printK(520,100,C);
// printL(570,100,C);
// printM(620,100,C);
// printN(680,100,C);
// printO(740,100,C);
// printP(790,100,C);
// printR(840,100,B);
// printS(890,100,B);
// printT(940,100,B);
// printV(990,100,B);

     munmap(fbp, screensize);
     close(fbfd);
     return 0;
 }
