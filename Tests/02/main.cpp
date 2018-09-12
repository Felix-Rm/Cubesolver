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

list<char> steps;

#include "draw.cpp"
#include "cube.cpp"
#include "solve.cpp"

int main()
{
    initCube(cube);

    steps.push_back('R');
    steps.push_back('R');
    steps.push_back('L');
    steps.push_back('L');
    steps.push_back('B');
    steps.push_back('B');
    steps.push_back('F');
    steps.push_back('F');


    while (!steps.empty()) {
      std::cout << steps.size() << " : " << steps.front() << '\n';
      executeCommand(&steps,cube);
      drawCube(cube);
    }


    return 0;
}
