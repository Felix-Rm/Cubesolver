void initCube(){
  initRow(cube[0][0],9,9,9,9,9);
  initRow(cube[0][1],9,0,0,0,9);
  initRow(cube[0][2],9,0,0,0,9);
  initRow(cube[0][3],9,0,0,0,9);
  initRow(cube[0][4],9,9,9,9,9);

  initRow(cube[1][0],9,5,5,5,9);
  initRow(cube[1][1],2,9,9,9,0);
  initRow(cube[1][2],2,9,9,9,0);
  initRow(cube[1][3],2,9,9,9,1);
  initRow(cube[1][4],9,1,1,1,9);

  initRow(cube[2][0],9,5,5,5,9);
  initRow(cube[2][1],2,9,9,9,4);
  initRow(cube[2][2],2,9,9,9,3);
  initRow(cube[2][3],2,9,9,9,1);
  initRow(cube[2][4],9,1,1,1,9);

  initRow(cube[3][0],9,5,5,5,9);
  initRow(cube[3][1],2,9,9,9,4);
  initRow(cube[3][2],2,9,9,9,2);
  initRow(cube[3][3],2,9,9,9,2);
  initRow(cube[3][4],9,1,1,1,9);

  initRow(cube[4][0],9,9,9,9,9);
  initRow(cube[4][1],9,4,4,4,9);
  initRow(cube[4][2],9,4,4,4,9);
  initRow(cube[4][3],9,4,4,4,9);
  initRow(cube[4][4],9,9,9,9,9);
}

void initRow(byte n1[],byte z1, byte z2, byte z3, byte z4, byte z5){
  n1[0] = z1;
  n1[1] = z2;
  n1[2] = z3;
  n1[3] = z4;
  n1[4] = z5;
}

