//#define debug_white
//#define debug_yellow

//#define debug_red
//#define debug_orange

//#define debug_green
//#define debug_blue

void initCube(tile cube[3][3][3]){

  for(int i = 0; i < 9; i++){
      cube[int(i/3)][0][int(i%3)].z = orange;
      cube[int(i/3)][2][int(i%3)].z = red;

      cube[0][int(i/3)][int(i%3)].y = white;
      cube[2][int(i/3)][int(i%3)].y = yellow;

      cube[int(i%3)][int(i/3)][0].x = green;
      cube[int(i%3)][int(i/3)][2].x = blue;
  }

  #ifdef debug_orange
      cube[0][0][1].z = white;//    orange    posIndicator      white
      cube[2][0][1].z = yellow;//   orange    posIndicator      yellow
      cube[1][0][0].z = green;//    orange    posIndicator      green
      cube[1][0][2].z = blue;//     orange    posIndicator      blue
  #endif

  #ifdef debug_red
      cube[0][2][1].z = white;//    red       posIndicator      white
      cube[2][2][1].z = yellow;//   red       posIndicator      yellow
      cube[1][2][0].z = green;//    red       posIndicator      green
      cube[1][2][2].z = blue;//     red       posIndicator      blue
  #endif

  #ifdef debug_white
      cube[0][2][1].y = red;//      white     posIndicator      red
      cube[0][0][1].y = orange;//   white     posIndicator      orange
      cube[0][1][0].y = green;//    white     posIndicator      green
      cube[0][1][2].y = blue;//     white     posIndicator      blue
  #endif

  #ifdef debug_yellow
      cube[2][2][1].y = red;//      yellow    posIndicator      red
      cube[2][0][1].y = orange;//   yellow    posIndicator      orange
      cube[2][1][0].y = green;//    yellow    posIndicator      green
      cube[2][1][2].y = blue;//     yellow    posIndicator      blue
  #endif

  #ifdef debug_green
      cube[0][1][0].x = white;//    green     posIndicator      white
      cube[2][1][0].x = yellow;//   green     posIndicator      yellow
      cube[1][0][0].x = orange;//   green     posIndicator      orange
      cube[1][2][0].x = red;//      green     posIndicator      red
  #endif

  #ifdef debug_blue
      cube[0][1][2].x = white;//    blue     posIndicator      white
      cube[2][1][2].x = yellow;//   blue     posIndicator      yellow
      cube[1][0][2].x = orange;//   blue     posIndicator      orange
      cube[1][2][2].x = red;//      blue     posIndicator      red
  #endif
}

tile rotateTileX(tile t){
  int temp = t.y;
  t.y = t.z;
  t.z = temp;
  return t;
}

tile rotateTileZ(tile t){
  int temp = t.y;
  t.y = t.x;
  t.x = temp;
  return t;
}

int rotateCoords[2][8][2] = {
  {{0,0},{2,0},{2,2},{0,2},{0,1},{1,0},{2,1},{1,2}},
  {{0,0},{0,2},{2,2},{2,0},{0,1},{1,2},{2,1},{1,0}}
};

void rotateRight(tile cube[3][3][3],short dir){
  for (int i = 0; i < 3; i++) {
    tile temp;
    temp                                                              = rotateTileX(cube[rotateCoords[0+dir][i+0][0]][rotateCoords[0+dir][i+0][1]][2]);
    cube[rotateCoords[0+dir][i+0][0]][rotateCoords[0+dir][i+0][1]][2] = rotateTileX(cube[rotateCoords[0+dir][i+1][0]][rotateCoords[0+dir][i+1][1]][2]);
    cube[rotateCoords[0+dir][i+1][0]][rotateCoords[0+dir][i+1][1]][2] = temp;

    temp                                                              = rotateTileX(cube[rotateCoords[0+dir][i+4][0]][rotateCoords[0+dir][i+4][1]][2]);
    cube[rotateCoords[0+dir][i+4][0]][rotateCoords[0+dir][i+4][1]][2] = rotateTileX(cube[rotateCoords[0+dir][i+5][0]][rotateCoords[0+dir][i+5][1]][2]);
    cube[rotateCoords[0+dir][i+5][0]][rotateCoords[0+dir][i+5][1]][2] = temp;
  }
}

void rotateLeft(tile cube[3][3][3],short dir){
  for (int i = 0; i < 3; i++) {
    tile temp;
    temp                                                              = rotateTileX(cube[rotateCoords[1-dir][i+0][0]][rotateCoords[1-dir][i+0][1]][0]);
    cube[rotateCoords[1-dir][i+0][0]][rotateCoords[1-dir][i+0][1]][0] = rotateTileX(cube[rotateCoords[1-dir][i+1][0]][rotateCoords[1-dir][i+1][1]][0]);
    cube[rotateCoords[1-dir][i+1][0]][rotateCoords[1-dir][i+1][1]][0] = temp;

    temp                                                              = rotateTileX(cube[rotateCoords[1-dir][i+4][0]][rotateCoords[1-dir][i+4][1]][0]);
    cube[rotateCoords[1-dir][i+4][0]][rotateCoords[1-dir][i+4][1]][0] = rotateTileX(cube[rotateCoords[1-dir][i+5][0]][rotateCoords[1-dir][i+5][1]][0]);
    cube[rotateCoords[1-dir][i+5][0]][rotateCoords[1-dir][i+5][1]][0] = temp;
  }
}

void rotateFront(tile cube[3][3][3],short dir){
  for (int i = 0; i < 3; i++) {
    tile temp;
    temp                                                              = rotateTileZ(cube[rotateCoords[1-dir][i+0][0]][2][rotateCoords[1-dir][i+0][1]]);
    cube[rotateCoords[1-dir][i+0][0]][2][rotateCoords[1-dir][i+0][1]] = rotateTileZ(cube[rotateCoords[1-dir][i+1][0]][2][rotateCoords[1-dir][i+1][1]]);
    cube[rotateCoords[1-dir][i+1][0]][2][rotateCoords[1-dir][i+1][1]] = temp;

    temp                                                              = rotateTileZ(cube[rotateCoords[1-dir][i+4][0]][2][rotateCoords[1-dir][i+4][1]]);
    cube[rotateCoords[1-dir][i+4][0]][2][rotateCoords[1-dir][i+4][1]] = rotateTileZ(cube[rotateCoords[1-dir][i+5][0]][2][rotateCoords[1-dir][i+5][1]]);
    cube[rotateCoords[1-dir][i+5][0]][2][rotateCoords[1-dir][i+5][1]] = temp;
  }
}

void rotateBack(tile cube[3][3][3],short dir){
  for (int i = 0; i < 3; i++) {
    tile temp;
    temp                                                              = rotateTileZ(cube[rotateCoords[0+dir][i+0][0]][0][rotateCoords[0+dir][i+0][1]]);
    cube[rotateCoords[0+dir][i+0][0]][0][rotateCoords[0+dir][i+0][1]] = rotateTileZ(cube[rotateCoords[0+dir][i+1][0]][0][rotateCoords[0+dir][i+1][1]]);
    cube[rotateCoords[0+dir][i+1][0]][0][rotateCoords[0+dir][i+1][1]] = temp;

    temp                                                              = rotateTileZ(cube[rotateCoords[0+dir][i+4][0]][0][rotateCoords[0+dir][i+4][1]]);
    cube[rotateCoords[0+dir][i+4][0]][0][rotateCoords[0+dir][i+4][1]] = rotateTileZ(cube[rotateCoords[0+dir][i+5][0]][0][rotateCoords[0+dir][i+5][1]]);
    cube[rotateCoords[0+dir][i+5][0]][0][rotateCoords[0+dir][i+5][1]] = temp;
  }
}
