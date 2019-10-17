#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
// #include <pgmspace.h>

Adafruit_PWMServoDriver pwm_0 = Adafruit_PWMServoDriver();
Adafruit_PWMServoDriver pwm_1 = Adafruit_PWMServoDriver(&Wire, 0x41);

#define SERVOMIN 92 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 464 // this is the 'maximum' pulse length count (out of 4096)

// #define SERVOMIN 102  // this is the 'minimum' pulse length count (out of 4096)
// #define SERVOMAX 1500 // this is the 'maximum' pulse length count (out of 4096)

//data begin

int servo_value = 0;
uint8_t current_servo = 0;
int stage = 1;
int change_currentservo_flag =0;
char buffer[50]={0};
int index=0;

void setup()
{
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");
//   pinMode(change_btn, INPUT);

  pwm_0.reset();
  pwm_1.reset();

  pwm_0.begin();
  pwm_1.begin();

  pwm_0.setPWMFreq(50); // Analog servos run at ~60 Hz updates
  pwm_1.setPWMFreq(50); // Analog servos run at ~60 Hz updates
  pinMode(LED_BUILTIN, OUTPUT);
  // convert_data();

  delay(10);
  // Serial.println( pgm_read_word(&straight_back_right[23][2]));
  // for(int i=0;i<50;i++)
  //   for(int k=0;k<3;k++){
  //     Serial.print(pgm_read_word(&straight_back_right[i][k]));
  //     Serial.print(' ');}
}


void loop(){
    // uint16_t de_t=430;
    // pwm_0.setPWM(0,0,SERVOMIN);
    // // delay(de_t);
    // delay(de_t);
    // pwm_0.setPWM(0,0,SERVOMAX);
    // delay(de_t);

    // long t_s = millis();
    uint16_t de_t1=4;

    for(uint32_t i=SERVOMIN;i<SERVOMAX-4;i+=4){
        pwm_0.setPWM(0,0,i);
        delay(de_t1);
    }
    // Serial.println(millis()-t_s);

    for(uint32_t i=SERVOMAX;i>SERVOMIN+4;i-=4){
        pwm_0.setPWM(0,0,i);
        delay(de_t1);
    }
}

void parse(char data[]){
    int cmd = (data[0]-'0')*10+(data[1]-'0');
    int arg = (data[2]-'0')*100+(data[3]-'0')*10+(data[4]-'0');

    current_servo=cmd;
    servo_value=arg;
    // Serial.println(cmd);
    // Serial.println(arg);

}

void serialEvent(){

    if(index<5){
        buffer[index]=Serial.read();
        index++;
    }else{
        index=0;
        parse(buffer);
    }
}
