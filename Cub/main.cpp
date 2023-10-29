#include <graphics.h>
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;

int cub[4][4][7];
int x1selectat,y1selectat,x2selectat,y2selectat,pselectat,p2selectat,varianta;
bool meniu=false;

void PatratFata1(int x1,int y1,int x2,int y2,int mje1,int mje2)
{
    line(125 + x1 + mje1, 125 + y1 + mje2, 125 + x2 + mje1, 250 + y2 + mje2);
    line(50 + x1 + mje1, 50 + y1 + mje2, 50 + x2 + mje1, 175 + y2 + mje2);
    line(50 + x1 + mje1, 50 + y1 + mje2, 125 + x2 + mje1, 125 + y2 + mje2);
    line(50 + x1 + mje1, 175 + y1 + mje2, 125 + x2 + mje1, 250 + y2 + mje2);
}

void PatratFata2(int x1,int y1,int x2,int y2,int mje1,int mje2)
{
    line(125 + x1 + mje1, 125 + y1 + mje2, 250 + x2 + mje1, 125 + y2 + mje2);
    line(50 + x1 + mje1, 50 + y1 + mje2, 175 + x2 + mje1, 50 + y2 + mje2);
    line(125 + x1 + mje1, 125 + y1 + mje2, 50 + x2 + mje1, 50 + y2 + mje2);
    line(175 + x1 + mje1, 50 + y1 + mje2, 250 + x2 + mje1, 125 + y2 + mje2);
}

void PatratFata3(int x1,int y1,int x2,int y2,int mje1,int mje2)
{
    line(50 + 225 + x1 + mje1, 50 + 225 + y1 + mje2, 175 + 225 + x2 + mje1, 50 + 225 + y2 + mje2);
    line(50 + 225 + x1 + mje1, 50 + 225 + y1 + mje2, 50 + 225 + x2 + mje1, 175 + 225 + y2 + mje2);
    line(50 + 225 + x1 + mje1, 175 + 225 + y1 + mje2, 175 + 225 + x2 + mje1, 175 + 225 + y2 + mje2);
    line(175 + 225 + x1 + mje1, 50 + 225 + y1 + mje2, 175 + 225 + x2 + mje1, 175 + 225 + y2 + mje2);
}

void AfisareFata1(int a,int b,int c,int d,int e,int f,int g,int h,int i,int selectat)
{
    setcolor(a);
    if(selectat == 111)
    {
        if(cub[1][1][1]>10)
        {
            setcolor(a-8);
            PatratFata1(0,0,0,0,0,0);
            setfillstyle(1,a-8);
            floodfill(70,100,a-8);

        }
        else
        {
            setcolor(a+8);
            PatratFata1(0,0,0,0,0,0);
            setfillstyle(1,a+8);
            floodfill(70,100,a+8);
        }
    }
    else
    {
        PatratFata1(0,0,0,0,0,0);
        setfillstyle(1,a);
        floodfill(70,100,a);
    }

    setcolor(b);
    PatratFata1(75,75,75,75,3,3);
    setfillstyle(1,b);
    floodfill(145,175,b);

    setcolor(c);
    if(selectat == 131)
    {
        if(cub[1][3][1]>10)
        {
            setcolor(c-8);
            PatratFata1(150,150,150,150,6,6);
            setfillstyle(1,c-8);
            floodfill(220,250,c-8);
        }
        else
        {
            setcolor(c+8);
            PatratFata1(150,150,150,150,6,6);
            setfillstyle(1,c+8);
            floodfill(220,250,c+8);
        }
    }
    else
    {
        PatratFata1(150,150,150,150,6,6);
        setfillstyle(1,c);
        floodfill(220,250,c);
    }


    setcolor(d);
    PatratFata1(0,125,0,125,0,4);
    setfillstyle(1,d);
    floodfill(70,225,d);

    setcolor(e);
    if(selectat == 221)
    {
        if(cub[2][2][1]>10)
        {
            setcolor(e-8);
            PatratFata1(75,200,75,200,3,7);
            setfillstyle(1,e-8);
            floodfill(145,300,e-8);

        }
        else
        {
            setcolor(e+8);
            PatratFata1(75,200,75,200,3,7);
            setfillstyle(1,e+8);
            floodfill(145,300,e+8);
    }
    }
    else
    {
        PatratFata1(75,200,75,200,3,7);
        setfillstyle(1,e);
        floodfill(145,300,e);
    }

    setcolor(f);
    PatratFata1(150,275,150,275,6,10);
    setfillstyle(1,f);
    floodfill(220,375,f);


    setcolor(g);
    if(selectat == 311)
    {
        if(cub[3][1][1]>10)
        {
            setcolor(g-8);
            PatratFata1(0,250,0,250,0,8);
            setfillstyle(1,g-8);
            floodfill(70,350,g-8);
        }
        else
        {
            setcolor(g+8);
            PatratFata1(0,250,0,250,0,8);
            setfillstyle(1,g+8);
            floodfill(70,350,g+8);
        }
    }
    else
    {
        PatratFata1(0,250,0,250,0,8);
        setfillstyle(1,g);
        floodfill(70,350,g);
    }

    setcolor(h);
    PatratFata1(75,325,75,325,3,11);
    setfillstyle(1,h);
    floodfill(145,425,h);

    setcolor(i);
    if(selectat == 331)
    {
        if(cub[3][3][1]>10)
        {
            setcolor(i-8);
            PatratFata1(150,400,150,400,6,14);
            setfillstyle(1,i-8);
            floodfill(220,500,i-8);
        }
        else
        {
            setcolor(i+8);
            PatratFata1(150,400,150,400,6,14);
            setfillstyle(1,i+8);
            floodfill(220,500,i+8);
        }
    }
    else
    {
        PatratFata1(150,400,150,400,6,14);
        setfillstyle(1,i);
        floodfill(220,500,i);
    }
}

void AfisareFata2(int a,int b,int c,int d,int e,int f,int g,int h,int i,int selectat)
{
    setcolor(a);
    if(selectat == 112)
    {
        if(cub[1][1][2]>10)
        {
            setcolor(a-8);
            PatratFata2(0,0,0,0,4,-2);
            setfillstyle(1,a-8);
            floodfill(100,70,a-8);
        }
        else
        {
            setcolor(a+8);
            PatratFata2(0,0,0,0,4,-2);
            setfillstyle(1,a+8);
            floodfill(100,70,a+8);
        }
    }
    else
    {
        PatratFata2(0,0,0,0,4,-2);
        setfillstyle(1,a);
        floodfill(100,70,a);
    }

    setcolor(b);
    PatratFata2(125,0,125,0,8,-2);
    setfillstyle(1,b);
    floodfill(225,70,b);

    setcolor(c);
    if(selectat == 132)
    {
        if(cub[1][3][2]>10)
        {
            setcolor(c-8);
            PatratFata2(250,0,250,0,12,-2);
            setfillstyle(1,c-8);
            floodfill(350,70,c-8);
        }
        else
        {
            setcolor(c+8);
            PatratFata2(250,0,250,0,12,-2);
            setfillstyle(1,c+8);
            floodfill(350,70,c+8);
        }
    }
    else
    {
        PatratFata2(250,0,250,0,12,-2);
        setfillstyle(1,c);
        floodfill(350,70,c);
    }


    setcolor(d);
    PatratFata2(75,75,75,75,7,1);
    setfillstyle(1,d);
    floodfill(175,145,d);

    setcolor(e);
    if(selectat == 222)
    {
        if(cub[2][2][2]>10)
        {
            setcolor(e-8);
            PatratFata2(200,75,200,75,10,1);
            setfillstyle(1,e-8);
            floodfill(300,145,e-8);
        }
        else
        {
            setcolor(e+8);
            PatratFata2(200,75,200,75,10,1);
            setfillstyle(1,e+8);
            floodfill(300,145,e+8);
        }
    }
    else
    {
        PatratFata2(200,75,200,75,10,1);
        setfillstyle(1,e);
        floodfill(300,145,e);
    }

    setcolor(f);
    PatratFata2(325,75,325,75,14,1);
    setfillstyle(1,f);
    floodfill(425,145,f);


    setcolor(g);
    if(selectat == 312)
    {
        if(cub[3][1][2]>10)
        {
            setcolor(g-8);
            PatratFata2(150,150,150,150,10,4);
            setfillstyle(1,g-8);
            floodfill(250,220,g-8);
        }
        else
        {
            setcolor(g+8);
            PatratFata2(150,150,150,150,10,4);
            setfillstyle(1,g+8);
            floodfill(250,220,g+8);
        }
    }
    else
    {
        PatratFata2(150,150,150,150,10,4);
        setfillstyle(1,g);
        floodfill(250,220,g);
    }

    setcolor(h);
    PatratFata2(275,150,275,150,13,4);
    setfillstyle(1,h);
    floodfill(375,220,h);

    setcolor(i);
    if(selectat == 332)
    {
        if(cub[3][3][2]>10)
        {
            setcolor(i-8);
            PatratFata2(400,150,400,150,17,4);
            setfillstyle(1,i-8);
            floodfill(500,220,i-8);
        }
        else
        {
            setcolor(i+8);
            PatratFata2(400,150,400,150,17,4);
            setfillstyle(1,i+8);
            floodfill(500,220,i+8);
        }
    }
    else
    {
        PatratFata2(400,150,400,150,17,4);
        setfillstyle(1,i);
        floodfill(500,220,i);
    }
}

void AfisareFata3(int a,int b,int c,int d,int e,int f,int g,int h,int i,int selectat)
{
    setcolor(a);
    if(selectat == 113)
    {
        if(cub[1][1][3]>10)
        {
            setcolor(a-8);
            PatratFata3(0,0,0,0,10,7);
            setfillstyle(1,a-8);
            floodfill(350,350,a-8);
        }
        else
        {
            setcolor(a+8);
            PatratFata3(0,0,0,0,10,7);
            setfillstyle(1,a+8);
            floodfill(350,350,a+8);
        }
    }
    else
    {
        PatratFata3(0,0,0,0,10,7);
        setfillstyle(1,a);
        floodfill(350,350,a);
    }

    setcolor(b);
    PatratFata3(125,0,125,0,13,7);
    setfillstyle(1,b);
    floodfill(475,350,b);

    setcolor(c);
    if(selectat == 133)
    {
        if(cub[1][3][3]>10)
        {
            setcolor(c-8);
            PatratFata3(250,0,250,0,16,7);
            setfillstyle(1,c-8);
            floodfill(600,350,c-8);
        }
        else
        {
            setcolor(c+8);
            PatratFata3(250,0,250,0,16,7);
            setfillstyle(1,c+8);
            floodfill(600,350,c+8);
        }
    }
    else
    {
        PatratFata3(250,0,250,0,16,7);
        setfillstyle(1,c);
        floodfill(600,350,c);
    }


    setcolor(d);
    PatratFata3(0,125,0,125,10,10);
    setfillstyle(1,d);
    floodfill(350,475,d);

    setcolor(e);
    if(selectat == 223)
    {
        if(cub[2][2][3]>10)
        {
            setcolor(e-8);
            PatratFata3(125,125,125,125,13,10);
            setfillstyle(1,e-8);
            floodfill(475,475,e-8);
        }
        else
        {
            setcolor(e+8);
            PatratFata3(125,125,125,125,13,10);
            setfillstyle(1,e+8);
            floodfill(475,475,e+8);
        }
    }
    else
    {
        PatratFata3(125,125,125,125,13,10);
        setfillstyle(1,e);
        floodfill(475,475,e);
    }

    setcolor(f);
    PatratFata3(250,125,250,125,16,10);
    setfillstyle(1,f);
    floodfill(600,475,f);


    setcolor(g);
    if(selectat == 313)
    {
        if(cub[3][1][3]>10)
        {
            setcolor(g-8);
            PatratFata3(0,250,0,250,10,13);
            setfillstyle(1,g-8);
            floodfill(350,600,g-8);
        }
        else
        {
            setcolor(g+8);
            PatratFata3(0,250,0,250,10,13);
            setfillstyle(1,g+8);
            floodfill(350,600,g+8);
        }
    }
    else
    {
        PatratFata3(0,250,0,250,10,13);
        setfillstyle(1,g);
        floodfill(350,600,g);
    }

    setcolor(h);
    PatratFata3(125,250,125,250,13,13);
    setfillstyle(1,h);
    floodfill(475,600,h);

    setcolor(i);
    if(selectat == 333)
    {
        if(cub[3][3][3]>10)
        {
            setcolor(i-8);
            PatratFata3(250,250,250,250,16,13);
            setfillstyle(1,i-8);
            floodfill(600,600,i-8);
        }
        else
        {
            setcolor(i+8);
            PatratFata3(250,250,250,250,16,13);
            setfillstyle(1,i+8);
            floodfill(600,600,i+8);
        }
    }
    else
    {
        PatratFata3(250,250,250,250,16,13);
        setfillstyle(1,i);
        floodfill(600,600,i);
    }
}

void Li()//a
{
    int       a1=cub[1][1][2],           a2=cub[2][1][2],           a3=cub[3][1][2];//a
    cub[1][1][2]=cub[1][1][3]; cub[2][1][2]=cub[2][1][3]; cub[3][1][2]=cub[3][1][3];//a
    cub[1][1][3]=cub[1][1][5]; cub[2][1][3]=cub[2][1][5]; cub[3][1][3]=cub[3][1][5];//a
    cub[1][1][5]=cub[3][1][4]; cub[2][1][5]=cub[2][1][4]; cub[3][1][5]=cub[1][1][4];//a
    cub[3][1][4]=a1;           cub[2][1][4]=a2;           cub[1][1][4]=a3;//a

    a1=cub[1][1][1];
    cub[1][1][1]=cub[1][3][1];
    cub[1][3][1]=cub[3][3][1];
    cub[3][3][1]=cub[3][1][1];
    cub[3][1][1]=a1;

    a1=cub[1][2][1];
    cub[1][2][1]=cub[2][3][1];
    cub[2][3][1]=cub[3][2][1];
    cub[3][2][1]=cub[2][1][1];
    cub[2][1][1]=a1;
}

void L()//a
{
    int       a1=cub[1][1][2],           a2=cub[2][1][2],           a3=cub[3][1][2];
    cub[1][1][2]=cub[3][1][4]; cub[2][1][2]=cub[2][1][4]; cub[3][1][2]=cub[1][1][4];
    cub[1][1][4]=cub[3][1][5]; cub[2][1][4]=cub[2][1][5]; cub[3][1][4]=cub[1][1][5];
    cub[1][1][5]=cub[1][1][3]; cub[2][1][5]=cub[2][1][3]; cub[3][1][5]=cub[3][1][3];
    cub[1][1][3]=a1;           cub[2][1][3]=a2;           cub[3][1][3]=a3;

    a1=cub[1][1][1];
    cub[1][1][1]=cub[3][1][1];
    cub[3][1][1]=cub[3][3][1];
    cub[3][3][1]=cub[1][3][1];
    cub[1][3][1]=a1;

    a1=cub[1][2][1];
    cub[1][2][1]=cub[2][1][1];
    cub[2][1][1]=cub[3][2][1];
    cub[3][2][1]=cub[2][3][1];
    cub[2][3][1]=a1;
}

void Ri()//a
{
    int       a1=cub[1][3][2],           a2=cub[2][3][2],           a3=cub[3][3][2];//a
    cub[1][3][2]=cub[3][3][4]; cub[2][3][2]=cub[2][3][4]; cub[3][3][2]=cub[1][3][4];//a
    cub[1][3][4]=cub[3][3][5]; cub[2][3][4]=cub[2][3][5]; cub[3][3][4]=cub[1][3][5];//a
    cub[1][3][5]=cub[1][3][3]; cub[2][3][5]=cub[2][3][3]; cub[3][3][5]=cub[3][3][3];//a
    cub[1][3][3]=a1;           cub[2][3][3]=a2;           cub[3][3][3]=a3;

    a1=cub[1][1][6];
    cub[1][1][6]=cub[1][3][6];
    cub[1][3][6]=cub[3][3][6];
    cub[3][3][6]=cub[3][1][6];
    cub[3][1][6]=a1;

    a1=cub[1][2][6];
    cub[1][2][6]=cub[2][3][6];
    cub[2][3][6]=cub[3][2][6];
    cub[3][2][6]=cub[2][1][6];
    cub[2][1][6]=a1;
}

void R()//a
{
    int       a1=cub[1][3][2],           a2=cub[2][3][2],           a3=cub[3][3][2];//a
    cub[1][3][2]=cub[1][3][3]; cub[2][3][2]=cub[2][3][3]; cub[3][3][2]=cub[3][3][3];//a
    cub[1][3][3]=cub[1][3][5]; cub[2][3][3]=cub[2][3][5]; cub[3][3][3]=cub[3][3][5];//a
    cub[1][3][5]=cub[3][3][4]; cub[2][3][5]=cub[2][3][4]; cub[3][3][5]=cub[1][3][4];//a
    cub[1][3][4]=a3;           cub[2][3][4]=a2;           cub[3][3][4]=a1;

    a1=cub[1][1][6];
    cub[1][1][6]=cub[3][1][6];
    cub[3][1][6]=cub[3][3][6];
    cub[3][3][6]=cub[1][3][6];
    cub[1][3][6]=a1;

    a1=cub[1][2][6];
    cub[1][2][6]=cub[2][1][6];
    cub[2][1][6]=cub[3][2][6];
    cub[3][2][6]=cub[2][3][6];
    cub[2][3][6]=a1;
}

void U()//a
{
    int       a1=cub[1][1][1],           a2=cub[1][2][1],           a3=cub[1][3][1];
    cub[1][1][1]=cub[1][1][3]; cub[1][2][1]=cub[1][2][3]; cub[1][3][1]=cub[1][3][3];
    cub[1][1][3]=cub[1][1][6]; cub[1][2][3]=cub[1][2][6]; cub[1][3][3]=cub[1][3][6];
    cub[1][1][6]=cub[1][3][4]; cub[1][2][6]=cub[1][2][4]; cub[1][3][6]=cub[1][1][4];
    cub[1][1][4]=a3;           cub[1][2][4]=a2;           cub[1][3][4]=a1;

    a1=cub[1][1][2];
    cub[1][1][2]=cub[3][1][2];
    cub[3][1][2]=cub[3][3][2];
    cub[3][3][2]=cub[1][3][2];
    cub[1][3][2]=a1;

    a1=cub[1][2][2];
    cub[1][2][2]=cub[2][1][2];
    cub[2][1][2]=cub[3][2][2];
    cub[3][2][2]=cub[2][3][2];
    cub[2][3][2]=a1;
}

void Ui()//a
{
    int       a1=cub[1][1][1],           a2=cub[1][2][1],           a3=cub[1][3][1];//a
    cub[1][1][1]=cub[1][3][4]; cub[1][2][1]=cub[1][2][4]; cub[1][3][1]=cub[1][1][4];//a
    cub[1][1][4]=cub[1][3][6]; cub[1][2][4]=cub[1][2][6]; cub[1][3][4]=cub[1][1][6];//a
    cub[1][1][6]=cub[1][1][3]; cub[1][2][6]=cub[1][2][3]; cub[1][3][6]=cub[1][3][3];//a
    cub[1][1][3]=a1;           cub[1][2][3]=a2;           cub[1][3][3]=a3;//a

    a1=cub[1][1][2];
    cub[1][1][2]=cub[1][3][2];
    cub[1][3][2]=cub[3][3][2];
    cub[3][3][2]=cub[3][1][2];
    cub[3][1][2]=a1;

    a1=cub[1][2][2];
    cub[1][2][2]=cub[2][3][2];
    cub[2][3][2]=cub[3][2][2];
    cub[3][2][2]=cub[2][1][2];
    cub[2][1][2]=a1;
}

void D()//a
{
    int       a1=cub[3][1][1],           a2=cub[3][2][1],           a3=cub[3][3][1];//a
    cub[3][1][1]=cub[3][3][4]; cub[3][2][1]=cub[3][2][4]; cub[3][3][1]=cub[3][1][4];//a
    cub[3][3][4]=cub[3][1][6]; cub[3][2][4]=cub[3][2][6]; cub[3][1][4]=cub[3][3][6];//a
    cub[3][1][6]=cub[3][1][3]; cub[3][2][6]=cub[3][2][3]; cub[3][3][6]=cub[3][3][3];//a
    cub[3][1][3]=a1;           cub[3][2][3]=a2;           cub[3][3][3]=a3;//a

    a1=cub[1][1][5];
    cub[1][1][5]=cub[3][1][5];
    cub[3][1][5]=cub[3][3][5];
    cub[3][3][5]=cub[1][3][5];
    cub[1][3][5]=a1;

    a1=cub[1][2][5];
    cub[1][2][5]=cub[2][1][5];
    cub[2][1][5]=cub[3][2][5];
    cub[3][2][5]=cub[2][3][5];
    cub[2][3][5]=a1;
}

void Di()//a
{
    int       a1=cub[3][1][1],           a2=cub[3][2][1],           a3=cub[3][3][1];//a
    cub[3][1][1]=cub[3][1][3]; cub[3][2][1]=cub[3][2][3]; cub[3][3][1]=cub[3][3][3];//a
    cub[3][1][3]=cub[3][1][6]; cub[3][2][3]=cub[3][2][6]; cub[3][3][3]=cub[3][3][6];
    cub[3][1][6]=cub[3][3][4]; cub[3][2][6]=cub[3][2][4]; cub[3][3][6]=cub[3][1][4];//a
    cub[3][1][4]=a3;           cub[3][2][4]=a2;           cub[3][3][4]=a1;//a

    a1=cub[1][1][5];
    cub[1][1][5]=cub[1][3][5];
    cub[1][3][5]=cub[3][3][5];
    cub[3][3][5]=cub[3][1][5];
    cub[3][1][5]=a1;

    a1=cub[1][2][5];
    cub[1][2][5]=cub[2][3][5];
    cub[2][3][5]=cub[3][2][5];
    cub[3][2][5]=cub[2][1][5];
    cub[2][1][5]=a1;
}

void B()//a
{
    int       a1=cub[1][1][2],           a2=cub[1][2][2],           a3=cub[1][3][2];//a
    cub[1][1][2]=cub[1][3][6]; cub[1][2][2]=cub[2][3][6]; cub[1][3][2]=cub[3][3][6];//a
    cub[1][3][6]=cub[3][3][5]; cub[2][3][6]=cub[3][2][5]; cub[3][3][6]=cub[3][1][5];//a
    cub[3][1][5]=cub[1][1][1]; cub[3][2][5]=cub[2][1][1]; cub[3][3][5]=cub[3][1][1];//a
    cub[1][1][1]=a3;           cub[2][1][1]=a2;           cub[3][1][1]=a1;

    a1=cub[1][1][4];
    cub[1][1][4]=cub[1][3][4];
    cub[1][3][4]=cub[3][3][4];
    cub[3][3][4]=cub[3][1][4];
    cub[3][1][4]=a1;

    a1=cub[1][2][4];
    cub[1][2][4]=cub[2][3][4];
    cub[2][3][4]=cub[3][2][4];
    cub[3][2][4]=cub[2][1][4];
    cub[2][1][4]=a1;
}

void Bi()//a
{
    int       a1=cub[1][1][2],           a2=cub[1][2][2],           a3=cub[1][3][2];//a
    cub[1][1][2]=cub[3][1][1]; cub[1][2][2]=cub[2][1][1]; cub[1][3][2]=cub[1][1][1];//a
    cub[3][1][1]=cub[3][3][5]; cub[2][1][1]=cub[3][2][5]; cub[1][1][1]=cub[3][1][5];//a
    cub[3][1][5]=cub[3][3][6]; cub[3][2][5]=cub[2][3][6]; cub[3][3][5]=cub[1][3][6];//a
    cub[1][3][6]=a1;           cub[2][3][6]=a2;           cub[3][3][6]=a3;

    a1=cub[1][1][4];
    cub[1][1][4]=cub[3][1][4];
    cub[3][1][4]=cub[3][3][4];
    cub[3][3][4]=cub[1][3][4];
    cub[1][3][4]=a1;

    a1=cub[1][2][4];
    cub[1][2][4]=cub[2][1][4];
    cub[2][1][4]=cub[3][2][4];
    cub[3][2][4]=cub[2][3][4];
    cub[2][3][4]=a1;
}

void F()//a
{
    int       a1=cub[3][1][2],           a2=cub[3][2][2],           a3=cub[3][3][2];//a
    cub[3][1][2]=cub[3][3][1]; cub[3][2][2]=cub[2][3][1]; cub[3][3][2]=cub[1][3][1];//a
    cub[3][3][1]=cub[1][3][5]; cub[2][3][1]=cub[1][2][5]; cub[1][3][1]=cub[1][1][5];//a
    cub[1][3][5]=cub[1][1][6]; cub[1][2][5]=cub[2][1][6]; cub[1][1][5]=cub[3][1][6];//a
    cub[1][1][6]=a1;           cub[2][1][6]=a2;           cub[3][1][6]=a3;

    a1=cub[1][1][3];
    cub[1][1][3]=cub[3][1][3];
    cub[3][1][3]=cub[3][3][3];
    cub[3][3][3]=cub[1][3][3];
    cub[1][3][3]=a1;

    a1=cub[1][2][3];
    cub[1][2][3]=cub[2][1][3];
    cub[2][1][3]=cub[3][2][3];
    cub[3][2][3]=cub[2][3][3];
    cub[2][3][3]=a1;
}

void Fi()//a
{
    int       a1=cub[3][1][2],           a2=cub[3][2][2],           a3=cub[3][3][2];
    cub[3][1][2]=cub[1][1][6]; cub[3][2][2]=cub[2][1][6]; cub[3][3][2]=cub[3][1][6];
    cub[1][1][6]=cub[1][3][5]; cub[2][1][6]=cub[1][2][5]; cub[3][1][6]=cub[1][1][5];
    cub[1][3][5]=cub[3][3][1]; cub[1][2][5]=cub[2][3][1]; cub[1][1][5]=cub[1][3][1];
    cub[3][3][1]=a1;           cub[2][3][1]=a2;           cub[1][3][1]=a3;

    a1=cub[1][1][3];
    cub[1][1][3]=cub[1][3][3];
    cub[1][3][3]=cub[3][3][3];
    cub[3][3][3]=cub[3][1][3];
    cub[3][1][3]=a1;

    a1=cub[1][2][3];
    cub[1][2][3]=cub[2][3][3];
    cub[2][3][3]=cub[3][2][3];
    cub[3][2][3]=cub[2][1][3];
    cub[2][1][3]=a1;
}

void M()//a
{
    int       a1=cub[2][1][1],           a2=cub[2][2][1],           a3=cub[2][3][1];
    cub[2][1][1]=cub[2][1][3]; cub[2][2][1]=cub[2][2][3]; cub[2][3][1]=cub[2][3][3];
    cub[2][1][3]=cub[2][1][6]; cub[2][2][3]=cub[2][2][6]; cub[2][3][3]=cub[2][3][6];
    cub[2][1][6]=cub[2][3][4]; cub[2][2][6]=cub[2][2][4]; cub[2][3][6]=cub[2][1][4];
    cub[2][3][4]=a1;           cub[2][2][4]=a2;           cub[2][1][4]=a3;
}

void Mi()//a
{
    int       a1=cub[2][1][1],           a2=cub[2][2][1],           a3=cub[2][3][1];
    cub[2][1][1]=cub[2][3][4]; cub[2][2][1]=cub[2][2][4]; cub[2][3][1]=cub[2][1][4];
    cub[2][1][4]=cub[2][3][6]; cub[2][2][4]=cub[2][2][6]; cub[2][3][4]=cub[2][1][6];
    cub[2][1][6]=cub[2][1][3]; cub[2][2][6]=cub[2][2][3]; cub[2][3][6]=cub[2][3][3];
    cub[2][1][3]=a1;           cub[2][2][3]=a2;           cub[2][3][3]=a3;
}

void S()//a
{
    int       a1=cub[1][2][2],           a2=cub[2][2][2],           a3=cub[3][2][2];
    cub[1][2][2]=cub[1][2][3]; cub[2][2][2]=cub[2][2][3]; cub[3][2][2]=cub[3][2][3];
    cub[1][2][3]=cub[1][2][5]; cub[2][2][3]=cub[2][2][5]; cub[3][2][3]=cub[3][2][5];
    cub[1][2][5]=cub[3][2][4]; cub[2][2][5]=cub[2][2][4]; cub[3][2][5]=cub[1][2][4];
    cub[1][2][4]=a3;           cub[2][2][4]=a2;           cub[3][2][4]=a1;
}

void Si()//a
{
    int       a1=cub[1][2][2],           a2=cub[2][2][2],           a3=cub[3][2][2];
    cub[1][2][2]=cub[3][2][4]; cub[2][2][2]=cub[2][2][4]; cub[3][2][2]=cub[1][2][4];
    cub[1][2][4]=cub[3][2][5]; cub[2][2][4]=cub[2][2][5]; cub[3][2][4]=cub[1][2][5];
    cub[1][2][5]=cub[1][2][3]; cub[2][2][5]=cub[2][2][3]; cub[3][2][5]=cub[3][2][3];
    cub[1][2][3]=a1;           cub[2][2][3]=a2;           cub[3][2][3]=a3;
}

void P()//a
{
    int       a1=cub[2][1][2],           a2=cub[2][2][2],           a3=cub[2][3][2];
    cub[2][1][2]=cub[3][2][1]; cub[2][2][2]=cub[2][2][1]; cub[2][3][2]=cub[1][2][1];
    cub[3][2][1]=cub[2][3][5]; cub[2][2][1]=cub[2][2][5]; cub[1][2][1]=cub[2][1][5];
    cub[2][1][5]=cub[3][2][6]; cub[2][2][5]=cub[2][2][6]; cub[2][3][5]=cub[1][2][6];
    cub[3][2][6]=a3;           cub[2][2][6]=a2;           cub[1][2][6]=a1;
}

void Pi()//a
{
    int       a1=cub[2][1][2],           a2=cub[2][2][2],           a3=cub[2][3][2];
    cub[2][1][2]=cub[1][2][6]; cub[2][2][2]=cub[2][2][6]; cub[2][3][2]=cub[3][2][6];
    cub[1][2][6]=cub[2][3][5]; cub[2][2][6]=cub[2][2][5]; cub[3][2][6]=cub[2][1][5];
    cub[2][3][5]=cub[3][2][1]; cub[2][2][5]=cub[2][2][1]; cub[2][1][5]=cub[1][2][1];
    cub[3][2][1]=a1;           cub[2][2][1]=a2;           cub[1][2][1]=a3;
}

void paralelogram(int x1,int y1,int x2,int y2,int unghi1,int unghi2,int culoare,int fix)
{
    setcolor(culoare);
    line(x1,y1,x2,y1+unghi2);///Linia de sus
    line(x2+unghi1,y2,x1+unghi1,y2-unghi2);///Linia de jos
    line(x1,y1,x1+unghi1,y2-unghi2);///Linia din stanga
    line(x2+unghi1,y2,x2,y1+unghi2);///Linia din dreapta
    setfillstyle(1,culoare);
    floodfill((x1+x2)/2,(y1+y2)/2,culoare);

}

void MeniuButton()
{
    char text[100];
    setcolor(15);
    line(600,50,750,50);
    line(600,50,600,100);
    line(750,50,750,100);
    line(600,100,750,100);
    settextstyle(8, 0, 5);
    sprintf(text, "Meniu");
    outtextxy(610,55,text);
}

void Meniu1()
{
    paralelogram(50,50,100,250,0,50,cub[1][1][1],1);
    paralelogram(50,206,100,406,0,50,cub[2][1][1],1);
    paralelogram(50,362,100,562,0,50,cub[3][1][1],1);

    paralelogram(103,102,153,302,0,50,cub[1][2][1],1);
    paralelogram(103,258,153,458,0,50,cub[2][2][1],1);
    paralelogram(103,414,153,614,0,50,cub[3][2][1],1);

    paralelogram(156,154,206,354,0,50,cub[1][3][1],1);
    paralelogram(156,310,206,510,0,50,cub[2][3][1],1);
    paralelogram(156,466,206,666,0,50,cub[3][3][1],1);
    //*/

    paralelogram(209,205,359,355,0,0,cub[1][1][3],1);
    paralelogram(362,205,512,355,0,0,cub[1][2][3],1);
    paralelogram(515,205,665,355,0,0,cub[1][3][3],1);

    paralelogram(209,358,359,511,0,0,cub[2][1][3],1);
    paralelogram(362,358,512,511,0,0,cub[2][2][3],1);
    paralelogram(515,358,665,511,0,0,cub[2][3][3],1);

    paralelogram(209,514,359,667,0,0,cub[3][1][3],1);
    paralelogram(362,514,512,667,0,0,cub[3][2][3],1);
    paralelogram(515,514,665,667,0,0,cub[3][3][3],1);
    //*/

    paralelogram(53,47,203,97,50,0,cub[1][1][2],1);
    paralelogram(206,47,356,97,50,0,cub[1][2][2],1);
    paralelogram(359,47,509,97,50,0,cub[1][3][2],1);

    int x=3;
    paralelogram(103+x,100,253+x,150,50,0,cub[2][1][2],1);
    paralelogram(256+x,100,406+x,150,50,0,cub[2][2][2],1);
    paralelogram(409+x,100,559+x,150,50,0,cub[2][3][2],1);
    x++;

    paralelogram(153+x,153,303+x,203,50,0,cub[3][1][2],1);
    paralelogram(306+x,153,456+x,203,50,0,cub[3][2][2],1);
    paralelogram(459+x,153,612+x,203,50,0,cub[3][3][2],1);
    //*/
}

void Meniu2()
{
    int x=3,y=2;
    paralelogram(50,50,75,250,0,25,cub[1][1][1],1);
    paralelogram(50,225+x,75,425+x,0,25,cub[2][1][1],1);x+=3;
    paralelogram(50,400+x,75,600+x,0,25,cub[3][1][1],1);x=3;

    paralelogram(75+x,75+y,100+x,275+y,0,25,cub[1][2][1],1);y+=3;
    paralelogram(75+x,250+y,100+x,450+y,0,25,cub[2][2][1],1);y+=3;
    paralelogram(75+x,425+y,100+x,625+y,0,25,cub[2][2][1],1);y=3;x=6;

    paralelogram(100+x,100+y,125+x,300+y,0,25,cub[1][3][1],1);y+=3;
    paralelogram(100+x,275+y,125+x,475+y,0,25,cub[2][3][1],1);y+=3;
    paralelogram(100+x,450+y,125+x,650+y,0,25,cub[3][3][1],1);y=3;x=9;
    //*/

    paralelogram(125+x,125+y,300+x,300+y,0,0,cub[1][1][3],1);x+=3;
    paralelogram(300+x,125+y,475+x,300+y,0,0,cub[1][2][3],1);x+=3;
    paralelogram(475+x,125+y,650+x,300+y,0,0,cub[1][3][3],1);x=9;y+=3;

    paralelogram(125+x,300+y,300+x,475+y,0,0,cub[2][1][3],1);x+=3;
    paralelogram(300+x,300+y,475+x,475+y,0,0,cub[2][2][3],1);x+=3;
    paralelogram(475+x,300+y,650+x,475+y,0,0,cub[2][3][3],1);x=9;y+=3;

    paralelogram(125+x,475+y,300+x,650+y,0,0,cub[3][1][3],1);x+=3;
    paralelogram(300+x,475+y,475+x,650+y,0,0,cub[3][2][3],1);x+=3;
    paralelogram(475+x,475+y,650+x,650+y,0,0,cub[3][3][3],1);x=3;y=3;
    //*/

    paralelogram(50+x,50-y,225+x,75-y,25,0,cub[1][1][2],1);x+=3;
    paralelogram(225+x,50-y,400+x,75-y,25,0,cub[1][2][2],1);x+=3;
    paralelogram(400+x,50-y,575+x,75-y,25,0,cub[1][3][2],1);x=6;y-=3;

    paralelogram(75+x,75-y,250+x,100-y,25,0,cub[2][1][2],1);x+=3;
    paralelogram(250+x,75-y,425+x,100-y,25,0,cub[2][2][2],1);x+=3;
    paralelogram(425+x,75-y,600+x,100-y,25,0,cub[2][3][2],1);x=9;y-=3;

    paralelogram(100+x,100-y,275+x,125-y,25,0,cub[3][1][2],1);x+=3;
    paralelogram(275+x,100-y,450+x,125-y,25,0,cub[3][2][2],1);x+=3;
    paralelogram(450+x,100-y,625+x,125-y,25,0,cub[3][3][2],1);x=3;y=3;
    //*/
}

void Meniu3()
{
    int x=3,y=-8;
    paralelogram(50,50,65,250,0,12,cub[1][1][1],1);
    paralelogram(50,250+y,65,450+y,0,12,cub[2][1][1],1);y+=42;
    paralelogram(50,400+y,65,600+y,0,12,cub[3][1][1],1);y=-12;

    paralelogram(65+x,75+y,80+x,275+y,0,12,cub[1][2][1],1);y+=17;
    paralelogram(65+x,250+y,80+x,450+y,0,12,cub[2][2][1],1);y+=17;
    paralelogram(65+x,425+y,80+x,625+y,0,12,cub[3][2][1],1);y=-24;x+=3;

    paralelogram(80+x,100+y,95+x,300+y,0,12,cub[1][3][1],1);y+=17;
    paralelogram(80+x,275+y,95+x,475+y,0,12,cub[2][3][1],1);y+=17;
    paralelogram(80+x,450+y,95+x,650+y,0,12,cub[3][3][1],1);y=-12;x=3;
    //*/

    paralelogram(100+x,100+y,300+x,300+y*2,0,0,cub[1][1][3],1);x+=3;
    paralelogram(300+x,100+y,500+x,300+y*2,0,0,cub[1][2][3],1);x+=3;
    paralelogram(500+x,100+y,700+x,300+y*2,0,0,cub[1][3][3],1);x=3;y-=9;

    paralelogram(100+x,300+y,300+x,500+y*2+11,0,0,cub[2][1][3],1);x+=3;
    paralelogram(300+x,300+y,500+x,500+y*2+11,0,0,cub[2][2][3],1);x+=3;
    paralelogram(500+x,300+y,700+x,500+y*2+11,0,0,cub[2][3][3],1);x=3;y-=6;

    paralelogram(100+x,500+y-1,300+x,700+y-11,0,0,cub[3][1][3],1);x+=3;
    paralelogram(300+x,500+y-1,500+x,700+y-11,0,0,cub[3][2][3],1);x+=3;
    paralelogram(500+x,500+y-1,700+x,700+y-11,0,0,cub[3][3][3],1);x=2;y=2;
    //*/

    paralelogram(50+x,50-y,250+x,62-y,15,0,cub[1][1][2],1);x+=3;
    paralelogram(250+x,50-y,450+x,62-y,15,0,cub[1][2][2],1);x+=3;
    paralelogram(450+x,50-y,650+x,62-y,15,0,cub[1][3][2],1);x=9;y-=2;

    paralelogram(62+x,62-y,262+x,75-y,17,0,cub[2][1][2],1);x+=3;
    paralelogram(262+x,62-y,462+x,75-y,17,0,cub[2][2][2],1);x+=3;
    paralelogram(462+x,62-y,662+x,75-y,17,0,cub[2][3][2],1);x=15;y-=2;

    paralelogram(75+x,75-y,275+x,84-y,12,0,cub[3][1][2],1);x+=3;
    paralelogram(275+x,75-y,475+x,84-y,12,0,cub[3][2][2],1);x+=3;
    paralelogram(475+x,75-y,675+x,84-y,12,0,cub[3][3][2],1);
    //*/
}

void Meniu4()
{
    int x=3,y=3;

    paralelogram(50,50,300,300,0,0,cub[1][1][3],1);
    paralelogram(300+x,50,550+x,300,0,0,cub[1][2][3],1);x+=3;
    paralelogram(550+x,50,800+x,300,0,0,cub[1][3][3],1);x=3;

    paralelogram(50,300+y,300,550+y,0,0,cub[2][1][3],1);
    paralelogram(300+x,300+y,550+x,550+y,0,0,cub[2][2][3],1);x+=3;
    paralelogram(550+x,300+y,800+x,550+y,0,0,cub[2][3][3],1);x=3;y+=3;

    paralelogram(50,550+y,300,800+y,0,0,cub[3][1][3],1);
    paralelogram(300+x,550+y,550+x,800+y,0,0,cub[3][2][3],1);x+=3;
    paralelogram(550+x,550+y,800+x,800+y,0,0,cub[3][3][3],1);
    //*/

    char text[100];
    settextstyle(8, 0, 5);
    sprintf(text, "Continua");
    outtextxy(580,(550+x+750+x)/2,text);

    sprintf(text, "Amesteca");
    outtextxy(70,(50+250)/2,text);


    sprintf(text, "Rezolva");
    outtextxy(338,(50+250)/2,text);
}

void Amesteca()
{
    int ultim=-1;
    char mutari[12] = {'f','F','u','U','b','B','l','L','d','D','r','R'};

    random_shuffle(mutari,mutari+12);
    srand ( time(NULL) );

    for(int i=1;i<=25;i++)
    {
        int lit = rand() % 12;
        while((mutari[lit]==ultim-32&&ultim>90)||(mutari[lit]==ultim+32&&ultim<90))
        {
            random_shuffle(mutari,mutari+12);
            srand(time(NULL));
            lit=rand()%12;
        }
        ultim = mutari[lit];
    if(mutari[lit]=='f')  {F();}
    if(mutari[lit]=='F')  {Fi();}
    if(mutari[lit]=='u')  {U();}
    if(mutari[lit]=='U')  {Ui();}
    if(mutari[lit]=='b')  {B();}
    if(mutari[lit]=='B')  {Bi();}
    if(mutari[lit]=='l')  {L();}
    if(mutari[lit]=='L')  {Li();}
    if(mutari[lit]=='d')  {D();}
    if(mutari[lit]=='D')  {Di();}
    if(mutari[lit]=='r')  {R();}
    if(mutari[lit]=='R')  {Ri();}
    cout<<mutari[lit]<<" ";
    }
}

struct culori
{
    int pozx;
    int pozy;
    int fata;
};

struct mijloace
{
    int x;
    int y;
    int fata;
};

struct mijloacePeBune
{
    int x;
    int y;
    int fata1;
    int fata2;
};

struct colturiAlbe
{
    int x;
    int y;
    int mijloc;
    int culoare;
};

culori mijloaceCentre[100],mijlocAlb;
mijloace traducere[4][4][16];
colturiAlbe traducereColturi[4][4][16][3],coltAlb,listaNeagraColturi[100];
mijloacePeBune mijloc;

int v[7]={0,2,1,3,6,4,5};
int nrcc,nrcpc;
int nrc;
int nr=1,cf=1,max4,ok;

int vajut[5]={0,1,4,6,3};

int coltVajut[5]={0,1,4,6,3};

int colty1[5]={0,1,1,1,3};

int colty2[5]={0,3,3,3,1};

int coltf[5]={0,1,3,6,4};


int vajutx[5]={0,2,1,2,3};
int vajuty[5]={0,1,2,3,2};

int vajutx1[5]={0,1,2,3,2};
int vajuty1[5]={0,2,3,2,1};

int vajutx3[5]={0,1,2,3,2};
int vajuty3[5]={0,2,3,2,1};

int coltVajutx[5]={0,1,1,3,3};
int coltVajuty[5]={0,1,3,3,1};

int nrajut,nrajutx,nrajuty,fata,centruFata,culoareFata,rezolvat[4][4];

void CautaUrmatorulAlb()
{
    bool amGasit=false;
    for(int k=1;k<=6&&amGasit==false;k++)
        {
            for(int i=1;i<=3&&amGasit==false;i++)
            {
                for(int j=1;j<=3&&amGasit==false;j++)
                {
                    if((i+j)%2==1)
                    {
                        if(cub[i][j][v[k]]==15)
                        {
                            bool aMaiFost=true;
                            if(v[k]==5)
                            {
                                int val1=0;

                                for(int o=1;o<=4;o++)
                                {
                                    if(i==vajutx[o] && j==vajuty[o])
                                    {
                                        val1=o;
                                        break;
                                    }
                                }

                                if(val1==1)
                                    fata=1;
                                if(val1==2)
                                    fata=3;
                                if(val1==3)
                                    fata=6;
                                if(val1==4)
                                    fata=4;

                                centruFata = cub[traducere[i][j][15].x][traducere[i][j][15].y][fata];

                                if(centruFata==1)///Albastru
                                    centruFata=4;///Codul fetei lui albastru
                                else
                                if(centruFata==2)///Verde
                                    centruFata=3;///Codul fetei lui verde
                                else
                                if(centruFata==4)///Rosu
                                    centruFata=1;///Codul fetei lui rosu
                                else
                                if(centruFata==5)///Mov
                                    centruFata=6;///Codul fetei lui mov
                                if(centruFata==fata)
                                    aMaiFost=false;
                            }
                            for(int p=1;p<=nrcc;p++)
                            {
                                if(mijloaceCentre[p].fata==v[k]&&mijloaceCentre[p].pozx==i&&mijloaceCentre[p].pozy==j)
                                    aMaiFost=false;
                            }
                            if(aMaiFost==true)
                            {
                                mijlocAlb.fata=v[k];
                                mijlocAlb.pozx=i;
                                mijlocAlb.pozy=j;
                                amGasit=true;

                                nrcc++;
                                mijloaceCentre[nrcc].fata=v[k];
                                mijloaceCentre[nrcc].pozx=i;
                                mijloaceCentre[nrcc].pozy=j;
                            }
                        }
                    }
                }
            }
        }
        if(amGasit==false)
        {
            mijlocAlb.fata=69;
        }
}

int tradusFata(int kapa)
{
    if(kapa == 1)
        return 4;
    else
    if(kapa == 2)
        return 3;
    else
    if(kapa == 4)
        return 1;
    else
    if(kapa == 5)
        return 6;
    else
    if(kapa == 15)
        return 5;
    else
    if(kapa == 14)
        return 2;
}

void Updateaza()
{
    traducereColturi[1][1][14][1].culoare=cub[1][1][4];
    traducereColturi[1][1][14][2].culoare=cub[1][1][1];
    traducereColturi[3][1][14][1].culoare=cub[1][3][1];
    traducereColturi[3][1][14][2].culoare=cub[1][1][3];
    traducereColturi[3][3][14][1].culoare=cub[1][3][3];
    traducereColturi[3][3][14][2].culoare=cub[1][1][6];
    traducereColturi[1][3][14][1].culoare=cub[1][3][6];
    traducereColturi[1][3][14][2].culoare=cub[1][3][4];


    traducereColturi[1][1][4][1].culoare=cub[1][1][2];
    traducereColturi[1][1][4][2].culoare=cub[1][1][4];
    traducereColturi[3][1][4][1].culoare=cub[3][1][5];
    traducereColturi[3][1][4][2].culoare=cub[3][1][4];
    traducereColturi[3][3][4][1].culoare=cub[1][1][5];
    traducereColturi[3][3][4][2].culoare=cub[3][1][3];
    traducereColturi[1][3][4][1].culoare=cub[3][1][2];
    traducereColturi[1][3][4][2].culoare=cub[1][1][3];


    traducereColturi[1][1][2][1].culoare=cub[3][1][2];
    traducereColturi[1][1][2][2].culoare=cub[1][3][1];
    traducereColturi[3][1][2][1].culoare=cub[1][1][5];
    traducereColturi[3][1][2][2].culoare=cub[3][3][1];
    traducereColturi[3][3][2][1].culoare=cub[1][3][5];
    traducereColturi[3][3][2][2].culoare=cub[3][1][6];
    traducereColturi[1][3][2][1].culoare=cub[3][3][2];
    traducereColturi[1][3][2][2].culoare=cub[1][1][6];


    traducereColturi[1][1][5][1].culoare=cub[3][3][2];
    traducereColturi[1][1][5][2].culoare=cub[1][3][3];
    traducereColturi[3][1][5][1].culoare=cub[1][3][5];
    traducereColturi[3][1][5][2].culoare=cub[3][3][3];
    traducereColturi[3][3][5][1].culoare=cub[3][3][5];
    traducereColturi[3][3][5][2].culoare=cub[3][3][4];
    traducereColturi[1][3][5][1].culoare=cub[1][3][2];
    traducereColturi[1][3][5][2].culoare=cub[1][3][4];


    traducereColturi[1][1][1][1].culoare=cub[1][1][2];
    traducereColturi[1][1][1][2].culoare=cub[1][1][1];
    traducereColturi[3][1][1][1].culoare=cub[3][1][5];
    traducereColturi[3][1][1][2].culoare=cub[3][1][1];
    traducereColturi[3][3][1][1].culoare=cub[3][3][5];
    traducereColturi[3][3][1][2].culoare=cub[3][3][6];
    traducereColturi[1][3][1][1].culoare=cub[1][3][2];
    traducereColturi[1][3][1][2].culoare=cub[1][3][6];


    traducereColturi[1][1][15][1].culoare=cub[3][1][3];
    traducereColturi[1][1][15][2].culoare=cub[3][3][1];
    traducereColturi[3][1][15][1].culoare=cub[3][1][1];
    traducereColturi[3][1][15][2].culoare=cub[3][1][4];
    traducereColturi[3][3][15][1].culoare=cub[3][3][4];
    traducereColturi[3][3][15][2].culoare=cub[3][3][6];
    traducereColturi[1][3][15][1].culoare=cub[3][1][6];
    traducereColturi[1][3][15][2].culoare=cub[3][3][3];
}

void Afisam(int timp)
{
    MeniuButton();
    AfisareFata1(cub[1][1][1],cub[1][2][1],cub[1][3][1],cub[2][1][1],cub[2][2][1],cub[2][3][1],cub[3][1][1],cub[3][2][1],cub[3][3][1],pselectat);
    AfisareFata2(cub[1][1][2],cub[1][2][2],cub[1][3][2],cub[2][1][2],cub[2][2][2],cub[2][3][2],cub[3][1][2],cub[3][2][2],cub[3][3][2],pselectat);
    AfisareFata3(cub[1][1][3],cub[1][2][3],cub[1][3][3],cub[2][1][3],cub[2][2][3],cub[2][3][3],cub[3][1][3],cub[3][2][3],cub[3][3][3],pselectat);
    delay(timp);
}

void PotrivesteSus(culori mijloc)
{
    int val1=0,val2=0,max4=0;

    for(int i=1;i<=4;i++)
    {
        if(mijloc.pozx==vajutx[i] && mijloc.pozy==vajuty[i])
        {
            val1=i;
            break;
        }
    }

    if(val1==1)
        fata=1;
    if(val1==2)
        fata=4;
    if(val1==3)
        fata=6;
    if(val1==4)
        fata=3;

    ///CentruFata -> Idealul nostru'n viata (fata unde tre' sa ajungem)
    ///Fata -> Codul fetei deasupra mijlocului care se misca

    centruFata = cub[traducere[mijloc.pozx][mijloc.pozy][14].x][traducere[mijloc.pozx][mijloc.pozy][14].y][fata];

    if(centruFata==1)///Albastru
        centruFata=4;///Codul fetei lui albastru
    else
    if(centruFata==2)///Verde
        centruFata=3;///Codul fetei lui verde
    else
    if(centruFata==4)///Rosu
        centruFata=1;///Codul fetei lui rosu
    else
    if(centruFata==5)///Mov
        centruFata=6;///Codul fetei lui mov
    //*/

    for(int i=1;i<=4;i++)
    {
        if(fata==vajut[i])///Daca codul fetei de unde plecam este egal cu o pozitie din vajut salvam pozitia
        {
            val2=i;
            break;
        }
    }
    //cout<<centruFata<<" "<<fata<<endl;
    //cout<<endl;
    while(centruFata!=fata&&max4<=9)
    {
        U();///Miscam vizual

        fata=vajut[val2];
        mijloc.pozx = vajutx[val1];
        mijloc.pozy = vajuty[val1];

        val2++;
        val1++;

        if(val1>4)
        {
            val1=1;
        }
        if(val2>4)
        {
            val2=1;
        }

        //cout<<centruFata<<" "<<fata<<endl;
        MeniuButton();
        AfisareFata1(cub[1][1][1],cub[1][2][1],cub[1][3][1],cub[2][1][1],cub[2][2][1],cub[2][3][1],cub[3][1][1],cub[3][2][1],cub[3][3][1],pselectat);
        AfisareFata2(cub[1][1][2],cub[1][2][2],cub[1][3][2],cub[2][1][2],cub[2][2][2],cub[2][3][2],cub[3][1][2],cub[3][2][2],cub[3][3][2],pselectat);
        AfisareFata3(cub[1][1][3],cub[1][2][3],cub[1][3][3],cub[2][1][3],cub[2][2][3],cub[2][3][3],cub[3][1][3],cub[3][2][3],cub[3][3][3],pselectat);
        delay(300);
        cleardevice();
        max4++;
    }
    if(centruFata==fata&&max4!=0)
    {
        Ui();
        val1--;
        if(val1<1)
        {
            val1=4;
        }
        mijloc.pozx = vajutx[val1];
        mijloc.pozy = vajuty[val1];
        MeniuButton();
        AfisareFata1(cub[1][1][1],cub[1][2][1],cub[1][3][1],cub[2][1][1],cub[2][2][1],cub[2][3][1],cub[3][1][1],cub[3][2][1],cub[3][3][1],pselectat);
        AfisareFata2(cub[1][1][2],cub[1][2][2],cub[1][3][2],cub[2][1][2],cub[2][2][2],cub[2][3][2],cub[3][1][2],cub[3][2][2],cub[3][3][2],pselectat);
        AfisareFata3(cub[1][1][3],cub[1][2][3],cub[1][3][3],cub[2][1][3],cub[2][2][3],cub[2][3][3],cub[3][1][3],cub[3][2][3],cub[3][3][3],pselectat);
        delay(300);
        cleardevice();
    }
    if(mijloc.pozx==1&&mijloc.pozy==2)
        rezolvat[3][2]==1;
    if(mijloc.pozx==2&&mijloc.pozy==3)
        rezolvat[2][3]==1;
    if(mijloc.pozx==3&&mijloc.pozy==2)
        rezolvat[1][2]==1;
    if(mijloc.pozx==2&&mijloc.pozy==1)
        rezolvat[2][1]==1;
    if(fata==1)
    {
        L(),L();
    }
    else
    if(fata==3)
        F(),F();
    else
    if(fata==6)
        R(),R();
    else
    if(fata==4)
        B(),B();
    MeniuButton();
    AfisareFata1(cub[1][1][1],cub[1][2][1],cub[1][3][1],cub[2][1][1],cub[2][2][1],cub[2][3][1],cub[3][1][1],cub[3][2][1],cub[3][3][1],pselectat);
    AfisareFata2(cub[1][1][2],cub[1][2][2],cub[1][3][2],cub[2][1][2],cub[2][2][2],cub[2][3][2],cub[3][1][2],cub[3][2][2],cub[3][3][2],pselectat);
    AfisareFata3(cub[1][1][3],cub[1][2][3],cub[1][3][3],cub[2][1][3],cub[2][2][3],cub[2][3][3],cub[3][1][3],cub[3][2][3],cub[3][3][3],pselectat);
    delay(300);
    cleardevice();
    //cout<<mijloc.pozx<<" "<<mijloc.pozy<<" "<<mijloc.fata<<" "<<cub[mijloc.pozx][mijloc.pozy][mijloc.fata]<<endl;
}

void PotrivesteColt(colturiAlbe colt)
{
    int k,k1,k2;
    for(int i=1;i<=4;i++)
    {
        if(colt.x==coltVajutx[i]&&colt.y==coltVajuty[i])
        {
            k1=i;
            break;
        }
    }

    for(int i=1;i<=4;i++)
    {
        if((traducereColturi[colt.x][colt.y][14][2].mijloc==coltVajut[i]&&traducereColturi[colt.x][colt.y][14][1].mijloc==coltVajut[i%4+1])||
            (traducereColturi[colt.x][colt.y][14][2].mijloc==coltVajut[i%4+1]&&traducereColturi[colt.x][colt.y][14][1].mijloc==coltVajut[i]))
        {
            k=i;
            break;
        }
    }

    k2=k+1;
    if(k2>4)
        k2=1;
    Updateaza();

    int ideal1=tradusFata(traducereColturi[colt.x][colt.y][14][1].culoare);
    int ideal2=tradusFata(traducereColturi[colt.x][colt.y][14][2].culoare);
    while(max4<9&&(coltVajut[k]!=ideal1&coltVajut[k2]!=ideal2))
    {
        colt.x=coltVajutx[k1];
        colt.y=coltVajuty[k1];
        U();
        k++;k1++;
        k2++;
        if(k>4)
            k=1;
        if(k2>4)
            k2=1;
        if(k1>4)
            k1=1;
        max4++;
        Afisam(300);
        //cout<<"Potriveste :"<<endl;
        //cout<<"x = "<<colt.x<<"  y = "<<colt.y<<endl;
        //cout<<"f1 = "<<coltVajut[k]<<"  f2 = "<<coltVajut[k2]<<endl<<endl;
    }
    colt.x=coltVajutx[k1];
    colt.y=coltVajuty[k1];
    //cout<<"Potrivit :"<<endl;
    //cout<<"x = "<<colt.x<<"  y = "<<colt.y<<endl;
    //cout<<"f1 = "<<coltVajut[k]<<"  f2 = "<<coltVajut[k2]<<endl<<endl;
    if(colt.x==1&&colt.y==1)
    {
        Ui();
        Afisam(300);
        Bi();
        Afisam(300);
        U();
        Afisam(300);
        U();
        Afisam(300);
        B();
        Afisam(300);
        Ui();
        Afisam(300);
        Bi();
        Afisam(300);
        U();
        Afisam(300);
        B();
        Afisam(300);
    }
    else
    if(colt.x==3&&colt.y==3)
    {
        R();
        Afisam(300);
        U();
        Afisam(300);
        Ri();
        Afisam(300);
        Ui();
        Afisam(300);
        R();
        Afisam(300);
        U();
        Afisam(300);
        Ri();
        Afisam(300);
        Ui();
        Afisam(300);
        R();
        Afisam(300);
        U();
        Afisam(300);
        Ri();
        Afisam(300);
        Ui();
        Afisam(300);
    }
    else
    if(colt.x==1&&colt.y==3)
    {
        U();
        Afisam(300);
        B();
        Afisam(300);
        U();
        Afisam(300);
        U();
        Afisam(300);
        Bi();
        Afisam(300);
        U();
        Afisam(300);
        B();
        Afisam(300);
        Ui();
        Afisam(300);
        Bi();
        Afisam(300);
    }
    else
    if(colt.x==3&&colt.y==1)
    {
        Li();
        Afisam(300);
        Ui();
        Afisam(300);
        L();
        Afisam(300);
        U();
        Afisam(300);
        Li();
        Afisam(300);
        Ui();
        Afisam(300);
        L();
        Afisam(300);
        U();
        Afisam(300);
        Li();
        Afisam(300);
        Ui();
        Afisam(300);
        L();
        Afisam(300);
        U();
        Afisam(300);
    }
}

void PotrivesteColt2(colturiAlbe colt, int culoare1, int culoare2,int situatie)
{
    int stagiu;
    if(situatie == 1)
    {
        for(int i=1;i<=4;i++)
        {
            if(colty1[i]==colt.y&&coltf[i]==colt.mijloc)
            {
                stagiu=i-1;
                if(stagiu<1)
                    stagiu=4;
                break;
            }
        }
        //cout<<stagiu<<" "<<stagiu%4+1<<endl;
        //cout<<coltf[stagiu]<<" "<<coltf[stagiu%4+1]<<endl<<endl;
        while(culoare2!=coltf[stagiu]&culoare1!=coltf[stagiu%4+1])
        {
            //cout<<1;
            Ui();
            stagiu++;
            if(stagiu>4)
                stagiu=1;
            colt.y=colty1[stagiu];
            Afisam(300);
        }
        //cout<<coltf[stagiu%4+1];
        if(coltf[stagiu%4+1]==1)
        {
            Ui();
            Afisam(300);
            Bi();
            Afisam(300);
            U();
            Afisam(300);
            B();
            Afisam(300);
        }
        if(coltf[stagiu%4+1]==3)
        {
            Ui();
            Afisam(300);
            Li();
            Afisam(300);
            U();
            Afisam(300);
            L();
            Afisam(300);
        }
        if(coltf[stagiu%4+1]==6)
        {
            Ui();
            Afisam(300);
            Fi();
            Afisam(300);
            U();
            Afisam(300);
            F();
            Afisam(300);
        }
        if(coltf[stagiu%4+1]==4)
        {
            Ui();
            Afisam(300);
            Ri();
            Afisam(300);
            U();
            Afisam(300);
            R();
            Afisam(300);
        }
    }
    else
    {
        for(int i=1;i<=4;i++)
        {
            if(colty2[i]==colt.y&&coltf[i]==colt.mijloc)
            {
                stagiu=i;
                if(stagiu<1)
                    stagiu=4;
                break;
            }
        }
        //cout<<stagiu<<" "<<stagiu%4+1<<endl;
        //cout<<culoare1<<" "<<culoare2<<endl;
        //cout<<coltf[stagiu]<<" "<<coltf[stagiu%4+1]<<endl<<endl;
        while(culoare1!=coltf[stagiu]&culoare2!=coltf[stagiu%4+1])
        {
            //cout<<1;
            Ui();
            stagiu++;
            if(stagiu>4)
                stagiu=1;
            colt.y=colty2[stagiu];
            Afisam(300);
        }
        if(coltf[stagiu]==1)
        {
            U();
            Afisam(300);
            F();
            Afisam(300);
            Ui();
            Afisam(300);
            Fi();
            Afisam(300);
        }
        if(coltf[stagiu]==3)
        {
            U();
            Afisam(300);
            R();
            Afisam(300);
            Ui();
            Afisam(300);
            Ri();
            Afisam(300);
        }
        if(coltf[stagiu]==6)
        {
            U();
            Afisam(300);
            B();
            Afisam(300);
            Ui();
            Afisam(300);
            Bi();
            Afisam(300);
        }
        if(coltf[stagiu]==4)
        {
            U();
            Afisam(300);
            L();
            Afisam(300);
            Ui();
            Afisam(300);
            Li();
            Afisam(300);
        }
    }
}

void Cruce()
{
    ok=0;
    nrcc=0;
    int c1=cub[2][2][1],c2=cub[2][2][2],c3=cub[2][2][3];//Culoarea alb

    if(c1==14||c1==15)
    {
        if(c1==14)
        {
            Bi();
            Afisam(300);
            P();
            Afisam(300);
            F();
            //cout<<"Roteste cubul spre sus din stanga"<<endl;
        }
        else
        {
            B();
            Afisam(300);
            Pi();
            Afisam(300);
            Fi();
            //cout<<"Roteste cubul spre jos din dreapta"<<endl;
        }
        MeniuButton();
        AfisareFata1(cub[1][1][1],cub[1][2][1],cub[1][3][1],cub[2][1][1],cub[2][2][1],cub[2][3][1],cub[3][1][1],cub[3][2][1],cub[3][3][1],pselectat);
        AfisareFata2(cub[1][1][2],cub[1][2][2],cub[1][3][2],cub[2][1][2],cub[2][2][2],cub[2][3][2],cub[3][1][2],cub[3][2][2],cub[3][3][2],pselectat);
        AfisareFata3(cub[1][1][3],cub[1][2][3],cub[1][3][3],cub[2][1][3],cub[2][2][3],cub[2][3][3],cub[3][1][3],cub[3][2][3],cub[3][3][3],pselectat);
        delay(300);
        cleardevice();
    }
    if(c2==15)
    {
        Bi();
        Afisam(300);
        P();
        Afisam(300);
        F();
        Afisam(300);
        Bi();
        Afisam(300);
        P();
        Afisam(300);
        F();
        //cout<<"Roteste cubul spre sus din stanga de doua ori"<<endl;
        MeniuButton();
        AfisareFata1(cub[1][1][1],cub[1][2][1],cub[1][3][1],cub[2][1][1],cub[2][2][1],cub[2][3][1],cub[3][1][1],cub[3][2][1],cub[3][3][1],pselectat);
        AfisareFata2(cub[1][1][2],cub[1][2][2],cub[1][3][2],cub[2][1][2],cub[2][2][2],cub[2][3][2],cub[3][1][2],cub[3][2][2],cub[3][3][2],pselectat);
        AfisareFata3(cub[1][1][3],cub[1][2][3],cub[1][3][3],cub[2][1][3],cub[2][2][3],cub[2][3][3],cub[3][1][3],cub[3][2][3],cub[3][3][3],pselectat);
        delay(300);
        cleardevice();
    }
    if(c3==14||c3==15)
    {
        if(c3==14)
        {
            S();
            Afisam(300);
            Li();
            Afisam(300);
            R();
            //cout<<"Roteste cubul spre sus"<<endl;
        }
        else
        {
            Si();
            Afisam(300);
            L();
            Afisam(300);
            Ri();
            //cout<<"Roteste cubul spre jos"<<endl;
        }
        MeniuButton();
        AfisareFata1(cub[1][1][1],cub[1][2][1],cub[1][3][1],cub[2][1][1],cub[2][2][1],cub[2][3][1],cub[3][1][1],cub[3][2][1],cub[3][3][1],pselectat);
        AfisareFata2(cub[1][1][2],cub[1][2][2],cub[1][3][2],cub[2][1][2],cub[2][2][2],cub[2][3][2],cub[3][1][2],cub[3][2][2],cub[3][3][2],pselectat);
        AfisareFata3(cub[1][1][3],cub[1][2][3],cub[1][3][3],cub[2][1][3],cub[2][2][3],cub[2][3][3],cub[3][1][3],cub[3][2][3],cub[3][3][3],pselectat);
        delay(300);
        cleardevice();
    }
    while(cub[2][2][1]!=4)
    {
        M();
        Afisam(300);
        U();
        Afisam(300);
        Di();
        MeniuButton();
        AfisareFata1(cub[1][1][1],cub[1][2][1],cub[1][3][1],cub[2][1][1],cub[2][2][1],cub[2][3][1],cub[3][1][1],cub[3][2][1],cub[3][3][1],pselectat);
        AfisareFata2(cub[1][1][2],cub[1][2][2],cub[1][3][2],cub[2][1][2],cub[2][2][2],cub[2][3][2],cub[3][1][2],cub[3][2][2],cub[3][3][2],pselectat);
        AfisareFata3(cub[1][1][3],cub[1][2][3],cub[1][3][3],cub[2][1][3],cub[2][2][3],cub[2][3][3],cub[3][1][3],cub[3][2][3],cub[3][3][3],pselectat);
        delay(300);
        cleardevice();
        //cout<<"Roteste cubul din dreapta in stanga"<<endl;
    }

    while(ok!=4)
    {
        CautaUrmatorulAlb();
        if(mijlocAlb.fata==2)
        {
            PotrivesteSus(mijlocAlb);
            ok++;
        }
        else
        if(mijlocAlb.fata==1)
        {
            if(mijlocAlb.pozx==1&&mijlocAlb.pozy==2)
            {
                Fi();
                Afisam(300);
                L();
                Afisam(300);
                F();
                Afisam(300);
                Li();
            }
            else
            if(mijlocAlb.pozx==2&&mijlocAlb.pozy==3)
            {
                F();
                Afisam(300);
                U();
                Afisam(300);
                Fi();
                Afisam(300);
                Ui();
            }
            else
            if(mijlocAlb.pozx==2&&mijlocAlb.pozy==1)
            {
                Bi();
                Afisam(300);
                U();
                Afisam(300);
                B();
                Afisam(300);
                Ui();
            }
            else
            if(mijlocAlb.pozx==3&&mijlocAlb.pozy==2)
            {
                Li();
                Afisam(300);
                F();
                Afisam(300);
                U();
                Afisam(300);
                Fi();
                Afisam(300);
                Ui();
                Afisam(300);
                L();
            }
            MeniuButton();
            AfisareFata1(cub[1][1][1],cub[1][2][1],cub[1][3][1],cub[2][1][1],cub[2][2][1],cub[2][3][1],cub[3][1][1],cub[3][2][1],cub[3][3][1],pselectat);
            AfisareFata2(cub[1][1][2],cub[1][2][2],cub[1][3][2],cub[2][1][2],cub[2][2][2],cub[2][3][2],cub[3][1][2],cub[3][2][2],cub[3][3][2],pselectat);
            AfisareFata3(cub[1][1][3],cub[1][2][3],cub[1][3][3],cub[2][1][3],cub[2][2][3],cub[2][3][3],cub[3][1][3],cub[3][2][3],cub[3][3][3],pselectat);
            delay(300);
            cleardevice();
            for(int i=1;i<=nrcc;i++)
            {
                mijloaceCentre[i].fata=0;
                mijloaceCentre[i].pozx=0;
                mijloaceCentre[i].pozy=0;
            }
            nrcc=0;
            CautaUrmatorulAlb();
            PotrivesteSus(mijlocAlb);
            ok++;
        }
        else
        if(mijlocAlb.fata==3)
        {
            if(mijlocAlb.pozx==1&&mijlocAlb.pozy==2)
            {
                Ri();
                Afisam(300);
                F();
                Afisam(300);
                R();
                Afisam(300);
                Fi();
            }
            else
            if(mijlocAlb.pozx==2&&mijlocAlb.pozy==3)
            {
                R();
                Afisam(300);
                U();
                Afisam(300);
                Ri();
                Afisam(300);
                Ui();
            }
            else
            if(mijlocAlb.pozx==2&&mijlocAlb.pozy==1)
            {
                Li();
                Afisam(300);
                U();
                Afisam(300);
                L();
                Afisam(300);
                Ui();
            }
            else
            if(mijlocAlb.pozx==3&&mijlocAlb.pozy==2)
            {
                F();
                Afisam(300);
                Li();
                Afisam(300);
                U();
                Afisam(300);
                L();
                Afisam(300);
                Ui();
                Afisam(300);
                Fi();
            }
            MeniuButton();
            AfisareFata1(cub[1][1][1],cub[1][2][1],cub[1][3][1],cub[2][1][1],cub[2][2][1],cub[2][3][1],cub[3][1][1],cub[3][2][1],cub[3][3][1],pselectat);
            AfisareFata2(cub[1][1][2],cub[1][2][2],cub[1][3][2],cub[2][1][2],cub[2][2][2],cub[2][3][2],cub[3][1][2],cub[3][2][2],cub[3][3][2],pselectat);
            AfisareFata3(cub[1][1][3],cub[1][2][3],cub[1][3][3],cub[2][1][3],cub[2][2][3],cub[2][3][3],cub[3][1][3],cub[3][2][3],cub[3][3][3],pselectat);
            delay(300);
            cleardevice();
            for(int i=1;i<=nrcc;i++)
            {
                mijloaceCentre[i].fata=0;
                mijloaceCentre[i].pozx=0;
                mijloaceCentre[i].pozy=0;
            }
            nrcc=0;
            CautaUrmatorulAlb();
            PotrivesteSus(mijlocAlb);
            ok++;
        }
        else
        if(mijlocAlb.fata==6)
        {
            if(mijlocAlb.pozx==1&&mijlocAlb.pozy==2)
            {
                Bi();
                Afisam(300);
                R();
                Afisam(300);
                B();
                Afisam(300);
                Ri();
            }
            else
            if(mijlocAlb.pozx==2&&mijlocAlb.pozy==3)
            {
                B();
                Afisam(300);
                U();
                Afisam(300);
                Bi();
                Afisam(300);
                Ui();
            }
            else
            if(mijlocAlb.pozx==2&&mijlocAlb.pozy==1)
            {
                Fi();
                Afisam(300);
                U();
                Afisam(300);
                F();
                Afisam(300);
                Ui();
            }
            else
            if(mijlocAlb.pozx==3&&mijlocAlb.pozy==2)
            {
                F();
                Afisam(300);
                R();
                Afisam(300);
                Fi();
                Afisam(300);
                Ri();
            }
            MeniuButton();
            AfisareFata1(cub[1][1][1],cub[1][2][1],cub[1][3][1],cub[2][1][1],cub[2][2][1],cub[2][3][1],cub[3][1][1],cub[3][2][1],cub[3][3][1],pselectat);
            AfisareFata2(cub[1][1][2],cub[1][2][2],cub[1][3][2],cub[2][1][2],cub[2][2][2],cub[2][3][2],cub[3][1][2],cub[3][2][2],cub[3][3][2],pselectat);
            AfisareFata3(cub[1][1][3],cub[1][2][3],cub[1][3][3],cub[2][1][3],cub[2][2][3],cub[2][3][3],cub[3][1][3],cub[3][2][3],cub[3][3][3],pselectat);
            delay(300);
            cleardevice();

            for(int i=1;i<=nrcc;i++)
            {
                mijloaceCentre[i].fata=0;
                mijloaceCentre[i].pozx=0;
                mijloaceCentre[i].pozy=0;
            }
            nrcc=0;
            CautaUrmatorulAlb();
            PotrivesteSus(mijlocAlb);
            ok++;
        }
        else
        if(mijlocAlb.fata==4)
        {
            if(mijlocAlb.pozx==1&&mijlocAlb.pozy==2)
            {
                Li();
                Afisam(300);
                B();
                Afisam(300);
                L();
                Afisam(300);
                Bi();
            }
            else
            if(mijlocAlb.pozx==2&&mijlocAlb.pozy==3)
            {
                Ri();
                Afisam(300);
                U();
                Afisam(300);
                R();
                Afisam(300);
                Ui();
            }
            else
            if(mijlocAlb.pozx==2&&mijlocAlb.pozy==1)
            {
                L();
                Afisam(300);
                U();
                Afisam(300);
                Li();
                Afisam(300);
                Ui();
            }
            else
            if(mijlocAlb.pozx==3&&mijlocAlb.pozy==2)
            {
                Li();
                Afisam(300);
                Bi();
                Afisam(300);
                L();
                Afisam(300);
                B();
            }
            MeniuButton();
            AfisareFata1(cub[1][1][1],cub[1][2][1],cub[1][3][1],cub[2][1][1],cub[2][2][1],cub[2][3][1],cub[3][1][1],cub[3][2][1],cub[3][3][1],pselectat);
            AfisareFata2(cub[1][1][2],cub[1][2][2],cub[1][3][2],cub[2][1][2],cub[2][2][2],cub[2][3][2],cub[3][1][2],cub[3][2][2],cub[3][3][2],pselectat);
            AfisareFata3(cub[1][1][3],cub[1][2][3],cub[1][3][3],cub[2][1][3],cub[2][2][3],cub[2][3][3],cub[3][1][3],cub[3][2][3],cub[3][3][3],pselectat);
            delay(300);
            cleardevice();

            for(int i=1;i<=nrcc;i++)
            {
                mijloaceCentre[i].fata=0;
                mijloaceCentre[i].pozx=0;
                mijloaceCentre[i].pozy=0;
            }

            nrcc=0;
            CautaUrmatorulAlb();
            PotrivesteSus(mijlocAlb);
            ok++;
        }
        else
        if(mijlocAlb.fata==69)
        {
            ok++;
        }
        else
        if(mijlocAlb.fata==5)
        {
            if(mijlocAlb.pozx==1&&mijlocAlb.pozy==2&&rezolvat[1][2]==0)
            {
                F();
                Afisam(300);
                F();
            }
            else
            if(mijlocAlb.pozx==2&&mijlocAlb.pozy==3&&rezolvat[2][3]==0)
            {
                R();
                Afisam(300);
                R();
            }
            else
            if(mijlocAlb.pozx==2&&mijlocAlb.pozy==1&&rezolvat[2][1]==0)
            {
                L();
                Afisam(300);
                L();
            }
            else
            if(mijlocAlb.pozx==3&&mijlocAlb.pozy==2&&rezolvat[3][2]==0)
            {
                B();
                Afisam(300);
                B();
            }
            MeniuButton();
            AfisareFata1(cub[1][1][1],cub[1][2][1],cub[1][3][1],cub[2][1][1],cub[2][2][1],cub[2][3][1],cub[3][1][1],cub[3][2][1],cub[3][3][1],pselectat);
            AfisareFata2(cub[1][1][2],cub[1][2][2],cub[1][3][2],cub[2][1][2],cub[2][2][2],cub[2][3][2],cub[3][1][2],cub[3][2][2],cub[3][3][2],pselectat);
            AfisareFata3(cub[1][1][3],cub[1][2][3],cub[1][3][3],cub[2][1][3],cub[2][2][3],cub[2][3][3],cub[3][1][3],cub[3][2][3],cub[3][3][3],pselectat);
            delay(300);
            cleardevice();

            for(int i=1;i<=nrcc;i++)
            {
                mijloaceCentre[i].fata=0;
                mijloaceCentre[i].pozx=0;
                mijloaceCentre[i].pozy=0;
            }

            nrcc=0;
            CautaUrmatorulAlb();
            PotrivesteSus(mijlocAlb);
            ok++;
        }
    }
    MeniuButton();
    AfisareFata1(cub[1][1][1],cub[1][2][1],cub[1][3][1],cub[2][1][1],cub[2][2][1],cub[2][3][1],cub[3][1][1],cub[3][2][1],cub[3][3][1],pselectat);
    AfisareFata2(cub[1][1][2],cub[1][2][2],cub[1][3][2],cub[2][1][2],cub[2][2][2],cub[2][3][2],cub[3][1][2],cub[3][2][2],cub[3][3][2],pselectat);
    AfisareFata3(cub[1][1][3],cub[1][2][3],cub[1][3][3],cub[2][1][3],cub[2][2][3],cub[2][3][3],cub[3][1][3],cub[3][2][3],cub[3][3][3],pselectat);
    delay(300);
}

int tradusCuloare(int kapa)
{
    if(kapa==2)
        return 14;
    if(kapa==1)
        return 4;
    if(kapa==3)
        return 2;
    if(kapa==6)
        return 5;
    if(kapa==4)
        return 1;
    if(kapa==5)
        return 15;
}

void CautaUrmatorulColtAlb()
{
    bool amGasit=false;
    for(int k=1;k<=6&&amGasit==false;k++)
    {
        for(int i=1;i<=3&&amGasit==false;i++)
        {
            for(int j=1;j<=3&&amGasit==false;j++)
            {
                if((i+j)%2==0&&(i!=2||j!=2))
                {
                    if(cub[i][j][v[k]]==15)
                    {
                        bool aMaiFost=true;
                        if(v[k]==5)
                        {
                            int o;
                            Updateaza();
                            for(int u=1;u<=4;u++)
                            {
                                if((traducereColturi[i][j][15][2].mijloc==coltVajut[u]&&traducereColturi[i][j][15][1].mijloc==coltVajut[u%4+1])||
                                    (traducereColturi[i][j][15][2].mijloc==coltVajut[u%4+1]&&traducereColturi[i][j][15][1].mijloc==coltVajut[u]))
                                {
                                    o=u;
                                    break;
                                }
                            }
                            //cout<<i<<" "<<j<<" "<<traducereColturi[i][j][15][1].culoare<<" ";
                            //cout<<tradusFata(traducereColturi[i][j][15][1].culoare)<<" "<<coltVajut[o]<<" "<<o<<endl<<endl;
                            if(tradusFata(traducereColturi[i][j][15][1].culoare)==coltVajut[o])
                            {
                                aMaiFost=false;
                            }
                        }
                        for(int p=1;p<=nrc;p++)
                        {
                            if(listaNeagraColturi[p].mijloc==v[k]&&listaNeagraColturi[p].x==i&&listaNeagraColturi[p].y==j)
                                aMaiFost=false;
                        }
                        if(aMaiFost==true)
                        {
                            coltAlb.mijloc=v[k];
                            coltAlb.culoare=15;
                            coltAlb.x=i;
                            coltAlb.y=j;
                            amGasit=true;

                            nrc++;
                            listaNeagraColturi[nrc].mijloc=v[k];
                            listaNeagraColturi[nrc].culoare=15;
                            listaNeagraColturi[nrc].x=i;
                            listaNeagraColturi[nrc].y=j;
                        }
                    }
                }
            }
        }
    }
    if(amGasit==false)
    {
        coltAlb.mijloc=69;
    }
}

void ColturiAlbe()
{
    ok=0;
    //cout<<1;
    while(ok!=4)
    {
        //cout<<2;
        CautaUrmatorulColtAlb();

        //cout<<ok<<endl;
        //cout<<"x = "<<coltAlb.x<<"   y = "<<coltAlb.y<<endl;
        //cout<<"mijloc = "<<coltAlb.mijloc<<endl<<endl;


        //cout<<3;
        Updateaza();
        if(coltAlb.mijloc==2)
        {
            PotrivesteColt(coltAlb);
            ok++;
        }
        else
        if(coltAlb.mijloc == 1)
        {
            Updateaza();
            if(coltAlb.x==1&&coltAlb.y==1)
            {
                PotrivesteColt2(coltAlb,
                                tradusFata(traducereColturi[coltAlb.x][coltAlb.y][tradusCuloare(coltAlb.mijloc)][1].culoare),
                                tradusFata(traducereColturi[coltAlb.x][coltAlb.y][tradusCuloare(coltAlb.mijloc)][2].culoare),
                                1);
                ok++;
            }
            else
            if(coltAlb.x==1&&coltAlb.y==3)
            {
                //cout<<tradusFata(traducereColturi[coltAlb.x][coltAlb.y][tradusCuloare(coltAlb.mijloc)][1].culoare)<<" ";
                //cout<<tradusFata(traducereColturi[coltAlb.x][coltAlb.y][tradusCuloare(coltAlb.mijloc)][2].culoare)<<endl;

                PotrivesteColt2(coltAlb,
                                tradusFata(traducereColturi[coltAlb.x][coltAlb.y][tradusCuloare(coltAlb.mijloc)][1].culoare),
                                tradusFata(traducereColturi[coltAlb.x][coltAlb.y][tradusCuloare(coltAlb.mijloc)][2].culoare),
                                2);
                ok++;
            }
            else
            if(coltAlb.x==3&&coltAlb.y==3)
            {
                F();
                Afisam(300);
                U();
                Afisam(300);
                Fi();
                Afisam(300);
                Ui();
                Afisam(300);
            }
            else
            if(coltAlb.x==3&&coltAlb.y==1)
            {
                Bi();
                Afisam(300);
                Ui();
                Afisam(300);
                B();
                Afisam(300);
                U();
                Afisam(300);
            }


            for(int i=1;i<=nrc;i++)
            {
                listaNeagraColturi[i].x=0;
                listaNeagraColturi[i].y=0;
                listaNeagraColturi[i].culoare=0;
                listaNeagraColturi[i].mijloc=0;
            }
            nrc=0;
        }
        else
        if(coltAlb.mijloc == 3)
        {
            Updateaza();
            if(coltAlb.x==1&&coltAlb.y==1)
            {
                PotrivesteColt2(coltAlb,
                                tradusFata(traducereColturi[coltAlb.x][coltAlb.y][tradusCuloare(coltAlb.mijloc)][1].culoare),
                                tradusFata(traducereColturi[coltAlb.x][coltAlb.y][tradusCuloare(coltAlb.mijloc)][2].culoare),
                                1);
                ok++;
            }
            else
            if(coltAlb.x==1&&coltAlb.y==3)
            {
                PotrivesteColt2(coltAlb,
                                tradusFata(traducereColturi[coltAlb.x][coltAlb.y][tradusCuloare(coltAlb.mijloc)][1].culoare),
                                tradusFata(traducereColturi[coltAlb.x][coltAlb.y][tradusCuloare(coltAlb.mijloc)][2].culoare),
                                2);
                ok++;
            }
            else
            if(coltAlb.x==3&&coltAlb.y==3)
            {
                R();
                Afisam(300);
                U();
                Afisam(300);
                Ri();
                Afisam(300);
                Ui();
                Afisam(300);
            }
            else
            if(coltAlb.x==3&&coltAlb.y==1)
            {
                Li();
                Afisam(300);
                Ui();
                Afisam(300);
                L();
                Afisam(300);
                U();
                Afisam(300);
            }

            for(int i=1;i<=nrc;i++)
            {
                listaNeagraColturi[i].x=0;
                listaNeagraColturi[i].y=0;
                listaNeagraColturi[i].culoare=0;
                listaNeagraColturi[i].mijloc=0;
            }
            nrc=0;
        }
        else
        if(coltAlb.mijloc == 6)
        {
            Updateaza();
            if(coltAlb.x==1&&coltAlb.y==1)
            {
                PotrivesteColt2(coltAlb,
                                tradusFata(traducereColturi[coltAlb.x][coltAlb.y][tradusCuloare(coltAlb.mijloc)][1].culoare),
                                tradusFata(traducereColturi[coltAlb.x][coltAlb.y][tradusCuloare(coltAlb.mijloc)][2].culoare),
                                1);
                ok++;
            }
            else
            if(coltAlb.x==1&&coltAlb.y==3)
            {
                PotrivesteColt2(coltAlb,
                                tradusFata(traducereColturi[coltAlb.x][coltAlb.y][tradusCuloare(coltAlb.mijloc)][1].culoare),
                                tradusFata(traducereColturi[coltAlb.x][coltAlb.y][tradusCuloare(coltAlb.mijloc)][2].culoare),
                                2);
                ok++;
            }
            else
            if(coltAlb.x==3&&coltAlb.y==3)
            {
                Ri();
                Afisam(300);
                Ui();
                Afisam(300);
                R();
                Afisam(300);
                U();
                Afisam(300);
            }
            else
            if(coltAlb.x==3&&coltAlb.y==1)
            {
                Fi();
                Afisam(300);
                U();
                Afisam(300);
                F();
                Afisam(300);
                Ui();
                Afisam(300);
            }


            for(int i=1;i<=nrc;i++)
            {
                listaNeagraColturi[i].x=0;
                listaNeagraColturi[i].y=0;
                listaNeagraColturi[i].culoare=0;
                listaNeagraColturi[i].mijloc=0;
            }
            nrc=0;
        }
        else
        if(coltAlb.mijloc == 4)
        {
            Updateaza();
            if(coltAlb.x==1&&coltAlb.y==1)
            {
                PotrivesteColt2(coltAlb,
                                tradusFata(traducereColturi[coltAlb.x][coltAlb.y][tradusCuloare(coltAlb.mijloc)][1].culoare),
                                tradusFata(traducereColturi[coltAlb.x][coltAlb.y][tradusCuloare(coltAlb.mijloc)][2].culoare),
                                2);
                ok++;
            }
            else
            if(coltAlb.x==1&&coltAlb.y==3)
            {
                PotrivesteColt2(coltAlb,
                                tradusFata(traducereColturi[coltAlb.x][coltAlb.y][tradusCuloare(coltAlb.mijloc)][1].culoare),
                                tradusFata(traducereColturi[coltAlb.x][coltAlb.y][tradusCuloare(coltAlb.mijloc)][2].culoare),
                                1);
                ok++;
            }
            else
            if(coltAlb.x==3&&coltAlb.y==3)
            {
                Ri();
                Afisam(300);
                Ui();
                Afisam(300);
                R();
                Afisam(300);
                U();
                Afisam(300);
            }
            else
            if(coltAlb.x==3&&coltAlb.y==1)
            {
                Bi();
                Afisam(300);
                U();
                Afisam(300);
                B();
                Afisam(300);
                Ui();
                Afisam(300);
            }

            for(int i=1;i<=nrc;i++)
            {
                listaNeagraColturi[i].x=0;
                listaNeagraColturi[i].y=0;
                listaNeagraColturi[i].culoare=0;
                listaNeagraColturi[i].mijloc=0;
            }
            nrc=0;
        }
        else
        if(coltAlb.mijloc == 69)
            ok++;
        else
        if(coltAlb.mijloc == 5)
        {
            if(coltAlb.x==1&&coltAlb.y==1)
            {
                Li();
                Afisam(300);
                Ui();
                Afisam(300);
                L();
                Afisam(300);
                U();
                Afisam(300);
            }
            else
            if(coltAlb.x==1&&coltAlb.y==3)
            {
                R();
                Afisam(300);
                U();
                Afisam(300);
                Ri();
                Afisam(300);
                Ui();
                Afisam(300);
            }
            else
            if(coltAlb.x==3&&coltAlb.y==3)
            {
                R();
                Afisam(300);
                Ui();
                Afisam(300);
                Ri();
                Afisam(300);
                U();
                Afisam(300);
            }
            else
            if(coltAlb.x==3&&coltAlb.y==1)
            {
                L();
                Afisam(300);
                U();
                Afisam(300);
                Li();
                Afisam(300);
                Ui();
                Afisam(300);
            }

            for(int i=1;i<=nrc;i++)
            {
                listaNeagraColturi[i].x=0;
                listaNeagraColturi[i].y=0;
                listaNeagraColturi[i].culoare=0;
                listaNeagraColturi[i].mijloc=0;
            }
            nrc=0;
        }
        for(int i=1;i<=nrc;i++)
        {
            listaNeagraColturi[i].x=0;
            listaNeagraColturi[i].y=0;
            listaNeagraColturi[i].culoare=0;
            listaNeagraColturi[i].mijloc=0;
        }
        nrc=0;
    }
}

void CautaUrmatorulMijloc()
{
    bool amGasit=false;
    for(int k=1;k<=5&&amGasit==false;k++)
        {
            for(int i=1;i<=3&&amGasit==false;i++)
            {
                for(int j=1;j<=3&&amGasit==false;j++)
                {
                    if((i+j)%2==1)
                    {
                        if(cub[i][j][v[k]]!=14&&cub[i][j][v[k]]!=15&&cub[traducere[i][j][tradusCuloare(v[k])].x][traducere[i][j][tradusCuloare(v[k])].y][traducere[i][j][tradusCuloare(v[k])].fata]!=14&&cub[traducere[i][j][tradusCuloare(v[k])].x][traducere[i][j][tradusCuloare(v[k])].y][traducere[i][j][tradusCuloare(v[k])].fata]!=15)
                        {
                            bool aMaiFost=true;
                            if(v[k]!=2)
                            {
                                int stagiu;
                                for(int o=1;o<=4;o++)
                                {
                                    //cout<<i<<" "<<j<<" "<<traducere[i][j][tradusCuloare(v[k])].fata<<" "<<v[k]<<" 1"<<endl;
                                    if(vajut[o]==traducere[i][j][tradusCuloare(v[k])].fata)
                                    {
                                        //cout<<i<<" "<<j<<" "<<traducere[i][j][tradusCuloare(v[k])].fata<<" "<<v[k]<<" 2"<<endl;
                                        stagiu=o;
                                        break;
                                    }
                                }
                                int culoare2 = tradusFata(cub[traducere[i][j][tradusCuloare(v[k])].x][traducere[i][j][tradusCuloare(v[k])].y][traducere[i][j][tradusCuloare(v[k])].fata]);

                                //cout<<i<<" "<<j<<" "<<traducere[i][j][tradusCuloare(v[k])].fata<<" "<<v[k]<<" 3"<<endl;
                                //cout<<"    -    "<<culoare2<<" "<<vajut[stagiu]<<" "<<stagiu<<endl<<endl;
                                //_getch();
                                if(culoare2==vajut[stagiu])
                                    aMaiFost=false;
                            }
                            if((i!=3&&v[k]!=2))
                            {
                                if(aMaiFost==true)
                                {
                                    mijloc.fata1=v[k];
                                    mijloc.fata2=traducere[i][j][tradusCuloare(v[k])].fata;
                                    mijloc.x=i;
                                    mijloc.y=j;
                                    amGasit=true;
                                }
                            }
                            else
                            if(v[k]==2)
                            {
                                if(aMaiFost==true)
                                {
                                    mijloc.fata1=v[k];
                                    mijloc.fata2=traducere[i][j][tradusCuloare(v[k])].fata;
                                    mijloc.x=i;
                                    mijloc.y=j;
                                    amGasit=true;
                                }
                            }
                        }
                    }
                }
            }
        }
        if(amGasit==false)
        {
            mijloc.fata1=69;
        }
}

void PotrivesteMijloc(mijloacePeBune mijlocCurent, int culoare1, int culoare2)
{
    int stagiu;
    for(int i=1;i<=4;i++)
    {
        if(vajut[i]==mijlocCurent.fata2)
        {
            stagiu=i;
            break;
        }
    }
    int stagiuxy;
    for(int i=1;i<=4;i++)
    {
        if(vajutx3[i]==mijlocCurent.x&&vajuty3[i]==mijlocCurent.y)
        {
            stagiuxy=i;
        }
    }

    while(culoare2!=vajut[stagiu])
    {
        //cout<<culoare2<<" "<<vajut[stagiu]<<endl;
        U();
        stagiu++;
        if(stagiu>4)
            stagiu=1;
        stagiuxy++;
        if(stagiuxy>4)
            stagiuxy=1;
        mijlocCurent.x=vajutx3[stagiuxy];
        mijlocCurent.y=vajuty3[stagiuxy];
        Afisam(300);
    }
    //cout<<" "<<mijlocCurent.x<<" "<<mijlocCurent.y<<endl;
    stagiu++;
    if(stagiu>4)
        stagiu=1;
    if(culoare1==vajut[stagiu])
    {
        if(mijlocCurent.x==1&&mijlocCurent.y==2)
        {
            Ui();
            Afisam(300);
            Ri();
            Afisam(300);
            U();
            Afisam(300);
            R();
            Afisam(300);
            U();
            Afisam(300);
            B();
            Afisam(300);
            Ui();
            Afisam(300);
            Bi();
            Afisam(300);
        }
        if(mijlocCurent.x==2&&mijlocCurent.y==3)
        {
            Ui();
            Afisam(300);
            Fi();
            Afisam(300);
            U();
            Afisam(300);
            F();
            Afisam(300);
            U();
            Afisam(300);
            R();
            Afisam(300);
            Ui();
            Afisam(300);
            Ri();
            Afisam(300);
        }
        if(mijlocCurent.x==3&&mijlocCurent.y==2)
        {
            Ui();
            Afisam(300);
            Li();
            Afisam(300);
            U();
            Afisam(300);
            L();
            Afisam(300);
            U();
            Afisam(300);
            F();
            Afisam(300);
            Ui();
            Afisam(300);
            Fi();
            Afisam(300);
        }
        if(mijlocCurent.x==2&&mijlocCurent.y==1)
        {
            Ui();
            Afisam(300);
            Bi();
            Afisam(300);
            U();
            Afisam(300);
            B();
            Afisam(300);
            U();
            Afisam(300);
            L();
            Afisam(300);
            Ui();
            Afisam(300);
            Li();
            Afisam(300);
        }
    }
    else
    {
        if(mijlocCurent.x==1&&mijlocCurent.y==2)
        {
            U();
            Afisam(300);
            L();
            Afisam(300);
            Ui();
            Afisam(300);
            Li();
            Afisam(300);
            Ui();
            Afisam(300);
            Bi();
            Afisam(300);
            U();
            Afisam(300);
            B();
            Afisam(300);
        }
        if(mijlocCurent.x==2&&mijlocCurent.y==3)
        {
            U();
            Afisam(300);
            B();
            Afisam(300);
            Ui();
            Afisam(300);
            Bi();
            Afisam(300);
            Ui();
            Afisam(300);
            Ri();
            Afisam(300);
            U();
            Afisam(300);
            R();
            Afisam(300);
        }
        if(mijlocCurent.x==3&&mijlocCurent.y==2)
        {
            U();
            Afisam(300);
            R();
            Afisam(300);
            Ui();
            Afisam(300);
            Ri();
            Afisam(300);
            Ui();
            Afisam(300);
            Fi();
            Afisam(300);
            U();
            Afisam(300);
            F();
            Afisam(300);
        }
        if(mijlocCurent.x==2&&mijlocCurent.y==1)
        {
            U();
            Afisam(300);
            F();
            Afisam(300);
            Ui();
            Afisam(300);
            Fi();
            Afisam(300);
            Ui();
            Afisam(300);
            Li();
            Afisam(300);
            U();
            Afisam(300);
            L();
            Afisam(300);
        }
    }
}

void Mijloace()
{
    int ok=0;
    while(ok!=4)
    {
        CautaUrmatorulMijloc();

        //cout<<"fata 1 = "<<mijloc.fata1<<"  ok = "<<ok<<endl<<endl;

        if(mijloc.fata1 == 2)
        {
            //cout<<"x = "<<mijloc.x<<"   y = "<<mijloc.y<<" ";
            //cout<<"mijloc 1 = "<<mijloc.fata1<<endl;
            //cout<<"tradus x = "<<traducere[mijloc.x][mijloc.y][tradusCuloare(mijloc.fata1)].x<<" ";
            //cout<<"tradus y = "<<traducere[mijloc.x][mijloc.y][tradusCuloare(mijloc.fata1)].y<<" ";
            //cout<<"mijloc 2 = "<<tradusCuloare(mijloc.fata1)<<endl<<endl;
            PotrivesteMijloc(mijloc,
                             tradusFata(cub[mijloc.x][mijloc.y][mijloc.fata1]),
                             tradusFata(cub[traducere[mijloc.x][mijloc.y][tradusCuloare(mijloc.fata1)].x][traducere[mijloc.x][mijloc.y][tradusCuloare(mijloc.fata1)].y][traducere[mijloc.x][mijloc.y][tradusCuloare(mijloc.fata1)].fata])
                             );
        }
        else
        if(mijloc.fata1 == 1)
        {
            //cout<<"x = "<<mijloc.x<<"   y = "<<mijloc.y<<" ";
            //cout<<"mijloc 1 = "<<mijloc.fata1<<endl;
            //cout<<"tradus x = "<<traducere[mijloc.x][mijloc.y][tradusCuloare(mijloc.fata1)].x<<" ";
            //cout<<"tradus y = "<<traducere[mijloc.x][mijloc.y][tradusCuloare(mijloc.fata1)].y<<" ";
            //cout<<"mijloc 2 = "<<traducere[mijloc.x][mijloc.y][tradusCuloare(mijloc.fata1)].fata<<endl<<endl;
            if(mijloc.x==2&&mijloc.y==1)
            {
                Ui();
                Afisam(300);
                Bi();
                Afisam(300);
                U();
                Afisam(300);
                B();
                Afisam(300);
                U();
                Afisam(300);
                L();
                Afisam(300);
                Ui();
                Afisam(300);
                Li();
                Afisam(300);
            }
            if(mijloc.x==2&&mijloc.y==3)
            {
                U();
                Afisam(300);
                F();
                Afisam(300);
                Ui();
                Afisam(300);
                Fi();
                Afisam(300);
                Ui();
                Afisam(300);
                Li();
                Afisam(300);
                U();
                Afisam(300);
                L();
                Afisam(300);
            }

            CautaUrmatorulMijloc();

            cout<<"x = "<<mijloc.x<<"   y = "<<mijloc.y<<" ";
            cout<<"mijloc 1 = "<<mijloc.fata1<<endl;
            cout<<"tradus x = "<<traducere[mijloc.x][mijloc.y][tradusCuloare(mijloc.fata1)].x<<" ";
            cout<<"tradus y = "<<traducere[mijloc.x][mijloc.y][tradusCuloare(mijloc.fata1)].y<<" ";
            cout<<"mijloc 2 = "<<traducere[mijloc.x][mijloc.y][tradusCuloare(mijloc.fata1)].fata<<endl<<endl;

            PotrivesteMijloc(mijloc,
                             tradusFata(cub[mijloc.x][mijloc.y][mijloc.fata1]),
                             tradusFata(cub[traducere[mijloc.x][mijloc.y][tradusCuloare(mijloc.fata1)].x][traducere[mijloc.x][mijloc.y][tradusCuloare(mijloc.fata1)].y][traducere[mijloc.x][mijloc.y][tradusCuloare(mijloc.fata1)].fata])
                             );

        }
        else
        if(mijloc.fata1 == 3)
        {
            if(mijloc.x==2&&mijloc.y==1)
            {
                Ui();
                Afisam(300);
                Li();
                Afisam(300);
                U();
                Afisam(300);
                L();
                Afisam(300);
                U();
                Afisam(300);
                F();
                Afisam(300);
                Ui();
                Afisam(300);
                Fi();
                Afisam(300);
            }
            if(mijloc.x==3&&mijloc.y==2)
            {
                U();
                Afisam(300);
                R();
                Afisam(300);
                Ui();
                Afisam(300);
                Ri();
                Afisam(300);
                Ui();
                Afisam(300);
                Fi();
                Afisam(300);
                U();
                Afisam(300);
                F();
                Afisam(300);
            }

            CautaUrmatorulMijloc();
            PotrivesteMijloc(mijloc,
                             tradusFata(cub[mijloc.x][mijloc.y][mijloc.fata1]),
                             tradusFata(cub[traducere[mijloc.x][mijloc.y][tradusCuloare(mijloc.fata1)].x][traducere[mijloc.x][mijloc.y][tradusCuloare(mijloc.fata1)].y][traducere[mijloc.x][mijloc.y][tradusCuloare(mijloc.fata1)].fata])
                            );
        }
        else
        if(mijloc.fata1 == 6)
        {
            if(mijloc.x==2&&mijloc.y==1)
            {
                Ui();
                Afisam(300);
                Fi();
                Afisam(300);
                U();
                Afisam(300);
                F();
                Afisam(300);
                U();
                Afisam(300);
                R();
                Afisam(300);
                Ui();
                Afisam(300);
                Ri();
                Afisam(300);
            }
            if(mijloc.x==3&&mijloc.y==2)
            {
                U();
                Afisam(300);
                B();
                Afisam(300);
                Ui();
                Afisam(300);
                Bi();
                Afisam(300);
                Ui();
                Afisam(300);
                Ri();
                Afisam(300);
                U();
                Afisam(300);
                R();
                Afisam(300);
            }

            CautaUrmatorulMijloc();
            PotrivesteMijloc(mijloc,
                             tradusFata(cub[mijloc.x][mijloc.y][mijloc.fata1]),
                             tradusFata(cub[traducere[mijloc.x][mijloc.y][tradusCuloare(mijloc.fata1)].x][traducere[mijloc.x][mijloc.y][tradusCuloare(mijloc.fata1)].y][traducere[mijloc.x][mijloc.y][tradusCuloare(mijloc.fata1)].fata])
                             );

        }
        else
        if(mijloc.fata1 == 4)
        {
            if(mijloc.x==2&&mijloc.y==1)
            {
                U();
                Afisam(300);
                L();
                Afisam(300);
                Ui();
                Afisam(300);
                Li();
                Afisam(300);
                Ui();
                Afisam(300);
                Bi();
                Afisam(300);
                U();
                Afisam(300);
                B();
                Afisam(300);
            }
            if(mijloc.x==3&&mijloc.y==2)
            {
                Ui();
                Afisam(300);
                Ri();
                Afisam(300);
                U();
                Afisam(300);
                R();
                Afisam(300);
                U();
                Afisam(300);
                B();
                Afisam(300);
                Ui();
                Afisam(300);
                Bi();
                Afisam(300);
            }
            CautaUrmatorulMijloc();
            PotrivesteMijloc(mijloc,
                             tradusFata(cub[mijloc.x][mijloc.y][mijloc.fata1]),
                             tradusFata(cub[traducere[mijloc.x][mijloc.y][tradusCuloare(mijloc.fata1)].x][traducere[mijloc.x][mijloc.y][tradusCuloare(mijloc.fata1)].y][traducere[mijloc.x][mijloc.y][tradusCuloare(mijloc.fata1)].fata])
                             );

        }
        ok++;
    }
}

void Rezolva()
{
    Cruce();
    ColturiAlbe();
    Mijloace();
}

void Configuratie(char mutari[100])
{
    for(int i=0;i<strlen(mutari);i++)
    {
        if((mutari[i]>=65&&mutari[i]<=90)||(mutari[i]>=97&&mutari[i]<=122))
        {
            if(mutari[i]=='r')
            {
                R();
            }
            else
            if(mutari[i]=='R')
            {
                Ri();
            }
            else
            if(mutari[i]=='u')
            {
                U();
            }
            else
            if(mutari[i]=='U')
            {
                Ui();
            }
            else
            if(mutari[i]=='l')
            {
                L();
            }
            else
            if(mutari[i]=='L')
            {
                Li();
            }
            else
            if(mutari[i]=='f')
            {
                F();
            }
            else
            if(mutari[i]=='F')
            {
                Fi();
            }
            else
            if(mutari[i]=='b')
            {
                B();
            }
            else
            if(mutari[i]=='B')
            {
                Bi();
            }
        }
    }
}

int main()
{
    if(1)///Traducator Laturi
    {
        if(1)///Traducerea Alb
        {
            traducere[1][2][15].x=3;
            traducere[1][2][15].y=2;

            traducere[2][1][15].x=3;
            traducere[2][1][15].y=2;

            traducere[2][3][15].x=3;
            traducere[2][3][15].y=2;

            traducere[3][2][15].x=3;
            traducere[3][2][15].y=2;
        }
        if(1)///Traducerea Rosu
        {
            traducere[1][2][4].x=2;
            traducere[1][2][4].y=1;
            traducere[1][2][4].fata=2;


            traducere[2][1][4].x=2;
            traducere[2][1][4].y=1;
            traducere[2][1][4].fata=4;

            traducere[2][3][4].x=2;
            traducere[2][3][4].y=1;
            traducere[2][3][4].fata=3;

            traducere[3][2][4].x=2;
            traducere[3][2][4].y=1;
        }
        if(1)///Traducerea Verde
        {
            traducere[1][2][2].x=3;
            traducere[1][2][2].y=2;
            traducere[1][2][2].fata=2;

            traducere[2][1][2].x=2;
            traducere[2][1][2].y=3;
            traducere[2][1][2].fata=1;

            traducere[2][3][2].x=2;
            traducere[2][3][2].y=1;
            traducere[2][3][2].fata=6;

            traducere[3][2][2].x=1;
            traducere[3][2][2].y=2;
        }
        if(1)///Traducerea Albastru
        {
            traducere[1][2][1].x=1;
            traducere[1][2][1].y=2;
            traducere[1][2][1].fata=2;

            traducere[2][1][1].x=2;
            traducere[2][1][1].y=1;
            traducere[2][1][1].fata=1;

            traducere[2][3][1].x=2;
            traducere[2][3][1].y=3;
            traducere[2][3][1].fata=6;

            traducere[3][2][1].x=3;
            traducere[3][2][1].y=2;
        }
        if(1)///Traducerea Mov
        {
            traducere[1][2][5].x=2;
            traducere[1][2][5].y=3;
            traducere[1][2][5].fata=2;

            traducere[2][1][5].x=2;
            traducere[2][1][5].y=3;
            traducere[2][1][5].fata=3;

            traducere[2][3][5].x=2;
            traducere[2][3][5].y=3;
            traducere[2][3][5].fata=4;

            traducere[3][2][5].x=2;
            traducere[3][2][5].y=3;
        }
        if(1)///Traducerea Galben
        {
            traducere[1][2][14].x=1;
            traducere[1][2][14].y=2;
            traducere[1][2][14].fata=4;

            traducere[2][1][14].x=1;
            traducere[2][1][14].y=2;
            traducere[2][1][14].fata=1;

            traducere[2][3][14].x=1;
            traducere[2][3][14].y=2;
            traducere[2][3][14].fata=6;

            traducere[3][2][14].x=1;
            traducere[3][2][14].y=2;
            traducere[3][2][14].fata=3;
        }
    }
    if(1)///Traducator Colturi
    {
        if(1)///Traducerea Galben
        {
            traducereColturi[1][1][14][1].x=1;
            traducereColturi[1][1][14][1].y=1;
            traducereColturi[1][1][14][1].mijloc=4;

            traducereColturi[1][1][14][2].x=1;
            traducereColturi[1][1][14][2].y=1;
            traducereColturi[1][1][14][2].mijloc=1;


            traducereColturi[3][1][14][1].x=1;
            traducereColturi[3][1][14][1].y=3;
            traducereColturi[3][1][14][1].mijloc=1;

            traducereColturi[3][1][14][2].x=1;
            traducereColturi[3][1][14][2].y=1;
            traducereColturi[3][1][14][2].mijloc=3;


            traducereColturi[3][3][14][1].x=1;
            traducereColturi[3][3][14][1].y=3;
            traducereColturi[3][3][14][1].mijloc=3;

            traducereColturi[3][3][14][2].x=1;
            traducereColturi[3][3][14][2].y=1;
            traducereColturi[3][3][14][2].mijloc=6;


            traducereColturi[1][3][14][1].x=1;
            traducereColturi[1][3][14][1].y=3;
            traducereColturi[1][3][14][1].mijloc=6;

            traducereColturi[1][3][14][2].x=1;
            traducereColturi[1][3][14][2].y=3;
            traducereColturi[1][3][14][2].mijloc=4;
        }
        if(1)///Traducerea Rosu
        {
            traducereColturi[1][1][4][1].x=1;
            traducereColturi[1][1][4][1].y=1;
            traducereColturi[1][1][4][1].mijloc=2;

            traducereColturi[1][1][4][2].x=1;
            traducereColturi[1][1][4][2].y=1;
            traducereColturi[1][1][4][2].mijloc=4;


            traducereColturi[3][1][4][1].x=3;
            traducereColturi[3][1][4][1].y=1;
            traducereColturi[3][1][4][1].mijloc=5;

            traducereColturi[3][1][4][2].x=3;
            traducereColturi[3][1][4][2].y=1;
            traducereColturi[3][1][4][2].mijloc=4;


            traducereColturi[3][3][4][1].x=1;
            traducereColturi[3][3][4][1].y=1;
            traducereColturi[3][3][4][1].mijloc=5;

            traducereColturi[3][3][4][2].x=3;
            traducereColturi[3][3][4][2].y=1;
            traducereColturi[3][3][4][2].mijloc=3;


            traducereColturi[1][3][4][1].x=3;
            traducereColturi[1][3][4][1].y=1;
            traducereColturi[1][3][4][1].mijloc=2;

            traducereColturi[1][3][4][2].x=1;
            traducereColturi[1][3][4][2].y=1;
            traducereColturi[1][3][4][2].mijloc=3;
        }
        if(1)///Traducerea Verde
        {
            traducereColturi[1][1][2][1].x=3;
            traducereColturi[1][1][2][1].y=1;
            traducereColturi[1][1][2][1].mijloc=2;

            traducereColturi[1][1][2][2].x=1;
            traducereColturi[1][1][2][2].y=3;
            traducereColturi[1][1][2][2].mijloc=1;


            traducereColturi[3][1][2][1].x=1;
            traducereColturi[3][1][2][1].y=1;
            traducereColturi[3][1][2][1].mijloc=5;

            traducereColturi[3][1][2][2].x=3;
            traducereColturi[3][1][2][2].y=3;
            traducereColturi[3][1][2][2].mijloc=1;


            traducereColturi[3][3][2][1].x=1;
            traducereColturi[3][3][2][1].y=3;
            traducereColturi[3][3][2][1].mijloc=5;

            traducereColturi[3][3][2][2].x=3;
            traducereColturi[3][3][2][2].y=1;
            traducereColturi[3][3][2][2].mijloc=6;


            traducereColturi[1][3][2][1].x=3;
            traducereColturi[1][3][2][1].y=3;
            traducereColturi[1][3][2][1].mijloc=2;

            traducereColturi[1][3][2][2].x=1;
            traducereColturi[1][3][2][2].y=1;
            traducereColturi[1][3][2][2].mijloc=6;
        }
        if(1)///Traducerea Mov
        {
            traducereColturi[1][1][5][1].x=3;
            traducereColturi[1][1][5][1].y=3;
            traducereColturi[1][1][5][1].mijloc=2;

            traducereColturi[1][1][5][2].x=1;
            traducereColturi[1][1][5][2].y=3;
            traducereColturi[1][1][5][2].mijloc=3;


            traducereColturi[3][1][5][1].x=1;
            traducereColturi[3][1][5][1].y=3;
            traducereColturi[3][1][5][1].mijloc=5;

            traducereColturi[3][1][5][2].x=3;
            traducereColturi[3][1][5][2].y=3;
            traducereColturi[3][1][5][2].mijloc=3;


            traducereColturi[3][3][5][1].x=3;
            traducereColturi[3][3][5][1].y=3;
            traducereColturi[3][3][5][1].mijloc=5;

            traducereColturi[3][3][5][2].x=3;
            traducereColturi[3][3][5][2].y=3;
            traducereColturi[3][3][5][2].mijloc=4;


            traducereColturi[1][3][5][1].x=1;
            traducereColturi[1][3][5][1].y=3;
            traducereColturi[1][3][5][1].mijloc=2;

            traducereColturi[1][3][5][2].x=1;
            traducereColturi[1][3][5][2].y=3;
            traducereColturi[1][3][5][2].mijloc=4;
        }
        if(1)///Traducerea Albastru
        {
            traducereColturi[1][1][1][1].x=1;
            traducereColturi[1][1][1][1].y=1;
            traducereColturi[1][1][1][1].mijloc=2;

            traducereColturi[1][1][1][2].x=1;
            traducereColturi[1][1][1][2].y=1;
            traducereColturi[1][1][1][2].mijloc=1;


            traducereColturi[3][1][1][1].x=3;
            traducereColturi[3][1][1][1].y=1;
            traducereColturi[3][1][1][1].mijloc=5;

            traducereColturi[3][1][1][2].x=3;
            traducereColturi[3][1][1][2].y=1;
            traducereColturi[3][1][1][2].mijloc=1;


            traducereColturi[3][3][1][1].x=3;
            traducereColturi[3][3][1][1].y=3;
            traducereColturi[3][3][1][1].mijloc=5;

            traducereColturi[3][3][1][2].x=3;
            traducereColturi[3][3][1][2].y=3;
            traducereColturi[3][3][1][2].mijloc=6;


            traducereColturi[1][3][1][1].x=1;
            traducereColturi[1][3][1][1].y=3;
            traducereColturi[1][3][1][1].mijloc=2;

            traducereColturi[1][3][1][2].x=1;
            traducereColturi[1][3][1][2].y=3;
            traducereColturi[1][3][1][2].mijloc=6;
        }
        if(1)///Traducerea Alb
        {
            traducereColturi[1][1][15][1].x=3;
            traducereColturi[1][1][15][1].y=1;
            traducereColturi[1][1][15][1].mijloc=3;

            traducereColturi[1][1][15][2].x=3;
            traducereColturi[1][1][15][2].y=3;
            traducereColturi[1][1][15][2].mijloc=1;


            traducereColturi[3][1][15][1].x=3;
            traducereColturi[3][1][15][1].y=1;
            traducereColturi[3][1][15][1].mijloc=1;

            traducereColturi[3][1][15][2].x=3;
            traducereColturi[3][1][15][2].y=1;
            traducereColturi[3][1][15][2].mijloc=4;


            traducereColturi[3][3][15][1].x=3;
            traducereColturi[3][3][15][1].y=3;
            traducereColturi[3][3][15][1].mijloc=4;

            traducereColturi[3][3][15][2].x=3;
            traducereColturi[3][3][15][2].y=3;
            traducereColturi[3][3][15][2].mijloc=6;


            traducereColturi[1][3][15][1].x=3;
            traducereColturi[1][3][15][1].y=1;
            traducereColturi[1][3][15][1].mijloc=6;

            traducereColturi[1][3][15][2].x=3;
            traducereColturi[1][3][15][2].y=3;
            traducereColturi[1][3][15][2].mijloc=3;
        }

    }

    for(int f=1;f<=6;f++)
    {
        //cout<<endl<<endl;
        for(int x=1;x<=3;x++)
        {
            //cout<<endl;
            for(int y=1;y<=3;y++)
            {
                if(f==1)
                {
                    //cout<<x<<" "<<y<<" "<<f<<"  "<<4<<"   ";
                    cub[x][y][f]=4;
                }
                else
                if(f==2)
                {
                    //cout<<x<<" "<<y<<" "<<f<<"  "<<14<<"   ";
                    cub[x][y][f]=14;
                }
                else
                if(f==3)
                {
                    //cout<<x<<" "<<y<<" "<<f<<"  "<<2<<"   ";
                    cub[x][y][f]=2;
                }
                else
                if(f==4)
                {
                    //cout<<x<<" "<<y<<" "<<f<<"  "<<1<<"   ";
                    cub[x][y][f]=1;
                }
                else
                if(f==5)
                {
                    //cout<<x<<" "<<y<<" "<<f<<"  "<<15<<"   ";
                    cub[x][y][f]=15;
                }
                else
                if(f==6)
                {
                    //cout<<x<<" "<<y<<" "<<f<<"  "<<6<<"   ";
                    cub[x][y][f]=5;
                }
            }
        }
    }

    //*/
    char input;
    int ok,aux=0,primaData;
    initwindow(900,850);

    //Configuratie("f f L u R f u F F B B L F l l F L R l l");
    //Configuratie("L U l U r r L U l u u b b u u f f u l l");
    //Configuratie("f u F U f u u F U U L u l r U R u U l u u L U l u L r u R U r u u R U r u R");
    //Configuratie("L U l U r r L U l u u b b u u f f u l l");

    while(1==1)
    {

        if(meniu==false)
        {
            if(primaData==4)
            {
                if(primaData==4)
                {
                    Meniu4();
                    delay(300);
                    cleardevice();
                    primaData=3;
                }
                if(primaData==3)
                {
                    Meniu3();

                    delay(300);
                    cleardevice();
                    primaData=2;
                }
                if(primaData==2)
                {
                    Meniu2();

                    delay(300);
                    cleardevice();
                    primaData=1;
                }
                if(primaData==1)
                {
                    Meniu1();

                    delay(300);
                    cleardevice();
                    primaData=0;
                }//*/
                //cleardevice();
                if(varianta==1)
                {
                    Amesteca();
                    cout<<endl;
                    Afisam(300);
                    delay(300);
                    cleardevice();
                }
                else
                if(varianta==2)
                {
                    Rezolva();
                    delay(300);
                    cleardevice();
                }
                //cleardevice();
                primaData=0;
                varianta=0;
            }
            MeniuButton();
            AfisareFata1(cub[1][1][1],cub[1][2][1],cub[1][3][1],cub[2][1][1],cub[2][2][1],cub[2][3][1],cub[3][1][1],cub[3][2][1],cub[3][3][1],pselectat);
            AfisareFata2(cub[1][1][2],cub[1][2][2],cub[1][3][2],cub[2][1][2],cub[2][2][2],cub[2][3][2],cub[3][1][2],cub[3][2][2],cub[3][3][2],pselectat);
            AfisareFata3(cub[1][1][3],cub[1][2][3],cub[1][3][3],cub[2][1][3],cub[2][2][3],cub[2][3][3],cub[3][1][3],cub[3][2][3],cub[3][3][3],pselectat);
        }
        else
        {
            if(primaData==0)
            {
                primaData=1;
                AfisareFata1(cub[1][1][1],cub[1][2][1],cub[1][3][1],cub[2][1][1],cub[2][2][1],cub[2][3][1],cub[3][1][1],cub[3][2][1],cub[3][3][1],pselectat);
                AfisareFata2(cub[1][1][2],cub[1][2][2],cub[1][3][2],cub[2][1][2],cub[2][2][2],cub[2][3][2],cub[3][1][2],cub[3][2][2],cub[3][3][2],pselectat);
                AfisareFata3(cub[1][1][3],cub[1][2][3],cub[1][3][3],cub[2][1][3],cub[2][2][3],cub[2][3][3],cub[3][1][3],cub[3][2][3],cub[3][3][3],pselectat);

                delay(300);
                cleardevice();
                primaData=1;
            }
            if(primaData==1)
            {
                Meniu1();

                delay(300);
                cleardevice();
                primaData=2;
            }
            if(primaData==2)
            {
                Meniu2();

                delay(300);
                cleardevice();
                primaData=3;
            }
            if(primaData==3)
            {
                Meniu3();

                delay(300);
                cleardevice();
                primaData=4;
            }//*/
            //cleardevice();
            primaData=4;
            if(primaData==4)
            {
                cleardevice();
                Meniu4();
                delay(300);
            }
        }

        if(aux>=2)
        {
            aux=0;
            pselectat=0;
            p2selectat=0;
        }//*/

        if(ismouseclick(WM_LBUTTONDOWN))
        {
            int x=mousex();
            int y=mousey();
            clearmouseclick(WM_LBUTTONDOWN);
            //cout<<" "<<x<<" "<<y<<endl;
            if(meniu==false)
            {
                if(600<x&&x<750&&50<y&&y<125)
                {
                    meniu=true;
                    primaData=0;
                    cleardevice();
                    aux=0;
                }
                else
                if(aux==1||aux==0)
                {
                    aux++;
                    if(aux==1)
                    {
                        x1selectat=x;
                        y1selectat=y;

                        int d1,d2,d3,d4,d5,d6,d7,d8;

                        d1=x1selectat-y1selectat+22;
                        d2=(-75)*x1selectat+76*y1selectat-11685;
                        d3=(-75)*x1selectat+76*y1selectat-21489;
                        d4=x1selectat-y1selectat+408;

                        d5=d1;
                        d6=116*x1selectat+(-115)*y1selectat-12949;
                        d7=116*x1selectat+(-115)*y1selectat-27913;
                        d8=233*x1selectat+(-231)*y1selectat-85657;


                        if(x1selectat>280&&y1selectat>280&&x1selectat<666&&y1selectat<663)///S-a apasat clicl pe fata 3
                        {
                            if(x1selectat>280&&x1selectat<412&&y1selectat>280&&y1selectat<408)
                            {
                                pselectat=113;
                            }
                            else
                            if(x1selectat>539&&x1selectat<666&&y1selectat>280&&y1selectat<408)
                            {
                                pselectat=133;
                            }
                            else
                            if(x1selectat>280&&x1selectat<412&&y1selectat>535&&y1selectat<663)
                            {
                                pselectat=313;
                            }
                            else
                            if(x1selectat>539&&x1selectat<666&&y1selectat>535&&y1selectat<663)
                            {
                                pselectat=333;
                            }
                            else
                            if(x1selectat>412&&x1selectat<539&&y1selectat>408&&y1selectat<535)
                            {
                                pselectat=223;
                            }
                            else
                                aux--;
                        }
                        else
                        if(d1<0&&d4>0&&x1selectat>50&&x1selectat<280)///S-a apasat clic pe fata 1
                        {
                            //cout<<d1<<" "<<d2<<" "<<d3<<" "<<d4<<endl;
                            if(d1<0&&d2>0&&x1selectat>50&&x1selectat<125)
                            {
                                pselectat=311;
                                //cout<<pselectat<<endl;
                            }
                            else
                            if(d1<0&&d2>0&&x1selectat>205&&x1selectat<280)
                            {
                                pselectat=331;//
                                //cout<<pselectat<<endl;
                            }
                            else
                            if(d3<0&&d4>0&&x1selectat>50&&x1selectat<125)
                            {
                                pselectat=111;//
                                //cout<<pselectat<<endl;
                            }
                            else
                            if(d3<0&&d4>0&&x1selectat>205&&x1selectat<280)
                            {
                                pselectat=131;//
                                //cout<<pselectat<<endl;
                            }
                            else
                            if(d2>0&&d3<0&&x1selectat>125&&x1selectat<205)
                            {
                                pselectat=221;
                            }
                            else
                                aux--;
                        }
                        else///S-a apasat clic pe fata 2
                        {
                            //cout<<d5<<" "<<d6<<" "<<d7<<" "<<d8<<endl;
                            if(d5>0&&d6<0&&y1selectat>50&&y1selectat<125)
                            {
                                pselectat=112;
                                //cout<<pselectat<<endl;
                            }
                            else
                            if(d5>0&&d6<0&&y1selectat>205&&y1selectat<280)
                            {
                                pselectat=312;//
                                //cout<<pselectat<<endl;
                            }
                            else
                            if(d7>0&&d8<0&&y1selectat>50&&y1selectat<125)
                            {
                                pselectat=132;//
                                //cout<<pselectat<<endl;
                            }
                            else
                            if(d7>0&&d8<0&&y1selectat>205&&y1selectat<280)
                            {
                                pselectat=332;//
                                //cout<<pselectat<<endl;
                            }
                            else
                            if(d6>0&&d7<0&&y1selectat>125&&y1selectat<205)
                            {
                                pselectat=222;
                            }
                            else
                            if(d6>0&&d7<0&&y1selectat>125&&y1selectat<205)
                            {
                                pselectat=222;
                            }
                            else
                                aux--;
                        }
                        //cout<<x1selectat<<" "<<y1selectat<<endl;
                    }
                    else
                    if(aux==2)
                    {
                        x2selectat=x;
                        y2selectat=y;

                        int d1,d2,d3,d4,d5,d6,d7,d8;

                        d1=x2selectat-y2selectat+22;
                        d2=(-75)*x2selectat+76*y2selectat-11685;
                        d3=(-75)*x2selectat+76*y2selectat-21489;
                        d4=x2selectat-y2selectat+408;

                        d5=d1;
                        d6=116*x2selectat+(-115)*y2selectat-12949;
                        d7=116*x2selectat+(-115)*y2selectat-27913;
                        d8=233*x2selectat+(-231)*y2selectat-85657;


                        if(x2selectat>280&&y2selectat>280&&x2selectat<666&&y2selectat<663)///S-a apasat clicl pe fata 3
                        {
                            if(x2selectat>280&&x2selectat<412&&y2selectat>280&&y2selectat<408&&pselectat!=113)
                            {
                                p2selectat=113;
                            }
                            else
                            if(x2selectat>539&&x2selectat<666&&y2selectat>280&&y2selectat<408&&pselectat!=133)
                            {
                                p2selectat=133;
                            }
                            else
                            if(x2selectat>280&&x2selectat<412&&y2selectat>535&&y2selectat<663&&pselectat!=313)
                            {
                                p2selectat=313;
                            }
                            else
                            if(x2selectat>539&&x2selectat<666&&y2selectat>535&&y2selectat<663&&pselectat!=333)
                            {
                                p2selectat=333;
                            }
                            else
                            if(x2selectat>412&&x2selectat<539&&y2selectat>408&&y2selectat<535&&pselectat!=223)
                            {
                                p2selectat=223;
                            }
                            else
                                aux--;
                        }
                        else
                        if(d1<0&&d4>0&&x2selectat>50&&x2selectat<280)///S-a apasat clic pe fata 1
                        {
                            //cout<<d1<<" "<<d2<<" "<<d3<<" "<<d4<<endl;
                            if(d1<0&&d2>0&&x2selectat>50&&x2selectat<125&&pselectat!=311)
                            {
                                p2selectat=311;
                                //cout<<pselectat<<endl;
                            }
                            else
                            if(d1<0&&d2>0&&x2selectat>205&&x2selectat<280&&pselectat!=331)
                            {
                                p2selectat=331;//
                                //cout<<pselectat<<endl;
                            }
                            else
                            if(d3<0&&d4>0&&x2selectat>50&&x2selectat<125&&pselectat!=111)
                            {
                                p2selectat=111;//
                                //cout<<pselectat<<endl;
                            }
                            else
                            if(d3<0&&d4>0&&x2selectat>205&&x2selectat<280&&pselectat!=131)
                            {
                                p2selectat=131;//
                                //cout<<pselectat<<endl;
                            }
                            else
                            if(d2>0&&d3<0&&x2selectat>125&&x2selectat<205&&pselectat!=221)
                            {
                                p2selectat=221;
                            }
                            else
                                aux--;
                        }
                        else///S-a apasat clic pe fata 2
                        if(d5>0&&d8<0&&y2selectat>50&&y2selectat<280)
                        {
                            //cout<<d5<<" "<<d6<<" "<<d7<<" "<<d8<<endl;
                            if(d5>0&&d6<0&&y2selectat>50&&y2selectat<125&&pselectat!=112)
                            {
                                p2selectat=112;
                                //cout<<pselectat<<endl;
                            }
                            else
                            if(d5>0&&d6<0&&y2selectat>205&&y2selectat<280&&pselectat!=312)
                            {
                                p2selectat=312;//
                                //cout<<pselectat<<endl;
                            }
                            else
                            if(d7>0&&d8<0&&y2selectat>50&&y2selectat<125&&pselectat!=132)
                            {
                                p2selectat=132;//
                                //cout<<pselectat<<endl;
                            }
                            else
                            if(d7>0&&d8<0&&y2selectat>205&&y1selectat<280&&pselectat!=332)
                            {
                                p2selectat=332;//
                                //cout<<pselectat<<endl;
                            }
                            else
                            if(d6>0&&d7<0&&y2selectat>125&&y2selectat<205&&pselectat!=222)
                            {
                                p2selectat=222;
                            }
                            else
                            if(d6>0&&d7<0&&y2selectat>125&&y2selectat<205&&pselectat!=222)
                            {
                                p2selectat=222;
                            }
                            else
                                aux--;
                        }
                        else
                        {
                            p2selectat=0;
                            pselectat=0;
                            aux=100;
                        }
                        //cout<<x2selectat<<" "<<y2selectat<<endl<<endl;
                    }
                }
            }
            else
            {
                if(x>556&&x<806&&y>556&&y<=806)
                {
                    meniu=false;
                }
                if(x>50&&x<300&&y>50&&y<300)
                {
                    meniu=false;
                    varianta=1;
                }
                if(x>300&&x<550&&y>50&&y<300)
                {
                    meniu=false;
                    varianta=2;
                }
            }

        }

        //*/
        if(1==1)
        {
            //cout<<pselectat<<" "<<p2selectat<<endl;
            if((input=='B'&&ok==2)||(pselectat==313&&p2selectat==113)||(pselectat==312&&p2selectat==112))///Li
            {
                Li();
            }
            else
            if((input=='b'&&ok==2)||(pselectat==113&&p2selectat==313)||(pselectat==112&&p2selectat==312))///L
            {
                L();
            }
            else
            if((input=='F'&&ok==2)||(pselectat==133&&p2selectat==333)||(pselectat==132&&p2selectat==332))///Ri
            {
                Ri();
            }
            else
            if((input=='f'&&ok==2)||(pselectat==333&&p2selectat==133)||(pselectat==332&&p2selectat==132))///R
            {
                R();
            }
            else
            if((input=='d'&&ok==2)||(pselectat==133&&p2selectat==113)||(pselectat==131&&p2selectat==111))///U
            {
                U();
            }
            else
            if((input=='D'&&ok==2)||(pselectat==113&&p2selectat==133)||(pselectat==111&&p2selectat==131))///Ui
            {
                Ui();
            }
            else
            if((input=='u'&&ok==2)||(pselectat==313&&p2selectat==333)||(pselectat==311&&p2selectat==331))///D
            {
                D();
            }
            else
            if((input=='U'&&ok==2)||(pselectat==333&&p2selectat==313)||(pselectat==331&&p2selectat==311))///Di
            {
                Di();
            }
            else
            if((input=='l'&&ok==2)||(pselectat==132&&p2selectat==112)||(pselectat==111&&p2selectat==311))///B
            {
                B();
            }
            else
            if((input=='L'&&ok==2)||(pselectat==112&&p2selectat==132)||(pselectat==311&&p2selectat==111))///Bi
            {
                Bi();
            }
            else
            if((input=='r'&&ok==2)||(pselectat==312&&p2selectat==332)||(pselectat==331&&p2selectat==131))///F
            {
                F();
            }
            else
            if((input=='R'&&ok==2)||(pselectat==332&&p2selectat==312)||(pselectat==131&&p2selectat==331))///Fi
            {
                Fi();
            }
            else
            if(pselectat==223&&p2selectat==221)///Intoarce cubul spre stanga
            {
                M();
                U();
                Di();
            }
            else
            if(pselectat==221&&p2selectat==223)///Intoarce cubul spre dreapota
            {
                Mi();
                Ui();
                D();
            }
            else
            if(pselectat==223&&p2selectat==222)///Intoarce cubul spre sus
            {
                S();
                Li();
                R();
            }
            else
            if(pselectat==222&&p2selectat==223)///Intoarce cubul spre jos
            {
                Si();
                L();
                Ri();
            }
            else
            if(pselectat==222&&p2selectat==221)///Intoarce cubul spre jos stanga
            {
                B();
                Pi();
                Fi();
            }
            if(pselectat==221&&p2selectat==222)///Intoarce cubul spre sus stanga
            {
                Bi();
                P();
                F();
            }
        }
        //*/
    }
    return 0;
}
