int latchpin = 8;
int clockpin = 12;
int datapin = 11;
byte data;
void setup() {
  pinMode(latchpin , OUTPUT);
  pinMode(clockpin, OUTPUT);
  pinMode(datapin, OUTPUT);
  }
void loop() {
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, 0b00000001);
  digitalWrite(latchpin, HIGH);
  delay(2000);
  }
