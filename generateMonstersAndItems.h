#ifndef GENERATE_MONSTERS_AND_ITEMS_H
#define GENERATE_MONSTERS_AND_ITEMS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>  // Include vector
#include <string>
using namespace std;

// Function prototype for generating monsters and items
void placeCharacter(vector<vector<string>>& maze, int width, int height, string character);

void generateMonstersAndItems(vector<vector<string>>& maze, int width, int height, int numItems);

void printMaze(const vector<vector<string>>& maze, int width, int height);

#endif
