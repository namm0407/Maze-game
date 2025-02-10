
#include "mazeSelection.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// function to generate random number; no input needed; int number returned
int mazeSelection(){
    int mazeNum = 0;
    srand(time(NULL));
    mazeNum = rand()%6+1;
    return mazeNum;
}