#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22
#define PIRPIN 27
#define LEDPIN 26

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;

const char* topic = "ishant-smart-home-demo-48271";

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  pinMode(PIRPIN, INPUT);
  pinMode(LEDPIN, OUTPUT);

  dht.begin();

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected!");

  client.setServer(mqtt_server, mqtt_port);

  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");

    if (client.connect("SmartHomeESP32Demo48271")) {
      Serial.println("MQTT connected!");
    } else {
      Serial.print("MQTT failed, state: ");
      Serial.println(client.state());
      delay(2000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    if (client.connect("SmartHomeESP32Demo48271")) {
      Serial.println("MQTT reconnected!");
    } else {
      delay(2000);
      return;
    }
  }

  client.loop();

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int motion = digitalRead(PIRPIN);

  digitalWrite(LEDPIN, motion ? HIGH : LOW);

  if (!isnan(temperature) && !isnan(humidity)) {
    char payload[160];

    snprintf(
      payload,
      sizeof(payload),
      "{\"temperature\":%.1f,\"humidity\":%.1f,\"motion\":%d,\"light\":%d}",
      temperature,
      humidity,
      motion,
      motion
    );

    client.publish(topic, payload);
    Serial.println(payload);
  }

  delay(3000);
}
