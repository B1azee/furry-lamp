#include <cassert>
#include "txlib.h"
#include <ctime>

struct square
{
    bool boat = false;
    bool hit = false;
};

using namespace std;
void paintInterface ();
void paintBoat1(int x,int y);
void paintBoat2(int x,int y);
void paintBoat3(int x,int y);
void paintBoat4(int x,int y);
void paintBoat2up(int x,int y);
void paintBoat3up(int x,int y);
void paintBoat4up(int x,int y);
void buttonBoat(RECT boatArea,int boatType);
void checkBoatRight(int i,int j, square boatk[10][10],int q);
void checkBoatUp(int ii,int jj, square boatk[10][10],int q);

int typeBoat;
bool t = false;
bool fight =false;
bool checkBoat= true;
square area [10][10];
square areaVs [10][10];
int main()
{
    srand(time(NULL));
    const int boat1 = 1;
    const int boat2 = 2;
    const int boat3 = 3;
    const int boat4 = 4;
    const int boat2up = 5;
    const int boat3up = 6;
    const int boat4up = 7;
    int boat1Lot = 0;
    int boat2Lot = 0;
    int boat3Lot = 0;
    int boat4Lot = 0;
    int boat1LotVs = 0;
    int boat2LotVs = 0;
    int boat3LotVs = 0;
    int boat4LotVs = 0;

    txCreateWindow (900,600);

    paintInterface();

    while(true)
    {

        int i = rand()%11;
        int j = rand()%10+2;
        int boatTypeVs = rand()%8;
        checkBoat = true;
        if(boatTypeVs==boat1 && boat1LotVs<4)
        {
            checkBoatRight(i,j,areaVs,3);
            if(checkBoat)
            {
                areaVs[i][j].boat = true;
                boat1LotVs=boat1LotVs+1;
            }
        }
        if(boatTypeVs==boat2 && boat2LotVs<3)
        {
            checkBoatRight(i,j,areaVs,4);
            if(checkBoat)
            {
                areaVs[i][j].boat = true;
                areaVs[i+1][j].boat = true;
                boat2LotVs=boat2LotVs+1;
            }
        }
        if(boatTypeVs==boat3 && boat3LotVs<2 )
        {
            checkBoatRight(i,j,areaVs,5);
            if(checkBoat)
            {
                areaVs[i][j].boat = true;
                areaVs[i+1][j].boat = true;
                areaVs[i+2][j].boat = true;
                boat3LotVs=boat3LotVs+1;
            }
        }
        if(boatTypeVs==boat4 && boat4LotVs<1 )
        {
            checkBoatRight(i,j,areaVs,6);
            if(checkBoat)
            {
                areaVs[i][j].boat = true;
                areaVs[i+1][j].boat = true;
                areaVs[i+2][j].boat = true;
                areaVs[i+3][j].boat = true;
                boat4LotVs=boat4LotVs+1;
            }
        }
        if(boatTypeVs==boat2up && boat2LotVs<3  )
        {
            checkBoatUp(i,j,areaVs,4);
            if(checkBoat)
            {
                areaVs[i][j].boat = true;
                areaVs[i][j-1].boat = true;
                boat2LotVs=boat2LotVs+1;
            }
        }
        if(boatTypeVs==boat3up && boat3LotVs<2 )
        {
            checkBoatUp(i,j,areaVs,5);
            if(checkBoat)
            {
                areaVs[i][j].boat = true;
                areaVs[i][j-1].boat = true;
                areaVs[i][j-2].boat = true;
                boat3LotVs=boat3LotVs+1;
            }
        }
        if(boatTypeVs==boat4up  &&   boat4LotVs<1 )
        {
            checkBoatUp(i,j,areaVs,6);
            if(checkBoat)
            {
                areaVs[i][j].boat = true;
                areaVs[i][j-1].boat = true;
                areaVs[i][j-2].boat = true;
                areaVs[i][j-3].boat = true;
                boat4LotVs=boat4LotVs+1;
            }
        }
        if( boat1LotVs == 4 && boat2LotVs == 3 &&  boat3LotVs == 2 && boat4LotVs == 1)
        {
            break;
        }
    }

    while(true)
    {
        RECT areaBoat1 = {30,360,150,390};
        RECT areaBoat2 = {30,390,150,420};
        RECT areaBoat3 = {30,420,150,450};
        RECT areaBoat4 = {30,450,150,480};
        RECT areaBoat2up = {150,360,180,480};
        RECT areaBoat3up = {180,360,210,480};
        RECT areaBoat4up = {210,360,240,480};

        if (txMouseButtons() & 1)
        {
            buttonBoat(areaBoat1,boat1);
            buttonBoat(areaBoat2,boat2);
            buttonBoat(areaBoat3,boat3);
            buttonBoat(areaBoat4,boat4);
            buttonBoat(areaBoat2up,boat2up);
            buttonBoat(areaBoat3up,boat3up);
            buttonBoat(areaBoat4up,boat4up);

            int j=0 ;
            for(int y = 30; y<330; y =y+30)
            {
                int i =0;

                for(int x = 30; x<330; x =x+30)
                {
                    RECT area1 = {x,y,x+30,y+30};
                    if (In (txMousePos(),area1) && t)
                    {
                        checkBoat =true;
                        if(typeBoat==boat1 && boat1Lot<4)
                        {
                            checkBoatRight(i,j,area,3);
                            if(checkBoat)
                            {
                                area[i][j].boat = true;
                                paintBoat1(x,y);
                                t = 0;
                                boat1Lot=boat1Lot+1;
                            }

                        }
                        if(typeBoat==boat2  && boat2Lot<3)
                        {
                            checkBoatRight(i,j,area,4);
                            if(checkBoat)
                            {

                                area[i][j].boat = true;
                                area[i+1][j].boat = true;
                                paintBoat2(x,y);
                                t = 0;
                                boat2Lot=boat2Lot+1;
                            }
                        }
                        if(typeBoat==boat3 &&   boat3Lot<2 )
                        {
                            checkBoatRight(i,j,area,5);
                            if(checkBoat)
                            {
                                area[i][j].boat = true;
                                area[i+1][j].boat = true;
                                area[i+2][j].boat = true;
                                paintBoat3(x,y);
                                t = 0;
                                boat3Lot=boat3Lot+1;
                            }
                        }
                        if(typeBoat==boat4 &&  boat4Lot<1)
                        {
                            checkBoatRight(i,j,area,6);
                            if(checkBoat)
                            {
                                area[i][j].boat = true;
                                area[i+1][j].boat = true;
                                area[i+2][j].boat = true;
                                area[i+3][j].boat = true;
                                paintBoat4(x,y);
                                t = 0;
                                boat4Lot=boat4Lot+1;
                            }
                        }
                        if(typeBoat==boat2up && boat2Lot <3  )
                        {
                            checkBoatUp(i,j,area,4);
                            if(checkBoat)
                            {
                                area[i][j].boat = true;
                                area[i][j-1].boat = true;
                                paintBoat2up(x,y);
                                t = 0;
                                boat2Lot=boat2Lot+1;
                            }
                        }
                        if(typeBoat==boat3up   && boat3Lot<2 )
                        {
                            checkBoatUp(i,j,area,5);
                            if(checkBoat)
                            {
                                area[i][j].boat = true;
                                area[i][j-1].boat = true;
                                area[i][j-2].boat = true;
                                paintBoat3up(x,y);
                                t = 0;
                                boat3Lot=boat3Lot+1;
                            }
                        }
                        if(typeBoat==boat4up  &&   boat4Lot<1 )
                        {
                            checkBoatUp(i,j,area,6);
                            if(checkBoat)
                            {
                                area[i][j].boat = true;
                                area[i][j-1].boat = true;
                                area[i][j-2].boat = true;
                                area[i][j-3].boat = true;
                                paintBoat4up(x,y);
                                t = 0;
                                boat4Lot=boat4Lot+1;
                            }
                        }
                    }
                    i++;
                }
                j++;
            }
        }
        if (txMouseButtons() & 1)
        {
            RECT areaFight = {240,360,330,480};
            if (In (txMousePos(),areaFight))
            {
                int win = 0;
                while(true)
                {
                    if(!fight)
                    {
                        if (!(txMouseButtons() & 1) )
                        {
                            continue;
                        }
                        int j=0 ;
                        for(int y = 30; y<330; y =y+30)
                        {
                            int i =0;
                            for(int x = 570; x<870; x =x+30)
                            {
                                RECT area1 = {x,y,x+30,y+30};
                                if (In (txMousePos(),area1) && !areaVs[i][j].hit )
                                {
                                    if(!areaVs[i][j].boat )
                                    {
                                        txSetFillColor (RGB (100,100,100));
                                        txRectangle(x,y,x+30,y+30);
                                        areaVs[i][j].hit =true;
                                        txSleep(1000);
                                        fight=true;
                                        continue;
                                    }
                                    if(areaVs[i][j].boat )
                                    {
                                        txSetFillColor (RGB (255,0,0));
                                        txRectangle(x,y,x+30,y+30);
                                        areaVs[i][j].hit = true;
                                        txSleep(1000);
                                        fight=false;
                                        win = win + 1;
                                        continue;
                                    }
                                }
                                i++;
                            }
                            j++;
                        }
                    }
                    if(fight)
                    {
                        int f = rand()%10;
                        int g = rand()%10;

                        if(!area[f][g].boat && !area[f][g].hit )
                        {
                            txSetFillColor (RGB (100,100,100));
                            txRectangle(f*30+30,g*30+30,f*30+60,g*30+60);
                            area[f][g].hit = true;
                            txSleep(1000);
                            fight=false;
                            continue;
                        }
                        if(area[f][g].boat && !area[f][g].hit)
                        {
                            txSetFillColor (RGB (255,0,0));
                            txRectangle(f*30+30,g*30+30,f*30+60,g*30+60);
                            area[f][g].hit = true;
                            txSleep(1000);
                            fight=true;
                            continue;
                        }
                    }
                    if(win == 20)
                    {
                        txSetFillColour(RGB(0,200,0));
                        txRectangle(0,0,900,900);
                    }
                }
            }
        }
    }
    return 0;
}
void paintBoat1(int x,int y)
{
    txSetFillColor (RGB (0, 255, 0));
    txRectangle(x+5,y+5,x+25,y+25);
    txSetFillColor (RGB (0,100, 0));
    txCircle(x+15,y+15,7);
}
void paintBoat2(int x,int y)
{
    txSetFillColor (RGB (0, 255, 0));
    txRectangle(x+5,y+5,x+55,y+25);
    txSetFillColor (RGB (0,100,0));
    txCircle(x+15,y+15,7);
}
void paintBoat3(int x,int y)
{
    txSetFillColor (RGB (0, 255, 0));
    txRectangle(x+5,y+5,x+85,y+25);
    txSetFillColor (RGB (0,100,0));
    txCircle(x+15,y+15,7);
}
void paintBoat4(int x,int y)
{
    txSetFillColor (RGB (0, 255, 0));
    txRectangle(x+5,y+5,x+115,y+25);
    txSetFillColor (RGB (0,100,0));
    txCircle(x+15,y+15,7);;
}
void paintBoat2up(int x,int y)
{
    txSetFillColor (RGB (0, 255, 0));
    txRectangle(x+5,y+25,x+25,y-25);
    txSetFillColor (RGB (0,100,0));
    txCircle(x+15,y+15,7);
}
void paintBoat3up(int x,int y)
{
    txSetFillColor (RGB (0, 255, 0));
    txRectangle(x+5,y+25,x+25,y-55);
    txSetFillColor (RGB (0,100,0));
    txCircle(x+15,y+15,7);
}
void paintBoat4up(int x,int y)
{
    txSetFillColor (RGB (0, 255, 0));
    txRectangle(x+5,y+25,x+25,y-85);
    txSetFillColor (RGB (0,100,0));
    txCircle(x+15,y+15,7);
}
void paintInterface()
{
    txSetFillColor (RGB (0, 0, 255));
    txRectangle(30,30,331,331);
    txRectangle(570,30,871,331);
    txSetFillColor (RGB (0, 255, 255));
    txRectangle(30,360,150,390);
    txRectangle(30,390,150,420);
    txRectangle(30,420,150,450);
    txRectangle(30,450,150,480);
    txRectangle(150,360,180,480);
    txRectangle(180,360,210,480);
    txRectangle(210,360,240,480);
    txSetFillColour(RGB(200,0,0));
    txRectangle(240,360,330,480);

    paintBoat1(30,360);
    paintBoat2(30,390);
    paintBoat3(30,420);
    paintBoat4(30,450);
    paintBoat2up(150,450);
    paintBoat3up(180,450);
    paintBoat4up(210,450);

    for(int h =30 ; h<360; h=h+30)
    {
        txSetColor (RGB (0, 0, 0));
        txLine(h,30,h,330);
        txLine(30,h,330,h);

    }
    for(int h =30 ; h<360; h=h+30)
    {
        txSetColor (RGB (0, 0, 0));
        txLine(h+570,30,h+570,330);
        txLine(570,h,870,h);

    }
}
void buttonBoat(RECT boatArea,int boatType)
{

    if (In (txMousePos(),boatArea))
    {
        typeBoat = boatType;
        t = true ;
    }
}
void checkBoatRight(int ii,int jj, square boatk[10][10],int q)
{
    ii--;
    jj--;
    for(int i = ii; i<ii+q; i++)
    {
        for(int j = jj; j<jj+3; j++)
        {
            if(boatk[i][j].boat==true or i>10 or j<-1)
            {
                checkBoat = 0;
            }

        }
    }
}

void checkBoatUp(int ii,int jj, square boatk[10][10],int q)
{
    ii--;
    jj++;
    for(int i = ii; i<ii+3; i++)
    {
        for(int j = jj; j>jj-q; j--)
        {
            if(boatk[i][j].boat==true or i>10 or j<-1)
            {
                checkBoat = 0;
            }

        }
    }
}
