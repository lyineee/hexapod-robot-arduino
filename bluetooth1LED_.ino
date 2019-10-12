int stat=0;
void setup() {
  Serial.begin(9600);//模块上电灯快闪，arduino发送指令时需要按住模块上的按键
  Serial.println("Hello");
  pinMode(LED_BUILTIN,OUTPUT);
}

void sendcmd(){
  //Serial.println("AT");//send cmd AT\r\n
  while(Serial.available())
  {
    char ch;
    ch = Serial.read();
    Serial.print(ch);
    digitalWrite(LED_BUILTIN,HIGH);
  } // Get response: OK\r\n
  delay(1000); // wait for printing 
  digitalWrite(LED_BUILTIN,LOW);

}

void loop() {
   sendcmd();//循环发送AT指令，并接收反馈（测试模块AT指令时使用）
  // char c;
  // c=Serial.read();
  // Serial.println(c);
  
  //  while(Serial.available())
  // {
  //   Serial.println('1');
//    int timeStart = millis();
    // char ch;
//    String str;
    // ch = Serial.read();
    // Serial.println(ch); 
  // } // Get response
//  Serial.println('0');

}

//void serialEvent(){
//  stat=int(Serial.read());
//}
