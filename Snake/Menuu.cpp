#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>
using namespace std;
#include "Menuu.h"


void Menuu::DrawMenu(){
for(unsigned int i = 0; i<body.size() ; i++){

float x = body[i].x;

float y = body[i].y;

Rectangle segment = Rectangle{x*cellSize,y*cellSize,30,30};


if (i==0){
DrawRectangleRounded (segment,0.5,6,Color{BLACK});}
else if (i==1){


DrawRectangleRounded (segment,0.5,6,Color{15,10,5,255});
}
else if (i==2){


DrawRectangleRounded (segment,0.5,6,Color{25,20,15,255});
}
else if (i==3){


DrawRectangleRounded (segment,0.5,6,Color{35,30,25,255});
}
else if (i==4){


DrawRectangleRounded (segment,0.5,6,Color{45,40,35,255});
}
else if (i==5){


DrawRectangleRounded (segment,0.5,6,Color{55,50,45,255});
}
else if (i==6){


DrawRectangleRounded (segment,0.5,6,Color{65,60,55,255});
}

else
DrawRectangleRounded (segment,0.5,6,Color{75,70,65,255});

}
for(unsigned int i = 0; i<body2.size() ; i++){

float x2 = body2[i].x;

float y2 = body2[i].y;

Rectangle segment = Rectangle{x2*cellSize,y2*cellSize,30,30};


if (i==0){



DrawRectangleRounded (segment,0.5,6,BLACK);
}
else
DrawRectangleRounded (segment,0.5,6,DARKGREEN);

}


}

void Menuu::UpdateMenu(){





if (body[0].x == cellCount+35)
{direction={0,1};}



if (body[0].y == cellCount+7 )
{direction={-1,0};}


if(body[0].x==1 )
{direction={0,-1};}

if(body[0].y==1 && body[0].x==1)
{ direction={1,0};}

if(body[0].y==1)
{ direction={1,0};}

if(body[0].y==1 && body[0].x == cellCount+35)
{direction={0,1};}


if (body2[0].x == cellCount+26)
{direction2={0,1};}



if (body2[0].y == cellCount+3 )
{direction2={-1,0};}


if(body2[0].x==12 )
{direction2={0,-1};}

if(body2[0].y==15 && body2[0].x==12)
{ direction2={1,0};}

if(body2[0].y==15)
{ direction2={1,0};}

if(body2[0].y==15 && body2[0].x == cellCount+26)
{direction2={0,1};}


body.pop_back();

body.push_front(Vector2Add(body[0],direction));

body2.pop_back();

body2.push_front(Vector2Add(body2[0],direction2));

}