#include <WiFi.h>
#include <ThingSpeak.h>

// WiFi credentials
const char *ssid = "vivoy";           // Your WiFi SSID
const char *password = "12345678";    // Your WiFi Password

// ThingSpeak credentials
unsigned long channelID = 2792801;    // Your ThingSpeak channel ID
const char *apiKey = "T7IX7635P4NG7J7Y";  // Your ThingSpeak Write API Key

// Sensor pins
#define SOUND_SENSOR_PIN 15
#define VIBRATION_SENSOR_PIN 18
#define FLAME_SENSOR_PIN 19
#define GAS_SENSOR_PIN 34

WiFiClient client;

void setup() {
  Serial.begin(9600);
  pinMode(SOUND_SENSOR_PIN, INPUT);
  pinMode(VIBRATION_SENSOR_PIN, INPUT);
  pinMode(FLAME_SENSOR_PIN, INPUT);
  pinMode(GAS_SENSOR_PIN, INPUT);

  connectToWiFi();
  ThingSpeak.begin(client);
}

void loop() {
  // Ensure WiFi connection
  if (WiFi.status() != WL_CONNECTED) {
    connectToWiFi();
  }

  // Read sensor values
  int soundDetected = digitalRead(SOUND_SENSOR_PIN);
  int vibrationDetected = digitalRead(VIBRATION_SENSOR_PIN);
  int flameDetected = digitalRead(FLAME_SENSOR_PIN);
  int gasLevel = analogRead(GAS_SENSOR_PIN);

  // Constrain gas level to a valid range
  gasLevel = constrain(gasLevel, 0, 4095);

  // Print sensor values to Serial Monitor
  Serial.print("Sound: ");
  Serial.print(soundDetected);
  Serial.print(" | Vibration: ");
  Serial.print(vibrationDetected);
  Serial.print(" | Flame: ");
  Serial.print(flameDetected);
  Serial.print(" | Gas Level: ");
  Serial.println(gasLevel);

  // Send data to ThingSpeak
  ThingSpeak.setField(1, soundDetected);
  ThingSpeak.setField(2, vibrationDetected);
  ThingSpeak.setField(3, flameDetected);
  ThingSpeak.setField(4, gasLevel);

  int statusCode = ThingSpeak.writeFields(channelID, apiKey);

  // Handle ThingSpeak response
  if (statusCode == 200) {
    Serial.println("Data sent successfully.");
  } else if (statusCode == -401) {
    Serial.println("Error: Unauthorized. Check your API key and channel ID.");
  } else if (statusCode == -304) {
    Serial.println("Error: Rate limit exceeded. Ensure 15 seconds between updates.");
  } else {
    Serial.print("Error sending data. Status code: ");
    Serial.println(statusCode);
  }

  delay(15000); // Ensure a 15-second delay to comply with ThingSpeak rate limits
}

void connectToWiFi() {
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\nWiFi connected. IP Address: " + WiFi.localIP().toString());
}
