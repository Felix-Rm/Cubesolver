///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////LEFT//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void rotate_left_a(){
  rotate_face(
  &cube[1][1][0], &cube[1][3][0], &cube[3][3][0], &cube[3][1][0],
  &cube[1][2][0], &cube[2][3][0], &cube[3][2][0], &cube[2][1][0] );

  rotate_perm(
  &cube[0][1][1], &cube[0][2][1], &cube[0][3][1],
  &cube[1][4][1], &cube[2][4][1], &cube[3][4][1],
  &cube[4][1][1], &cube[4][2][1], &cube[4][3][1],
  &cube[1][0][1], &cube[2][0][1], &cube[3][0][1] );
}

void rotate_left_c(){
  rotate_face(
  &cube[1][1][0], &cube[3][1][0], &cube[3][3][0], &cube[1][3][0],
  &cube[1][2][0], &cube[2][1][0], &cube[3][2][0], &cube[2][3][0] );

  rotate_perm(
  &cube[0][1][1], &cube[0][2][1], &cube[0][3][1],
  &cube[1][0][1], &cube[2][0][1], &cube[3][0][1],
  &cube[4][1][1], &cube[4][2][1], &cube[4][3][1],
  &cube[1][4][1], &cube[2][4][1], &cube[3][4][1] );
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////RIGHT/////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void rotate_right_a(){
  rotate_face(
  &cube[1][1][4], &cube[1][3][4], &cube[3][3][4], &cube[3][1][4],
  &cube[1][2][4], &cube[2][3][4], &cube[3][2][4], &cube[2][1][4] );

  rotate_perm(
  &cube[0][1][1], &cube[0][2][1], &cube[0][3][1],
  &cube[1][4][1], &cube[2][4][1], &cube[3][4][1],
  &cube[4][1][1], &cube[4][2][1], &cube[4][3][1],
  &cube[1][0][1], &cube[2][0][1], &cube[3][0][1] );
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////FRONT/////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////BACK//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////X - AXIS//////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////Y - AXIS//////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void rotate_face(byte* n1, byte* n2, byte* n3, byte* n4, byte* n5, byte* n6, byte* n7, byte* n8){
  byte* temp;

  *temp = *n1;
  *n1 = *n2;
  *n2 = *n3;
  *n3 = *n4;
  *n4 = *temp;

  *temp = *n5;
  *n5 = *n6;
  *n6 = *n7;
  *n7 = *n8;
  *n8 = *temp;
}

void rotate_perm(byte* a1, byte* a2, byte* a3, byte* b1, byte* b2, byte* b3,byte* c1, byte* c2, byte* c3,byte* d1, byte* d2, byte* d3){
  byte* temp1; 
  byte* temp2; 
  byte* temp3; 
  
  *temp1 = *a1;
  *temp2 = *a2;
  *temp3 = *a3;
  
  *a1 = *b1;
  *a2 = *b2;
  *a3 = *b3;
  
  *b1 = *c1;
  *b2 = *c2;
  *b3 = *c3;
  
  *c1 = *d1;
  *c2 = *d2;
  *c3 = *d3;
  
  *d1 = *temp1;
  *d2 = *temp2;
  *d3 = *temp3;
};  






