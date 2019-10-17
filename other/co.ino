#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
// #define SERIAL_RX_BUFFER_SIZE 

Adafruit_PWMServoDriver pwm_0 = Adafruit_PWMServoDriver();
Adafruit_PWMServoDriver pwm_1 = Adafruit_PWMServoDriver(&Wire, 0x41);

//data begin

const uint16_t  straight_ahead_right[30][3] = {{150,196,101},{154,197,103},{157,197,105},{161,197,107},{165,198,109},{169,198,111},{172,199,113},{175,199,116},{178,200,119},{181,201,122},{184,202,124},{187,203,128},{189,205,131},{192,206,134},{194,207,138},{196,209,141},{199,210,145},{202,212,149},{204,213,152},{207,215,156},{209,216,160},{212,218,163},{214,219,167},{216,221,172},{218,224,177},{219,227,183},{220,229,188},{222,232,194},{223,235,199},{224,237,205}};
const uint16_t straight_middle_right[30][3] = {{244,216,158},{247,215,156},{250,214,154},{253,213,152},{256,212,150},{259,212,148},{262,211,147},{266,211,146},{269,210,145},{272,210,144},{276,209,142},{279,209,141},{282,208,140},{286,207,139},{289,207,139},{293,207,138},{296,207,139},{300,207,139},{304,207,139},{307,207,138},{310,207,138},{314,207,139},{317,207,139},{320,208,140},{324,208,141},{327,209,142},{330,209,144},{334,210,145},{337,210,146},{340,211,147}};
const uint16_t   straight_back_right[30][3] = {{271,236,203},{273,234,198},{275,232,193},{277,229,188},{279,227,183},{281,225,178},{283,223,173},{285,221,168},{287,219,164},{288,217,160},{291,216,157},{292,214,153},{294,212,149},{296,210,145},{298,208,141},{301,207,137},{304,206,134},{306,205,131},{309,203,128},{312,202,125},{315,202,122},{318,201,119},{321,200,116},{324,199,114},{328,199,111},{331,198,109},{335,198,107},{338,198,105},{342,197,103},{346,197,101}};
const uint16_t   straight_ahead_left[30][3] = {{320,373,458},{317,372,456},{314,372,454},{310,372,453},{307,371,451},{304,371,449},{301,370,447},{298,370,445},{295,369,442},{292,368,439},{290,367,437},{287,366,434},{285,365,431},{283,364,428},{281,363,425},{279,362,422},{276,360,419},{274,359,415},{272,357,412},{269,356,409},{267,355,405},{265,353,402},{263,352,399},{261,350,395},{260,348,390},{258,345,385},{257,343,380},{256,340,375},{255,338,370},{254,336,365}};
const uint16_t  straight_middle_left[30][3] = {{424,355,407},{421,356,408},{418,357,410},{416,357,412},{413,358,414},{410,359,415},{407,359,417},{404,360,418},{401,360,419},{398,360,420},{395,361,421},{392,361,422},{389,362,423},{386,363,424},{383,363,424},{380,363,424},{377,363,424},{373,363,424},{370,363,424},{367,363,424},{364,363,425},{361,363,424},{358,363,424},{355,362,423},{352,362,422},{349,361,421},{346,361,420},{343,360,419},{340,360,418},{337,359,416}};
const uint16_t    straight_back_left[30][3] = {{305,337,367},{303,339,371},{302,341,376},{300,343,380},{298,345,384},{297,347,389},{295,349,393},{293,350,398},{292,352,401},{290,354,405},{288,355,408},{286,357,412},{285,359,415},{283,360,419},{281,362,422},{279,363,425},{276,364,428},{274,365,431},{271,366,434},{269,367,437},{266,368,439},{263,369,442},{261,369,444},{258,370,447},{255,370,449},{252,371,450},{248,371,452},{245,371,454},{242,372,456},{238,372,458}};
//left 
const uint16_t  turn_right_ahead_right[30][3] = {{202,212,149},{203,212,150},{204,213,152},{205,213,153},{206,214,154},{206,214,155},{207,215,157},{208,216,158},{209,216,159},{210,216,160},{211,217,162},{211,217,163},{212,218,164},{213,219,165},{214,219,167},{215,219,168},{216,220,169},{216,221,171},{216,222,173},{217,223,174},{217,224,176},{218,224,178},{218,225,180},{219,226,182},{219,227,183},{220,228,185},{220,229,187},{221,230,189},{221,231,191},{222,232,193}};
const uint16_t turn_right_middle_right[30][3] = {{309,207,138},{310,207,138},{311,207,138},{312,207,138},{313,207,139},{314,207,139},{316,207,139},{317,207,139},{318,208,140},{319,208,140},{320,208,140},{321,208,140},{322,208,140},{323,208,141},{324,208,141},{326,208,141},{327,209,142},{328,209,142},{329,209,143},{330,209,143},{331,209,144},{332,209,144},{333,210,145},{334,210,145},{336,210,146},{336,210,146},{338,210,147},{339,211,147},{340,211,147},{341,211,148}};
const uint16_t   turn_right_back_right[30][3] = {{275,231,192},{276,230,190},{277,230,189},{277,229,187},{278,228,186},{279,228,184},{279,227,182},{280,226,181},{281,225,179},{281,225,177},{282,224,176},{282,223,174},{283,223,172},{284,222,171},{284,221,169},{285,221,168},{286,220,167},{286,219,165},{287,219,164},{287,218,163},{288,218,161},{289,217,160},{290,216,159},{290,216,157},{291,215,156},{291,215,155},{292,214,153},{293,213,152},{293,213,151},{294,212,149}};
//right
const uint16_t  turn_left_ahead_left[30][3] = {{274,358,415},{273,358,414},{272,358,412},{271,357,411},{270,357,410},{270,356,409},{269,356,408},{268,355,407},{268,355,406},{267,354,405},{266,354,404},{265,354,403},{264,353,402},{264,353,400},{263,352,399},{262,352,398},{262,351,397},{261,350,395},{261,350,394},{260,349,392},{260,348,390},{259,347,389},{259,347,387},{259,346,385},{258,345,384},{258,344,382},{257,343,381},{257,342,379},{257,342,377},{256,341,376}};
const uint16_t turn_left_middle_left[30][3] = {{365,363,424},{364,363,425},{363,363,425},{362,363,424},{361,363,424},{360,363,424},{359,363,424},{358,363,424},{357,362,423},{356,362,423},{355,362,423},{354,362,423},{353,362,423},{352,362,422},{351,362,422},{350,362,422},{349,361,421},{348,361,421},{347,361,420},{346,361,420},{345,361,420},{344,361,419},{343,360,419},{342,360,418},{341,360,418},{340,360,418},{339,360,417},{338,360,417},{338,359,417},{337,359,416}};
const uint16_t   turn_left_back_left[30][3] = {{302,341,376},{301,342,378},{300,343,379},{300,343,381},{299,344,382},{299,344,384},{298,345,385},{298,346,387},{297,346,388},{296,347,389},{296,348,391},{295,348,392},{295,349,394},{294,349,395},{294,350,397},{293,351,398},{292,351,399},{292,352,400},{291,352,402},{291,353,403},{290,353,404},{289,354,405},{289,354,406},{288,355,408},{288,356,409},{287,356,410},{287,357,411},{286,357,412},{285,358,413},{285,358,415}};
//right_2
const uint16_t  turn_right_2_ahead_right[30][3] = {{219,226,182},{219,227,183},{219,227,183},{219,227,183},{219,227,183},{219,227,184},{219,228,184},{219,228,185},{220,228,185},{220,228,185},{220,228,186},{220,228,186},{220,229,186},{220,229,187},{220,229,187},{220,229,188},{220,229,188},{220,229,188},{220,230,189},{221,230,189},{221,230,189},{221,230,190},{221,230,190},{221,231,190},{221,231,191},{221,231,191},{221,231,192},{221,231,192},{221,232,192},{222,232,193}};
const uint16_t turn_right_2_middle_right[30][3] = {{335,210,145},{335,210,145},{335,210,145},{335,210,145},{336,210,146},{336,210,146},{336,210,146},{336,210,146},{336,210,146},{336,210,146},{337,210,146},{337,210,146},{337,210,146},{337,210,146},{338,210,147},{338,210,147},{338,210,147},{338,211,147},{339,211,147},{339,211,147},{339,211,147},{339,211,147},{339,211,147},{340,211,147},{340,211,147},{340,211,147},{340,211,147},{340,211,147},{341,211,148},{341,211,148}};
const uint16_t   turn_right_2_back_right[30][3] = {{275,231,192},{276,231,192},{276,231,191},{276,231,191},{276,231,191},{276,230,190},{276,230,190},{276,230,190},{277,230,189},{277,230,189},{277,230,189},{277,230,188},{277,229,188},{277,229,188},{277,229,187},{277,229,187},{278,229,187},{278,229,186},{278,229,186},{278,229,186},{278,228,186},{278,228,185},{278,228,185},{278,228,185},{278,228,184},{279,228,184},{279,228,183},{279,227,183},{279,227,183},{279,227,183}};
//left_2
const uint16_t  turn_left_2_ahead_left[30][3] = {{259,345,385},{258,345,385},{258,345,385},{258,345,384},{258,345,384},{258,345,384},{258,344,383},{258,344,383},{258,344,383},{258,344,382},{258,344,382},{258,344,382},{258,344,381},{258,343,381},{257,343,381},{257,343,380},{257,343,380},{257,343,380},{257,343,379},{257,342,379},{257,342,379},{257,342,378},{257,342,378},{257,342,378},{257,342,377},{257,342,377},{256,341,377},{256,341,377},{256,341,376},{256,341,376}};
const uint16_t turn_left_2_middle_left[30][3] = {{342,360,418},{342,360,418},{342,360,418},{342,360,418},{341,360,418},{341,360,418},{341,360,418},{341,360,418},{341,360,418},{340,360,418},{340,360,418},{340,360,418},{340,360,417},{340,360,417},{339,360,417},{339,360,417},{339,360,417},{339,360,417},{339,360,417},{338,360,417},{338,360,417},{338,360,417},{338,360,417},{338,359,417},{338,359,417},{337,359,416},{337,359,416},{337,359,416},{337,359,416},{337,359,416}};
const uint16_t   turn_left_2_back_left[30][3] = {{302,341,376},{301,341,377},{301,342,377},{301,342,377},{301,342,378},{301,342,378},{301,342,378},{301,342,378},{300,342,379},{300,342,379},{300,343,379},{300,343,380},{300,343,380},{300,343,380},{300,343,380},{300,343,381},{300,343,381},{300,343,381},{299,344,382},{299,344,382},{299,344,382},{299,344,383},{299,344,383},{299,344,383},{299,344,383},{299,344,384},{299,344,384},{298,345,384},{298,345,385},{298,345,385}};
//data end 41.4Â°

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
      pwm_0.setPWM(5, 0, straight_back_right[i][0]));
      pwm_0.setPWM(6, 0, straight_back_right[i][1]) - hang);
      pwm_0.setPWM(7, 0, straight_back_right[i][2]));

      pwm_1.setPWM(8, 0, straight_middle_left[i][0]));
      pwm_1.setPWM(9, 0, straight_middle_left[i][1]) + hang);
      pwm_1.setPWM(10, 0,straight_middle_left[i][2]));

      pwm_0.setPWM(12, 0,straight_ahead_right[i][0]));
      pwm_0.setPWM(13, 0,straight_ahead_right[i][1]) - hang);
      pwm_0.setPWM(14, 0,straight_ahead_right[i][2]));
      // //backward
      pwm_1.setPWM(4, 0, straight_ahead_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(5, 0, straight_ahead_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(6, 0, straight_ahead_left[sample_num - 1 - i][2]));

      pwm_0.setPWM(9, 0, straight_middle_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(10, 0, straight_middle_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(11, 0, straight_middle_right[sample_num - 1 - i][2]));

      pwm_1.setPWM(12, 0, straight_back_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(13, 0, straight_back_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(14, 0, straight_back_left[sample_num - 1 - i][2]));
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
      pwm_1.setPWM(4, 0, straight_ahead_left[i][0]));
      pwm_1.setPWM(5, 0, straight_ahead_left[i][1]) + hang);
      pwm_1.setPWM(6, 0, straight_ahead_left[i][2]));

      pwm_0.setPWM(9, 0, straight_middle_right[i][0]));
      pwm_0.setPWM(10, 0, straight_middle_right[i][1]) - hang);
      pwm_0.setPWM(11, 0, straight_middle_right[i][2]));

      pwm_1.setPWM(12, 0, straight_back_left[i][0]));
      pwm_1.setPWM(13, 0, straight_back_left[i][1]) + hang);
      pwm_1.setPWM(14, 0, straight_back_left[i][2]));
      //backward
      pwm_0.setPWM(5, 0, straight_back_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(6, 0, straight_back_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(7, 0, straight_back_right[sample_num - 1 - i][2]));

      pwm_1.setPWM(8, 0, straight_middle_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(9, 0, straight_middle_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(10, 0, straight_middle_left[sample_num - 1 - i][2]));

      pwm_0.setPWM(12, 0, straight_ahead_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(13, 0, straight_ahead_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(14, 0, straight_ahead_right[sample_num - 1 - i][2]));
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
      pwm_0.setPWM(5, 0, turn_right_back_right[i][0]));
      pwm_0.setPWM(6, 0, turn_right_back_right[i][1]) - hang);
      pwm_0.setPWM(7, 0, turn_right_back_right[i][2]));

      pwm_1.setPWM(8, 0, straight_middle_left[i][0]));
      pwm_1.setPWM(9, 0, straight_middle_left[i][1]) + hang);
      pwm_1.setPWM(10, 0, straight_middle_left[i][2]));

      pwm_0.setPWM(12, 0, turn_right_ahead_right[i][0]));
      pwm_0.setPWM(13, 0, turn_right_ahead_right[i][1]) - hang);
      pwm_0.setPWM(14, 0, turn_right_ahead_right[i][2]));
      // //backward
      pwm_1.setPWM(4, 0, straight_ahead_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(5, 0, straight_ahead_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(6, 0, straight_ahead_left[sample_num - 1 - i][2]));

      pwm_0.setPWM(9, 0, turn_right_middle_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(10, 0, turn_right_middle_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(11, 0, turn_right_middle_right[sample_num - 1 - i][2]));

      pwm_1.setPWM(12, 0, straight_back_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(13, 0, straight_back_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(14, 0, straight_back_left[sample_num - 1 - i][2]));
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
      pwm_1.setPWM(4, 0, straight_ahead_left[i][0]));
      pwm_1.setPWM(5, 0, straight_ahead_left[i][1]) + hang);
      pwm_1.setPWM(6, 0, straight_ahead_left[i][2]));

      pwm_0.setPWM(9, 0, turn_right_middle_right[i][0]));
      pwm_0.setPWM(10, 0, turn_right_middle_right[i][1]) - hang);
      pwm_0.setPWM(11, 0, turn_right_middle_right[i][2]));

      pwm_1.setPWM(12, 0, straight_back_left[i][0]));
      pwm_1.setPWM(13, 0, straight_back_left[i][1]) + hang);
      pwm_1.setPWM(14, 0, straight_back_left[i][2]));
      //backward
      pwm_0.setPWM(5, 0, turn_right_back_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(6, 0, turn_right_back_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(7, 0, turn_right_back_right[sample_num - 1 - i][2]));

      pwm_1.setPWM(8, 0, straight_middle_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(9, 0, straight_middle_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(10, 0, straight_middle_left[sample_num - 1 - i][2]));

      pwm_0.setPWM(12, 0, turn_right_ahead_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(13, 0, turn_right_ahead_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(14, 0, turn_right_ahead_right[sample_num - 1 - i][2]));
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
      pwm_0.setPWM(5, 0, straight_back_right[i][0]));
      pwm_0.setPWM(6, 0, straight_back_right[i][1]) - hang);
      pwm_0.setPWM(7, 0, straight_back_right[i][2]));

      pwm_1.setPWM(8, 0, turn_left_middle_left[i][0]));
      pwm_1.setPWM(9, 0, turn_left_middle_left[i][1]) + hang);
      pwm_1.setPWM(10, 0, turn_left_middle_left[i][2]));

      pwm_0.setPWM(12, 0, straight_ahead_right[i][0]));
      pwm_0.setPWM(13, 0, straight_ahead_right[i][1]) - hang);
      pwm_0.setPWM(14, 0, straight_ahead_right[i][2]));
      // //backward
      pwm_1.setPWM(4, 0, turn_left_ahead_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(5, 0, turn_left_ahead_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(6, 0, turn_left_ahead_left[sample_num - 1 - i][2]));

      pwm_0.setPWM(9, 0, straight_middle_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(10, 0, straight_middle_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(11, 0, straight_middle_right[sample_num - 1 - i][2]));

      pwm_1.setPWM(12, 0, turn_left_back_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(13, 0, turn_left_back_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(14, 0, turn_left_back_left[sample_num - 1 - i][2]));
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
      pwm_1.setPWM(4, 0, turn_left_ahead_left[i][0]));
      pwm_1.setPWM(5, 0, turn_left_ahead_left[i][1]) + hang);
      pwm_1.setPWM(6, 0, turn_left_ahead_left[i][2]));

      pwm_0.setPWM(9, 0, straight_middle_right[i][0]));
      pwm_0.setPWM(10, 0, straight_middle_right[i][1]) - hang);
      pwm_0.setPWM(11, 0, straight_middle_right[i][2]));

      pwm_1.setPWM(12, 0, turn_left_back_left[i][0]));
      pwm_1.setPWM(13, 0, turn_left_back_left[i][1]) + hang);
      pwm_1.setPWM(14, 0, turn_left_back_left[i][2]));
      //backward
      pwm_0.setPWM(5, 0, straight_back_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(6, 0, straight_back_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(7, 0, straight_back_right[sample_num - 1 - i][2]));

      pwm_1.setPWM(8, 0, turn_left_middle_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(9, 0, turn_left_middle_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(10, 0, turn_left_middle_left[sample_num - 1 - i][2]));

      pwm_0.setPWM(12, 0, straight_ahead_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(13, 0, straight_ahead_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(14, 0, straight_ahead_right[sample_num - 1 - i][2]));
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
      pwm_0.setPWM(5, 0, turn_right_2_back_right[i][0]));
      pwm_0.setPWM(6, 0, turn_right_2_back_right[i][1]) - hang);
      pwm_0.setPWM(7, 0, turn_right_2_back_right[i][2]));

      pwm_1.setPWM(8, 0, straight_middle_left[i][0]));
      pwm_1.setPWM(9, 0, straight_middle_left[i][1]) + hang);
      pwm_1.setPWM(10, 0, straight_middle_left[i][2]));

      pwm_0.setPWM(12, 0, turn_right_2_ahead_right[i][0]));
      pwm_0.setPWM(13, 0, turn_right_2_ahead_right[i][1]) - hang);
      pwm_0.setPWM(14, 0, turn_right_2_ahead_right[i][2]));
      // //backward
      pwm_1.setPWM(4, 0, straight_ahead_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(5, 0, straight_ahead_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(6, 0, straight_ahead_left[sample_num - 1 - i][2]));

      pwm_0.setPWM(9, 0, turn_right_2_middle_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(10, 0, turn_right_2_middle_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(11, 0, turn_right_2_middle_right[sample_num - 1 - i][2]));

      pwm_1.setPWM(12, 0, straight_back_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(13, 0, straight_back_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(14, 0, straight_back_left[sample_num - 1 - i][2]));
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
      pwm_1.setPWM(4, 0, straight_ahead_left[i][0]));
      pwm_1.setPWM(5, 0, straight_ahead_left[i][1]) + hang);
      pwm_1.setPWM(6, 0, straight_ahead_left[i][2]));

      pwm_0.setPWM(9, 0, turn_right_2_middle_right[i][0]));
      pwm_0.setPWM(10, 0, turn_right_2_middle_right[i][1]) - hang);
      pwm_0.setPWM(11, 0, turn_right_2_middle_right[i][2]));

      pwm_1.setPWM(12, 0, straight_back_left[i][0]));
      pwm_1.setPWM(13, 0, straight_back_left[i][1]) + hang);
      pwm_1.setPWM(14, 0, straight_back_left[i][2]));
      //backward
      pwm_0.setPWM(5, 0, turn_right_2_back_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(6, 0, turn_right_2_back_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(7, 0, turn_right_2_back_right[sample_num - 1 - i][2]));

      pwm_1.setPWM(8, 0, straight_middle_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(9, 0, straight_middle_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(10, 0, straight_middle_left[sample_num - 1 - i][2]));

      pwm_0.setPWM(12, 0, turn_right_2_ahead_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(13, 0, turn_right_2_ahead_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(14, 0, turn_right_2_ahead_right[sample_num - 1 - i][2]));
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
      pwm_0.setPWM(5, 0, straight_back_right[i][0]));
      pwm_0.setPWM(6, 0, straight_back_right[i][1]) - hang);
      pwm_0.setPWM(7, 0, straight_back_right[i][2]));

      pwm_1.setPWM(8, 0, turn_left_2_middle_left[i][0]));
      pwm_1.setPWM(9, 0, turn_left_2_middle_left[i][1]) + hang);
      pwm_1.setPWM(10, 0, turn_left_2_middle_left[i][2]));

      pwm_0.setPWM(12, 0, straight_ahead_right[i][0]));
      pwm_0.setPWM(13, 0, straight_ahead_right[i][1]) - hang);
      pwm_0.setPWM(14, 0, straight_ahead_right[i][2]));
      // //backward
      pwm_1.setPWM(4, 0, turn_left_2_ahead_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(5, 0, turn_left_2_ahead_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(6, 0, turn_left_2_ahead_left[sample_num - 1 - i][2]));

      pwm_0.setPWM(9, 0, straight_middle_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(10, 0, straight_middle_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(11, 0, straight_middle_right[sample_num - 1 - i][2]));

      pwm_1.setPWM(12, 0, turn_left_2_back_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(13, 0, turn_left_2_back_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(14, 0, turn_left_2_back_left[sample_num - 1 - i][2]));
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
      pwm_1.setPWM(4, 0, turn_left_ahead_left[i][0]));
      pwm_1.setPWM(5, 0, turn_left_ahead_left[i][1]) + hang);
      pwm_1.setPWM(6, 0, turn_left_ahead_left[i][2]));

      pwm_0.setPWM(9, 0, straight_middle_right[i][0]));
      pwm_0.setPWM(10, 0, straight_middle_right[i][1]) - hang);
      pwm_0.setPWM(11, 0, straight_middle_right[i][2]));

      pwm_1.setPWM(12, 0, turn_left_back_left[i][0]));
      pwm_1.setPWM(13, 0, turn_left_back_left[i][1]) + hang);
      pwm_1.setPWM(14, 0, turn_left_back_left[i][2]));
      //backward
      pwm_0.setPWM(5, 0, straight_back_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(6, 0, straight_back_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(7, 0, straight_back_right[sample_num - 1 - i][2]));

      pwm_1.setPWM(8, 0, turn_left_middle_left[sample_num - 1 - i][0]));
      pwm_1.setPWM(9, 0, turn_left_middle_left[sample_num - 1 - i][1]));
      pwm_1.setPWM(10, 0, turn_left_middle_left[sample_num - 1 - i][2]));

      pwm_0.setPWM(12, 0, straight_ahead_right[sample_num - 1 - i][0]));
      pwm_0.setPWM(13, 0, straight_ahead_right[sample_num - 1 - i][1]));
      pwm_0.setPWM(14, 0, straight_ahead_right[sample_num - 1 - i][2]));
      delay(sleepTime);
    }
  }
}

void stand(int i)
{
      pwm_0.setPWM(5, 0, straight_back_right[i][0]));
      pwm_0.setPWM(6, 0, straight_back_right[i][1]));
      pwm_0.setPWM(7, 0, straight_back_right[i][2]));

      pwm_1.setPWM(8, 0, turn_left_2_middle_left[i][0]));
      pwm_1.setPWM(9, 0, turn_left_2_middle_left[i][1]));
      pwm_1.setPWM(10, 0, turn_left_2_middle_left[i][2]));

      pwm_0.setPWM(12, 0, straight_ahead_right[i][0]));
      pwm_0.setPWM(13, 0, straight_ahead_right[i][1]));
      pwm_0.setPWM(14, 0, straight_ahead_right[i][2]));

      pwm_1.setPWM(4, 0, turn_left_ahead_left[i][0]));
      pwm_1.setPWM(5, 0, turn_left_ahead_left[i][1]));
      pwm_1.setPWM(6, 0, turn_left_ahead_left[i][2]));

      pwm_0.setPWM(9, 0, straight_middle_right[i][0]));
      pwm_0.setPWM(10, 0, straight_middle_right[i][1]));
      pwm_0.setPWM(11, 0, straight_middle_right[i][2]));

      pwm_1.setPWM(12, 0, turn_left_back_left[i][0]));
      pwm_1.setPWM(13, 0, turn_left_back_left[i][1]));
      pwm_1.setPWM(14, 0, turn_left_back_left[i][2]));
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