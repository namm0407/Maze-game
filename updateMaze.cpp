#include "updateMaze.h"
#include <iostream>
#include <vector>
#include <fstream> 
#include <string>
using namespace std;

void print_maze(const vector<vector<string>>& maze, int life_point, int score) {
    // Check if maze is empty
    if (maze.empty() || maze[0].empty()) {
        cout << "Empty maze!" << endl;
        return;
    }

    // Print status bar
    cout << "Life: ";
    for(int i = 0; i < life_point; i++) {
        cout << "♥";
    }
    cout << "   Score: " << score << endl;

    // Print maze content
    for (const auto& row : maze) {
        for (const auto& cell : row) {
            cout << cell;
        }
        cout << endl;
    }
}

void updateMaze(vector<vector<string>>& maze, int& playerX, int& playerY, bool &has_item, int newX, int newY, int& score, int& life_point, int& number_of_monster_killed, bool& continueGame) {
    // Print the current position and the intended new position
    cout << "Player moving from (" << playerX << ", " << playerY << ") to (" << newX << ", " << newY << ")" << endl;

    // Ensure new coordinates are within maze bounds
    if (newX < 0 || newX >= maze.size() || newY < 0 || newY >= maze[0].size()) {
        cout << "Error: new position (" << newX << ", " << newY << ") is out of bounds!" << endl;
        return;
    }
    if (maze[newX][newY] == "#") {
    	cout << "You cannot walk through walk. Please try again with another direction!!" << endl;
        return;
    }

    // Handle interactions at the new position
    if (maze[newX][newY] == "S") {
        cout << "You found an item!" << endl;
        maze[newX][newY] = "O"; // Removing the weapon from the game once obtained
        has_item = true;
    }
    else if (maze[newX][newY] == "M") {
        if (has_item){
            cout << "You managed to fight off the monster!" << endl; 
            maze[newX][newY] = "O"; // Removing the monster from the game once attacked by player with weapon
            has_item = false; //item is a consumable
            number_of_monster_killed++; //update the number_of_monster_killed
        }
        else{
            life_point--; // Decrease life points if encountering a monster without a weapon, 3life points
            cout << "A monster attacked you! Life points decreased by 1!" << endl;
            if (life_point == 0){
                continueGame = false;
                // Read and print lose.txt
                ifstream lose_file("lose.txt");
                if (lose_file.is_open()) {
                    string line;
                    while (getline(lose_file, line)) {
                        cout << line << endl;
                    }
                    lose_file.close();
                }
                
                cout << "You died from the attack.. Game over man! Game over!" << endl << "Returning you to the main menu..." << endl;
            }
        }
    }

    // Update the maze to reflect the player's movement
    maze[playerX][playerY] = "O"; // Clear the old position
    maze[newX][newY] = "!";    // Place the player at the new position


    // Update the player's position
    playerX = newX;
    playerY = newY;
    cout << "Player's new position: (" << playerX << ", " << playerY << ")" << endl;
}


