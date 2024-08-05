#include <IRremote.h>

int button = 0;
int on_or_off = 0;

// maps a code from sensor to button
int mapCodeToButton(unsigned long code)
{
  if ((code & 0x0000FFFF) == 0x0000BF00)
  {
    code >>= 16;
    if (((code >> 8) ^ (code & 0x00FF)) == 0x00FF)
    {
      return code & 0XFF;
    }
  }
  return -1;
}

int readInfrared()
{
  int result = -1;
  if (IrReceiver.decode())
  {
    unsigned long code = IrReceiver.decodedIRData.decodedRawData;
    // map it to specific button on the remote
    result = mapCodeToButton(code);
    // enable receiving of next value
    IrReceiver.resume();
  }
  return result;
}


void setup() {
  // put your setup code here, to run once:
  IrReceiver.begin(2);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  button = readInfrared();
  Serial.println(button);
  // if button 0 is pressed
  if (button == 12)
  {
    // togggle light bulb
    if (on_or_off)
    {
      digitalWrite(3, LOW);
      on_or_off = 0;
    }
    else
    {
      digitalWrite(3, HIGH);
      on_or_off = 1;
    }
  }
  delay(500);

}
