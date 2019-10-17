
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm_0 = Adafruit_PWMServoDriver();
// Adafruit_PWMServoDriver pwm_1 = Adafruit_PWMServoDriver(0x41);

#define SERVOMIN  102 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  512 // this is the 'maximum' pulse length count (out of 4096)

//data begin 

uint16_t ahead[50][3] = {{329, 336, 238}, {331, 344, 226}, {333, 349, 219}, {334, 353, 212}, {336, 358, 205}, {338, 362, 198}, {339, 367, 191}, {341, 370, 185}, {342, 373, 182}, {344, 375, 178}, {346, 378, 174}, {347, 380, 170}, {349, 383, 167}, {351, 385, 163}, {352, 387, 159}, {354, 390, 155}, {355, 392, 152}, {357, 395, 148}, {359, 397, 144}, {360, 399, 141}, {362, 400, 139}, {364, 401, 138}, {365, 403, 137}, {367, 403, 135}, {368, 405, 134}, {370, 406, 132}, {372, 407, 131}, {373, 408, 129}, {375, 409, 128}, {377, 410, 126}, {378, 411, 125}, {380, 412, 124}, {382, 413, 122}, {383, 414, 121}, {385, 415, 119}, {386, 416, 118}, {388, 416, 117}, {390, 417, 116}, {391, 417, 116}, {393, 418, 115}, {395, 418, 114}, {396, 418, 114}, {398, 419, 113}, {399, 419, 112}, {401, 419, 111}, {403, 420, 111}, {404, 420, 111}, {406, 420, 111}, {408, 420, 111}, {409, 420, 111}};
uint16_t middle[50][3] = {{250, 387, 159}, {253, 391, 154}, {256, 394, 149}, {259, 397, 144}, {262, 401, 140}, {265, 404, 135}, {268, 407, 130}, {271, 408, 128}, {274, 410, 126}, {277, 411, 124}, {280, 413, 122}, {283, 414, 120}, {286, 415, 118}, {289, 416, 116}, {292, 418, 115}, {295, 419, 113}, {298, 419, 113}, {301, 419, 113}, {304, 419, 112}, {307, 420, 112}, {310, 420, 112}, {313, 419, 112}, {316, 419, 112}, {319, 418, 113}, {322, 418, 115}, {325, 416, 116}, {328, 415, 118}, {331, 414, 119}, {334, 413, 121}, {337, 412, 123}, {340, 411, 125}, {343, 409, 128}, {346, 406, 131}, {349, 404, 134}, {352, 402, 138}, {355, 399, 142}, {359, 396, 147}, {362, 392, 152}, {364, 388, 157}, {367, 384, 163}, {371, 380, 171}, {374, 375, 179}, {377, 370, 187}, {380, 362, 198}, {383, 354, 211}, {386, 344, 226}, {389, 332, 243}, {392, 321, 261}, {395, 315, 271}, {398, 308, 281}};
uint16_t back[50][3] = {{193, 418, 114}, {196, 419, 113}, {198, 420, 112}, {201, 420, 111}, {204, 421, 110}, {207, 420, 111}, {210, 420, 112}, {212, 419, 113}, {215, 418, 114}, {218, 418, 114}, {221, 417, 115}, {224, 417, 116}, {226, 415, 118}, {229, 414, 120}, {232, 413, 122}, {235, 411, 124}, {238, 410, 126}, {240, 408, 129}, {243, 407, 131}, {246, 405, 133}, {249, 403, 137}, {251, 399, 142}, {254, 396, 147}, {257, 393, 152}, {260, 390, 156}, {263, 386, 161}, {265, 383, 166}, {268, 378, 174}, {271, 372, 183}, {274, 366, 192}, {276, 360, 201}, {279, 354, 211}, {282, 344, 227}, {285, 332, 245}, {288, 319, 264}, {291, 307, 283}, {293, 294, 302}, {296, 285, 316}, {299, 277, 329}, {302, 268, 342}, {304, 260, 355}, {307, 253, 366}, {310, 249, 372}, {313, 246, 377}, {316, 243, 383}, {318, 240, 388}, {321, 238, 392}, {324, 235, 397}, {327, 232, 402}, {329, 230, 406}};
//data end

// our servo # counter
uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");

  pwm_0.begin();
  pwm_1.begin();
  
  pwm_0.setPWMFreq(50);  // Analog servos run at ~60 Hz updates
  pwm_1.setPWMFreq(50);  // Analog servos run at ~60 Hz updates

  delay(10);
}
void loop() {
  servo_sweep(0);
}

void set_servo_position(){
  uint8_t sample_num=50;
  uint8_t state = 40;
  uint8_t hang = 10;

  //ahead
    pwm_1.setPWM(0,0,ahead[0][0]);
    pwm_1.setPWM(1,0,ahead[0][1]+hang);
    pwm_1.setPWM(2,0,ahead[0][2]);
  //middle
    pwm_0.setPWM(0,0,middle[0][0]);
    pwm_0.setPWM(0,0,middle[0][1]+hang);
    pwm_0.setPWM(0,0,middle[0][2]);
  //back
    pwm_1.setPWM(0,0,back[0][0]);
    pwm_1.setPWM(0,0,back[0][1]+hang);
    pwm_1.setPWM(0,0,back[0][2]);

  for(int i=0;i<sample_num;i++){
    //ahead
      pwm_0.setPWM(0,0,ahead[i][0]);
      pwm_0.setPWM(1,0,ahead[i][1]);
      pwm_0.setPWM(2,0,ahead[i][2]);
    //middle
      pwm_1.setPWM(0,0,middle[i][0]);
      pwm_1.setPWM(0,0,middle[i][1]);
      pwm_1.setPWM(0,0,middle[i][2]);
    //back
      pwm_0.setPWM(0,0,back[i][0]);
      pwm_0.setPWM(0,0,back[i][1]);
      pwm_0.setPWM(0,0,back[i][2]);

      delay(2);
  }
  //back 
  //ahead
    pwm_0.setPWM(0,0,ahead[0][0]);
    pwm_0.setPWM(1,0,ahead[0][1]+hang);
    pwm_0.setPWM(2,0,ahead[0][2]);
  //middle
    pwm_1.setPWM(0,0,middle[0][0]);
    pwm_1.setPWM(0,0,middle[0][1]+hang);
    pwm_1.setPWM(0,0,middle[0][2]);
  //back
    pwm_0.setPWM(0,0,back[0][0]);
    pwm_0.setPWM(0,0,back[0][1]+hang);
    pwm_0.setPWM(0,0,back[0][2]);

  for(int i=0;i<sample_num;i++){
    //ahead
      pwm_1.setPWM(0,0,ahead[i][0]);
      pwm_1.setPWM(1,0,ahead[i][1]);
      pwm_1.setPWM(2,0,ahead[i][2]);
    //middle
      pwm_0.setPWM(0,0,middle[i][0]);
      pwm_0.setPWM(0,0,middle[i][1]);
      pwm_0.setPWM(0,0,middle[i][2]);
    //back
      pwm_1.setPWM(0,0,back[i][0]);
      pwm_1.setPWM(0,0,back[i][1]);
      pwm_1.setPWM(0,0,back[i][2]);
      
      delay(2);
  }
}

void set_servo_position_test(){
  uint8_t sample_num=50;
  uint8_t state = 40;
  uint8_t hang = 10;

  //ahead
    pwm_0.setPWM(0,0,ahead[0][0]);
  //   pwm_1.setPWM(1,0,ahead[0][1]+hang);
  //   pwm_1.setPWM(2,0,ahead[0][2]);
  // //middle
  //   pwm_0.setPWM(0,0,middle[0][0]);
  //   pwm_0.setPWM(0,0,middle[0][1]+hang);
  //   pwm_0.setPWM(0,0,middle[0][2]);
  // //back
  //   pwm_1.setPWM(0,0,back[0][0]);
  //   pwm_1.setPWM(0,0,back[0][1]+hang);
  //   pwm_1.setPWM(0,0,back[0][2]);

  for(int i=0;i<sample_num;i++){
    //ahead
      pwm_0.setPWM(0,0,ahead[i][0]);
    //   pwm_0.setPWM(1,0,ahead[i][1]);
    //   pwm_0.setPWM(2,0,ahead[i][2]);
    // //middle
    //   pwm_1.setPWM(0,0,middle[i][0]);
    //   pwm_1.setPWM(0,0,middle[i][1]);
    //   pwm_1.setPWM(0,0,middle[i][2]);
    // //back
    //   pwm_0.setPWM(0,0,back[i][0]);
    //   pwm_0.setPWM(0,0,back[i][1]);
    //   pwm_0.setPWM(0,0,back[i][2]);

      delay(2);
  }
  // back 
  // ahead
  //   pwm_0.setPWM(0,0,ahead[0][0]);
  //   pwm_0.setPWM(1,0,ahead[0][1]+hang);
  //   pwm_0.setPWM(2,0,ahead[0][2]);
  // //middle
  //   pwm_1.setPWM(0,0,middle[0][0]);
  //   pwm_1.setPWM(0,0,middle[0][1]+hang);
  //   pwm_1.setPWM(0,0,middle[0][2]);
  // //back
  //   pwm_0.setPWM(0,0,back[0][0]);
  //   pwm_0.setPWM(0,0,back[0][1]+hang);
  //   pwm_0.setPWM(0,0,back[0][2]);

  // for(int i=0;i<sample_num;i++){
  //   //ahead
  //     pwm_1.setPWM(0,0,ahead[i][0]);
  //     pwm_1.setPWM(1,0,ahead[i][1]);
  //     pwm_1.setPWM(2,0,ahead[i][2]);
  //   //middle
  //     pwm_0.setPWM(0,0,middle[i][0]);
  //     pwm_0.setPWM(0,0,middle[i][1]);
  //     pwm_0.setPWM(0,0,middle[i][2]);
  //   //back
  //     pwm_1.setPWM(0,0,back[i][0]);
  //     pwm_1.setPWM(0,0,back[i][1]);
  //     pwm_1.setPWM(0,0,back[i][2]);
      
  //     delay(2);
  // }
}

void servo_sweep(int num){
  // Drive each servo one at a time
  // Serial.println(servonum);
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
    pwm_0.setPWM(num, 0, pulselen);
    delay(2);

  }

  delay(500);
  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
    pwm_0.setPWM(num, 0, pulselen);
    delay(2);

  }
  delay(500);
}

uint16_t convert(float deg){
  uint16_t result=512/225*deg+307.2;
  return result;
}