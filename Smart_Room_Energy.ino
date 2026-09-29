// AI-Based Smart Room Energy Monitoring System
// Embedded monitoring code using ESP32

const int CURRENT_SENSOR_PIN = 34;
const int TEMP_SENSOR_PIN = 35;
const int ALERT_LED_PIN = 2;

float energyLimit = 300.0;

void setup() {
  Serial.begin(115200);
  pinMode(ALERT_LED_PIN, OUTPUT);

  Serial.println("Smart Room Energy Monitor Started");
}

void loop() {

  // Simulated sensor readings
 // Read multiple samples to reduce sensor noise
float totalReading = 0;

for (int i = 0; i < 10; i++) {
  totalReading += analogRead(CURRENT_SENSOR_PIN);
  delay(10);
}

float currentReading = totalReading / 10.0;
// Read temperature sensor continuously
float temperatureReading = analogRead(TEMP_SENSOR_PIN);

Serial.print("Updated Temperature Sensor Reading: ");
Serial.println(temperatureReading);

// Convert averaged sensor reading to estimated energy usage
float energyUsage = (currentReading / 4095.0) * 500.0;

  // Convert sensor reading to estimated energy usage
  float energyUsage = (currentReading / 4095.0) * 500.0;

  Serial.print("Energy Usage: ");
  Serial.print(energyUsage);
  Serial.println(" W");

  Serial.print("Temperature Sensor: ");
  Serial.println(temperatureReading);

  // Abnormal energy consumption detection
  // Check for abnormal energy consumption
bool abnormalEnergy = energyUsage > energyLimit;

if (abnormalEnergy) {
  digitalWrite(ALERT_LED_PIN, HIGH);
  Serial.println("ALERT: Abnormal energy consumption detected!");
}
else {
  digitalWrite(ALERT_LED_PIN, LOW);
  Serial.println("Status: Normal energy consumption");
}

  delay(2000);
}
