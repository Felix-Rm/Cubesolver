#include <iostream>
#include <unistd.h>
#include <list>

using namespace std;

#define dummy1 6
#define dummy2 7
#define dummy3 8

#define white 0
#define yellow 1
#define green 2
#define blue 3
#define orange 4
#define red 5

#define clockwise 1
#define counterclockwise 0

#define vizualization_delay 100000

struct tile {
    int x = dummy1;
    int y = dummy1;
    int z = dummy1;
};

typedef struct tile tile;

tile cube[3][3][3];

string steps;
int step_at = 0;


#include "find.cpp"
#include "draw.cpp"
#include "cube.cpp"
#include "algorithms.cpp"
#include "solve.cpp"


int main()
{
    initCube(cube);

    steps = "RRLLFFBBXFFBBx";

    mix(cube);
    drawCube(cube);

    solve(cube);

    return 0;

    while (steps.length() > step_at) {
      std::cout << step_at << " : " << steps[step_at] << '\n';
      executeCommandServo(steps[step_at],cube);
      step_at++;
      drawCube(cube);
    }


    return 0;
}
