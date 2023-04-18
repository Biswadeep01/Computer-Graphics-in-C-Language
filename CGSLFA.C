#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>

// Declaration of class point
typedef struct {
    int x,y;
} point;

typedef struct {
    point p[20];
    int inter[20],x,y;
    int v,xmin,ymin,xmax,ymax;
    int c;
} poly;

void read(poly *x);
void calcs(poly *x);
void display(poly *x);
void ints(poly *x, float);
void sort(poly *x, int);

int main() {
    int cl,gd=DETECT,gm;
    poly x;
    initgraph(&gd, &gm, "C:\\turboc3\\bgi");
    cleardevice();

    read(&x);
    calcs(&x);
    cleardevice();
    printf("\n\tEnter the colour you want:(0-15)->"); // Selecting colour
    scanf("%d", &cl);
    setcolor(cl);
    display(&x);
    closegraph(); // Closing graphics mode
    getch();
    return 0;
}

void read(poly *x) {
    int i;
    printf("\n\tSCAN_FILL ALGORITHM");
    printf("\n Enter the no of vertices of polygon:");
    scanf("%d", &x->v);
    if(x->v>2) {
	for(i=0;i<x->v;i++) { // Accept the vertices
	    printf("\nEnter the co-ordinate no.- %d : ",i+1);
	    printf("\n\tx%d=",i+1);
	    scanf("%d", &x->p[i].x);
	    printf("\n\ty%d=",i+1);
	    scanf("%d", &x->p[i].y);
	}
	x->p[i].x=x->p[0].x;
	x->p[i].y=x->p[0].y;
	x->xmin=x->xmax=x->p[0].x;
	x->ymin=x->ymax=x->p[0].y;
    } else {
	printf("\n Enter valid no. of vertices.");
    }
}

void calcs(poly *p) { //MAX,MIN
    int i;
    for (i = 0; i < p->v; i++) {
	if (p->xmin > p->p[i].x)
	    p->xmin = p->p[i].x;
        if (p->xmax < p->p[i].x)
            p->xmax = p->p[i].x;
        if (p->ymin > p->p[i].y)
            p->ymin = p->p[i].y;
        if (p->ymax < p->p[i].y)
            p->ymax = p->p[i].y;
    }
}

void ints(poly *p, float z) { //DEFINE FUNCTION INTS
    int x1, x2, y1, y2, temp, i;
    p->c = 0;
    for (i = 0; i < p->v; i++) {
        x1 = p->p[i].x;
        y1 = p->p[i].y;
        x2 = p->p[i + 1].x;
        y2 = p->p[i + 1].y;
        if (y2 < y1) {
            temp = x1;
            x1 = x2;
            x2 = temp;
            temp = y1;
            y1 = y2;
            y2 = temp;
        }
        if (z <= y2 && z >= y1) {
            if ((y1 - y2) == 0)
                p->x = x1;
            else // used to make changes in x. so that we can fill our polygon after certain distance
            {
                p->x = ((x2 - x1) * (z - y1)) / (y2 - y1);
                p->x = p->x + x1;
            }
            if (p->x <= p->xmax && p->x >= p->xmin)
                p->inter[p->c++] = p->x;
        }
    }
}

void sort(poly *p, int z)
{
    int temp,j,i;

    for(i=0;i<p->v;i++)
    {
        line(p->p[i].x,p->p[i].y,p->p[i+1].x,p->p[i+1].y); // used to make hollow outlines of a polygon
    }
    delay(100);
    for(i=0; i<p->c;i+=2)
    {
        delay(100);
        line(p->inter[i],z,p->inter[i+1],z);  // Used to fill the polygon ....
    }
}

void display(poly *p)
{
    int ch1;
    char ch='y';
    float s,s2;
    do
    {
        printf("\n\nMENU:");
        printf("\n\n\t1 . Scan line Fill ");
        printf("\n\n\t2 . Exit ");
        printf("\n\nEnter your choice:");
        scanf("%d",&ch1);
        switch(ch1)
        {
            case 1:
                s=p->ymin+0.01;
                delay(100);
                cleardevice();
                while(s<=p->ymax)
                {
                    ints(p, s);
                    sort(p, s);
                    s++;
                }
                break;
            case 2:
                exit(0);
        }

        printf("Do you want to continue?: ");
        scanf(" %c",&ch);
    }while(ch=='y' || ch=='Y');
}