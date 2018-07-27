void drawCube(){
  for(int i = 0; i < 9; i++){
    lcd.fillRect(sx + (3  + (i / 3)) * block_width, sy + (5 - (i % 3)) * block_width, block_width, block_width, block_color[cube[0][1 + (i / 3)][1 + (i % 3)]]); //top
    lcd.fillRect(sx + (11 - (i / 3)) * block_width, sy + (3 + (i % 3)) * block_width, block_width, block_width, block_color[cube[4][1 + (i / 3)][3 - (i % 3)]]); //bottom
    lcd.fillRect(sx + (6  + (i / 3)) * block_width, sy + (5 - (i % 3)) * block_width, block_width, block_width, block_color[cube[1 + (i / 3)][4][1 + (i % 3)]]); //front 
    lcd.fillRect(sx + (0  + (i / 3)) * block_width, sy + (3 + (i % 3)) * block_width, block_width, block_width, block_color[cube[3 - (i / 3)][0][3 - (i % 3)]]); //back 
    lcd.fillRect(sx + (3  + (i / 3)) * block_width, sy + (2 - (i % 3)) * block_width, block_width, block_width, block_color[cube[1 + (i % 3)][1 + (i / 3)][4]]); //right  
    lcd.fillRect(sx + (3  + (i % 3)) * block_width, sy + (6 + (i / 3)) * block_width, block_width, block_width, block_color[cube[1 + (i / 3)][1 + (i % 3)][0]]); //left
  }
}







