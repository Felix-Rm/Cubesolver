#include <Servo.h> 
#include <StepperMotor.h>
#include <IRremote.h>

IRrecv ir(33);
decode_results ir_inp;

Servo Servo_w; 
Servo Servo_e; 
Servo Servo_s; 
Servo Servo_n;

Stepper Stepper_w;
Stepper Stepper_e;
Stepper Stepper_s;
Stepper Stepper_n;

const short Servo_rel = 150;
const short Servo_grb = 10;
const short Servo_mdl = 50;
const short Servo_del = 400;

const short Stepper_90 = 500;


void setup() 
{ 
  Serial.begin(9600);
  ir.enableIRIn();

  Servo_w.attach(6);
  Servo_s.attach(7);
  Servo_e.attach(5);
  Servo_n.attach(4);

  Stepper_w.attach(40,38,36,34);
  Stepper_e.attach(49,47,45,43);
  Stepper_s.attach(41,39,37,35);
  Stepper_n.attach(48,46,44,42);

  initServos();

  ir.resume();
} 


void loop() 
{ 
  if(ir.decode(&ir_inp)){

    switch(ir_inp.value){
    case 0x8E7E21D://standby button
      initServos();
      break;
    case 0x8E720DF://mute button
      grabCube();
      break;
    case 0xFFFFFFFF://repeat code
      break;
    default:
      Serial.println(ir_inp.value,HEX);
      break;
    }

    ir.resume();
  }
} 





