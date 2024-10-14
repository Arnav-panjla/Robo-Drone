#include <esp_now.h>
#include <WiFi.h>

#define ESPNOW_WIFI_CHANNEL 6

const int fadePins[] = {D10, D9, D8, D7}; // Array of fade pins
const int LEDpin = D6;
int pwmval = 0;
unsigned long lastSignalTime = 0; // Track the last time a signal was received
const unsigned long blinkInterval = 500; // Blink interval in milliseconds
bool ledState = false; // Track LED state

void onDataRecv(const esp_now_recv_info_t *info, const uint8_t *data, int len) {
  if (len <= 0) return;

  char receivedData[len + 1];
  memcpy(receivedData, data, len);
  receivedData[len] = '\0';

  pwmval = atoi(receivedData);
  if (pwmval < 200) {
    pwmval = 200;
  }

  int pwm1 = map(pwmval, 200, 4095, 0, 255);

  // Write the PWM value to all fade pins
  for (int i = 0; i < sizeof(fadePins) / sizeof(fadePins[0]); i++) {
    analogWrite(fadePins[i], pwm1);
  }

  digitalWrite(LEDpin, HIGH); // Turn LED off when data is received
  lastSignalTime = millis(); // Update the last signal time
}

void setup() {
  for (int i = 0; i < sizeof(fadePins) / sizeof(fadePins[0]); i++) {
    pinMode(fadePins[i], OUTPUT); // Set each fade pin as output
  }
  
  pinMode(LEDpin, OUTPUT);
  
  WiFi.mode(WIFI_STA);
  WiFi.setChannel(ESPNOW_WIFI_CHANNEL);

  if (esp_now_init() != ESP_OK) {
    // Indicate error on LED
    while (true) {
      digitalWrite(LEDpin, HIGH);
      delay(100);
      digitalWrite(LEDpin, LOW);
      delay(100);
    }
  }

  esp_now_register_recv_cb(onDataRecv);
  digitalWrite(LEDpin, HIGH); // Start with LED off initially
}

void loop() {
  // Check if enough time has passed since the last signal was received
  if (millis() - lastSignalTime > 1000) { // 1 second without a signal
    ledState = !ledState; // Toggle LED state
    digitalWrite(LEDpin, ledState ? HIGH : LOW); // Set LED
    delay(blinkInterval); // Delay to control blink speed
  }
}
