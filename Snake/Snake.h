#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>
#pragma once
using namespace std;




class Snake {


public:

int cellSize = 30;

 int cellCount =27;

 int offset = 75;

deque<Vector2> body = {Vector2{6,9},Vector2{5,9},Vector2{4,9}};
Texture2D texture;
Texture2D texture2;
Vector2 direction = {1,0};

Snake();

~Snake();

void Draw(int c); 

void Update();

void Grow();

void UpdateWall();


};