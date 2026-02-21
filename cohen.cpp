#include <graphics.h>
#include <iostream>
#include <conio.h>
using namespace std;

/* Region Codes */
#define INSIDE 0
#define LEFT   1
#define RIGHT  2
#define BOTTOM 4
#define TOP    8

/* Clipping window */
int xmin = 100, ymin = 100, xmax = 400, ymax = 300;

/* Compute region code */
int computeCode(float x, float y)
{
    int code = INSIDE;

    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;

    if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax)
        code |= TOP;

    return code;
}

/* Cohen-Sutherland Algorithm */
void cohenSutherland(float x1, float y1, float x2, float y2)
{
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int accept = 0;

    while (1)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            accept = 1;
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else
        {
            float x, y;
            int code_out = (code1 != 0) ? code1 : code2;

            if (code_out & TOP)
            {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (code_out & BOTTOM)
            {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (code_out & RIGHT)
            {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else if (code_out & LEFT)
            {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept)
    {
        setcolor(GREEN);  // clipped line
        line(x1, y1, x2, y2);
        outtextxy(200, 350, (char*)"Line Accepted");
    }
    else
    {
        outtextxy(200, 350, (char*)"Line Rejected");
    }
}

/* Main Function */
int main()
{
    int gd = DETECT, gm;
    float x1, y1, x2, y2;
char path[] = "C:\\TURBOC3\\BGI";  
    initgraph(&gd, &gm, path);

    // Draw window
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);

    // Input
    cout << "Enter x1 y1: ";
    cin >> x1 >> y1;

    cout << "Enter x2 y2: ";
    cin >> x2 >> y2;

    //  Show ORIGINAL line
    setcolor(RED);
    line(x1, y1, x2, y2);

    outtextxy(50, 50, (char*)"Original Line");

    getch();   // wait

    //  Clear screen
    cleardevice();

    // Draw window again
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);

    // Show CLIPPED line
    cohenSutherland(x1, y1, x2, y2);

    outtextxy(50, 50, (char*)"Clipped Line");

    getch();
    closegraph();
    return 0;
}
