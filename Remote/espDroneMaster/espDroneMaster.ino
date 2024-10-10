#include <esp_now.h>
#include <WiFi.h>
#define X_AXIS_PIN 32   // Joystick X-axis connected to D14
#define Y_AXIS_PIN 35   // Joystick Y-axis connected to D27
#define BUTTON_PIN 23   // Joystick button connected to D23 (you can change this if needed)
#define ESPNOW_WIFI_CHANNEL 6

// Define the broadcast MAC address
uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

// PWM value to be sent
int yVal = 10;  // Example value
//void yvalue() {
  //yVal = analogRead(Y_AXIS_PIN);
//}
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("Last Packet Send Status: ");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  // Initialize Wi-Fi in station mode
  WiFi.mode(WIFI_STA);
  WiFi.setChannel(ESPNOW_WIFI_CHANNEL);

  // Initialize ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    ESP.restart();
  }

  // Register the send callback
  esp_now_register_send_cb(OnDataSent);

  // Define peer info structure for broadcast
  esp_now_peer_info_t peerInfo;
  memset(&peerInfo, 0, sizeof(esp_now_peer_info_t));
  memcpy(peerInfo.peer_addr, broadcastAddress, sizeof(broadcastAddress));
  peerInfo.channel = ESPNOW_WIFI_CHANNEL;
  peerInfo.encrypt = false; // No encryption

  // Register the broadcast peer
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Error adding broadcast peer");
    ESP.restart();
  }

  Serial.println("Master setup complete. Broadcasting data...");
}

void loop() {
  char data[32];
  int xVal = analogRead(X_AXIS_PIN);  // Read the X-axis value
  //yvalue();
  //Serial.println(yVal);
  //Serial.println(xVal);
  yVal = analogRead(Y_AXIS_PIN);  // Read the Y-axis value
  
  int buttonVal = digitalRead(BUTTON_PIN);
  // Convert yVal to string and send it
  snprintf(data, sizeof(data), "%d", yVal);  // Sending yVal
  //snprintf(data, sizeof(data), "%d", buttonVal);
  // Broadcast the message
  if (esp_now_send(broadcastAddress, (uint8_t *)data, sizeof(data)) == ESP_OK) {
    Serial.print("Broadcasting yVal: ");
    Serial.println(yVal);
    //Serial.println(buttonVal);
  } else {
    Serial.println("Failed to send data");
  }

  delay(100);  // Broadcast every 5 seconds
}