#include<iostream>
#include<graphics.h>
#include<math.h>
#include<conio.h>
using namespace std;

void drawAxes()
{
    line(320,0,320,480);
    line(0,240,640,240);
}

void drawTriangle(int x1,int y1,int x2,int y2,int x3,int y3)
{
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);
}

int main()
{
    int gd=DETECT, gm;
    char path[100] = "C:\\TURBOC3\\BGI";
    initgraph(&gd,&gm,path);

    setbkcolor(BLACK);
    cleardevice();
    drawAxes();

    int x1,y1,x2,y2,x3,y3;
    cout<<"Enter triangle coordinates x1,y1,x2,y2,x3,y3: ";
    cin>>x1>>y1>>x2>>y2>>x3>>y3;


    setcolor(WHITE);
    drawTriangle(x1,y1,x2,y2,x3,y3);

    int choice=0;
    while(choice!=4)
    {
        cout<<"\n1. Translation\n2. Scaling\n3. Rotation\n4. Exit\nChoice: ";
        cin>>choice;

        if(choice==1) 
        {
            int tx,ty;
            cout<<"Enter tx ty: ";
            cin>>tx>>ty;

            setcolor(YELLOW);
            drawTriangle(x1+tx+320, y1+ty+240,  x2+tx+320, y2+ty+240, x3+tx+320, y3+ty+240);
        }

        else if(choice==2) 
        {
            float sx,sy;
            cout<<"Enter sx sy: ";
            cin>>sx>>sy;

            setcolor(GREEN);
            drawTriangle(x1*sx, y1*sy+240, x2*sx, y2*sy+240, x3*sx, y3*sy+240);
        }

        else if(choice==3) 
        {
            float angle;
            cout<<"Enter angle: ";
            cin>>angle;

            float rad = angle * 3.14159/180;

            int rx1 = x1*cos(rad) - y1*sin(rad);
            int ry1 = x1*sin(rad) + y1*cos(rad);
            int rx2 = x2*cos(rad) - y2*sin(rad);
            int ry2 = x2*sin(rad) + y2*cos(rad);
            int rx3 = x3*cos(rad) - y3*sin(rad);
            int ry3 = x3*sin(rad) + y3*cos(rad);

            setcolor(CYAN);
            drawTriangle(rx1+320, ry1, rx2+320, ry2, rx3+320, ry3);
                       
    }

    getch();
    closegraph();
    return 0;
}
