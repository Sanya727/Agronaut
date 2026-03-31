#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

// WiFi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// ThingSpeak
String apiKey = "903UPT1PX6LOIO3H";
String server = "http://api.thingspeak.com/update";

// DHT Sensor
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// Analog Pins
int soilPin = 34;
int nPin = 32;
int pPin = 33;
int kPin = 35;

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password);
  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi!");
}

void loop() {

  // Read sensors
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();

  int soilRaw = analogRead(soilPin);
  int nRaw = analogRead(nPin);
  int pRaw = analogRead(pPin);
  int kRaw = analogRead(kPin);

  // Convert values
  int soil = map(soilRaw, 0, 4095, 100, 0);
  int N = map(nRaw, 0, 4095, 0, 100);
  int P = map(pRaw, 0, 4095, 0, 100);
  int K = map(kRaw, 0, 4095, 0, 100);

  // Print values
  Serial.println("------ SENSOR DATA ------");
  Serial.print("Temperature: "); Serial.println(temp);
  Serial.print("Humidity: "); Serial.println(humidity);
  Serial.print("Soil Moisture: "); Serial.println(soil);
  Serial.print("Nitrogen (N): "); Serial.println(N);
  Serial.print("Phosphorus (P): "); Serial.println(P);
  Serial.print("Potassium (K): "); Serial.println(K);

  // Send to ThingSpeak
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String url = server + "?api_key=" + apiKey +
                 "&field1=" + String(temp) +
                 "&field2=" + String(humidity) +
                 "&field3=" + String(soil) +
                 "&field4=" + String(N) +
                 "&field5=" + String(P) +
                 "&field6=" + String(K);

    http.begin(url);
    int response = http.GET();

    Serial.print("Response Code: ");
    Serial.println(response);

    http.end();
  }

  delay(15000); // ThingSpeak limit
}