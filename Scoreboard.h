#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <iostream>
#include <string>

using namespace std;

void update_personal_best_score (int &personal_best_score, int current_score);

void print_score_board (int life_point, int current_score, int personal_best_score, string score_achievement, int movesleft, string monster_killing_achievement, int number_of_monster_killed);

void loading_Personal_best_score (int &personal_best_score);

void store_personal_best_score (int personal_best_score);

void loading_life_point (int &life_point);

void store_life_point (int life_point);

void loading_move_left (int &move_left);

void store_move_left (int move_left);

void loading_current_score (int &current_score);

void store_current_score (int current_score);
#endif //SCOREBOARD_H
