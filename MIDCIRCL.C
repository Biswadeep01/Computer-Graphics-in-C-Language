#include<graphics.h>
#include<conio.h>
void Midcircle(int xc, int yc, int r){
	int x=0, y=r, p=1-r;
	void Plotpoints(int, int, int, int);
	Plotpoints(xc, yc, x, y);
	while(x<y){
		x++;
		if(p<0)
			p+=2*x-1;
		else{
			y--;
			p+=2*(x-y)+1;
		}
		Plotpoints(xc, yc, x, y);

	}
}
void Plotpoints(int xc,int yc,int x,int y){
	putpixel(xc+x, yc+y, 15);
	putpixel(xc-x, yc+y, 15);
	putpixel(xc+x, yc-y, 15);
	putpixel(xc-x, yc-y, 15);
	putpixel(xc+y, yc+x, 15);
	putpixel(xc-y, yc+x, 15);
	putpixel(xc+y, yc-x, 15);
	putpixel(xc-y, yc-x, 15);
}
void main(){
int gd=DETECT, gm;
initgraph(&gd, &gm, "c:\\turboc3\\bgi");
Midcircle(100, 100, 50);
getch();
}