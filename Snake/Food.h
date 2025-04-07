#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>
#pragma once
using namespace std;

class Food {

public:
int cellSize = 30;
int cellCount =27;
int offset = 75;
int yem1;
int yem2;

Vector2 position;
Texture2D texture;
Texture2D texture2;
Texture2D texture3;
Texture2D texture4;
Color Red {250,0,0,250};


Food();


~Food();

void Draw(int i);

Vector2 GenerateRandomPos();



};


