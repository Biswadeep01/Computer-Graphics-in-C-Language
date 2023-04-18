#include<graphics.h>
#include<conio.h>
void main(){
int gd=DETECT, gm;
initgraph(&gd, &gm, "c:\\turboc3\\bgi");
line(60,0,0,100);
line(60,0,100,100);
line(24,60,83,60);
getch();
}