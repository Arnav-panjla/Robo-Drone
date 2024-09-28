const int fadePin = D10;
//const int fadePin1 =7;
//const int altPin =9;

void setup(){
pinMode(fadePin, OUTPUT);
Serial.begin(9600);
}

void loop(){

for(int i = 0; i<360; i++){
// //convert 0-360 angle to radian (needed for sin function)
float rad = DEG_TO_RAD * i;

//calculate sin of angle as number between 0 and 255
int sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
//int sinOut = 0;
analogWrite(fadePin, sinOut);
//analogWrite(fadePin1, sinOut);

//analogWrite(altPin,sinOut);

Serial.println(sinOut);
delay(15);
}}
// }