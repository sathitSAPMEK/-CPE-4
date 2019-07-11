const int analogInPin = A0; 
const int sensorValue = 0; 
int LED = 16 ;

void setup() {
  Serial.begin(9600);
  pinMode(16,OUTPUT);
}

void loop() {
 int sensorValue = analogRead(analogInPin);//อ่านค่าsensoranalogInPin = A0เก็บไว้ในsensorValue
 int  outputValue = map(sensorValue, 0,4096, 0, 255);//setค่าsensor
  
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);
  if(outputValue<150){
    digitalWrite(LED,HIGH);
  }else{
    digitalWrite(LED,LOW);
  }
  
 
  delay(100);
}
