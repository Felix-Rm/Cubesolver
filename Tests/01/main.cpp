

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

#define vizualization_delay 1

struct tile {
    int x = dummy1;
    int y = dummy1;
    int z = dummy1;
};

typedef struct tile tile;

tile cube[3][3][3];


#include <iostream>
#include <unistd.h>
#include "draw.cpp"
#include "cube.cpp"

int main()
{
    initCube(cube);

    drawCube(cube);
  
    rotateBlueClockwise(cube);
    drawCube(cube);
    

    return 0;
}
