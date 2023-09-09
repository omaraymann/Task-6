//define registers 
#define IMU_ADD 0x68
#define GYRO_CONFIG 0x1B
#define PWR_MGMT_1 0x6B
#define ACCEL_ZOUT_H 0x3F
#define GYRO_ZOUT_H 0x43

#include <Wire.h>
// MPU6050 variables
int16_t acc_X, acc_Y, acc_Z;
int16_t gyr_X, gyr_Y, gyr_Z;
float yaw_angle;

void setup() {
  Serial.begin(9600);
  
  //I2C communication
  Wire.begin();
  
  // Wake up MPU6050
  Wire.beginTransmission(IMU_ADD);
  Wire.write(PWR_MGMT_1);
  Wire.write(0);
  Wire.endTransmission(true);
  
  // Configure gyroscope range
  Wire.beginTransmission(IMU_ADD);
  Wire.write(GYRO_CONFIG);
  Wire.write(0x00);  // Set full-scale range to ±250 degrees per second
  Wire.endTransmission(true);
}

void loop() {
  // Read accelerometer data
  Wire.beginTransmission(IMU_ADD);
  Wire.write(ACCEL_ZOUT_H);
  Wire.endTransmission(false);
  Wire.requestFrom(IMU_ADD, 6, true);
  acc_X = Wire.read() << 8 | Wire.read();
  acc_Y = Wire.read() << 8 | Wire.read();
  acc_Z = Wire.read() << 8 | Wire.read();
  
  // Read gyroscope data
  Wire.beginTransmission(IMU_ADD);
  Wire.write(GYRO_ZOUT_H);
  Wire.endTransmission(false);
  Wire.requestFrom(IMU_ADD, 6, true);
  gyr_X = Wire.read() << 8 | Wire.read();
  gyr_Y = Wire.read() << 8 | Wire.read();
  gyr_Z = Wire.read() << 8 | Wire.read();
  
  // Convert raw gyroscope values to degrees per second
  float gyroScale = 250.0 / 32768.0;  // ±250 degrees per second
  float gyro_X_deg = gyr_X * gyroScale;
  float gyro_Y_deg = gyr_Y * gyroScale;
  float gyro_Z_deg = gyr_Z * gyroScale;
  
  // Calculate yaw angle
  yaw_angle+= (gyro_Z_deg / 1000.0) * (180.0 / PI);  // Integration over time
  
  // Print yaw angle
  Serial.print("Yaw Angle: ");
  Serial.println(yaw_angle);
  delay(1500);
}
