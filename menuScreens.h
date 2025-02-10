
#ifndef MENUSCREENS_H
#define MENUSCREENS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void printStartScreen();
void printPauseScreen();

bool trySaveGameData(int playerX, int playerY, int movesLeft, int score, int mazeNum, const vector<vector<string>>& currentMaze);
bool loadGameData(int& playerX, int& playerY, int& movesLeft, int& score, int& mazeNum, vector<vector<string>>& currentMaze);
bool clear_saved_game();
#endif
