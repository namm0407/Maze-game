#include "UpdateScore.h"
#include <iostream>
using namespace std;

void Update_Score(int &score, int move_left, int life_point, int number_of_monster_killed, bool completed, bool continueGame){
    if (completed && continueGame) { // if the game is completed and the Player has arrived the ending point
        score = 0;
        score += (move_left * 1000);
        score += (number_of_monster_killed * 500);
        score += (life_point * 700);
    }
    else { // condition that the Player does not arrive the ending point or running out of life_point
        score = 0;
        score = (number_of_monster_killed * 500);
    }
}
