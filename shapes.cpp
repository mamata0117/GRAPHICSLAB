#include<iostream>
#include<conio.h>
#include<graphics.h>
using namespace std;
 int main()
 {
    int gd=DETECT,gm;
   
    initgraph(&gd, &gm,NULL);
    cleardevice();
    int choice;
    while(true) {
    cout<<"1.Point\n 2.Circle \n 3.Ellipse\n 4.Line\n 5.Rectangle\n 6.Arc\n 7.Triangle\n 8.Parallelogram\n 9.Square\n  10.Bagchal";
    cout<<"Enter your choice:";
    cin>>choice;
     switch(choice){
        case 1:
        int x,y;
        cout<<"Enter the coordinates of x and y:";
        cin>>x>>y;
        cout<<"Point"<<endl;
        putpixel(x,y,RED);
        break;
        case 2:
        int xx,yy,rr;
        cin>>xx>>yy>>rr;
         cout<<"Circle"<<endl;
         setcolor(BLUE);
        
        circle(xx,yy,rr);
        outtextxy(50,40,"center");
        break;
         case 3:
        int xc,yc,sa,ea,xr,yr;
        cout<<"Enter xc,yc,sa,ea,xr,yr:";
        cin>>xc>>yc>>sa>>ea>>xr>>yr;
         cout<<"Ellipse"<<endl;
       ellipse(xc,yc,sa,ea,xr,yr);
        setfillstyle(SOLID_FILL,YELLOW);
        break;
         case 4:
        int x1,y1,x2,y2;
        cout<<"Enter x1,y1,x2,y2:";
        cin>>x1>>y1>>x2>>y2;
         cout<<"line"<<endl;
    line(x1,y1,x2,y2);
        break;
        
        case 5:
        int l,r,t,b;
        cout<<"Enter left, top , right and bottom for rectangle:";
        cin>>l>>t>>r>>b;
        cout<<"Rectangle"<<endl;
        rectangle(l,t,r,b);
        break;

        case 6:
      int xc1,yc1,sa1,ea1,xrr;
      cout<<"Enter xc1,yc1,sa1,ea1,radius for arc:";
      cin>>xc1>>yc1>>sa1>>ea1>>xrr;
         cout<<"Arc"<<endl;
       arc(xc1,yc1,sa1,ea1,xrr);
        break;

        case 7:
        int a1,b1,a2,b2,a3,b3;
        cout<<"Enter value for line a1,b1,a2,b2,a3,b3:";
        cin>>a1>>b1>>a2>>b2>>a3>>b3;
        cout<<"Triangle"<<endl;
        line(a1,b1,a2,b2);
        line(a2,b2,a3,b3);
        line(a3,b3,a1,b1);
        break;

        case 8:
        int a11,b11,a12,b12,a13,b13,a14,b14;
        cout<<"Enter value for line a11,b11,a12,b12,a13,b13,a14,b14:";
        cin>>a11>>b11>>a12>>b12>>a13>>b13>>a14>>b14;
        cout<<"Parallelogram"<<endl;
        line(a11,b11,a12,b12);
        line(a12,b12,a13,b13);
        line(a13,b13,a14,b14);
        line(a14,b14,a11,b11);
        break;
        case 9:
        int l1,r1,t1,b111;
        cout<<"Enter left, top , right and bottom for square:";
        cin>>l1>>t1>>r1>>b111;
        cout<<"square"<<endl;
        rectangle(l1,t1,r1,b111);
        break;

        case 10:
       int  start=100,gap=100;
       for(int i=0;i<5;i++){
        int x= start+gap*i;
        line(x,start,x,start+gap*4);
       }
       
       for(int i=0;i<5;i++){
        int y= start+gap*i;
        line(start,y,start+gap*4,y);
       } 
       line(start,start,start+gap*4,start+gap*4);
       line(start+gap*4,start,start,start+gap*4);

       for(int i =0;i<4;i++){
        for(int j =0;j<4;j++){
            int x=start+gap*i;
            int y=start+gap*j;
            if((i+j)%2==0)
            {
                line(x,y,x+gap,y+gap);}
                else{
                line(x+gap,y,x,y+gap);
            }
        }
       }

        break;
        
     } }
getch();
closegraph();
return 0;
 }