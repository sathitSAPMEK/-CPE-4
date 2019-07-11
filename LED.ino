int LED = 16; //ประกาศตัวเเปร
void setup() {
  pinMode(LED, OUTPUT); //กำหนดให้ตัวเเปรชื่อLEDเป็นOUTPUT(เเสดงออก)
}

void loop() {
  digitalWrite(LED, HIGH); //กำหนดให้LEDเปิด 
  delay(1000);             //หน่วงเวลา1second          
  digitalWrite(LED, LOW);  //กำหนดให้LEDปิด 
  delay(1000);             //หน่วงเวลา1second          
}
