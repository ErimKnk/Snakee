#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>
#include "Game.h"
#include "Snake.h"
#include "Food.h"
#include "Menuu.h"
#include <fstream>
#include <cstdlib>
using namespace std;


Color Green {150,95,20,150};
Color Bluisch{150,95,80,150};
Color darkGreen {43,51,24,255};

int cellSize = 30;

int cellCount =27;

int offset = 75;



int Games(){
    Game game = Game();
    



 
while(IsKeyPressed(KEY_F4)==false){

if(IsKeyReleased(KEY_ESCAPE)){
 
while(IsKeyPressed(KEY_SPACE) == false){

BeginDrawing();
ClearBackground(Bluisch);
DrawText(TextFormat("\t\t\t\tPAUSE"),offset+590,200,80,RED);
DrawText(TextFormat("\n\nPress SPACE To Continue\n\n\t\t\tPress ESC to Quit"),offset+590,200,50,darkGreen);
EndDrawing();

if(IsKeyPressed(KEY_ESCAPE)){

return 0;

}

}

}

BeginDrawing();
if(game.Score>19){
game.Barrier();
}
if(game.Score>39){
game.Barrier2();
}
if(game.food.yem2==5){

if(game.EventTriggered(0.1)){
game.Update();
}
}
else if(game.food.yem2==6){

if(game.EventTriggered(0.03)){
game.Update();
}

}
else{

if(game.EventTriggered(0.055)){
game.Update();
}

}


ClearBackground(Green);





  


if(IsKeyPressed(KEY_W) && game.snake.direction.y != 1){

game.snake.direction = {0,-1};

}

if(IsKeyPressed(KEY_A)&& game.snake.direction.x != 1){

game.snake.direction = {-1,0};

}

if(IsKeyPressed(KEY_D)&& game.snake.direction.x != -1){

game.snake.direction = {1,0};

}


if(IsKeyPressed(KEY_S)&& game.snake.direction.y != -1){

game.snake.direction = {0,1};

}

DrawText(TextFormat("Level:%i",game.Score/20+1),offset-5,30,50,BLACK);

DrawText(TextFormat("Point:%i",game.Score),offset-5,80,50,BLACK);
DrawRectangleLinesEx(Rectangle{(float)offset-20,(float)offset+70,(float)cellSize*cellCount+1000,(float)cellSize*cellCount+70},5,darkGreen);

if(game.food.yem2==3){
    DrawText(TextFormat("Snake: Teleporter"),offset+1315,80,50,PURPLE);

DrawRectangleLinesEx(Rectangle{(float)offset-20,(float)offset+70,(float)cellSize*cellCount+1000,(float)cellSize*cellCount+70},20,Color{200,122,255,50});

}

else if(game.food.yem2==4){
    DrawText(TextFormat("Snake: Ouroboros"),offset+1325,80,50,YELLOW);
}

else if(game.food.yem2==5){
    DrawText(TextFormat("Snake: Cold Blooded"),offset+1270,80,50,BLUE);

}
else if(game.food.yem2==6){
    DrawText(TextFormat("Snake: Speedy Boi"),offset+1300,80,50,ORANGE);

}
else if(game.food.yem2==7){
    DrawText(TextFormat("Snake: Tunneller"),offset+1325,80,50,DARKPURPLE);

}
else{
    DrawText(TextFormat("Snake: Normal"),offset+1430,80,50,Color{70,70,70,255});
}



game.Draw(game.a);


EndDrawing();

}





CloseWindow();

    return 0;
}


int Menu(){
Game game2 = Game();
Menuu menuu = Menuu();
int g;
ifstream infile("deneme.txt");
infile>>g;
infile.close();

while(WindowShouldClose() == false){

BeginDrawing();

if(IsKeyPressed(KEY_ENTER)==true){

return Games();

}

ClearBackground(Green);

DrawText(TextFormat("\t\t WEIRD SNAKE GAME\nPRESS            TO START"),offset+380,150,75,darkGreen);
DrawText(TextFormat("\n         ENTER"),offset+420,150,75,RED);
  DrawText(TextFormat("HIGH SCORE: %i",g),585,650,100,ORANGE);

if(game2.EventTriggered(0.01)){menuu.UpdateMenu();}

menuu.DrawMenu();

EndDrawing();

}

CloseWindow();
return 0;




}


int main () {
InitWindow(2*offset+cellSize*cellCount+960,2*offset+cellSize*cellCount+40,"Snakess"); 
ToggleFullscreen();
//ShowCursor();
HideCursor();
SetTargetFPS(60);

Menu();
   


}