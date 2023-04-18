#include<graphics.h>
#include<conio.h>
void Bline(int x1, int y1, int x2, int y2){
	int dx, dy, p;
	dx=x2-x1;
	dy=y2-y1;
	p=2*dy-dx;
	while(x1<x2){
		if(p>=0){
		       putpixel(x1, y1, 15);
		       y1+=1;
		       p+=2*dy+2*dx;
		}else{
		       putpixel(x1, y1, 15);
		       p+=2*dy;
		}
		x1+=1;
	}
}
void main(){
int gd=DETECT, gm;
initgraph(&gd, &gm, "c:\\turboc3\\bgi");
Bline(100,100,200,150);
getch();
}