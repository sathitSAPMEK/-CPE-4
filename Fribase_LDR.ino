#include <WiFi.h>
#include "FirebaseESP32.h"

#define FIREBASE_HOST "hw-bootcamp.firebaseio.com" //Do not include https:// in FIREBASE_HOST
#define FIREBASE_AUTH "Wleb7G85te03i9RRbZsU9X5Za56g4xwD5D3jMNLG"
#define WIFI_SSID "Error_404"
#define WIFI_PASSWORD "1029384756"

FirebaseData firebaseData;


const int analogInPin = A0;
int LED = 16;  

void setup() {
 Serial.begin(115200);
 pinMode(LED,OUTPUT);
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
  // read the analog in value:
 int sensorValue = analogRead(analogInPin);//อ่านค่าsensoranalogInPin = A0เก็บไว้ในsensorValue
 int  outputValue = map(sensorValue, 0,4096, 0, 255);//setค่าsensor
//  Serial.print("sensor = ");
//  Serial.print(sensorValue);
//  Serial.print("\t output = ");
  Firebase.pushInt(firebaseData,"/Psh/Int/Output value",outputValue);
  delay(1000);
  int LDR_value = Firebase.getInt(firebaseData,"/Psh/Int/Output value",outputValue);
  Serial.print(LDR_value);
//  if(LDR_value<150){
//    digitalWrite(LED,HIGH);
//  }else;
}
