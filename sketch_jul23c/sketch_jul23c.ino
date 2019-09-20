
#define shcp 4//16
#define stcp 3//5
#define ds 2//4
 
void setup() {
  pinMode(stcp, OUTPUT);
  pinMode(shcp, OUTPUT);
  pinMode(ds, OUTPUT);
  pinMode(0, OUTPUT);
}
 
void loop() {
  digitalWrite(0,HIGH);
  for (int i = 0; i < 256; i++)
  {
    digitalWrite(stcp, LOW);
    shiftOut(ds, shcp, MSBFIRST, i);
    digitalWrite(stcp, HIGH);
    delay(500);
  }
}  
