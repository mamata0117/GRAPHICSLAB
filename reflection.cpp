#include <graphics.h>
#include <conio.h>

void drawTriangle(int x1,int y1,int x2,int y2,int x3,int y3)
{
    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x1,y1);
}

int main()
{
    int gd = DETECT, gm;
    char path[] = "C:\\Turboc3\\BGI";
    initgraph(&gd, &gm, path);

    int cx = getmaxx()/2;
    int cy = getmaxy()/2;

   
    setcolor(WHITE);
    line(0, cy, getmaxx(), cy);
    line(cx, 0, cx, getmaxy());

   
    line(0, 0, getmaxx(), getmaxy());
    line(0, getmaxy(), getmaxx(), 0);

   
    int x1 = 60, y1 = 20;
    int x2 = 90, y2 = 20;
    int x3 = 75, y3 = 50;

    for(int i = 1; i <= 8; i++)
    {
       
                setcolor(WHITE);
                drawTriangle(cx+x1, cy-y1, cx+x2, cy-y2, cx+x3, cy-y3);
         
                setcolor(RED);
                drawTriangle(cx+y1, cy-x1, cx+y2, cy-x2, cx+y3, cy-x3);
       
                setcolor(GREEN);
                drawTriangle(cx-x1, cy-y1, cx-x2, cy-y2, cx-x3, cy-y3);
   
                setcolor(CYAN);
                drawTriangle(cx-y1, cy-x1, cx-y2, cy-x2, cx-y3, cy-x3);
        
                setcolor(YELLOW);
                drawTriangle(cx-x1, cy+y1, cx-x2, cy+y2, cx-x3, cy+y3);
            
                setcolor(MAGENTA);
                drawTriangle(cx-y1, cy+x1, cx-y2, cy+x2, cx-y3, cy+x3);
       
                setcolor(BLUE);
                drawTriangle(cx+x1, cy+y1, cx+x2, cy+y2, cx+x3, cy+y3);
          
                setcolor(LIGHTGREEN);
                drawTriangle(cx+y1, cy+x1, cx+y2, cy+x2, cx+y3, cy+x3);
    
        delay(200);
    }

    getch();
    closegraph();
    return 0;
}
