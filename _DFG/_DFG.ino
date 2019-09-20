
#define stcp 5// 3 
#define shcp 16// 4
#define ds 4// 2

 
void setup() {
   pinMode(shcp, OUTPUT);
   pinMode(stcp, OUTPUT);
   pinMode(ds, OUTPUT);
   pinMode(0, OUTPUT);
   pinMode(2, OUTPUT);
   pinMode(14, OUTPUT);
   pinMode(12, OUTPUT);
   pinMode(13, OUTPUT);
   pinMode(15, OUTPUT);
   pinMode(1, OUTPUT);
   pinMode(3, OUTPUT);
   
}
 
void loop() { 
  digitalWrite(0,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(14,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  digitalWrite(15,HIGH);
  digitalWrite(1,HIGH);
  digitalWrite(3,HIGH);
  
  
  digitalWrite(ds,1);
  digitalWrite(shcp,1);
  digitalWrite(shcp,0);
  digitalWrite(stcp,1);
  digitalWrite(stcp,0);
  
  delay(2000);
  digitalWrite(ds,0);
  digitalWrite(shcp,1);
  digitalWrite(shcp,0);
  digitalWrite(stcp,1);
  digitalWrite(stcp,0);
  
  delay(2000);
   
}
