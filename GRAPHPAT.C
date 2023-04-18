#include<graphics.h>
#include<conio.h>
void main(){
int gd=DETECT,gm,i=0,j=0,x=15;
initgraph(&gd,&gm, "c:\\turboc3\\bgi");
for(i=0;i<5;i++){
for(j=0;j<=i;j++){
putpixel(j*x,i*x,15);
}
}
getch();
}
