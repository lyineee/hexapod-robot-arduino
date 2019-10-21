
int data = 7;
void setup()
{
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    analogWrite(LED_BUILTIN,LOW);
}

void loop()
{
    get_bluez_data();
    // if(data == 1)
    //     analogWrite(LED_BUILTIN,HIGH);
    // else
    //     analogWrite(LED_BUILTIN,LOW);
}
void get_bluez_data()
{
    while (Serial.available() > 0)
    {
        Serial.println('g');
        data = int(Serial.read()) - '0';
    }
}