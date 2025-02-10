
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "moveValidationAndCount.h"

using namespace std;

//check move validation
bool isValidMove(const vector<vector<string>>& maze, int x, int y, int mazeWidth, int mazeHeight) {
    return (x >= 0 && x < mazeHeight && y >= 0 && y < mazeWidth &&
            (maze[x][y] == "O" || maze[x][y] == "M" || maze[x][y] == "S"));
}


void moveValidationAndCount(int &playerX, int &playerY, int &movesLeft, vector<vector<string>> &maze, int mazeWidth, int mazeHeight, vector<pair<int, int>>* playerPath, string move) {
    int newX = playerX, newY = playerY;

    // move the player's position
    if (move == "W") {
        newX -= 1;
    } 
    else if (move == "A") {
        newY -= 1;
    } 
    else if (move == "S") {
        newX += 1;
    } 
    else if (move == "D") {
        newY += 1;
    } 

    // check if move is validated for player movenment 
    if (isValidMove(maze, newX, newY, mazeWidth, mazeHeight)) {
        // countdown
        movesLeft--;        
        playerPath->push_back({playerX, playerY});
        
    } 
    // print invalidation message
    else {
        cout << "Invalid move. Try again!" << endl;
    }
}
