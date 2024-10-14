#include <esp_now.h>
#include <WiFi.h>



/// transmitting the recieved signal to all motor pins 

#define ESPNOW_WIFI_CHANNEL 6
const int fadePin1 = D7;
const int fadePin2 = D8;
const int fadePin3 = D9;
const int fadePin4 = D10;
const int LEDpin = D6;

int pwmval(0);

// Correct callback function signature
void onDataRecv(const esp_now_recv_info_t *info, const uint8_t *data, int len) {
  // Ensure the received data is null-terminated
  char receivedData[len + 1];
  memcpy(receivedData, data, len);
  receivedData[len] = '\0';  // Null-terminate the string

  // Convert the received string to an integer
  pwmval = atoi(receivedData);
  if (pwmval<200){
    pwmval=200;
  }
  int pwm1= map(pwmval, 200, 4095, 0, 255);
  analogWrite(fadePin1, pwm1);
  analogWrite(fadePin2, pwm1);
  analogWrite(fadePin3, pwm1);
  analogWrite(fadePin4, pwm1);

  digitalWrite(LEDpin,HIGH);// lighing the blue LED

  // Print the received pwmval
  Serial.printf("Received pwmval: %d\n", pwm1);
}


void setup() {
  Serial.begin(115200);
  pinMode(fadePin1, OUTPUT);
  pinMode(fadePin2, OUTPUT);
  pinMode(fadePin3, OUTPUT);
  pinMode(fadePin4, OUTPUT);
  pinMode(LEDpin,OUTPUT);



  while (!Serial) {
    delay(10);
  }

  // Initialize Wi-Fi in station mode
  WiFi.mode(WIFI_STA);
  WiFi.setChannel(ESPNOW_WIFI_CHANNEL);

  // Initialize ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    ESP.restart();
  }

  // Register the callback function for receiving data
  esp_now_register_recv_cb(onDataRecv);

  digitalWrite(LEDpin,LOW);//LED at low state
  Serial.println("Slave setup complete. Waiting for data...");
}

void loop() {
  //analogWrite(fadePin, pwmval);

  // Nothing to do here. All data is handled in the onDataRecv callback
  // Serial.println(pwmval);
  delay(1000);
}