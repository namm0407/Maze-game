#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include "menuScreens.h"

void printStartScreen() { 
    cout << "====== Welcome to the Maze Adventure! ======" << endl;
    cout << "  _____ _            __  __               " << endl;
    cout << " |_   _| |__   ___  |  \\/  | __ _ _______ " << endl;
    cout << "   | | | '_ \\ / _ \\ | |\\/| |/ _` |_  / _ \\ " << endl;
    cout << "   | | | | | |  __/ | |  | | (_| |/ /  __/ " << endl;
    cout << "   |_| |_| |_|\\___| |_|  |_|\\__,_/___\\___| " << endl;
    cout << "============================================" << endl;
    cout << "            Created by Team 4            " << endl;
}

bool confirmSave() {
    cout << "Would you like to save your progress? (Y/N): ";
    char choice;
    cin >> choice;
    return (toupper(choice) == 'Y');
}

bool confirmOverwrite() {
    cout << "A saved game already exists." << endl;
    cout << "Would you like to overwrite it? (Y/N): ";
    char choice;
    cin >> choice;
    return (toupper(choice) == 'Y');
}


// In menuScreens.cpp
bool trySaveGameData(int playerX, int playerY, int movesLeft, int score, int mazeNum, const vector<vector<string>>& currentMaze) {
    // First check if user wants to save
    if (!confirmSave()) {
        return false;
    }

    // Check if save file exists
    ifstream checkFile("savegame.txt");
    bool saveExists = checkFile.good();
    checkFile.close();

    // If save exists, confirm overwrite
    if (saveExists && !confirmOverwrite()) {
        return false;
    }

    // Proceed with saving
    ofstream saveFile("savegame.txt");
    if (saveFile.is_open()) {
        // Save maze dimensions
        saveFile << currentMaze.size() << " " << currentMaze[0].size() << endl;
        
        // Save maze content
        for (const auto& row : currentMaze) {
            for (const string& cell : row) {
                saveFile << cell << " ";  // Add space between each cell
            }
            saveFile << endl;
        }
        
        // Save game state
        saveFile << playerX << " " << playerY << " " << movesLeft << " " << score << " " << mazeNum;
        saveFile.close();
        cout << "Game saved successfully!" << endl;
        return true;
    }
    
    cout << "Error: Could not save game." << endl;
    return false;
}

// try to load previously saved game data
bool loadGameData(int& playerX, int& playerY, int& movesLeft, int& score, int& mazeNum, vector<vector<string>>& currentMaze) {
    ifstream saveFile("savegame.txt");
    if (!saveFile) {
        return false;  // No save file exists
    }

    ifstream loadFile("savegame.txt");
    if (loadFile.is_open()) {
        // Load maze dimensions
        int height, width;
        loadFile >> height >> width;
        loadFile.ignore(); // Skip newline

        // Load maze content
        currentMaze.clear();
        currentMaze.resize(height, vector<string>(width));
        
        // Read each row
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                loadFile >> currentMaze[i][j];
            }
            loadFile.ignore(); // Skip newline
        }

        // Load game state
        loadFile >> playerX >> playerY >> movesLeft >> score >> mazeNum;
        loadFile.close();
        return true;
    }
    return false;
}

bool clear_saved_game() {
    try {
        // Open and truncate the save file (clears all content)
        ofstream save_file("save_game.txt", ios::trunc);
        
        // Check if file opened successfully
        if (!save_file.is_open()) {
            return false;
        }
        
        // Close the file
        save_file.close();
        return true;
    }
    catch (...) {
        return false;
    }
}

void printPauseScreen() {
    cout << "=========================================" << endl;
    cout << "                PAUSED                   " << endl;
    cout << "=========================================" << endl;
    cout << "RESUME - Continue your adventure" << endl;
    cout << "MENU   - Save and return to main menu" << endl;
    cout << "         (will overwrite existing saves)" << endl;
    cout << "----------------------------------------" << endl;
}
