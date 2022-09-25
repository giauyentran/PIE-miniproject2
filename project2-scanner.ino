#include <Servo.h>

Servo pan_servo; //create servo object to control servo
Servo tilt_servo;

int sersor_pin = A5;
int pan_pin = 9;
int tilt_pin = 10;

int pan_pos = 0;
int tilt_pos = 0;
int max_tilt_range = 60;
int max_pan_range = 60;
int prev_time = -1;
int servo_wait_time = 15;
bool tilt_movement = 0;
bool pan_movement = 1;

void setup() {
  // put your setup code here, to run once:
  pan_servo.attach(pan_pin);
  tilt_servo.attach(tilt_pin);
  pinMode(sensor_pin,INPUT);
}


void scan(){
  int dist = anglogRead(sensor_pin);
  ##transform voltage to dist
  
}

void loop() {
  //motion pattern: horizontal scan: pan servo moves first

  if (prev_time < 0){
    //if timestamp is not initialized:
    prev_time = 0;
  }

  if (pan_movement == 1){
    /*
     * pan performing the scan
     */
     if (millis() - prev_time > 15){
      pan_servo.write(pan_pos);
      prev_time = millis();

      if (pan_pos < max_pan_range){
        pan_pos += 1;
      }else{
        //one scan completed,return to starting position
        pan_pos = 0;
        tilt_movement = 1;
        pan_movement = 0;
      }
      
     }
    
    }
  
  if (tilt_movement == 1){
    /*
     * tilt performing the scan
     * will only run after the one pan horizontal is done.
     */
    if (millis() - prev_time > 15){
      tilt_servo.write(tilt_pos);
      prev_time = millis();
      tilt_movement = 0;
      pan_movement = 1;

      if (tilt_pos < max_tilt_range){
        //continue the scan
        tilt_pos += 1;
      }
      else{
        //scan completed
        tilt_pos = 0;
        tilt_servo.write(tilt_pos);
        pan_movement = 0;
        //no more scan because one whole scan is completed.
      }
    }
  }

  
}
