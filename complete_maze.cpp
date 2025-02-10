#include "complete_maze.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// need two functions (1. obtain the end point, 2. determine it is complete or not)
end_point obtain_end_point(vector<vector<string>> maze) {
  	end_point end_point;
  	for (int i = 0; i < maze.size(); ++i) {
    	for (int j = 0; j < maze[i].size(); ++j) {
          	if (maze[i][j] == "E") {  // the player start point is already changed to "🧍🏻" in updateMaze.cpp
           		end_point.x = i;
                end_point.y = j;
            }
        }
    }
    return end_point;
}

void complete_maze(end_point end_point, int PlayerX, int PlayerY, bool& completed) {
    if (PlayerX == end_point.x && PlayerY == end_point.y) {
		completed = true;
    }
}