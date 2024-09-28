// Name pin 10 as motorPin for motor pin identification
int motorPin = D5;
// Name pin A0 as potPin for potentiometer pin identification
int potPin = A0;

int controlValue = 0;

void setup () {
	pinMode(potPin, INPUT);	
}

void loop() {
	controlValue = analogRead(potPin);
	analogWrite(motorPin, controlValue/4);
	// wait 2 milliseconds ADC to settle after the last reading:
	delayMicroseconds(2);
}
