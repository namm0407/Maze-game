# The Maze🚶‍♂️‍➡️

### Demo video 🎞️
https://youtu.be/ByH3LpwpCQU

## Game Description🎮
Welcome to "The Maze," an exciting and challenging 2D game that will test your wits, strategy, and survival skills! The game features a top-down view, players can see the maze layout and plan their route. Players will be given a labyrinthine structure from a starting point to a designated exit. The primary goal is to find your way from the starting point to the exit while avoiding the monsters`M` and dead-ends. Players navigate through a series of randomly selected mazes filled with twists, turns, and lurking monsters. Each level presents a unique challenge as the maze layouts and the monsters' placements are randomly generated, ensuring a fresh and unpredictable experience every time you play. But no worries! Pick up the sword `S` to kill the monsters and find yourself a way out. Can you conquer "The Maze" and emerge victorious?


## Features🕹
* Monsters `M` & Swords`S`
   * Randomly placed in each maze, ensuring a fresh challenge every time. If a monster`M` catches you, you lose a life point! But you can kill them using the sword🗡! ⚠ you can only get one sword at a time ⚠

* Life Points ❤️
   * Players will start with 3 life points ❤️. If your life points reach zero, the game is over!

* Scoreboard
   * A scoreboard tracks and displays your current scores, personal best scores and achievements

* Dynamic Environments
   * Maze layout will be randomly selected from a collection of 6 mazes

* Limited Number Of Moves
   * The number of moves is limited to increase the level of difficulty


## How to play 
1. Use WASD to move your character through the maze.
2. Monsters `M` are randomly placed within the maze at the start of each game. You start the game with a set number of life points. Each time a monster catches you, you lose a life point. If your life points reach zero, the game is over.
3. Get your sword `S` to kill the monster `M` and escape the maze!
4. Reach the exit of the maze (E) to win the game.

## Assumptions
1. The player input must be standard input
2. The player must input valid input stated in the instruction
3. THE MAZE must be run in LINUX
4. The player can only move in four directions (Up, Down, Left and Right)
5. You can only get one sword at a time 
6. Once you have obtained a sword `S` already and got to a new position with `S`, the position will return `O` but you will not obtain two `S`
7. The maximum life point is set at 3
8. A monster can only attack one time, and after it attacks the player, it will disappear and the position will return `O`


## Code Requirements 
### 1. Generation of random events
* The maze formats 
      * The function searchAndStoreMaze opens a file named mazeLayout.txt and reads through it line by line to find a specific maze layout identified by mazeNum. After finding a maze layout, it populates a vector<vector<string>> with the maze's layout.
  
* The monsters`M` & sword `S`
      * srand(time(0)) : line seeds the random number generator, ensuring that different random values are generated each time the program runs. 


### 2. Data structures for storing data
* The players' positions are stored in a 2D vector (vector<vector<string>>)

* Row/Column numbers are stored in an array


### 3. Dynamic memory management

#### a.  Dynamic Management of the Player's Path
* The player's path is stored in a dynamically allocated vector of pairs.
  
* vector<pair<int, int>>* playerPath parameter is a pointer to a vector. It allocates memory for the vector on the heap.
  
* playerPath->push_back({playerX, playerY}); dynamically adds the player's current position to the path after each move.

#### b. Dynamic Management of the maze
* vector<vector<string>> maze parameter allows for a dynamic 2D array, where the size can be adjusted at runtime based on the maze's dimensions


### 4. File input/output (e.g., for loading/saving data)
The program can store all the variables(e.g. player's position, number of move left, current score) into a savegame.txt file upon player's request. Which can then be loaded into the game again.


### 5. Program codes in multiple files
* The main.cpp file contains basic inputs for this game. 
* Different functions will be declared and stored in separate files.


## A list of non-standard C/C++ libraries (if any)
There were no non-standard libraries used in the creation of this game.


## Compilation and Execution Instructions
1. Download the zip file
2. type `make game` command
3. type `./game` to play the game!


