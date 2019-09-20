#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <SocketIOClient.h>
#include <ArduinoJson.h> 

// Replace with your network credentials
const byte RX = RX;
const byte TX = TX;
SocketIOClient client;
const char* ssid = "datphanhuu";
const char* password = "huudat99";

char host[] = "ledcube2019.herokuapp.com";
int port = 80; 

extern String RID;
extern String Rfull;
 
const int ESP_BUILTIN_LED = 2;

void setup() {
  Serial.begin(115200);
//  Serial.println("Booting");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

  // Port defaults to 8266
  // ArduinoOTA.setPort(8266);

  // Hostname defaults to esp8266-[ChipID]
  // ArduinoOTA.setHostname("myesp8266");

  // No authentication by default
  // ArduinoOTA.setPassword((const char *)"123");

  ArduinoOTA.onStart([]() {
    Serial.println("Start");
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });
  ArduinoOTA.begin();
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  pinMode(ESP_BUILTIN_LED, OUTPUT);

//  --------------------------------------------------
  client.connect(host, port);
  if (!client.connect(host, port)) {
        client.connect(host, port);
    }
}

void loop() {
  ArduinoOTA.handle();
  if(!client.connected()) {
      
      client.reconnect(host, port);
      delay(1);
    }
    if (client.monitor()) {
        //in ra serial cho Arduino
      StaticJsonDocument<200> doc;
      DeserializationError err = deserializeJson(doc, Rfull);
      int dataMode = (int)doc["AR"];
      if(!err)
       {
          Serial.write(dataMode+48);
          Rfull = {""};
       }
    }
}
