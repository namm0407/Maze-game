
#ifndef COMPLETE_MAZE_H
#define COMPLETE_MAZE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct end_point {
  int x;
  int y;
};

end_point obtain_end_point(vector<vector<string>> maze);

void complete_maze(end_point end_point, int PlayerX, int PlayerY, bool& completed);

#endif //COMPLETE_MAZE_H
