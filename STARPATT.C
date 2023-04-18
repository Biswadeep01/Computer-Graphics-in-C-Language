#include<graphics.h>
#include<conio.h>
void star(int x, int y){
line(x-5,y,x+5,y);
line(x,y-5,x,y+5);
line(x-5,y-5,x+5,y+5);
line(x+5,y-5,x-5,y+5);
}
void main(){
int gd=DETECT, gm, i=0,j=0;
initgraph(&gd, &gm, "c:\\turboc3\\bgi");
for(i=1;i<6;i++){
	for(j=1; j<=i; j++){
		star(j*20,i*20);
		}
	}
getch();
}