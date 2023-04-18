#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main(){
 int gd = DETECT, gm, x, y;
 initgraph(&gd, &gm, "C:\\turboc3\\bgi");
 x= getmaxx();
 y= getmaxy();
 outtextxy(x/2, y/2, "Tbis is not a test.");
 printf("Max x = %d and Max y = %d", x, y);
 getch();
 }