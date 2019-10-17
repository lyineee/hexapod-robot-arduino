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
const PROGMEM uint16_t  turn_right_ahead_right[30][3] = {{156,268,261},{157,265,256},{157,262,252},{158,260,247},{159,257,242},{160,255,238},{160,252,234},{161,250,229},{162,248,225},{163,245,221},{163,243,217},{164,241,213},{165,239,209},{166,237,205},{167,235,202},{169,234,198},{170,232,195},{171,231,192},{172,230,188},{174,228,185},{175,227,182},{176,225,179},{177,224,175},{179,222,172},{180,221,169},{181,220,166},{183,219,163},{184,217,161},{185,216,158},{186,215,156}};
const PROGMEM uint16_t turn_right_middle_right[30][3] = {{315,207,139},{317,207,139},{319,208,140},{321,208,140},{324,208,141},{326,208,142},{328,209,143},{330,209,144},{333,209,144},{335,210,145},{337,210,146},{339,211,147},{341,211,148},{343,212,149},{345,212,150},{347,212,150},{350,213,152},{352,213,153},{353,214,154},{355,214,156},{357,215,157},{359,216,159},{361,216,160},{363,217,161},{364,217,163},{366,218,164},{368,219,165},{369,219,167},{371,221,169},{373,222,171}};
const PROGMEM uint16_t   turn_right_back_right[30][3] = {{311,214,155},{312,215,158},{314,216,160},{316,217,163},{317,218,165},{319,219,167},{320,221,170},{321,222,174},{322,224,178},{323,226,181},{324,228,185},{325,230,189},{326,232,192},{327,233,196},{328,235,199},{329,237,203},{330,238,207},{330,240,210},{331,242,214},{332,244,218},{333,246,221},{334,248,225},{335,249,229},{336,252,233},{336,254,238},{337,257,242},{337,259,247},{338,262,252},{339,264,256},{340,268,262}};
//right
const PROGMEM uint16_t  turn_left_ahead_left[30][3] = {{315,309,314},{314,311,319},{314,313,323},{313,316,327},{312,318,331},{312,320,335},{311,322,339},{310,324,343},{310,326,347},{309,328,350},{308,330,354},{308,332,358},{307,334,362},{306,336,365},{305,338,368},{304,339,371},{303,340,374},{301,341,377},{300,343,380},{299,344,383},{298,345,385},{297,347,388},{296,348,391},{294,349,394},{293,350,397},{292,351,400},{291,353,402},{290,354,404},{289,355,407},{288,356,409}};
const PROGMEM uint16_t turn_left_middle_left[30][3] = {{360,363,424},{358,363,424},{356,362,423},{354,362,423},{352,362,422},{350,362,422},{348,361,421},{346,361,420},{344,361,419},{342,360,418},{340,360,418},{338,360,417},{336,359,416},{334,359,415},{333,359,414},{331,358,414},{329,358,412},{327,357,411},{325,357,410},{324,356,409},{322,356,408},{320,355,406},{319,355,405},{317,354,404},{315,354,403},{314,353,401},{312,353,400},{311,352,399},{309,351,397},{308,350,395}};
const PROGMEM uint16_t   turn_left_back_left[30][3] = {{270,356,409},{268,355,407},{267,354,405},{265,354,403},{264,353,400},{262,352,398},{261,351,396},{260,349,392},{259,347,389},{259,346,386},{258,344,383},{257,343,379},{256,341,376},{255,339,373},{255,338,370},{254,336,366},{253,335,363},{252,333,360},{251,331,357},{250,330,353},{250,328,350},{249,327,347},{248,325,343},{248,323,339},{247,320,335},{247,318,331},{246,316,327},{245,314,323},{245,312,319},{244,309,314}};
//right_2
const PROGMEM uint16_t  turn_right_2_ahead_right[30][3] = {{156,268,261},{157,266,259},{157,265,257},{157,264,255},{157,263,254},{157,262,252},{158,261,250},{158,260,248},{158,259,246},{158,258,244},{159,257,242},{159,256,241},{159,255,239},{160,254,237},{160,253,235},{160,252,234},{160,252,232},{161,251,230},{161,250,229},{162,249,227},{162,248,225},{162,247,224},{163,246,222},{163,245,220},{163,244,219},{163,243,217},{164,242,215},{164,242,214},{164,241,212},{165,240,210}};
const PROGMEM uint16_t turn_right_2_middle_right[30][3] = {{353,213,154},{353,214,154},{354,214,155},{355,214,155},{355,214,156},{356,215,156},{357,215,157},{357,215,157},{358,215,158},{359,216,159},{360,216,159},{360,216,160},{361,216,160},{362,216,161},{363,217,161},{363,217,162},{364,217,162},{365,217,163},{365,218,163},{366,218,164},{367,218,164},{367,218,165},{368,219,166},{369,219,167},{369,219,167},{370,220,168},{371,220,169},{371,221,170},{372,221,170},{373,222,171}};
const PROGMEM uint16_t   turn_right_2_back_right[30][3] = {{331,241,212},{331,242,213},{331,242,215},{332,243,216},{332,244,218},{333,245,219},{333,245,221},{333,246,222},{334,247,224},{334,248,225},{334,248,226},{335,249,228},{335,250,230},{335,251,232},{336,252,233},{336,253,235},{336,254,237},{336,255,239},{336,256,241},{337,257,242},{337,258,244},{337,259,246},{337,260,248},{338,261,250},{338,262,252},{338,263,253},{339,264,255},{339,265,258},{339,266,260},{340,268,262}};
//left_2
const PROGMEM uint16_t  turn_left_2_ahead_left[30][3] = {{315,309,314},{314,310,316},{314,310,318},{314,312,319},{314,312,321},{314,313,323},{313,314,325},{313,315,326},{313,316,328},{313,317,330},{312,318,331},{312,319,333},{312,320,334},{312,321,336},{311,322,338},{311,322,339},{311,323,340},{310,324,342},{310,325,344},{310,325,345},{310,326,347},{309,327,348},{309,328,349},{309,329,351},{309,330,353},{308,330,354},{308,331,355},{308,332,357},{307,333,358},{307,334,360}};
const PROGMEM uint16_t turn_left_2_middle_left[30][3] = {{326,357,411},{325,357,410},{325,357,410},{324,357,409},{324,356,409},{323,356,408},{322,356,408},{322,356,407},{321,355,407},{320,355,406},{320,355,406},{319,355,405},{318,355,405},{318,354,404},{317,354,404},{317,354,404},{316,354,403},{315,354,403},{315,353,402},{314,353,401},{313,353,401},{313,353,400},{312,352,400},{312,352,399},{311,352,399},{310,351,398},{310,351,397},{309,350,396},{309,350,396},{308,350,395}};
const PROGMEM uint16_t   turn_left_2_back_left[30][3] = {{252,332,358},{252,332,357},{251,331,356},{251,330,355},{250,330,353},{250,329,352},{250,328,351},{250,328,349},{249,327,348},{249,327,347},{249,326,345},{248,325,344},{248,324,343},{248,324,341},{248,323,339},{247,322,338},{247,321,336},{247,320,334},{247,319,333},{247,318,331},{246,317,329},{246,317,328},{246,315,326},{246,315,324},{245,314,323},{245,313,321},{245,312,320},{245,311,318},{244,310,316},{244,309,314}};
//data end 41.4°

void straight(int sleepTime, int stepStage, int sample_num,int start=0,int end=30,int jump=1);
void right(int sleepTime, int stepStage, int sample_num,int start=0,int end=30,int jump=1);
void left(int sleepTime, int stepStage, int sample_num,int start=0,int end=30,int jump=1);
void right_2(int sleepTime, int stepStage, int sample_num,int start=0,int end=30,int jump=1);
void left_2(int sleepTime, int stepStage, int sample_num,int start=0,int end=30,int jump=1);
void stand(int i=15);



int data = 7;
int stage = 1;
int delay_time = 40;


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
  int hang_ori = 50;
  if (stepStage == 1)
  {
    for (uint16_t i = start; i < end; i += jump)
    {
      hang=(-(4/(double)sq(sample_num))*sq(i)+(4/(double)sample_num)*i)*hang_ori;
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

      hang=(-(4/(double)sq(sample_num))*sq(i)+(4/(double)sample_num)*i)*hang_ori;
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
  int hang_ori = 50;
  if (stepStage == 1)
  {
    for (uint16_t i = start; i < end; i += jump)
    {
      hang=(-(4/(double)sq(sample_num))*sq(i)+(4/(double)sample_num)*i)*hang_ori;
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

      hang=(-(4/(double)sq(sample_num))*sq(i)+(4/(double)sample_num)*i)*hang_ori;
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
  int hang_ori = 50;
  if (stepStage == 1)
  {
    for (uint16_t i = start; i < end; i += jump)
    {
      hang=(-(4/(double)sq(sample_num))*sq(i)+(4/(double)sample_num)*i)*hang_ori;
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


void right_2(int sleepTime, int stepStage, int sample_num, int start, int end, int jump)
{
  int hang = 30;
  int hang_ori = 50;
  if (stepStage == 1)
  {
    for (uint16_t i = start; i < end; i += jump)
    {
      hang=(-(4/(double)sq(sample_num))*sq(i)+(4/(double)sample_num)*i)*hang_ori;
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

      hang=(-(4/(double)sq(sample_num))*sq(i)+(4/(double)sample_num)*i)*hang_ori;
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
  int hang_ori = 50;
  if (stepStage == 1)
  {
    for (uint16_t i = start; i < end; i += jump)
    {
      hang=(-(4/(double)sq(sample_num))*sq(i)+(4/(double)sample_num)*i)*hang_ori;
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
    walk(delay_time, stage, 30,1,30,7);
    break;
  case 5:
    right(delay_time, stage, 30,1,30,7);
    break;
  case 6:
    right_2(delay_time, stage, 30,1,30,7);
    break;
  case 2:
    left(delay_time, stage, 30,1,30,7);
    break;
  case 3:
    left_2(delay_time, stage, 30,1,30,7);
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