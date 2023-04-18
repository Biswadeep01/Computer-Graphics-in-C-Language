#include<graphics.h>
#include<conio.h>
void Midellipse(int rx, int ry, int xc, int yc){
	float dx, dy, d1, d2, x=0, y=ry;
	d1=(ry*rx)-(rx*rx*ry)+(0.25*rx*rx);
	dx=2*ry*ry*x;
	dy=2*rx*rx*y;
	while(dx<dy){
		putpixel(x+xc, y+yc, 15);
		putpixel(-x+xc, y+yc, 15);
		putpixel(x+xc, -y+yc, 15);
		putpixel(-x+xc, -y+yc, 15);
		if(d1<0){
			x++;
			dx=dx+(2*ry*ry);
			d1=d1+dx+(ry*ry);
		}else{
			x++;
			y--;
			dx=dx+(2*ry*ry);
			dy=dy-(2*ry*ry);
			d1=d1+dx-dy+(ry*ry);
		}
	}
	d2 = ((ry*ry)*((x+0.5)*(x+0.5)))+((rx*rx)*((y-1)*(y-1)))-((rx*rx*ry*ry));
	while (y>=0){
		putpixel(x+xc, y+yc, 15);
		putpixel(-x+xc, y+yc, 15);
		putpixel(x+xc, -y+yc, 15);
		putpixel(-x+xc, -y+yc, 15);
		if(d2>0){
			y--;
			dy=dy-(2*rx*rx);
			d2=d2+(rx*rx)-dy;
		}else{
			y--;
			x++;
			dy=dy-(2*rx*rx);
			dx=dx+(2*ry*ry);
			d2=d2+(rx*rx)+dx-dy;
		}
	}
}
void main(){
int gd=DETECT, gm;
initgraph(&gd, &gm, "c:\\turboc3\\bgi");
Midellipse(15, 10, 100, 100);
getch();
}


