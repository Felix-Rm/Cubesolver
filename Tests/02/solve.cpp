void executeCommand(list<char>* steps,tile cube[3][3][3]){
  char step = steps->front();

  if (step == 'R' || step == 'r')
    rotateRight(cube,step < 'r');

  if (step == 'L' || step == 'l')
    rotateLeft(cube,step < 'l');

  if (step == 'F' || step == 'f')
    rotateFront(cube,step < 'f');

  if (step == 'B' || step == 'b')
    rotateBack(cube,step < 'b');

  steps->pop_front();
}
