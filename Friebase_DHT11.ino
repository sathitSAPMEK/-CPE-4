//WIFI
#include <WiFi.h>
#include "FirebaseESP32.h"

#define FIREBASE_HOST "hw-bootcamp.firebaseio.com" //Do not include https:// in FIREBASE_HOST
#define FIREBASE_AUTH "Wleb7G85te03i9RRbZsU9X5Za56g4xwD5D3jMNLG"
#define WIFI_SSID "Error_404"
#define WIFI_PASSWORD "1029384756"

FirebaseData firebaseData;



//DHT11
#include "DHT.h"
#define DHTPIN 2 //data
#define DHTTYPE DHT11 //Type 
DHT dht(DHTPIN, DHTTYPE);

void setup() {
 dht.begin();

 Serial.begin(115200);
 WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }

 Serial.println();
 Serial.print("Connected with IP: ");
 Serial.println(WiFi.localIP());
 Serial.println();

 Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
 Firebase.reconnectWiFi(true);
 Firebase.setReadTimeout(firebaseData, 1000 * 60);
 Firebase.setwriteSizeLimit(firebaseData, "tiny");
 
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
//    Serial.print("Humidity: ");
//    Serial.print(h);
//    Serial.print("%\t");
//    Serial.print("Temperature: ");
//    Serial.print(t);
//    Serial.println(" *C ");
//    delay(1000);
    int value = t ;
    Firebase.pushInt(firebaseData,"/DHT11/int",value);
      delay(1000); 
}
