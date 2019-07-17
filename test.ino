
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>

Adafruit_PWMServoDriver pwm_0 = Adafruit_PWMServoDriver();
// Adafruit_PWMServoDriver pwm_1 = Adafruit_PWMServoDriver(0x41);

// #define SERVOMIN  102 // this is the 'minimum' pulse length count (out of 4096)
// #define SERVOMAX  512 // this is the 'maximum' pulse length count (out of 4096)

#define SERVOMIN 102  // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 1500 // this is the 'maximum' pulse length count (out of 4096)

//data begin

uint16_t ahead[50][3] = {{432, 277, 238}, {433, 270, 226}, {435, 265, 219}, {437, 260, 212}, {438, 256, 205}, {440, 251, 198}, {442, 247, 191}, {443, 243, 185}, {445, 241, 182}, {446, 238, 178}, {448, 236, 174}, {450, 233, 170}, {451, 231, 167}, {453, 228, 163}, {455, 226, 159}, {456, 223, 155}, {458, 221, 152}, {459, 218, 148}, {461, 216, 144}, {463, 214, 141}, {464, 213, 139}, {466, 212, 138}, {468, 211, 137}, {469, 210, 135}, {471, 209, 134}, {473, 208, 132}, {474, 207, 131}, {476, 206, 129}, {477, 205, 128}, {479, 204, 126}, {481, 203, 125}, {482, 202, 124}, {484, 201, 122}, {486, 200, 121}, {487, 199, 119}, {489, 198, 118}, {490, 197, 117}, {492, 197, 116}, {494, 196, 116}, {495, 196, 115}, {497, 196, 114}, {499, 195, 114}, {500, 195, 113}, {502, 194, 112}, {503, 194, 111}, {505, 194, 111}, {507, 194, 111}, {508, 194, 111}, {510, 194, 111}, {512, 194, 111}};
uint16_t middle[50][3] = {{352, 226, 159}, {355, 222, 154}, {358, 219, 149}, {361, 216, 144}, {364, 213, 140}, {367, 210, 135}, {370, 207, 130}, {373, 205, 128}, {376, 203, 126}, {379, 202, 124}, {382, 201, 122}, {385, 199, 120}, {388, 198, 118}, {391, 197, 116}, {395, 196, 115}, {397, 195, 113}, {400, 195, 113}, {404, 194, 113}, {407, 194, 112}, {410, 194, 112}, {413, 194, 112}, {416, 194, 112}, {419, 194, 112}, {422, 195, 113}, {425, 196, 115}, {428, 197, 116}, {431, 198, 118}, {434, 199, 119}, {437, 200, 121}, {440, 201, 123}, {443, 203, 125}, {446, 205, 128}, {449, 207, 131}, {452, 209, 134}, {455, 211, 138}, {458, 215, 142}, {461, 218, 147}, {464, 221, 152}, {467, 225, 157}, {470, 229, 163}, {473, 234, 171}, {476, 239, 179}, {479, 244, 187}, {482, 252, 198}, {485, 260, 211}, {488, 270, 226}, {491, 281, 243}, {494, 292, 261}, {497, 299, 271}, {500, 305, 281}};
uint16_t back[50][3] = {{295, 195, 114}, {297, 195, 113}, {299, 194, 113}, {301, 194, 112}, {303, 193, 111}, {305, 193, 111}, {306, 192, 110}, {308, 193, 111}, {310, 193, 111}, {312, 194, 112}, {314, 194, 112}, {316, 195, 113}, {318, 195, 114}, {319, 195, 114}, {321, 196, 115}, {323, 196, 115}, {325, 197, 116}, {327, 197, 116}, {329, 198, 118}, {331, 199, 119}, {332, 200, 121}, {334, 201, 122}, {336, 202, 123}, {338, 203, 125}, {340, 204, 126}, {342, 205, 128}, {344, 206, 129}, {345, 207, 131}, {347, 208, 132}, {349, 209, 134}, {351, 211, 137}, {353, 213, 140}, {355, 215, 143}, {357, 217, 147}, {359, 220, 150}, {360, 222, 153}, {362, 224, 156}, {364, 226, 160}, {366, 228, 163}, {368, 230, 166}, {370, 233, 171}, {372, 237, 177}, {373, 241, 183}, {375, 245, 189}, {377, 249, 195}, {379, 253, 201}, {381, 257, 208}, {383, 263, 216}, {385, 270, 227}, {386, 278, 239}};
//data end

// our servo # counter
uint8_t servonum = 0;

void setup()
{
  Serial.begin(115200);
  Serial.println("8 channel Servo test!");

  pwm_0.begin();
  // pwm_1.begin();

  pwm_0.setPWMFreq(50); // Analog servos run at ~60 Hz updates
  // pwm_1.setPWMFreq(50);  // Analog servos run at ~60 Hz updates

  delay(10);
}
void loop()
{
  // servo_sweep(7);
  // for(int i=0;i<3;i++){
  // // init_step();
  // }
  delay(300);
  // for(int i=0;i<5;i++){
  set_servo_position_test();
  // }
  // while(1){
  //   set_servo_position_test();
  //   delay(100);
  // }
  // test(6);
}

void init_step()
{
  //{360, 399, 141
  servo_sweep(1);
  for (int i = 0; i < 100; i++)
  {
    pwm_0.setPWM(5, 0, map(i, 0, 100, SERVOMIN, 360));
    pwm_0.setPWM(6, 0, map(i, 0, 100, SERVOMIN, 399));
    pwm_0.setPWM(7, 0, map(i, 0, 100, SERVOMIN, 141));
    delay(3);
  }
  pwm_0.setPWM(5, 0, 360);
  pwm_0.setPWM(6, 0, 399);
  pwm_0.setPWM(7, 0, 141);
}

void test(int num)
{
  //489 - 62
  int sensor = analogRead(A1);
  int a = map(sensor, 0, 1023, 50, 1500);
  // uint8_t data =pwm_0.getPWM(0);
  Serial.println(a);
  pwm_0.setPWM(num, 0, a);
}

void set_servo_position_test()
{
  uint8_t sample_num = 49;
  uint8_t state = 40;
  uint8_t hang = 10;

  for (uint16_t i = 0; i < sample_num; i += 1)
  {
    //forward
    pwm_0.setPWM(5, 0, back[i][0]);
    pwm_0.setPWM(6, 0, back[i][1]);
    pwm_0.setPWM(7, 0, back[i][2]);

    pwm_1.setPWM(9, 0, back[i][0]);
    pwm_1.setPWM(10, 0, back[i][1]);
    pwm_1.setPWM(11, 0, back[i][2]);

    pwm_0.setPWM(12, 0, back[i][0]);
    pwm_0.setPWM(13, 0, back[i][1]);
    pwm_0.setPWM(14, 0, back[i][2]);
    //backward
    pwm_1.setPWM(5, 0, back[sample_num-i][0]);
    pwm_1.setPWM(6, 0, back[sample_num-i][1]);
    pwm_1.setPWM(7, 0, back[sample_num-i][2]);

    pwm_0.setPWM(9, 0, back[sample_num-i][0]);
    pwm_0.setPWM(10, 0, back[sample_num-i][1]);
    pwm_0.setPWM(11, 0, back[sample_num-i][2]);

    pwm_1.setPWM(12, 0, back[sample_num-i][0]);
    pwm_1.setPWM(13, 0, back[sample_num-i][1]);
    pwm_1.setPWM(14, 0, back[sample_num-i][2]);
    delay(25);
  }
  delay(100);

  /*****************************************/
  for (uint16_t i = 0; i < sample_num; i += 1)
  {
    //forward
    pwm_1.setPWM(5, 0, back[i][0]);
    pwm_1.setPWM(6, 0, back[i][1]);
    pwm_1.setPWM(7, 0, back[i][2]);

    pwm_0.setPWM(9, 0, back[i][0]);
    pwm_0.setPWM(10, 0, back[i][1]);
    pwm_0.setPWM(11, 0, back[i][2]);

    pwm_1.setPWM(12, 0, back[i][0]);
    pwm_1.setPWM(13, 0, back[i][1]);
    pwm_1.setPWM(14, 0, back[i][2]);
    //backward
    pwm_0.setPWM(5, 0, back[sample_num-i][0]);
    pwm_0.setPWM(6, 0, back[sample_num-i][1]);
    pwm_0.setPWM(7, 0, back[sample_num-i][2]);

    pwm_1.setPWM(9, 0, back[sample_num-i][0]);
    pwm_1.setPWM(10, 0, back[sample_num-i][1]);
    pwm_1.setPWM(11, 0, back[sample_num-i][2]);

    pwm_0.setPWM(12, 0, back[sample_num-i][0]);
    pwm_0.setPWM(13, 0, back[sample_num-i][1]);
    pwm_0.setPWM(14, 0, back[sample_num-i][2]);
    delay(25);
  }
  delay(100);
}

void servo_sweep(int num)
{
  for (int pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen += 1)
  {
    for (int i = 0; i < 8; i++)
    {
      pwm_0.setPWM(i, 0, pulselen);
    }
    delay(3);
  }

  delay(100);
  for (int pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen -= 1)
  {
    for (int i = 0; i < 8; i++)
    {
      pwm_0.setPWM(i, 0, pulselen);
    }
    delay(3);
  }
  delay(100);
}

uint16_t convert(float deg)
{
  uint16_t result = 512 / 225 * deg + 307.2;
  return result;
}