#include <IBusBM.h>
IBusBM IBus;
const int fadePin =10;
void setup() {
  pinMode(fadePin, OUTPUT);
  Serial.begin(115200);
  IBus.begin(Serial);
  delay(2000);
}

int data[10];

void readChannel() {
  for (int i = 0; i < 10; i++) {
    data[i] = IBus.readChannel(i);
  }
  delay(10);
}

void loop() {
  readChannel();
  int throtle=data[2];
  int voltage=map(throtle,1000,2000,0,255);
  //Serial.println(voltage);
  //for(int i = 0; i<360; i++){
// //convert 0-360 angle to radian (needed for sin function)
  //float rad = DEG_TO_RAD * i;

  //calculate sin of angle as number between 0 and 255
  // int sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
  //int sinOut = 0;
  analogWrite(fadePin, voltage);
  //analogWrite(altPin,sinOut);

  Serial.println(voltage);

}