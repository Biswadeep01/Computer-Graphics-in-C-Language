#include<graphics.h>
#include<conio.h>
#include<dos.h>
void lineRotate(int x, int y){
	int i;
	for(i=0; i<=50; i++){
		line((x-50)+i, y-i, (x+50)-i, y+i);
		delay(100);
		if(i<50)
			cleardevice();
	}
}
void main(){
	int gd=DETECT, gm;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	lineRotate(100, 100);
	getch();
}