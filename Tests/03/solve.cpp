

void executeCommandServo(char step,tile cube[3][3][3]) {
  /* code */
}

void mix(tile cube[3][3][3]){
  srand(time(NULL));
  //srand(1);//front
  //srand(7);//back
  //srand(3);//right
  //srand(8);//left
  //srand(5);//bottom
  //srand(2);//top
  char posible[12] = {'R','r','L','l','F','f','B','b','X','x','Z','z'};
  for (int i = 0; i < 20; i++) {
    int num = rand()%12;
    executeCommand(posible[num],cube,false);
  }
}

void solve(tile cube[3][3][3]) {
  positionMiddle(cube,white,"011");
  positionMiddle(cube,red,"121");
}
