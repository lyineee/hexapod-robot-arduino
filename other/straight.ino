
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
// #define SERIAL_RX_BUFFER_SIZE 1
// #include <pgmspace.h>

Adafruit_PWMServoDriver pwm_0 = Adafruit_PWMServoDriver();
Adafruit_PWMServoDriver pwm_1 = Adafruit_PWMServoDriver(&Wire, 0x41);

//data begin

const PROGMEM uint16_t  straight_ahead_right[30][3] = {{111,196,91},{118,196,92},{126,195,93},{134,196,95},{142,196,97},{148,196,100},{154,197,103},{160,197,106},{166,198,109},{172,199,113},{177,200,118},{182,202,122},{186,203,127},{190,205,132},{194,207,138},{198,209,144},{202,212,150},{206,214,155},{210,217,161},{214,219,167},{217,223,175},{219,227,184},{222,232,193},{224,236,202},{226,240,210},{228,245,219},{230,249,228},{232,255,239},{233,261,250},{235,268,262}};
const PROGMEM uint16_t straight_middle_right[30][3] = {{228,222,173},{232,219,167},{236,217,163},{240,216,160},{245,215,157},{250,214,154},{255,213,151},{260,212,148},{265,211,146},{271,210,144},{276,209,142},{281,208,140},{287,207,139},{292,207,138},{298,207,139},{304,207,139},{310,207,138},{315,207,139},{320,208,140},{326,208,142},{331,209,144},{336,210,146},{341,211,148},{346,212,150},{352,213,153},{356,215,156},{360,216,160},{365,217,163},{369,219,167},{373,222,171}};
const PROGMEM uint16_t   straight_back_right[30][3] = {{261,268,261},{262,261,250},{264,255,239},{266,249,229},{268,244,218},{270,238,208},{272,235,200},{275,231,192},{278,228,184},{281,224,176},{285,221,168},{288,218,162},{291,215,156},{294,212,150},{297,209,143},{301,207,137},{305,205,132},{310,203,127},{314,202,122},{319,200,118},{324,199,114},{330,199,110},{336,198,107},{342,197,104},{348,196,101},{355,196,98},{362,196,96},{369,196,94},{377,196,92},{384,196,91}};
const PROGMEM uint16_t   straight_ahead_left[30][3] = {{355,373,467},{349,373,466},{342,373,465},{335,373,463},{328,373,462},{322,373,459},{317,372,456},{311,372,453},{306,371,450},{301,370,447},{296,369,443},{292,368,439},{288,366,435},{284,364,430},{281,363,425},{277,361,420},{273,358,414},{270,356,409},{266,354,404},{263,352,399},{260,349,392},{258,345,384},{256,341,376},{254,337,368},{252,333,360},{250,329,352},{248,325,344},{247,320,334},{246,315,325},{244,309,314}};
const PROGMEM uint16_t  straight_middle_left[30][3] = {{438,350,394},{435,352,399},{431,354,402},{427,355,405},{423,356,408},{418,357,410},{414,358,413},{409,359,416},{404,359,418},{399,360,419},{395,361,421},{390,362,423},{385,363,424},{380,363,424},{375,363,424},{370,363,424},{364,363,424},{360,363,424},{355,362,423},{350,362,422},{345,361,420},{341,360,418},{336,359,416},{332,358,414},{327,357,411},{323,356,408},{319,355,405},{315,354,403},{312,352,399},{308,350,395}};
const PROGMEM uint16_t    straight_back_left[30][3] = {{315,309,314},{313,314,325},{312,320,334},{310,325,344},{308,330,353},{307,335,362},{304,338,369},{302,341,376},{299,344,383},{296,347,390},{293,350,398},{290,353,403},{288,356,409},{285,358,414},{282,361,420},{279,363,425},{275,365,430},{271,366,435},{267,368,439},{262,369,443},{258,370,447},{253,370,450},{247,371,453},{242,372,456},{236,372,458},{230,373,461},{224,373,463},{217,373,464},{210,373,466},{204,373,467}};
//left 
const PROGMEM uint16_t  turn_right_ahead_right[30][3] = {{280,196,91},{281,196,91},{281,196,91},{282,196,91},{282,195,91},{283,195,91},{284,195,91},{284,195,91},{285,195,90},{286,195,90},{286,195,90},{287,195,90},{287,195,90},{288,195,90},{289,195,90},{289,195,90},{290,195,90},{291,195,90},{291,195,90},{292,195,90},{293,195,90},{294,195,90},{294,195,90},{295,195,90},{296,196,90},{297,196,90},{297,196,90},{298,196,90},{299,196,90},{299,196,90}};
const PROGMEM uint16_t turn_right_middle_right[30][3] = {{274,209,143},{275,209,143},{277,209,142},{279,209,141},{281,208,141},{283,208,140},{284,208,140},{286,207,139},{288,207,139},{290,207,139},{292,207,138},{293,207,139},{295,207,139},{297,207,139},{299,207,139},{301,207,139},{303,207,139},{305,207,138},{307,207,138},{309,207,138},{311,207,138},{312,207,138},{314,207,139},{316,207,139},{318,208,140},{320,208,140},{321,208,140},{323,208,140},{325,208,141},{327,209,142}};
const PROGMEM uint16_t   turn_right_back_right[30][3] = {{215,196,92},{214,196,92},{213,196,92},{213,196,91},{212,196,91},{212,196,91},{211,196,91},{210,196,91},{209,196,91},{209,196,91},{208,196,91},{208,196,91},{207,196,91},{206,196,91},{206,196,91},{205,196,90},{204,196,90},{204,196,90},{203,196,90},{202,196,90},{201,196,90},{201,196,90},{200,196,90},{199,196,90},{199,196,90},{198,196,91},{197,196,91},{196,196,91},{196,196,91},{195,196,91}};
//right
const PROGMEM uint16_t  turn_left_ahead_left[30][3] = {{204,373,467},{203,373,467},{203,373,467},{202,373,467},{202,373,467},{201,373,467},{200,373,467},{200,373,467},{199,373,468},{199,373,468},{198,373,468},{198,373,468},{197,373,468},{197,373,468},{196,373,468},{195,373,468},{195,373,468},{194,373,468},{193,373,468},{193,373,468},{192,373,468},{192,373,468},{191,373,468},{190,373,468},{189,373,468},{189,373,468},{188,373,468},{188,373,468},{187,373,468},{186,373,468}};
const PROGMEM uint16_t turn_left_middle_left[30][3] = {{397,361,420},{395,361,421},{394,361,421},{392,361,422},{390,362,422},{389,362,423},{387,362,423},{385,363,424},{384,363,424},{382,363,424},{381,363,424},{379,363,424},{377,363,424},{376,363,424},{374,363,424},{372,363,424},{370,363,424},{369,363,424},{367,363,424},{365,363,424},{364,363,425},{362,363,424},{361,363,424},{359,363,424},{357,362,423},{356,362,423},{354,362,423},{353,362,423},{351,362,422},{349,361,421}};
const PROGMEM uint16_t   turn_left_back_left[30][3] = {{356,373,467},{357,373,467},{357,373,467},{358,373,467},{358,373,467},{359,373,467},{359,373,467},{360,373,467},{361,373,467},{361,373,467},{362,373,467},{362,373,467},{363,373,467},{364,373,467},{364,373,467},{365,373,468},{365,373,468},{366,373,468},{367,373,468},{367,373,468},{368,373,468},{369,373,468},{369,373,468},{370,373,468},{370,373,468},{371,373,467},{372,373,467},{372,373,467},{373,373,467},{373,373,467}};
//right_2
const PROGMEM uint16_t  turn_right_2_ahead_right[30][3] = {{280,196,91},{281,196,91},{281,196,91},{282,196,91},{282,195,91},{283,195,91},{284,195,91},{284,195,91},{285,195,90},{286,195,90},{286,195,90},{287,195,90},{287,195,90},{288,195,90},{289,195,90},{289,195,90},{290,195,90},{291,195,90},{291,195,90},{292,195,90},{293,195,90},{294,195,90},{294,195,90},{295,195,90},{296,196,90},{297,196,90},{297,196,90},{298,196,90},{299,196,90},{299,196,90}};
const PROGMEM uint16_t turn_right_2_middle_right[30][3] = {{287,207,139},{287,207,139},{288,207,139},{289,207,139},{290,207,139},{291,207,139},{292,207,138},{293,207,138},{294,207,139},{295,207,139},{296,207,139},{297,207,139},{298,207,139},{299,207,139},{300,207,139},{301,207,139},{302,207,139},{303,207,139},{304,207,139},{305,207,139},{306,207,138},{307,207,138},{307,207,138},{309,207,138},{310,207,138},{310,207,138},{311,207,138},{312,207,138},{313,207,138},{314,207,139}};
const PROGMEM uint16_t   turn_right_2_back_right[30][3] = {{215,196,92},{214,196,92},{213,196,92},{213,196,91},{212,196,91},{212,196,91},{211,196,91},{210,196,91},{209,196,91},{209,196,91},{208,196,91},{208,196,91},{207,196,91},{206,196,91},{206,196,91},{205,196,90},{204,196,90},{204,196,90},{203,196,90},{202,196,90},{201,196,90},{201,196,90},{200,196,90},{199,196,90},{199,196,90},{198,196,91},{197,196,91},{196,196,91},{196,196,91},{195,196,91}};
//left_2
const PROGMEM uint16_t  turn_left_2_ahead_left[30][3] = {{204,373,467},{203,373,467},{203,373,467},{202,373,467},{202,373,467},{201,373,467},{200,373,467},{200,373,467},{199,373,468},{199,373,468},{198,373,468},{198,373,468},{197,373,468},{197,373,468},{196,373,468},{195,373,468},{195,373,468},{194,373,468},{193,373,468},{193,373,468},{192,373,468},{192,373,468},{191,373,468},{190,373,468},{189,373,468},{189,373,468},{188,373,468},{188,373,468},{187,373,468},{186,373,468}};
const PROGMEM uint16_t turn_left_2_middle_left[30][3] = {{385,363,424},{384,363,424},{384,363,424},{383,363,424},{382,363,424},{381,363,424},{380,363,424},{379,363,424},{379,363,424},{378,363,424},{377,363,424},{376,363,424},{375,363,424},{374,363,424},{373,363,424},{373,363,424},{372,363,424},{371,363,424},{370,363,424},{369,363,424},{368,363,424},{367,363,424},{367,363,424},{365,363,424},{365,363,424},{364,363,425},{363,363,425},{363,363,424},{362,363,424},{361,363,424}};
const PROGMEM uint16_t   turn_left_2_back_left[30][3] = {{356,373,467},{357,373,467},{357,373,467},{358,373,467},{358,373,467},{359,373,467},{359,373,467},{360,373,467},{361,373,467},{361,373,467},{362,373,467},{362,373,467},{363,373,467},{364,373,467},{364,373,467},{365,373,468},{365,373,468},{366,373,468},{367,373,468},{367,373,468},{368,373,468},{369,373,468},{369,373,468},{370,373,468},{370,373,468},{371,373,467},{372,373,467},{372,373,467},{373,373,467},{373,373,467}};



uint16_t state = 0;
uint8_t current_servo = 0;
int stage = 1;

char buffer[50] = {0};
int index = 0;
int mode = 0;

void straight(int sleepTime, int stepStage, int sample_num,int start=0,int end=30,int jump=1);

void setup()
{
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");

  pwm_0.reset();
  pwm_1.reset();

  pwm_0.begin();
  pwm_1.begin();

  pwm_0.setPWMFreq(50); // Analog servos run at ~50 Hz updates
  pwm_1.setPWMFreq(50); // Analog servos run at ~50 Hz updates

  delay(10);
}

void loop()
{
  // 这里是延时 staright的第一个参数，单位为毫秒
    left(40, stage, 30,1,30,7);
    if (stage == 1)
      stage = 2;
    else
      stage = 1;

}


void straight(int sleepTime, int stepStage, int sample_num,int start,int end,int jump)
{
  // uint8_t sample_num = 30;
  int hang = 30;

  // hang_ori 是抬起的高度，单位 “不是” 度。 
  int hang_ori = 50;
  
  uint8_t delta = 0;
  uint8_t delta_1 = 0;
  if (stepStage == 1)
  {

    unsigned long time_1=millis();
    for (uint16_t i = start; i < end; i += jump)
    {
      // hang=(int)(-0.17*(float)sq(i)+5.33*i); //s=30
      // hang=(int)(-0.35*(float)sq(i)+10.6*i); //s=30 h=80
      // hang=(int)((-0.0044444*(double)sq(i)+0.133333*i)*hang_ori); //unit hight, unit width
      hang=(-(4/(double)sq(sample_num))*sq(i)+(4/(double)sample_num)*i)*hang_ori;
      // hang = (int)(-0.256 * (float)sq(i) + 6.4 * i); //s=25
      // forward
      pwm_0.setPWM(5, 0, pgm_read_word(&straight_back_right[i][0]));
      pwm_0.setPWM(6, 0, pgm_read_word(&straight_back_right[i][1]) - hang - delta - delta_1);
      pwm_0.setPWM(7, 0, pgm_read_word(&straight_back_right[i][2]));

      pwm_1.setPWM(8, 0, pgm_read_word(&straight_middle_left[i][0]));
      pwm_1.setPWM(9, 0, pgm_read_word(&straight_middle_left[i][1]) + hang);
      pwm_1.setPWM(10, 0, pgm_read_word(&straight_middle_left[i][2]));

      pwm_0.setPWM(12, 0, pgm_read_word(&straight_ahead_right[i][0]));
      pwm_0.setPWM(13, 0, pgm_read_word(&straight_ahead_right[i][1]) - hang + delta);
      pwm_0.setPWM(14, 0, pgm_read_word(&straight_ahead_right[i][2]));
      // //backward
      pwm_1.setPWM(4, 0, pgm_read_word(&straight_ahead_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(5, 0, pgm_read_word(&straight_ahead_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(6, 0, pgm_read_word(&straight_ahead_left[sample_num - 1 - i][2]));

      pwm_0.setPWM(9, 0, pgm_read_word(&straight_middle_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(10, 0, pgm_read_word(&straight_middle_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(11, 0, pgm_read_word(&straight_middle_right[sample_num - 1 - i][2]));

      pwm_1.setPWM(12, 0, pgm_read_word(&straight_back_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(13, 0, pgm_read_word(&straight_back_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(14, 0, pgm_read_word(&straight_back_left[sample_num - 1 - i][2]));
      delay(sleepTime);
    }
    // Serial.println(millis()-time_1);
  }
  if (stepStage == 2)
  {
    for (uint16_t i = start; i < end; i += jump)
    {
      
      // hang=(int)(-0.17*(float)sq(i)+5.33*i); //s=30
      // hang=(int)(-0.35*(float)sq(i)+10.6*i); //s=30 h=80
      // hang = (int)(-0.256 * (float)sq(i) + 6.4 * i); //s=25
      // hang=(int)((-0.0044444*(double)sq(i)+0.133333*(double)i)*hang_ori); //unit hight, unit width
      hang=(-(4/(double)sq(sample_num))*sq(i)+(4/(double)sample_num)*i)*hang_ori;

      // Serial.println(hang);
      // forward
      pwm_1.setPWM(4, 0, pgm_read_word(&straight_ahead_left[i][0]));
      pwm_1.setPWM(5, 0, pgm_read_word(&straight_ahead_left[i][1]) + hang - delta);
      pwm_1.setPWM(6, 0, pgm_read_word(&straight_ahead_left[i][2]));

      pwm_0.setPWM(9, 0, pgm_read_word(&straight_middle_right[i][0]));
      pwm_0.setPWM(10, 0, pgm_read_word(&straight_middle_right[i][1]) - hang);
      pwm_0.setPWM(11, 0, pgm_read_word(&straight_middle_right[i][2]));

      pwm_1.setPWM(12, 0, pgm_read_word(&straight_back_left[i][0]));
      pwm_1.setPWM(13, 0, pgm_read_word(&straight_back_left[i][1]) + hang + delta + delta_1);
      pwm_1.setPWM(14, 0, pgm_read_word(&straight_back_left[i][2]));
      //backward
      pwm_0.setPWM(5, 0, pgm_read_word(&straight_back_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(6, 0, pgm_read_word(&straight_back_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(7, 0, pgm_read_word(&straight_back_right[sample_num - 1 - i][2]));

      pwm_1.setPWM(8, 0, pgm_read_word(&straight_middle_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(9, 0, pgm_read_word(&straight_middle_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(10, 0, pgm_read_word(&straight_middle_left[sample_num - 1 - i][2]));

      pwm_0.setPWM(12, 0, pgm_read_word(&straight_ahead_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(13, 0, pgm_read_word(&straight_ahead_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(14, 0, pgm_read_word(&straight_ahead_right[sample_num - 1 - i][2]));
      delay(sleepTime);
    }
  }
}


void left(int sleepTime, int stepStage, int sample_num, int start, int end, int jump)
{
  int hang = 30;
  int hang_ori = 50;
  if (stepStage == 1)
  {
    for (uint16_t i = start; i < end; i += jump)
    {
      hang=(-(4/(double)sq(sample_num))*sq(i)+(4/(double)sample_num)*i)*hang_ori;
      // hang=(int)(-0.35*(float)sq(i)+10.6*i); //s=30 h=80
      // hang=(int)((-0.0044444*(float)sq(i)+0.133333*i)*hang); //unit hight, unit width
      // hang = (int)(-0.256 * (float)sq(i) + 6.4 * i); //s=25
      // forward
      pwm_0.setPWM(5, 0, pgm_read_word(&straight_back_right[i][0]));
      pwm_0.setPWM(6, 0, pgm_read_word(&straight_back_right[i][1]) - hang);
      pwm_0.setPWM(7, 0, pgm_read_word(&straight_back_right[i][2]));

      pwm_1.setPWM(8, 0, pgm_read_word(&turn_left_middle_left[i][0]));
      pwm_1.setPWM(9, 0, pgm_read_word(&turn_left_middle_left[i][1]) + hang);
      pwm_1.setPWM(10, 0, pgm_read_word(&turn_left_middle_left[i][2]));

      pwm_0.setPWM(12, 0, pgm_read_word(&straight_ahead_right[i][0]));
      pwm_0.setPWM(13, 0, pgm_read_word(&straight_ahead_right[i][1]) - hang);
      pwm_0.setPWM(14, 0, pgm_read_word(&straight_ahead_right[i][2]));
      // //backward
      pwm_1.setPWM(4, 0, pgm_read_word(&turn_left_ahead_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(5, 0, pgm_read_word(&turn_left_ahead_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(6, 0, pgm_read_word(&turn_left_ahead_left[sample_num - 1 - i][2]));

      pwm_0.setPWM(9, 0, pgm_read_word(&straight_middle_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(10, 0, pgm_read_word(&straight_middle_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(11, 0, pgm_read_word(&straight_middle_right[sample_num - 1 - i][2]));

      pwm_1.setPWM(12, 0, pgm_read_word(&turn_left_back_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(13, 0, pgm_read_word(&turn_left_back_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(14, 0, pgm_read_word(&turn_left_back_left[sample_num - 1 - i][2]));
      delay(sleepTime);
    }
  }
  if (stepStage == 2)
  {
    for (uint16_t i = start; i < end; i += jump)
    {

      hang=(-(4/(double)sq(sample_num))*sq(i)+(4/(double)sample_num)*i)*hang_ori;

      // forward
      pwm_1.setPWM(4, 0, pgm_read_word(&turn_left_ahead_left[i][0]));
      pwm_1.setPWM(5, 0, pgm_read_word(&turn_left_ahead_left[i][1]) + hang);
      pwm_1.setPWM(6, 0, pgm_read_word(&turn_left_ahead_left[i][2]));

      pwm_0.setPWM(9, 0, pgm_read_word(&straight_middle_right[i][0]));
      pwm_0.setPWM(10, 0, pgm_read_word(&straight_middle_right[i][1]) - hang);
      pwm_0.setPWM(11, 0, pgm_read_word(&straight_middle_right[i][2]));

      pwm_1.setPWM(12, 0, pgm_read_word(&turn_left_back_left[i][0]));
      pwm_1.setPWM(13, 0, pgm_read_word(&turn_left_back_left[i][1]) + hang);
      pwm_1.setPWM(14, 0, pgm_read_word(&turn_left_back_left[i][2]));
      //backward
      pwm_0.setPWM(5, 0, pgm_read_word(&straight_back_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(6, 0, pgm_read_word(&straight_back_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(7, 0, pgm_read_word(&straight_back_right[sample_num - 1 - i][2]));

      pwm_1.setPWM(8, 0, pgm_read_word(&turn_left_middle_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(9, 0, pgm_read_word(&turn_left_middle_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(10, 0, pgm_read_word(&turn_left_middle_left[sample_num - 1 - i][2]));

      pwm_0.setPWM(12, 0, pgm_read_word(&straight_ahead_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(13, 0, pgm_read_word(&straight_ahead_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(14, 0, pgm_read_word(&straight_ahead_right[sample_num - 1 - i][2]));
      delay(sleepTime);
    }
  }
}