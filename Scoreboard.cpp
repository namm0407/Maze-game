#include "Scoreboard.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// update the personal_best_score
void update_personal_best_score (int &personal_best_score, int current_score){
    if (current_score >=  personal_best_score){
        personal_best_score = current_score;
    }
}

// update the score_achievement
void update_score_achievement (string &score_achievement, int current_score){
    if (current_score < 5000) {
        score_achievement = "No score achievement 😢";
    }
    else if (current_score >= 5000 && current_score < 10000) {
        score_achievement = "🥉 Achieve 5000 score points 🥉";
    }
    else if (current_score >= 10000 && current_score < 30000) {
        score_achievement = "🥈 Achieve 10000 score points 🥈";
    }
    else if (current_score >= 30000 && current_score < 35000) {
        score_achievement = "🥇 Achieve 30000 score points 🥇";
    }
    else {
        score_achievement = "💎 Achieve 35000 score points 💎";
    }
}

// update the monster_killing_achievement
void update_monster_killing_achievement (string &monster_killing_achievement, int number_of_monster_killed){
	if (number_of_monster_killed < 4) {
    	monster_killing_achievement = "No Monster Killing Achievement 😢";
    }
    else if (number_of_monster_killed >= 4 && number_of_monster_killed < 10) {
      	monster_killing_achievement = "🔪 Basic Monster Killer 🔪";
    }
    else if (number_of_monster_killed >= 10 && number_of_monster_killed < 15) {
      	monster_killing_achievement = "🏹 Intermediate monster killer 🏹";
    }
    else {
      	monster_killing_achievement = "🔫 Advanced monster killer 🔫";
    }
}

//for printing the scoreboard
void print_score_board (int life_point, int current_score, int personal_best_score, string score_achievement, int movesleft, string monster_killing_achievement, int number_of_monster_killed){
    cout << "  __________________  ________ _____________________ __________ ________ __________    _____ __________________   " << endl;
    cout << "/   _____/\\_   ___ \\ \\_____  \\\\______   \\_   _____/ \\______   \\\\_____  \\\\______   \\  /  _  \\\\______   \\______ \\  " << endl;
    cout << "\\_____  \\ /    \\  \\/  /   |   \\|       _/|    __)_   |    |  _/ /   |   \\|       _/ /  /_\\  \\|       _/|    |  \\ " << endl;
    cout << "/        \\\\     \\____/    |    \\    |   \\|        \\  |    |   \\/    |    \\    |   \\/    |    \\    |   \\|    `   \\" << endl;
    cout << "/_______  / \\______  /\\_______  /____|_  /_______  /  |______  /\\_______  /____|_  /\\____|__  /____|_  /_______  /" << endl;
    cout << "        \\/         \\/         \\/       \\/        \\/          \\/         \\/       \\/         \\/       \\/        \\/" << endl;
    cout << "==================================================================================================================" << endl;
    cout << endl << endl;
    cout << "life Point(s): ";
    for (int i = 0; i < life_point; i++){
      cout << " ❤️ ";
    }
    cout << setw(2) << life_point << endl;
    cout << "Number of moves left🏃🏻: " << movesleft << endl;
    cout << "Current Score💯: " << current_score << endl;
    update_personal_best_score(personal_best_score, current_score);
    cout << "Personal best Score💯: " << personal_best_score << endl;
    update_score_achievement (score_achievement, current_score);
    cout << "Score Achievement🏅: " << score_achievement << endl;
    update_monster_killing_achievement (monster_killing_achievement, number_of_monster_killed);
    cout << "Monster Killing Achievement🔪: " << monster_killing_achievement << endl;
}

//loading the personal_best_score from personal_best.txt
void loading_Personal_best_score (int &personal_best_score) {
    int temp_personal_best_score = 0;
    ifstream personal_best_score_file ("personal_best.txt");
    if (personal_best_score_file.fail()){  // if the file does not exist, it means there is no personal best score and needed to be set as 0
        personal_best_score = temp_personal_best_score;
    }
    else if (personal_best_score_file.peek() == ifstream::traits_type::eof()) {// if the file is empty, it means there is no personal best score and needed to be set as 0
        personal_best_score = temp_personal_best_score;
    }
    else {
        personal_best_score_file >> temp_personal_best_score;
        personal_best_score = temp_personal_best_score;
    }
    personal_best_score_file.close();
}

void store_personal_best_score (int personal_best_score){
    if (personal_best_score > 0){ // store the personal_best_score when the personal best score is greater than 0
        ofstream personal_best_score_file ("personal_best.txt"); // overwrite the file
        if (personal_best_score_file.fail()) {
            cout << "Error in storing the personal best score" << endl;
            cout << "Please try again 🙇‍♂️🙇‍♂️!!" << endl;
            personal_best_score_file.close();
        }
        else {
            personal_best_score_file << personal_best_score;
            personal_best_score_file.close();
        }
    }
}

//loading the life_point
void loading_life_point (int &life_point){
    int temp_life_point = 3;  // default life point when starting the game is set at 3
    ifstream life_point_file ("life_point.txt");
    if (life_point_file.fail()){ // conditon that the file does not exist, set the lifepoint as default
        life_point = temp_life_point;
    }
    else if (life_point_file.peek() == ifstream::traits_type::eof()){ // condition that the file is empty
        life_point = temp_life_point;
    }
    else {
        life_point_file >> temp_life_point;
         if (temp_life_point <= 0){  // condition that the life point has used up
             cout << "The player has used up all the life point 💀" << endl;
             cout << "It will start a new game 🙇‍♂️🙇‍♂️" << endl;
             life_point = 0;
         }
         else {
             life_point = temp_life_point;
         }
    }
    life_point_file.close();
}

//storing life point
void store_life_point (int life_point){
    if (life_point >= 0) { // the life_point needs to be store when the life_point is greater than 0 only
        ofstream life_point_file ("life_point.txt"); // overwrite the file
        if (life_point_file.fail()){
            cout << "Error in storing the life point(s)" << endl;
            cout << "Please try again 🙇‍♂️🙇‍♂️!!" << endl;
            life_point_file.close();
        }
        else {
            life_point_file << life_point;
            life_point_file.close();
        }
    }
}

//loading_move_left
void loading_move_left (int &move_left){
    int temp_move_left = 0;
    ifstream move_left_file ("move_left.txt");
    if (move_left_file.fail()){
        move_left = temp_move_left;
    }
    else if (move_left_file.peek() == ifstream::traits_type::eof()){
        move_left = temp_move_left;
    }
    else {
        move_left_file >> temp_move_left;
        move_left = temp_move_left;
    }
}
//storing_move_left
void store_move_left (int move_left){
    if (move_left > 0){
        ofstream move_left_file ("move_left.txt");
        if (move_left_file.fail()){
            cout << "Error in storing the move left(s)" << endl;
            cout << "Please try again 🙇‍♂️🙇‍♂️!!" << endl;
            move_left_file.close();
        }
        else {
          move_left_file << move_left;
          move_left_file.close();
        }
    }
}

void loading_current_score (int &current_score) {
    int temp_current_score = 0;
    ifstream current_score_file ("current_score.txt");
    if (current_score_file.fail()){  // if the file does not exist, it means there is no personal best score and needed to be set as 0
        current_score = temp_current_score;
    }
    else if (current_score_file.peek() == ifstream::traits_type::eof()) {// if the file is empty, it means there is no personal best score and needed to be set as 0
        current_score = temp_current_score;
    }
    else {
        current_score_file >> temp_current_score;
        current_score = temp_current_score;
    }
    current_score_file.close();
}

void store_current_score (int current_score){
    if (current_score > 0){ // store the personal_best_score when the personal best score is greater than 0
        ofstream current_score_file ("current_score.txt"); // overwrite the file
        if (current_score_file.fail()) {
            cout << "Error in storing the current_score" << endl;
            cout << "Please try again 🙇‍♂️🙇‍♂️!!" << endl;
            current_score_file.close();
        }
        else {
            current_score_file << current_score;
            current_score_file.close();
        }
    }
}
