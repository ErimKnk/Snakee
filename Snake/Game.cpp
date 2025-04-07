#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>
#include "Game.h"
#include <fstream>
#include <cstdlib>
using namespace std;


void Game::Starting()

{
  if(p==0){
while(IsKeyPressed(KEY_D)==false){

if(WindowShouldClose() == true){
  

}

ClearBackground(Green);
snake.Draw(food.yem2);
DrawText(TextFormat("Press 'D' To Start"),720,550,50,PURPLE);
DrawText(TextFormat("Point:%i",Score),offset-5,80,50,darkGreen);

DrawRectangleLinesEx(Rectangle{(float)offset-20,(float)offset+70,(float)cellSize*cellCount+1000,(float)cellSize*cellCount+70},5,darkGreen);
  EndDrawing();

  }
p++;

  }
  
  }

void Game::Draw(int i){
food.Draw(i);
snake.Draw(food.yem2);
}


void Game::Update(){
  
Starting();

if(food.yem2==3){
  
snake.UpdateWall();
Check();
CheckColl();
}
else{

snake.Update();
Check();
CheckColl();
}
}


void Game::Grow(){


snake.Grow();

}

void Game::Check(){

if(Vector2Equals(snake.body[0],food.position))

/*if(snake.body[0].x == food.position.x && snake.body[0].y == food.position.y)*/

{



food.position = food.GenerateRandomPos();
if(Score>18){
for(unsigned int i=0;i<barrier.size();i++){

while(Vector2Equals(food.position,barrier[i])||Vector2Equals(food.position,barrier2[i])){

food.position = food.GenerateRandomPos();

}

}
}
Grow();

Score++;
food.yem2=a;
a=GetRandomValue(1,9);



}

}



void Game::Reset(){

snake.body = {Vector2{6,9},Vector2{5,9},Vector2{4,9}};
snake.direction ={1,0};
Score=0;
p=0;
}

void Game::GameOver(){

ifstream infile("deneme.txt");
int l;
int g;
infile>>l;
infile.close();
if(Score>l){
ofstream outfile("deneme.txt");
outfile << Score << endl;
outfile.close();  
}
while(IsKeyPressed(KEY_SPACE) == false){

if(WindowShouldClose() == true){
CloseWindow();
  exit(0);
  
}
ifstream infile("deneme.txt");
infile>>g;
infile.close();
  DrawText(TextFormat("Game Over :("),670,350,100,DARKPURPLE);

DrawText(TextFormat("\t\t\t Score:%i",Score),670,500,75,PURPLE);

DrawText(TextFormat("\tHigh Score: %i",g),670,600,75,DARKPURPLE);


  DrawText(TextFormat("Press Space To Play Again"),640,750,50,PURPLE);

  EndDrawing();

}
Reset();
}

void Game::CheckColl(){
if(food.yem2==4){
if (snake.body[1].x == cellCount+35 || snake.body[1].x==1)
{GameOver();}

if (snake.body[1].y == cellCount+7 || snake.body[1].y==4)
{GameOver();}
if(Score>19){for(unsigned int i = 0;i<barrier.size();i++){
if(snake.body[1].x == barrier[i].x && snake.body[1].y == barrier[i].y)
{GameOver();}
}
}
}
else{

if (snake.body[1].x == cellCount+35 || snake.body[1].x==1)
{GameOver();}

if (snake.body[1].y == cellCount+7 || snake.body[1].y==4)
{GameOver();}
if(food.yem2!=7){
if(Score>19){for(unsigned int i = 0;i<barrier.size();i++){
if(snake.body[1].x == barrier[i].x && snake.body[1].y == barrier[i].y)
{GameOver();}

}
}
}

if(food.yem2!=7){
if(Score>39){for(unsigned int i = 0;i<barrier.size();i++){
if(snake.body[1].x == barrier2[i].x && snake.body[1].y == barrier2[i].y)
{GameOver();}

}
}
}
for(unsigned int i=2;i<snake.body.size();i++){

if (Vector2Equals(snake.body[1],snake.body[i])){

  GameOver();
}
}
}
}

bool Game::EventTriggered(double interval){

double currentTime = GetTime();

if(currentTime - LastUpdateTime >= interval){

LastUpdateTime = currentTime;

return true;

}
return false;

};

void Game::Barrier(){

for(unsigned int i = 0; i<barrier.size() ; i++){

float x = barrier[i].x;

float y = barrier[i].y;


Rectangle ask = Rectangle{x*cellSize,y*cellSize,30,30};

DrawRectangle(x*cellSize,y*cellSize,30,30,darkGreen);
if(food.yem2==7){
DrawRectangleLinesEx(ask,20,Color{112,31,126,50});
}
}
}

void Game::Barrier2(){

for(unsigned int i = 0; i<barrier2.size() ; i++){

float x = barrier2[i].x;

float y = barrier2[i].y;


Rectangle ask = Rectangle{x*cellSize,y*cellSize,30,30};

DrawRectangle(x*cellSize,y*cellSize,30,30,darkGreen);
if(food.yem2==7){
DrawRectangleLinesEx(ask,20,Color{112,31,126,50});
}
}
}