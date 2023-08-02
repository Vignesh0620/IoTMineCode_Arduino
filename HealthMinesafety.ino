#include <DHT.h>

// DHT11 Sensor
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// MQ-5 Gas Sensor
#define GAS_SENSOR_PIN A0
const int gasThreshold = 430; // Adjust this threshold value based on your calibration

// Alcohol Sensor (MQ-3)
#define ALCOHOL_SENSOR_PIN A1
const int alcoholThreshold = 400; // Adjust this threshold value based on your calibration

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);

  // Initialize DHT11 sensor
  dht.begin();
}

void loop() {
  // Read sensor data
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int gasValue = analogRead(GAS_SENSOR_PIN);
  int alcoholValue = analogRead(ALCOHOL_SENSOR_PIN);

  // Print sensor data in Serial Monitor
  Serial.println("-------- Mine Safety Monitoring --------");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C ");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  Serial.print("Gas Value: ");
  Serial.println(gasValue);
  Serial.print("Alcohol Value: ");
  Serial.println(alcoholValue);

  // Check for abnormal readings and print warning messages
  if (gasValue > gasThreshold) {
    Serial.println("WARNING: Toxic gas detected!");
  }

  if (alcoholValue > alcoholThreshold) {
    Serial.println("WARNING: Person may be intoxicated!");
  }
  if (temperature > 32) {
    Serial.println("Temperature is too hot");
  }

  delay(5000); // Update data every 5 seconds
}
