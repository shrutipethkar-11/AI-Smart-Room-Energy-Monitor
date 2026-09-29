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
  float currentReading = analogRead(CURRENT_SENSOR_PIN);
  float temperatureReading = analogRead(TEMP_SENSOR_PIN);

  // Convert sensor reading to estimated energy usage
  float energyUsage = (currentReading / 4095.0) * 500.0;

  Serial.print("Energy Usage: ");
  Serial.print(energyUsage);
  Serial.println(" W");

  Serial.print("Temperature Sensor: ");
  Serial.println(temperatureReading);

  // Abnormal energy consumption detection
  if (energyUsage > energyLimit) {
    digitalWrite(ALERT_LED_PIN, HIGH);
    Serial.println("ALERT: Abnormal energy consumption detected!");
  } 
  else {
    digitalWrite(ALERT_LED_PIN, LOW);
    Serial.println("Status: Normal energy consumption");
  }

  delay(2000);
}
