void grabCube(){
  Servo_w.write(Servo_rel);
  Servo_s.write(Servo_rel);
  Servo_e.write(Servo_rel);
  Servo_n.write(Servo_rel);
  delay(Servo_del);

  delay(2000);

  Servo_w.write(Servo_mdl);
  Servo_s.write(Servo_mdl);
  Servo_e.write(Servo_mdl);
  Servo_n.write(Servo_mdl);
  delay(Servo_del);

  delay(2000);

  Servo_w.write(Servo_grb);
  Servo_s.write(Servo_grb);
  Servo_e.write(Servo_grb);
  Servo_n.write(Servo_grb);
  delay(Servo_del);
}

void initServos(){
  Servo_w.write(Servo_rel);
  Servo_s.write(Servo_rel);
  Servo_e.write(Servo_rel);
  Servo_n.write(Servo_rel);
  delay(Servo_del);
}


