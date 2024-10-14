#include <Wire.h>
#include <DFRobot_BMX160.h>

DFRobot_BMX160 bmx160;

const float alpha = 0.98; // Complementary filter constant
float pitch = 0.0;
float roll = 0.0;
unsigned long previousTime;

void setup() {
  Serial.begin(115200);

  if (!bmx160.begin()) {
    Serial.println("Could not find a valid BMX160 sensor, check wiring!");
    while (1);
  }

  bmx160.wakeUp();
  bmx160.setGyroRange(eGyroRange_2000DPS);
  bmx160.setAccelRange(eAccelRange_16G);

  previousTime = millis();
}

void loop() {
  unsigned long currentTime = millis();
  float dt = (currentTime - previousTime) / 1000.0; // Convert milliseconds to seconds
  previousTime = currentTime;

  sBmx160SensorData_t Omagn, Ogyro, Oaccel;
  bmx160.getAllData(&Omagn, &Ogyro, &Oaccel);

  // Read accelerometer data
  float accX = Oaccel.x;
  float accY = Oaccel.y;
  float accZ = Oaccel.z;

  // Calculate pitch and roll from accelerometer
  float accPitch = atan2(accY, accZ) * 180 / PI;
  float accRoll = atan2(-accX, sqrt(accY * accY + accZ * accZ)) * 180 / PI;

  // Read gyroscope data
  float gyroX = Ogyro.x; // Gyro data in degrees per second
  float gyroY = Ogyro.y;

  // Integrate gyroscope data to get angles
  pitch += gyroX * dt;
  roll += gyroY * dt;

  // Apply complementary filter
  pitch = alpha * pitch + (1 - alpha) * accPitch;
  roll = alpha * roll + (1 - alpha) * accRoll;

  // Print the results in degrees
  
  Serial.print(pitch);
  Serial.print(", ");
  Serial.print(roll);
  Serial.println(" degrees");

  delay(10);
}