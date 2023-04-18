#include<graphics.h>
#include<conio.h>
#include<dos.h>
void floodFill4(int x, int y, int fc, int oc){
	if(getpixel(x,y) == oc){
		setcolor(fc);
		putpixel(x, y, fc);
		floodFill4(x+1, y, fc, oc);
		floodFill4(x-1, y, fc, oc);
		floodFill4(x, y+1, fc, oc);
		floodFill4(x, y-1, fc, oc);
	}
	delay(5);
}
void main(){
	int gd=DETECT, gm;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	cleardevice();
	setcolor(11);
	circle(100, 100, 20);
	floodFill4(100, 100, 5, 0);
	getch();
	closegraph();
}