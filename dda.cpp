#include<iostream>
#include<conio.h>
#include<math.h>
#include<graphics.h>
using namespace std;
 int main()
 {
    int gd=DETECT,gm;
   
    initgraph(&gd, &gm,NULL);
    cleardevice();
    float x1,y1,x2,y2;
    float dx,dy,x,y;
    int steps;
    cout<<"Enter x1,y1,x2,y2: ";
    cin>>x1>>y1>>x2>>y2;
     dx=x2-x1;
     dy=y2-y1;
    
     if(abs(dx)>abs(dy))
     {
        steps=dx;
     }
     else 
     steps=dy;
     float xinc,yinc;
     xinc=dx/steps;
     yinc=dy/steps;
     x=x1;
     y=y1;
     putpixel(round(x),round(y),WHITE);
     for(int i=0;i<steps;i++)
     {    cout<<"("<<round(x)<<","<<round(y)<<")"<<endl;
        putpixel(round(x), round(y), WHITE);
        x=x+xinc;
        y=y+yinc;
     }
getch();
closegraph();
return 0;
}