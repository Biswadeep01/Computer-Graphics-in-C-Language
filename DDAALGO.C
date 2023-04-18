#include<graphics.h>
#include<conio.h>
#include<math.h>
int round(float x){
float r = ceil(x);
float d = r-x;
if(d>0.5)
	return (int) x;
else
	return (int) r;
	}

void dda(int w, int x, int y, int z){
int dx, i, dy, stp;
float xin, yin, a=w, b=x;
dx=y-w;
dy=z-x;
if(abs(dx) > abs(dy))
	stp = abs(dx);
else
	stp = abs(dy);
xin = dx/(float)stp;
yin = dy/(float)stp;
for(i=0;i<stp;i++){
      a = a+ xin;
      b = b+ yin;
      putpixel(round(a),round(b),15);
      }
}
void main(){
int gd=DETECT, gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
dda(100,100, 200,100);
getch();
}
