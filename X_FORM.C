#include<conio.h>
#include<graphics.h>
void main(){
int gd= DETECT, gm, x, y;
initgraph(&gd, &gm,"C:\\turboc3\\bgi");
line(0,0,639,479);
line(639,0,0,479);
getch();
}