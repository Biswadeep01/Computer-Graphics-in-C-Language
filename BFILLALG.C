#include<graphics.h>
#include<conio.h>
void boundaryFill4(int x, int y, int fill, int boundary){
	int current;
	current = getpixel(x,y);
	if((current != boundary) && (current != fill)){
		putpixel(x,y,fill);
		boundaryFill4(x+1, y, fill, boundary);
		boundaryFill4(x-1, y, fill, boundary);
		boundaryFill4(x, y+1, fill, boundary);
		boundaryFill4(x, y-1, fill, boundary);
	}
}

void main(){
	int gd=DETECT, gm;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	circle(100, 100, 5);
	boundaryFill4(100,100,1,15);
	getch();
}