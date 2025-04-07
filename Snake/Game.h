#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>
#include "Snake.h"
#include "Food.h"

#pragma once
using namespace std;
class Game {
  
  public:

int cellSize = 30;
int cellCount =27;
int offset = 75;
int Score = 0;
int a = 3;

Snake snake = Snake();
Food food = Food();
void Draw (int i);
void Update ();
void Grow ();
void Check();
void Reset();
void GameOver();
int p=0;
Color Green {150,95,20,150};
Color darkGreen {43,51,24,255};
void CheckColl();
double LastUpdateTime = 0;
bool EventTriggered(double interval);
void Starting();
void Barrier();
void Barrier2();
deque<Vector2> barrier = {Vector2{50,5},Vector2{50,6},Vector2{50,7},Vector2{50,8},Vector2{50,9},Vector2{50,10},Vector2{50,11},Vector2{50,12}};
deque<Vector2> barrier2 = {Vector2{10,33},Vector2{10,32},Vector2{10,31},Vector2{10,30},Vector2{10,29},Vector2{10,28},Vector2{10,27},Vector2{10,26}};

};