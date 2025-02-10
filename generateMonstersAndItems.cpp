#include "generateMonstersAndItems.h" //declaration for genrating monster and items
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

void placeCharacter(vector<vector<string>>& maze, int width, int height, string character) {
    int x, y;
    //finding "O" to place monster and items
    do {
        x = rand() % width; //random column
        y = rand() % height;//random row
    } while (maze[y][x] != "O");//check the place is O
    
    maze[y][x] = character; //place char at random position
}

void generateMonstersAndItems(vector<vector<string>>& maze, int width, int height, int numItems) {
    srand(time(0));//random number generator

    int area = width * height;
    int numMonsters = area /25; // number of monsters depends on the size of maze
    int itemPlaced = 0;
    
    for (int i = 0; i < numMonsters; i++) {
        placeCharacter(maze, width, height, "M"); // Monster char
    }

    for (int i = 0; i < numItems; i++) {
        placeCharacter(maze, width, height, "S"); // Item char
        itemPlaced++; //increment no of placed items
    }
}

void printMaze(const vector<vector<string>>& maze, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}
