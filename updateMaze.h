#ifndef UPDATE_MAZE_H
#define UPDATE_MAZE_H

#include <iostream>
#include <vector>
using namespace std;

// Function declaration for updating the maze
void updateMaze(vector<vector<string>>& maze, int& playerX, int& playerY, bool &has_item, int newX, int newY, int& score, int& life_point, int& number_of_monster_killed, bool& continueGame);
void print_maze(const vector<vector<string>>& maze, int life_point, int score);

#endif