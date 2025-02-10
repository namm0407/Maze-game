// include libraries here
#include <iostream>
#include <string>
#include <vector>
#include <utility> // For pair

using namespace std;

// include header files here
#include "Scoreboard.h"
#include "generateMonstersAndItems.h"
#include "mazeSelection.h"
#include "searchAndStoreMaze.h"
#include "menuScreens.h"
#include "printInstructions.h"
#include "moveValidationAndCount.h"
#include "UpdateScore.h"
#include "updateMaze.h"
#include "complete_maze.h"

void toUpperCase(string &input) {
    for (char &c : input) {
        c = toupper(c);
    }
}

int main(){
    // print start up/menu screen upon game initialisation 
    printStartScreen();

    string input = "";
    //variable to check if user is at MENU screen, GAME interface, PAUSE screen, or END of level screen
    string screen = "MENU";

    cout << "Welcome to Maze, a thrilling journey through a labyrinthine world where every twist and turn brings new challenges and mysteries" << endl;
    cout << " In this game, players must navigate intricate pathways, solve clever puzzles, and outsmart formidable foes lurking in the shadows." << endl;
    cout << "Ready to embark on an exciting quest? Here’s how to navigate your journey:" << endl;
    while(true){
        // ---------- game implementation here ----------
        // input function call (request user input and pass on command to other functions)
        cout << "You can type the following commands:" << endl;
        cout << "1. PLAY - Dive into the maze! Start a new adventure or load a previous quest." << endl;
        cout << "2. INSTRUCTIONS - Need a hint? Check out these friendly tips!" << endl;
        cout << "3. SCOREBOARD - See how you stack up! Check out the leaderboard of champions." << endl;
        cout << "4. QUIT - Ready to exit? Say goodbye to the maze for now." << endl;
        cin >> input;

        // Convert input to uppercase
        toUpperCase(input);
        
        int mazeWidth, mazeHeight;
        int playerX, playerY;
        int movesLeft, mazeNum, score = 0, personal_best_score = 0, life_point;
        string score_achievement;
        string monster_killing_achievement;
        int number_of_monster_killed = 0; // count the number of monster that killed by player for scoring system
        vector<vector<string>> maze; // Maze stored as a vector of vectors
        vector<pair<int, int>> playerPath; // To store the player's movement path
        bool has_item; // check whether the player has the item 🔪 or not
        bool completed = false; // check whether the maze is completed or not
        pair<int, int> playerPosition = {-1, -1}; // Initialize with invalid position
        pair<int, int> monsterPosition = {-1, -1}; // Initialize with invalid position

        //MENU screen operations
        if (screen=="MENU"){
            if (input=="PLAY"){
                // variable to check if previously playing game exists
                cout << "Now, brave adventurer, let the maze challenge begin!" << endl;

                // ---------- load game data ----------
                // create/access savefile(s); change playing to true if necessary 
                // brings back previous save if such file exists
                // load the default or stored life_point 
                bool playing = false;
                loading_life_point(life_point); // return 0 for life_point if the player has used up all the life point
                // It will only load the game data if the life_point is greater than 0
                if (life_point > 0){
                    playing = loadGameData(playerX, playerY, movesLeft, score, mazeNum, maze);
                }

                // if no previously playing games, then select random new maze 
                if (!playing){
                    // obtain random maze
                    mazeNum = mazeSelection();
                    //search for maze and store maze data
                    searchAndStoreMaze(maze, mazeNum, movesLeft);
                    movesLeft += 25;
                }
                // else load previous maze 
                else {
                // IF THERE IS PREVIOUS GAMES, IT SHOULD ALREADY BE LOADED INTO THE VARIABLES ABOVE
                    searchAndStoreMaze(maze, mazeNum, movesLeft);

                }

                // Calculate maze dimensions 
                mazeHeight = maze.size();
                mazeWidth = maze.empty() ? 0 : maze[0].size();
            
                // Initialize player's position 
                for (int i = 0; i < maze.size(); ++i) {
                    for (int j = 0; j < maze[i].size(); ++j) {
                        if (maze[i][j] == "!") { // Check if the current cell is the player's position
                            playerX = i; // Store the row
                            playerY = j; // Store the column
                        }
                    }
                }

                                   

                // generate monster/item placement for new maze 
                                      
                // Number of monsters and items to generate based on maze size 
                int numItems = (mazeWidth * mazeHeight) / 10;  
      
                generateMonstersAndItems(maze, mazeWidth, mazeHeight, numItems);


                // enter GAME
                screen = "GAME";
            }
            else if (input=="INSTRUCTIONS"){
                    printInstructions();
            }
            else if (input=="SCOREBOARD"){
                // create/access savefile(s) 
                loading_current_score(score);
                loading_move_left (movesLeft);
                loading_Personal_best_score (personal_best_score); //updating the previous personal_best_score
                loading_life_point(life_point);
                // print out scoreboard 
                print_score_board (life_point, score, personal_best_score, score_achievement, movesLeft, monster_killing_achievement, number_of_monster_killed);
            }
            else if (input=="QUIT"){
                return 0;
            }
            else {
                cout << "Invalid command. Please try again by typing (PLAY / INSTRUCTIONS / SCOREBOARD / QUIT)" << endl;
            }
        }

        //GAME screen operations
        if (screen=="GAME"){
            
            // Check if the maze is valid and print it
            if (maze.empty()) {
                cout << "Error: Maze is empty. Exiting game." << endl;
                return 1; // Or handle the error appropriately
            }

            end_point end_point = obtain_end_point(maze); //get the end point to deduce whether player complete the maze or not

            vector<pair<int, int>> playerPath;

            // sets a flag to pause the gameplay loop when a pause is called
            bool continueGame = true; 
        
            // Game loop
            while (movesLeft > 0 && continueGame) {
                print_maze(maze, life_point, score);
                string move;
                cout << "Moves left: " << movesLeft << endl;
                cout << "Enter your move (WASD / PAUSE): ";
                cin >> move;
                toUpperCase(move);
                if (move == "W" || move == "A" || move == "S" || move == "D"){
                    moveValidationAndCount(playerX, playerY, movesLeft, maze, mazeWidth, mazeHeight, &playerPath, move);

                    int new_playerX, new_playerY;
                    if (move == "W") {
                      	new_playerX = playerX - 1;
                      	new_playerY = playerY;
                    }
                    else if (move == "A") {
                      	new_playerX = playerX;
                      	new_playerY = playerY - 1;
                    }
                    else if (move == "S") {
                      	new_playerX = playerX + 1;
                      	new_playerY = playerY;
                    }
                    else {
                        new_playerX = playerX;
                        new_playerY = playerY + 1;
                    }

                    updateMaze(maze, playerX, playerY, has_item, new_playerX, new_playerY, score, life_point, number_of_monster_killed, continueGame);
                    if (!continueGame){ // condition that have moves left but life_point is zero (must end the game)
                        Update_Score(score, movesLeft, life_point, number_of_monster_killed, completed, continueGame); // update the score
                        print_score_board (life_point, score, personal_best_score, score_achievement, movesLeft, monster_killing_achievement, number_of_monster_killed); // print scoreboard after lossing the game
                        life_point = 3;
                        store_life_point(life_point);
                        clear_saved_game();
                        screen = "MENU";
                        // move to menu screen operations by ending game loop
                    }
                    else{ // condtion that life point is not zero and moved
                        complete_maze(end_point, playerX, playerY, completed); //check whether the Player complete the maze or not
                        if (completed){  // if the player completed, player win
                            ifstream win_file("win.txt"); //print the win.txt
                            if (win_file.is_open()) {
                                string line;
                                while (getline(win_file, line)) {
                                    cout << line << endl;
                                }
                                win_file.close();
                            }
                            Update_Score(score, movesLeft, life_point, number_of_monster_killed, completed, continueGame);
                            cout << "Congratulations, you have won THE MAZE. Good Job 👍🏻" << endl;
                            print_score_board (life_point, score, personal_best_score, score_achievement, movesLeft, monster_killing_achievement, number_of_monster_killed); // print scoreboard after lossing the game
                            life_point = 3;
                        	store_life_point(life_point);
                            clear_saved_game();
                            continueGame = false; //end the game
                            screen = "MENU";
                            // move to menu screen operations by ending game loop
                        }
                        else {
                            Update_Score(score, movesLeft, life_point, number_of_monster_killed, completed, continueGame);
                        }
                    }
                }

                else if (move=="PAUSE"){
                    printPauseScreen(); 

                    screen = "PAUSE";
                    
                    continueGame = false; // move to pause screen operations by ending game loop
                }
                else{
                    cout << "Invalid move! Please type (WASD / USE / PAUSE)." << endl;
                }
            }
            // condition that move is used up but not PAUSE
            if (continueGame){
                complete_maze(end_point, playerX, playerY, completed);
                if (!completed){  // conditon that the maze is not completed. Don't need to consider the life_point, it is already included in the Game loop
                    ifstream lose_file("lose.txt");
                    if (lose_file.is_open()) {
                        string line;
                        while (getline(lose_file, line)) {
                            cout << line << endl;
                        }
                        lose_file.close();
                    }
                    Update_Score(score, movesLeft, life_point, number_of_monster_killed, completed, continueGame); // update the score
                    cout << "You have run out of move 🏃🏻. Game over!" << endl;
                    print_score_board (life_point, score, personal_best_score, score_achievement, movesLeft, monster_killing_achievement, number_of_monster_killed); // print scoreboard after lossing the game
                    life_point = 3;
                    store_life_point(life_point);
                    clear_saved_game();
                    screen = "MENU";
                    // move to menu screen operations
                }
            }
        }

        //PAUSE screen operations
        if (screen=="PAUSE"){
            cout << "Paused. What would you like to do?" << endl;
            cout << "1. RESUME - Continue the game." << endl;
            cout << "2. MENU - Save run and go back to the main menu." << endl;
            cin >> input;
            toUpperCase(input);
            
            if (input=="RESUME"){
                // Maze is now automatically printed on game loop so this is unecessary
                // enter game
                screen = "GAME";
            }
        else if (input=="MENU"){
            // Try to save game state
            bool savedSuccessfully = trySaveGameData(playerX, playerY, movesLeft, score, mazeNum, maze);
            
            // Return to menu regardless of save success
            screen = "MENU";
            
            if (!savedSuccessfully) {
                cout << "Returning to menu without saving..." << endl;
        }
            else {
                store_life_point(life_point);
                store_move_left (movesLeft);
                store_personal_best_score (personal_best_score);
                store_current_score (score);
                cout << "Returning to menu..." << endl;
            }
        }

        else {
            cout << "Invalid command! Please try again by typing (PLAY / INSTRUCTIONS / SCOREBOARD / QUIT)" << endl;
        }
    }
    }
}
