#include<iostream>
#include<conio.h>
#include<math.h>
#include<graphics.h>
using namespace std;

int x1,y11,x2,y22,po,pk,dx,dy,xo,yo,x,y;

void beg()
{
    cout<<"Enter x1,y11,x2,y22: ";
    cin>>x1>>y11>>x2>>y22;
    x = x1;
    y = y11;
    dy = y22 - y11;
    dx = x2 - x1;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    cleardevice();

    beg();   

    if(abs(dx) > abs(dy))   // m < 1
    {
        po = 2*dy - dx;

        for(int i = 0; i <= dx; i++)   
        {
            cout<<"Current (xk,yk): ("<<x<<","<<y<<")";

            if(po < 0)
            {
                xo = x + 1;
                yo = y;
                pk = po + 2*dy;
            }
            else
            {
                xo = x + 1;
                yo = y + 1;
                pk = po + 2*dy - 2*dx;
            }

            cout<<" -> Next (xk+1,yk+1): ("<<xo<<","<<yo<<")"<<endl;

            putpixel(x, y, WHITE);

            x = xo;   
            y = yo;
            po = pk;
        }
    }
    else   // m > 1
    {
        po = 2*dx - dy;

        for(int i = 0; i <= dy; i++)
        {
            cout<<"Current (xk,yk): ("<<x<<","<<y<<")";

            if(po < 0)
            {
                xo = x;
                yo = y + 1;
                pk = po + 2*dx;
            }
            else
            {
                xo = x + 1;
                yo = y + 1;
                pk = po + 2*dx - 2*dy;
            }

            cout<<" -> Next (xk+1,yk+1): ("<<xo<<","<<yo<<")"<<endl;

            putpixel(x, y, WHITE);

            x = xo;  
            y = yo;
            po = pk;
        }
    }

    getch();
    closegraph();
    return 0;
}