//#define debug_middle

void positionMiddle(tile cube[3][3][3],short color,string pos2){
  string steps,pos1,rel;

  steps = "";
  pos1 = findTile(cube,color,dummy1,dummy1);
  rel = relativeCoords(pos1,pos2);

  #ifdef debug_middle
    std::cout << "current  position: " << pos1 << '\n';
    std::cout << "goal     position: " << pos2 << '\n';
    std::cout << "relative position: " << rel << '\n';
  #endif

  if(rel.substr(0,2) + rel.substr(2,2) == "+1+1" || rel.substr(0,2) + rel.substr(2,2) == "-1-1")
    steps = "x";
  if(rel.substr(0,2) + rel.substr(2,2) == "+1-1" || rel.substr(0,2) + rel.substr(2,2) == "-1+1")
    steps = "X";
  if(rel.substr(0,2) + rel.substr(4,2) == "+1+1" || rel.substr(0,2) + rel.substr(4,2) == "-1-1")
    steps = "Z";
  if(rel.substr(0,2) + rel.substr(4,2) == "+1-1" || rel.substr(0,2) + rel.substr(4,2) == "-1+1")
    steps = "z";
  if(rel.substr(0,2) == "+2" || rel.substr(0,2) == "-2")
    steps = "zz";



  for (int i = 0; i < steps.length(); i++) {
      executeCommand(steps[i],cube,false);
  }
  drawCube(cube);

  steps = "";
  pos1 = findTile(cube,color,dummy1,dummy1);
  rel = relativeCoords(pos1,pos2);

  #ifdef debug_middle
    std::cout << "current  position: " << pos1 << '\n';
    std::cout << "goal     position: " << pos2 << '\n';
    std::cout << "relative position: " << rel << '\n';
  #endif


  if(rel == "+0+0-2" || rel == "+0+0+2")
    steps = "xzzX";
  if(rel == "+0-2+0" || rel == "+0+2+0")
    steps = "zxxZ";

  if(rel == "+0+1+1" && pos1[3] == 'x')
    steps = "xzX";
  if(rel == "+0+1-1" && pos1[3] == 'x')
    steps = "xZX";
  if(rel == "+0-1+1" && pos1[3] == 'x')
    steps = "xZX";
  if(rel == "+0-1-1" && pos1[3] == 'x')
    steps = "xzX";

  if(rel == "+0-1+1" && pos1[3] == 'z')
    steps = "zXZ";
  if(rel == "+0-1-1" && pos1[3] == 'z')
    steps = "zxZ";
  if(rel == "+0+1-1" && pos1[3] == 'z')
    steps = "xzX";
  if(rel == "+0+1+1" && pos1[3] == 'z')
    steps = "xZX";


  for (int i = 0; i < steps.length(); i++) {
      executeCommand(steps[i],cube,false);
  }
  drawCube(cube);

  #ifdef debug_middle
    pos1 = findTile(cube,color,dummy1,dummy1);
    rel = relativeCoords(pos1,pos2);
    std::cout << "current  position: " << pos1 << '\n';
    std::cout << "goal     position: " << pos2 << '\n';
    std::cout << "relative position: " << rel << '\n';
  #endif
}
