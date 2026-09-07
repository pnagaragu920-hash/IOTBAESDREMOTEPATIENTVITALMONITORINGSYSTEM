#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include "MAX30105.h"
#include "heartRate.h"

// -----------------------------
// Wi-Fi Configuration
// -----------------------------
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

// -----------------------------
// Sensor Objects
// -----------------------------
MAX30105 max30102;
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

// -----------------------------
// AD8232 ECG Pin
// -----------------------------
#define ECG_PIN 34

// -----------------------------
// Blood Pressure
// -----------------------------
// Connect your actual BP sensor/module here.
// The exact code depends on the BP sensor used.

// -----------------------------
// Variables
// -----------------------------
float temperature;
int heartRate = 0;
int spo2 = 0;
int systolicBP = 0;
int diastolicBP = 0;
int ecgValue = 0;

void setup() {

  Serial.begin(115200);

  // Start I2C
  Wire.begin();

  // -----------------------------
  // Connect to Wi-Fi
  // -----------------------------
  WiFi.begin(ssid, password);

  Serial.print("Connecting to Wi-Fi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Wi-Fi Connected!");

  // -----------------------------
  // Initialize MLX90614
  // -----------------------------
  if (!mlx.begin()) {
    Serial.println("MLX90614 not detected!");
  } else {
    Serial.println("MLX90614 initialized.");
  }

  // -----------------------------
  // Initialize MAX30102
  // -----------------------------
  if (!max30102.begin(Wire, I2C_SPEED_FAST)) {
    Serial.println("MAX30102 not detected!");
  } else {

    Serial.println("MAX30102 initialized.");

    max30102.setup();

    max30102.setPulseAmplitudeRed(0x0A);
    max30102.setPulseAmplitudeGreen(0);
  }

  // -----------------------------
  // ECG
  // -----------------------------
  pinMode(ECG_PIN, INPUT);

  Serial.println("System Ready!");
}

void loop() {

  // -----------------------------
  // Temperature
  // -----------------------------
  temperature = mlx.readObjectTempC();

  // -----------------------------
  // MAX30102
  // -----------------------------
  long irValue = max30102.getIR();

  if (irValue > 50000) {

    if (checkForBeat(irValue)) {

      static unsigned long lastBeat = 0;

      unsigned long currentTime = millis();

      float bpm = 60.0 / ((currentTime - lastBeat) / 1000.0);

      lastBeat = currentTime;

      if (bpm > 40 && bpm < 200) {
        heartRate = (int)bpm;
      }
    }

    // SpO2 calculation requires
    // red/IR signal processing.
    // Add your calibrated algorithm/library here.

  } else {

    heartRate = 0;
    spo2 = 0;
  }

  // -----------------------------
  // ECG Reading
  // -----------------------------
  ecgValue = analogRead(ECG_PIN);

  // -----------------------------
  // Blood Pressure
  // -----------------------------
  // Replace these placeholders with
  // readings from your actual BP module.

  // -----------------------------
  // Display Values
  // -----------------------------
  Serial.println("-----------------------------");

  Serial.print("Heart Rate: ");
  Serial.print(heartRate);
  Serial.println(" BPM");

  Serial.print("SpO2: ");
  Serial.print(spo2);
  Serial.println(" %");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Blood Pressure: ");
  Serial.print(systolicBP);
  Serial.print("/");
  Serial.print(diastolicBP);
  Serial.println(" mmHg");

  Serial.print("ECG: ");
  Serial.println(ecgValue);

  delay(1000);
}
