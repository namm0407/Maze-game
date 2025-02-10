flags = -pedantic-errors -std=c++11

all: game

# Compile each source file into an object file
Scoreboard.o: Scoreboard.cpp Scoreboard.h 
	g++ $(flags) -c $<

mazeSelection.o: mazeSelection.cpp mazeSelection.h
	g++ $(flags) -c $<

UpdateScore.o: UpdateScore.cpp UpdateScore.h
	g++ $(flags) -c $<

menuScreens.o: menuScreens.cpp menuScreens.h
	g++ $(flags) -c $<

moveValidationAndCount.o: moveValidationAndCount.cpp moveValidationAndCount.h
	g++ $(flags) -c $<

printInstructions.o: printInstructions.cpp printInstructions.h
	g++ $(flags) -c $<

searchAndStoreMaze.o: searchAndStoreMaze.cpp searchAndStoreMaze.h
	g++ $(flags) -c $<

updateMaze.o: updateMaze.cpp updateMaze.h
	g++ $(flags) -c $<

generateMonstersAndItems.o: generateMonstersAndItems.cpp generateMonstersAndItems.h
	g++ $(flags) -c $<

complete_maze.o: complete_maze.cpp complete_maze.h
	g++ $(flags) -c $<

main.o: main.cpp Scoreboard.h generateMonstersAndItems.h mazeSelection.h menuScreens.h moveValidationAndCount.h printInstructions.h searchAndStoreMaze.h UpdateScore.h updateMaze.h complete_maze.h
	g++ $(flags) -c $<

# Link all object files into the final executable
game: main.o Scoreboard.o generateMonstersAndItems.o mazeSelection.o menuScreens.o moveValidationAndCount.o printInstructions.o searchAndStoreMaze.o UpdateScore.o updateMaze.o complete_maze.o
	g++ $(flags) $^ -o game

# Clean up generated files
clean:
	rm -rf *.o game

# Archive all source files and headers
tar:
	tar -czvf game.tgz *.cpp *.h

.PHONY: all clean tar
