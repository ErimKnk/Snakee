#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>
using namespace std;
#include "Food.h"

 Food::Food(){
/*Image image = LoadImage("daire_gri.png");


texture = LoadTextureFromImage(image);

UnloadImage (image);
 
 
 Image image2 = LoadImage("sari_daire.png");

texture2 = LoadTextureFromImage(image2);

UnloadImage (image2);


Image image3 = LoadImage("daire_gri.png");

texture3 = LoadTextureFromImage(image3);

UnloadImage (image3);


Image image4 = LoadImage("daire_mavi.png");

texture4 = LoadTextureFromImage(image4);

UnloadImage (image4);

*/
position = GenerateRandomPos();


}



Food::~Food(){



//UnloadTexture(texture);
//UnloadTexture(texture2);
//UnloadTexture(texture3);
//UnloadTexture(texture4);

}

void Food::Draw(int i){ 

Rectangle segment = Rectangle{position.x*cellSize,position.y*cellSize,30,30};
if(i==3){

DrawRectangleRounded (segment,1,6,PURPLE);
}
else if (i==4){
    DrawRectangleRounded (segment,1,6,YELLOW);
}
else if (i==5){
    DrawRectangleRounded (segment,1,6,BLUE);
}
else if (i==6){
    DrawRectangleRounded (segment,1,6,ORANGE);
}
else if (i==7){
    DrawRectangleRounded (segment,1,6,DARKPURPLE);
}

else {DrawRectangleRounded (segment,1,6,Color{70,70,70,255});}
/*if(i==2){
DrawTexture(texture,position.x*cellSize,position.y*cellSize,WHITE);
}
if(i==3){
DrawTexture(texture2,position.x*cellSize,position.y*cellSize,WHITE);
}
if(i==4){
DrawTexture(texture4,position.x*cellSize,position.y*cellSize,WHITE);
}
else {
DrawTexture(texture3,position.x*cellSize,position.y*cellSize,WHITE);
}
}
*/
}
Vector2 Food::GenerateRandomPos(){

float x = GetRandomValue(3,cellCount+33);

float y = GetRandomValue(6,cellCount+5);

return Vector2{x,y};

}

