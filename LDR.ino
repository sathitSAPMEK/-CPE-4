const int analogInPin = A0;  

void setup() {
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
 int sensorValue = analogRead(analogInPin);//อ่านค่าsensoranalogInPin = A0เก็บไว้ในsensorValue
 int  outputValue = map(sensorValue, 0,4096, 0, 255);//setค่าsensor
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);
  delay(100);
}
