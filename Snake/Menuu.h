#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>
#include "Snake.h"
#include "Food.h"

#pragma once
using namespace std;
class Menuu {
  
  public:

int cellSize = 30;
int cellCount =27;
int offset = 75;
void DrawMenu();
void UpdateMenu();
deque<Vector2> body = {Vector2{1,9},Vector2{0,9},Vector2{-1,9},Vector2{-2,9},Vector2{-3,9},Vector2{-4,9},Vector2{-5,9},Vector2{-6,9},Vector2{-7,9},Vector2{-8,9},Vector2{-9,9}};

deque<Vector2> body2 = {Vector2{15,15},Vector2{14,15},Vector2{13,15},Vector2{12,15},Vector2{11,15},Vector2{10,15},Vector2{9,15},Vector2{8,15},Vector2{7,15},Vector2{6,15},Vector2{5,15},Vector2{4,15},Vector2{3,15},Vector2{2,15},Vector2{1,15},Vector2{0,15},Vector2{-1,15},Vector2{-2,15},Vector2{-3,15},Vector2{-4,15}};


Vector2 direction = {0,-1};

Vector2 direction2 = {0,-1};

~Menuu(){

};

};