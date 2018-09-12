bool tileIdentical(tile a,short x,short y,short z){
  if(a.x == x && a.y == y && a.z == z)
    return true;

  if(a.x == y && a.y == z && a.z == x)
    return true;

  if(a.x == z && a.y == x && a.z == y)
    return true;

  return false;
}

string findTile(tile cube[3][3][3],int x,int y,int z){

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if(tileIdentical(cube[i][j][k],x,y,z)){
          string pos = to_string(i)  + to_string(j) + to_string(k);

          char posX = '0';
          if(cube[i][j][k].x == x)
            posX = 'x';
          if(cube[i][j][k].y == x)
            posX = 'y';
          if(cube[i][j][k].z == x)
            posX = 'z';

          return pos  + posX;
        }
      }
    }
  }
}
