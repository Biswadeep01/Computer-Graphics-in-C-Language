#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
void main(){
	int gd=DETECT, gm, x, y;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	cleardevice();
	printf("Translating a 2d point");
	putpixel(100, 100, 15);
	printf("\nEnter the x co-ordinate distance: ");
	scanf("%d",&x);
	printf("\nEnter the y co-ordinate distance: ");
	scanf("%d",&y);
	delay(50);
	cleardevice();
	delay(50);
	//putpixel(100, 100, 15);
	putpixel(100+x, 100+y, 15);
	getch();
	closegraph();
}