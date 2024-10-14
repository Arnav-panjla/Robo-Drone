#include <esp_now.h>
#include <WiFi.h>

#define PotPIN 36
#define Y_AXIS_PIN 35
#define BUTTON_PIN 23
#define LED_PIN 19      // LED that indicates everything is fine
#define ERROR_LED_PIN 22 // LED that indicates an error
#define ESPNOW_WIFI_CHANNEL 6

uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
    Serial.print("Last Packet Send Status: ");
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void setup() {
    Serial.begin(115200);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);      // Set LED pin as output
    pinMode(ERROR_LED_PIN, OUTPUT); // Set error LED pin as output
    
    digitalWrite(LED_PIN, HIGH);    // Turn on LED initially to indicate everything is fine
    digitalWrite(ERROR_LED_PIN, LOW); // Ensure error LED is off initially

    WiFi.mode(WIFI_STA);
    WiFi.setChannel(ESPNOW_WIFI_CHANNEL);

    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        digitalWrite(LED_PIN, LOW);      // Turn off LED indicating normal operation
        digitalWrite(ERROR_LED_PIN, HIGH); // Turn on error LED
        ESP.restart();
    }

    esp_now_register_send_cb(OnDataSent);
    
    esp_now_peer_info_t peerInfo;
    memset(&peerInfo, 0, sizeof(peerInfo));
    memcpy(peerInfo.peer_addr, broadcastAddress, sizeof(broadcastAddress));
    peerInfo.channel = ESPNOW_WIFI_CHANNEL;
    peerInfo.encrypt = false;

    if (esp_now_add_peer(&peerInfo) != ESP_OK) {
        Serial.println("Error adding broadcast peer");
        digitalWrite(LED_PIN, LOW);       // Turn off LED indicating normal operation
        digitalWrite(ERROR_LED_PIN, HIGH); // Turn on error LED
        ESP.restart();
    }

    Serial.println("Master setup complete. Broadcasting data...");
}

void loop() {
    char data[32];
    int potVal = analogRead(PotPIN);
    int yVal = analogRead(Y_AXIS_PIN);
    int buttonVal = digitalRead(BUTTON_PIN);

    // Combine data into a single value, you could also use a struct for more complex data
    int val = (9 * map(potVal, 0, 4095, 4095, 0) / 10) + (yVal / 10);

    snprintf(data, sizeof(data), "%d,%d", val, buttonVal);

    if (esp_now_send(broadcastAddress, (uint8_t *)data, sizeof(data)) == ESP_OK) {
        Serial.print("Broadcasting Val: ");
        Serial.println(data);
    } else {
        Serial.println("Failed to send data");
        digitalWrite(LED_PIN, LOW);        // Turn off LED indicating normal operation
        digitalWrite(ERROR_LED_PIN, HIGH); // Turn on error LED on send failure
    }

    delay(200);  // Broadcast every 200 milliseconds
}
