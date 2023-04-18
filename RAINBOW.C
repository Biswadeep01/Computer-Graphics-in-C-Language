#include<conio.h>
#include<graphics.h>
#include<dos.h>
void main(){
int gd=DETECT, gm, i, j;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
for(i=1; i<8; i++){
setcolor(i+2);
arc(getmaxx()/2,getmaxy()/2,0,180,100-i*10);
delay(1000);
}
for(i=8; i>0; i--){
setcolor(0);
arc(getmaxx()/2,getmaxy()/2,0,180,100-i*10);
delay(1000);
}
getch();
}