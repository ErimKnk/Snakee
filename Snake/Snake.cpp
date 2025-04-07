#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>
using namespace std;
#include "Snake.h"

Snake::Snake(){
    
/*Image image = LoadImage("snake.png");

Image image2 = LoadImage("indir.png");

texture = LoadTextureFromImage(image);

texture2 = LoadTextureFromImage(image2);

UnloadImage (image);

UnloadImage (image2);
*/
}


Snake::~Snake(){

//UnloadTexture(texture);
//UnloadTexture(texture2);

}

void Snake::Draw(int c){




for(unsigned int i = 0; i<body.size() ; i++){

float x = body[i].x;

float y = body[i].y;

Rectangle segment = Rectangle{x*cellSize,y*cellSize,30,30};

if(c==3){
if (i==0){
DrawRectangle(x*cellSize+7.5,y*cellSize+7.5,15,15,RED);}
else if (i==1){


DrawRectangleRounded (segment,0.5,6,PURPLE);
}
else
DrawRectangleRounded (segment,0.5,6,DARKGREEN);
}
else if(c==4){
    
    if (i==0){
DrawRectangle(x*cellSize+7.5,y*cellSize+7.5,15,15,RED);}
else if (i==1){


DrawRectangleRounded (segment,0.5,6,YELLOW);
}
else{
DrawRectangleRounded (segment,0.5,6,DARKGREEN);
DrawRectangleRoundedLines(segment,0.5,6,10,Color{253,249,0,20});}
}

else if(c==5){
    
    if (i==0){
DrawRectangle(x*cellSize+7.5,y*cellSize+7.5,15,15,RED);
//DrawRectangleLinesEx(segment,1,Color{0,121,241,20});
}
else if (i==1){


DrawRectangleRounded (segment,0.5,6,BLUE);
//DrawRectangleLinesEx(segment,30,Color{0,121,241,20});
}
else{
DrawRectangleRounded (segment,0.5,6,DARKGREEN);
DrawRectangleRoundedLines(segment,0.5,6,10,Color{0,121,241,20});}

}

else if(c==6){
    
    if (i==0){
DrawRectangle(x*cellSize+7.5,y*cellSize+7.5,15,15,RED);
//DrawRectangleLinesEx(segment,1,Color{0,121,241,20});
}
else if (i==1){


DrawRectangleRounded (segment,0.5,6,ORANGE);
//DrawRectangleLinesEx(segment,30,Color{0,121,241,20});
}
else{
DrawRectangleRounded (segment,0.5,6,DARKGREEN);
DrawRectangleRoundedLines(segment,0.5,6,10,Color{255,161,0,20});}

}
else if(c==7){
    
    if (i==0){
DrawRectangle(x*cellSize+7.5,y*cellSize+7.5,15,15,RED);
//DrawRectangleLinesEx(segment,1,Color{0,121,241,20});
}
else if (i==1){


DrawRectangleRounded (segment,0.5,6,DARKPURPLE);
//DrawRectangleLinesEx(segment,30,Color{112,31,126,50});
}
else{
DrawRectangleRounded (segment,0.5,6,DARKGREEN);
//DrawRectangleRoundedLines(segment,0.5,6,10,Color{0,121,241,20});
}

}

else{
if (i==0){
DrawRectangle(x*cellSize+7.5,y*cellSize+7.5,15,15,RED);

}
else if(i==1){
DrawRectangleRounded (segment,0.5,6,Color{70,70,70,255});
}
else
DrawRectangleRounded (segment,0.5,6,DARKGREEN);

}





}
}

void Snake::Update(){

if(body[0].x+direction.x==body[1].x && body[0].y+direction.y==body[1].y){

direction.x=-direction.x;
direction.y=-direction.y;

}


body.pop_back();

body.push_front(Vector2Add(body[0],direction));



}


void Snake::Grow(){

body.push_back(Vector2Add(body[body.size()-1],Vector2Multiply({-1,-1},direction)));

}

void Snake::UpdateWall(){

    if(body[0].x+direction.x==body[1].x && body[0].y+direction.y==body[1].y){

direction.x=-direction.x;
direction.y=-direction.y;}

if (body[0].x == cellCount+34)
{
body.pop_back();

body.push_front(Vector2Add(body[0],{-58,0}));
}
else if( body[0].x==2)
{
body.pop_back();

body.push_front(Vector2Add(body[0],{58,0}));
}

else if(body[0].y == cellCount+6) 
{
body.pop_back();

body.push_front(Vector2Add(body[0],{0,-27}));
}
else if( body[0].y==5)
{
body.pop_back();

body.push_front(Vector2Add(body[0],{0,27}));
}
else{
body.pop_back();

body.push_front(Vector2Add(body[0],direction));
}




}