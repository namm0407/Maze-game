#ifndef MOVEVALIDATIONANDCOUNT_H
#define MOVEVALIDATIONANDCOUNT_H

#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

bool isValidMove(const vector<vector<string>>& maze, int x, int y, int mazeWidth, int mazeHeight);

void moveValidationAndCount(int &playerX, int &playerY, int &movesLeft, vector<vector<string>> &maze, int mazeWidth, int mazeHeight, vector<pair<int, int>>* playerPath, string move);

#endif 
