#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
// #define SERIAL_RX_BUFFER_SIZE 

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
const PROGMEM uint16_t  turn_right_ahead_right[30][3] = {{202,212,149},{203,212,150},{204,213,152},{205,213,153},{206,214,154},{206,214,155},{207,215,157},{208,216,158},{209,216,159},{210,216,160},{211,217,162},{211,217,163},{212,218,164},{213,219,165},{214,219,167},{215,219,168},{216,220,169},{216,221,171},{216,222,173},{217,223,174},{217,224,176},{218,224,178},{218,225,180},{219,226,182},{219,227,183},{220,228,185},{220,229,187},{221,230,189},{221,231,191},{222,232,193}};
const PROGMEM uint16_t turn_right_middle_right[30][3] = {{309,207,138},{310,207,138},{311,207,138},{312,207,138},{313,207,139},{314,207,139},{316,207,139},{317,207,139},{318,208,140},{319,208,140},{320,208,140},{321,208,140},{322,208,140},{323,208,141},{324,208,141},{326,208,141},{327,209,142},{328,209,142},{329,209,143},{330,209,143},{331,209,144},{332,209,144},{333,210,145},{334,210,145},{336,210,146},{336,210,146},{338,210,147},{339,211,147},{340,211,147},{341,211,148}};
const PROGMEM uint16_t   turn_right_back_right[30][3] = {{275,231,192},{276,230,190},{277,230,189},{277,229,187},{278,228,186},{279,228,184},{279,227,182},{280,226,181},{281,225,179},{281,225,177},{282,224,176},{282,223,174},{283,223,172},{284,222,171},{284,221,169},{285,221,168},{286,220,167},{286,219,165},{287,219,164},{287,218,163},{288,218,161},{289,217,160},{290,216,159},{290,216,157},{291,215,156},{291,215,155},{292,214,153},{293,213,152},{293,213,151},{294,212,149}};
//right
const PROGMEM uint16_t  turn_left_ahead_left[30][3] = {{274,358,415},{273,358,414},{272,358,412},{271,357,411},{270,357,410},{270,356,409},{269,356,408},{268,355,407},{268,355,406},{267,354,405},{266,354,404},{265,354,403},{264,353,402},{264,353,400},{263,352,399},{262,352,398},{262,351,397},{261,350,395},{261,350,394},{260,349,392},{260,348,390},{259,347,389},{259,347,387},{259,346,385},{258,345,384},{258,344,382},{257,343,381},{257,342,379},{257,342,377},{256,341,376}};
const PROGMEM uint16_t turn_left_middle_left[30][3] = {{365,363,424},{364,363,425},{363,363,425},{362,363,424},{361,363,424},{360,363,424},{359,363,424},{358,363,424},{357,362,423},{356,362,423},{355,362,423},{354,362,423},{353,362,423},{352,362,422},{351,362,422},{350,362,422},{349,361,421},{348,361,421},{347,361,420},{346,361,420},{345,361,420},{344,361,419},{343,360,419},{342,360,418},{341,360,418},{340,360,418},{339,360,417},{338,360,417},{338,359,417},{337,359,416}};
const PROGMEM uint16_t   turn_left_back_left[30][3] = {{302,341,376},{301,342,378},{300,343,379},{300,343,381},{299,344,382},{299,344,384},{298,345,385},{298,346,387},{297,346,388},{296,347,389},{296,348,391},{295,348,392},{295,349,394},{294,349,395},{294,350,397},{293,351,398},{292,351,399},{292,352,400},{291,352,402},{291,353,403},{290,353,404},{289,354,405},{289,354,406},{288,355,408},{288,356,409},{287,356,410},{287,357,411},{286,357,412},{285,358,413},{285,358,415}};
//right_2
const PROGMEM uint16_t  turn_right_2_ahead_right[30][3] = {{219,226,182},{219,227,183},{219,227,183},{219,227,183},{219,227,183},{219,227,184},{219,228,184},{219,228,185},{220,228,185},{220,228,185},{220,228,186},{220,228,186},{220,229,186},{220,229,187},{220,229,187},{220,229,188},{220,229,188},{220,229,188},{220,230,189},{221,230,189},{221,230,189},{221,230,190},{221,230,190},{221,231,190},{221,231,191},{221,231,191},{221,231,192},{221,231,192},{221,232,192},{222,232,193}};
const PROGMEM uint16_t turn_right_2_middle_right[30][3] = {{335,210,145},{335,210,145},{335,210,145},{335,210,145},{336,210,146},{336,210,146},{336,210,146},{336,210,146},{336,210,146},{336,210,146},{337,210,146},{337,210,146},{337,210,146},{337,210,146},{338,210,147},{338,210,147},{338,210,147},{338,211,147},{339,211,147},{339,211,147},{339,211,147},{339,211,147},{339,211,147},{340,211,147},{340,211,147},{340,211,147},{340,211,147},{340,211,147},{341,211,148},{341,211,148}};
const PROGMEM uint16_t   turn_right_2_back_right[30][3] = {{275,231,192},{276,231,192},{276,231,191},{276,231,191},{276,231,191},{276,230,190},{276,230,190},{276,230,190},{277,230,189},{277,230,189},{277,230,189},{277,230,188},{277,229,188},{277,229,188},{277,229,187},{277,229,187},{278,229,187},{278,229,186},{278,229,186},{278,229,186},{278,228,186},{278,228,185},{278,228,185},{278,228,185},{278,228,184},{279,228,184},{279,228,183},{279,227,183},{279,227,183},{279,227,183}};
//left_2
const PROGMEM uint16_t  turn_left_2_ahead_left[30][3] = {{259,345,385},{258,345,385},{258,345,385},{258,345,384},{258,345,384},{258,345,384},{258,344,383},{258,344,383},{258,344,383},{258,344,382},{258,344,382},{258,344,382},{258,344,381},{258,343,381},{257,343,381},{257,343,380},{257,343,380},{257,343,380},{257,343,379},{257,342,379},{257,342,379},{257,342,378},{257,342,378},{257,342,378},{257,342,377},{257,342,377},{256,341,377},{256,341,377},{256,341,376},{256,341,376}};
const PROGMEM uint16_t turn_left_2_middle_left[30][3] = {{342,360,418},{342,360,418},{342,360,418},{342,360,418},{341,360,418},{341,360,418},{341,360,418},{341,360,418},{341,360,418},{340,360,418},{340,360,418},{340,360,418},{340,360,417},{340,360,417},{339,360,417},{339,360,417},{339,360,417},{339,360,417},{339,360,417},{338,360,417},{338,360,417},{338,360,417},{338,360,417},{338,359,417},{338,359,417},{337,359,416},{337,359,416},{337,359,416},{337,359,416},{337,359,416}};
const PROGMEM uint16_t   turn_left_2_back_left[30][3] = {{302,341,376},{301,341,377},{301,342,377},{301,342,377},{301,342,378},{301,342,378},{301,342,378},{301,342,378},{300,342,379},{300,342,379},{300,343,379},{300,343,380},{300,343,380},{300,343,380},{300,343,380},{300,343,381},{300,343,381},{300,343,381},{299,344,382},{299,344,382},{299,344,382},{299,344,383},{299,344,383},{299,344,383},{299,344,383},{299,344,384},{299,344,384},{298,345,384},{298,345,385},{298,345,385}};
//data end 41.4°

void straight(int sleepTime, int stepStage, int sample_num,int start=0,int end=30,int jump=1);
void right(int sleepTime, int stepStage, int sample_num,int start=0,int end=30,int jump=1);
void left(int sleepTime, int stepStage, int sample_num,int start=0,int end=30,int jump=1);
void right_2(int sleepTime, int stepStage, int sample_num,int start=0,int end=30,int jump=1);
void left_2(int sleepTime, int stepStage, int sample_num,int start=0,int end=30,int jump=1);
void stand(int i=15);



int data = 7;
int stage = 1;
int delay_time = 8;


void setup()
{
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");
  pwm_0.reset();
  pwm_1.reset();

  pwm_0.begin();
  pwm_1.begin();

  pwm_0.setPWMFreq(50); // Analog servos run at ~60 Hz updates
  pwm_1.setPWMFreq(50); // Analog servos run at ~60 Hz updates
  pinMode(LED_BUILTIN, OUTPUT);

  delay(10);
}

void walk(int sleepTime, int stepStage, int sample_num, int start, int end, int jump)
{
  int hang = 30;
  if (stepStage == 1)
  {
    for (uint16_t i = start; i < end; i += jump)
    {
      hang = (int)(-0.17 * (float)sq(i) + 5.33 * i); //s=30
      // hang=(int)(-0.35*(float)sq(i)+10.6*i); //s=30 h=80
      // hang=(int)((-0.0044444*(float)sq(i)+0.133333*i)*hang); //unit hight, unit width
      // hang = (int)(-0.256 * (float)sq(i) + 6.4 * i); //s=25
      // forward
      pwm_0.setPWM(5, 0, pgm_read_word(&straight_back_right[i][0]));
      pwm_0.setPWM(6, 0, pgm_read_word(&straight_back_right[i][1]) - hang);
      pwm_0.setPWM(7, 0, pgm_read_word(&straight_back_right[i][2]));

      pwm_1.setPWM(8, 0, pgm_read_word(&straight_middle_left[i][0]));
      pwm_1.setPWM(9, 0, pgm_read_word(&straight_middle_left[i][1]) + hang);
      pwm_1.setPWM(10, 0, pgm_read_word(&straight_middle_left[i][2]));

      pwm_0.setPWM(12, 0, pgm_read_word(&straight_ahead_right[i][0]));
      pwm_0.setPWM(13, 0, pgm_read_word(&straight_ahead_right[i][1]) - hang);
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
  }
  if (stepStage == 2)
  {
    for (uint16_t i = start; i < end; i += jump)
    {

      hang = (int)(-0.17 * (float)sq(i) + 5.33 * i); //s=30
      // hang=(int)(-0.35*(float)sq(i)+10.6*i); //s=30 h=80
      // hang = (int)(-0.256 * (float)sq(i) + 6.4 * i); //s=25

      // forward
      pwm_1.setPWM(4, 0, pgm_read_word(&straight_ahead_left[i][0]));
      pwm_1.setPWM(5, 0, pgm_read_word(&straight_ahead_left[i][1]) + hang);
      pwm_1.setPWM(6, 0, pgm_read_word(&straight_ahead_left[i][2]));

      pwm_0.setPWM(9, 0, pgm_read_word(&straight_middle_right[i][0]));
      pwm_0.setPWM(10, 0, pgm_read_word(&straight_middle_right[i][1]) - hang);
      pwm_0.setPWM(11, 0, pgm_read_word(&straight_middle_right[i][2]));

      pwm_1.setPWM(12, 0, pgm_read_word(&straight_back_left[i][0]));
      pwm_1.setPWM(13, 0, pgm_read_word(&straight_back_left[i][1]) + hang);
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

void right(int sleepTime, int stepStage, int sample_num, int start, int end, int jump)
{
  int hang = 30;
  if (stepStage == 1)
  {
    for (uint16_t i = start; i < end; i += jump)
    {
      hang = (int)(-0.17 * (float)sq(i) + 5.33 * i); //s=30
      // hang=(int)(-0.35*(float)sq(i)+10.6*i); //s=30 h=80
      // hang=(int)((-0.0044444*(float)sq(i)+0.133333*i)*hang); //unit hight, unit width
      // hang = (int)(-0.256 * (float)sq(i) + 6.4 * i); //s=25
      // forward
      pwm_0.setPWM(5, 0, pgm_read_word(&turn_right_back_right[i][0]));
      pwm_0.setPWM(6, 0, pgm_read_word(&turn_right_back_right[i][1]) - hang);
      pwm_0.setPWM(7, 0, pgm_read_word(&turn_right_back_right[i][2]));

      pwm_1.setPWM(8, 0, pgm_read_word(&straight_middle_left[i][0]));
      pwm_1.setPWM(9, 0, pgm_read_word(&straight_middle_left[i][1]) + hang);
      pwm_1.setPWM(10, 0, pgm_read_word(&straight_middle_left[i][2]));

      pwm_0.setPWM(12, 0, pgm_read_word(&turn_right_ahead_right[i][0]));
      pwm_0.setPWM(13, 0, pgm_read_word(&turn_right_ahead_right[i][1]) - hang);
      pwm_0.setPWM(14, 0, pgm_read_word(&turn_right_ahead_right[i][2]));
      // //backward
      pwm_1.setPWM(4, 0, pgm_read_word(&straight_ahead_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(5, 0, pgm_read_word(&straight_ahead_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(6, 0, pgm_read_word(&straight_ahead_left[sample_num - 1 - i][2]));

      pwm_0.setPWM(9, 0, pgm_read_word(&turn_right_middle_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(10, 0, pgm_read_word(&turn_right_middle_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(11, 0, pgm_read_word(&turn_right_middle_right[sample_num - 1 - i][2]));

      pwm_1.setPWM(12, 0, pgm_read_word(&straight_back_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(13, 0, pgm_read_word(&straight_back_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(14, 0, pgm_read_word(&straight_back_left[sample_num - 1 - i][2]));
      delay(sleepTime);
    }
  }
  if (stepStage == 2)
  {
    for (uint16_t i = start; i < end; i += jump)
    {

      hang = (int)(-0.17 * (float)sq(i) + 5.33 * i); //s=30
      // hang=(int)(-0.35*(float)sq(i)+10.6*i); //s=30 h=80
      // hang = (int)(-0.256 * (float)sq(i) + 6.4 * i); //s=25

      // forward
      pwm_1.setPWM(4, 0, pgm_read_word(&straight_ahead_left[i][0]));
      pwm_1.setPWM(5, 0, pgm_read_word(&straight_ahead_left[i][1]) + hang);
      pwm_1.setPWM(6, 0, pgm_read_word(&straight_ahead_left[i][2]));

      pwm_0.setPWM(9, 0, pgm_read_word(&turn_right_middle_right[i][0]));
      pwm_0.setPWM(10, 0, pgm_read_word(&turn_right_middle_right[i][1]) - hang);
      pwm_0.setPWM(11, 0, pgm_read_word(&turn_right_middle_right[i][2]));

      pwm_1.setPWM(12, 0, pgm_read_word(&straight_back_left[i][0]));
      pwm_1.setPWM(13, 0, pgm_read_word(&straight_back_left[i][1]) + hang);
      pwm_1.setPWM(14, 0, pgm_read_word(&straight_back_left[i][2]));
      //backward
      pwm_0.setPWM(5, 0, pgm_read_word(&turn_right_back_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(6, 0, pgm_read_word(&turn_right_back_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(7, 0, pgm_read_word(&turn_right_back_right[sample_num - 1 - i][2]));

      pwm_1.setPWM(8, 0, pgm_read_word(&straight_middle_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(9, 0, pgm_read_word(&straight_middle_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(10, 0, pgm_read_word(&straight_middle_left[sample_num - 1 - i][2]));

      pwm_0.setPWM(12, 0, pgm_read_word(&turn_right_ahead_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(13, 0, pgm_read_word(&turn_right_ahead_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(14, 0, pgm_read_word(&turn_right_ahead_right[sample_num - 1 - i][2]));
      delay(sleepTime);
    }
  }
}

void left(int sleepTime, int stepStage, int sample_num, int start, int end, int jump)
{
  int hang = 30;
  if (stepStage == 1)
  {
    for (uint16_t i = start; i < end; i += jump)
    {
      hang = (int)(-0.17 * (float)sq(i) + 5.33 * i); //s=30
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

      hang = (int)(-0.17 * (float)sq(i) + 5.33 * i); //s=30
      // hang=(int)(-0.35*(float)sq(i)+10.6*i); //s=30 h=80
      // hang = (int)(-0.256 * (float)sq(i) + 6.4 * i); //s=25

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


void right_2(int sleepTime, int stepStage, int sample_num, int start, int end, int jump)
{
  int hang = 30;
  if (stepStage == 1)
  {
    for (uint16_t i = start; i < end; i += jump)
    {
      hang = (int)(-0.17 * (float)sq(i) + 5.33 * i); //s=30
      // hang=(int)(-0.35*(float)sq(i)+10.6*i); //s=30 h=80
      // hang=(int)((-0.0044444*(float)sq(i)+0.133333*i)*hang); //unit hight, unit width
      // hang = (int)(-0.256 * (float)sq(i) + 6.4 * i); //s=25
      // forward
      pwm_0.setPWM(5, 0, pgm_read_word(&turn_right_2_back_right[i][0]));
      pwm_0.setPWM(6, 0, pgm_read_word(&turn_right_2_back_right[i][1]) - hang);
      pwm_0.setPWM(7, 0, pgm_read_word(&turn_right_2_back_right[i][2]));

      pwm_1.setPWM(8, 0, pgm_read_word(&straight_middle_left[i][0]));
      pwm_1.setPWM(9, 0, pgm_read_word(&straight_middle_left[i][1]) + hang);
      pwm_1.setPWM(10, 0, pgm_read_word(&straight_middle_left[i][2]));

      pwm_0.setPWM(12, 0, pgm_read_word(&turn_right_2_ahead_right[i][0]));
      pwm_0.setPWM(13, 0, pgm_read_word(&turn_right_2_ahead_right[i][1]) - hang);
      pwm_0.setPWM(14, 0, pgm_read_word(&turn_right_2_ahead_right[i][2]));
      // //backward
      pwm_1.setPWM(4, 0, pgm_read_word(&straight_ahead_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(5, 0, pgm_read_word(&straight_ahead_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(6, 0, pgm_read_word(&straight_ahead_left[sample_num - 1 - i][2]));

      pwm_0.setPWM(9, 0, pgm_read_word(&turn_right_2_middle_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(10, 0, pgm_read_word(&turn_right_2_middle_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(11, 0, pgm_read_word(&turn_right_2_middle_right[sample_num - 1 - i][2]));

      pwm_1.setPWM(12, 0, pgm_read_word(&straight_back_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(13, 0, pgm_read_word(&straight_back_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(14, 0, pgm_read_word(&straight_back_left[sample_num - 1 - i][2]));
      delay(sleepTime);
    }
  }
  if (stepStage == 2)
  {
    for (uint16_t i = start; i < end; i += jump)
    {

      hang = (int)(-0.17 * (float)sq(i) + 5.33 * i); //s=30
      // hang=(int)(-0.35*(float)sq(i)+10.6*i); //s=30 h=80
      // hang = (int)(-0.256 * (float)sq(i) + 6.4 * i); //s=25

      // forward
      pwm_1.setPWM(4, 0, pgm_read_word(&straight_ahead_left[i][0]));
      pwm_1.setPWM(5, 0, pgm_read_word(&straight_ahead_left[i][1]) + hang);
      pwm_1.setPWM(6, 0, pgm_read_word(&straight_ahead_left[i][2]));

      pwm_0.setPWM(9, 0, pgm_read_word(&turn_right_2_middle_right[i][0]));
      pwm_0.setPWM(10, 0, pgm_read_word(&turn_right_2_middle_right[i][1]) - hang);
      pwm_0.setPWM(11, 0, pgm_read_word(&turn_right_2_middle_right[i][2]));

      pwm_1.setPWM(12, 0, pgm_read_word(&straight_back_left[i][0]));
      pwm_1.setPWM(13, 0, pgm_read_word(&straight_back_left[i][1]) + hang);
      pwm_1.setPWM(14, 0, pgm_read_word(&straight_back_left[i][2]));
      //backward
      pwm_0.setPWM(5, 0, pgm_read_word(&turn_right_2_back_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(6, 0, pgm_read_word(&turn_right_2_back_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(7, 0, pgm_read_word(&turn_right_2_back_right[sample_num - 1 - i][2]));

      pwm_1.setPWM(8, 0, pgm_read_word(&straight_middle_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(9, 0, pgm_read_word(&straight_middle_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(10, 0, pgm_read_word(&straight_middle_left[sample_num - 1 - i][2]));

      pwm_0.setPWM(12, 0, pgm_read_word(&turn_right_2_ahead_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(13, 0, pgm_read_word(&turn_right_2_ahead_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(14, 0, pgm_read_word(&turn_right_2_ahead_right[sample_num - 1 - i][2]));
      delay(sleepTime);
    }
  }
}

void left_2(int sleepTime, int stepStage, int sample_num, int start, int end, int jump)
{
  int hang = 30;
  if (stepStage == 1)
  {
    for (uint16_t i = start; i < end; i += jump)
    {
      hang = (int)(-0.17 * (float)sq(i) + 5.33 * i); //s=30
      // hang=(int)(-0.35*(float)sq(i)+10.6*i); //s=30 h=80
      // hang=(int)((-0.0044444*(float)sq(i)+0.133333*i)*hang); //unit hight, unit width
      // hang = (int)(-0.256 * (float)sq(i) + 6.4 * i); //s=25
      // forward
      pwm_0.setPWM(5, 0, pgm_read_word(&straight_back_right[i][0]));
      pwm_0.setPWM(6, 0, pgm_read_word(&straight_back_right[i][1]) - hang);
      pwm_0.setPWM(7, 0, pgm_read_word(&straight_back_right[i][2]));

      pwm_1.setPWM(8, 0, pgm_read_word(&turn_left_2_middle_left[i][0]));
      pwm_1.setPWM(9, 0, pgm_read_word(&turn_left_2_middle_left[i][1]) + hang);
      pwm_1.setPWM(10, 0, pgm_read_word(&turn_left_2_middle_left[i][2]));

      pwm_0.setPWM(12, 0, pgm_read_word(&straight_ahead_right[i][0]));
      pwm_0.setPWM(13, 0, pgm_read_word(&straight_ahead_right[i][1]) - hang);
      pwm_0.setPWM(14, 0, pgm_read_word(&straight_ahead_right[i][2]));
      // //backward
      pwm_1.setPWM(4, 0, pgm_read_word(&turn_left_2_ahead_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(5, 0, pgm_read_word(&turn_left_2_ahead_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(6, 0, pgm_read_word(&turn_left_2_ahead_left[sample_num - 1 - i][2]));

      pwm_0.setPWM(9, 0, pgm_read_word(&straight_middle_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(10, 0, pgm_read_word(&straight_middle_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(11, 0, pgm_read_word(&straight_middle_right[sample_num - 1 - i][2]));

      pwm_1.setPWM(12, 0, pgm_read_word(&turn_left_2_back_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(13, 0, pgm_read_word(&turn_left_2_back_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(14, 0, pgm_read_word(&turn_left_2_back_left[sample_num - 1 - i][2]));
      delay(sleepTime);
    }
  }
  if (stepStage == 2)
  {
    for (uint16_t i = start; i < end; i += jump)
    {

      hang = (int)(-0.17 * (float)sq(i) + 5.33 * i); //s=30
      // hang=(int)(-0.35*(float)sq(i)+10.6*i); //s=30 h=80
      // hang = (int)(-0.256 * (float)sq(i) + 6.4 * i); //s=25

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

void stand(int i)
{
      pwm_0.setPWM(5, 0, pgm_read_word(&straight_back_right[i][0]));
      pwm_0.setPWM(6, 0, pgm_read_word(&straight_back_right[i][1]));
      pwm_0.setPWM(7, 0, pgm_read_word(&straight_back_right[i][2]));

      pwm_1.setPWM(8, 0, pgm_read_word(&turn_left_2_middle_left[i][0]));
      pwm_1.setPWM(9, 0, pgm_read_word(&turn_left_2_middle_left[i][1]));
      pwm_1.setPWM(10, 0, pgm_read_word(&turn_left_2_middle_left[i][2]));

      pwm_0.setPWM(12, 0, pgm_read_word(&straight_ahead_right[i][0]));
      pwm_0.setPWM(13, 0, pgm_read_word(&straight_ahead_right[i][1]));
      pwm_0.setPWM(14, 0, pgm_read_word(&straight_ahead_right[i][2]));

      pwm_1.setPWM(4, 0, pgm_read_word(&turn_left_ahead_left[i][0]));
      pwm_1.setPWM(5, 0, pgm_read_word(&turn_left_ahead_left[i][1]));
      pwm_1.setPWM(6, 0, pgm_read_word(&turn_left_ahead_left[i][2]));

      pwm_0.setPWM(9, 0, pgm_read_word(&straight_middle_right[i][0]));
      pwm_0.setPWM(10, 0, pgm_read_word(&straight_middle_right[i][1]));
      pwm_0.setPWM(11, 0, pgm_read_word(&straight_middle_right[i][2]));

      pwm_1.setPWM(12, 0, pgm_read_word(&turn_left_back_left[i][0]));
      pwm_1.setPWM(13, 0, pgm_read_word(&turn_left_back_left[i][1]));
      pwm_1.setPWM(14, 0, pgm_read_word(&turn_left_back_left[i][2]));
}


void loop()
{
  long s_time=millis();
  get_bluez_data();
  switch (data)
  {
  case 0:
    walk(delay_time, stage, 30,1,30,2);
    break;
  case 5:
    right(delay_time, stage, 30,1,30,2);
    break;
  case 6:
    right_2(delay_time, stage, 30,1,30,2);
    break;
  case 2:
    left(delay_time, stage, 30,1,30,2);
    break;
  case 3:
    left_2(delay_time, stage, 30,1,30,2);
    break;
  case 7:
    break;
  default:
    stand();
    break;
  }

  if (stage == 1)
    stage = 2;
  else
    stage = 1;

  Serial.println(millis()-s_time);
}

void get_bluez_data()
{
  while (Serial.available()>0)
  {
    data=int(Serial.read())-'0';
  }
}
LED_BUILTIN