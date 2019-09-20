#include <SoftwareSerial.h>

#define stcp  3//5// 
#define shcp  4//16//
#define ds 2//4// 

void setup()
{
   Serial.begin(9600); 
   pinMode(shcp, OUTPUT);
   pinMode(stcp, OUTPUT);
   pinMode(ds, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(7, OUTPUT);
   pinMode(8, OUTPUT);
   pinMode(9, OUTPUT);
   pinMode(10, OUTPUT);
   pinMode(11, OUTPUT);
   pinMode(12, OUTPUT);
}
void loop()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  
  if(Serial.available()) // if data is coming
  { 
//     Serial.write(Serial.read());
       if(Serial.read()=='a')
       {
        
        digitalWrite(ds,1);
        digitalWrite(shcp,1);
        digitalWrite(shcp,0);
        digitalWrite(stcp,1);
        digitalWrite(stcp,0);
  
//        delay(2000);
//        digitalWrite(ds,0);
//        digitalWrite(shcp,1);
//        digitalWrite(shcp,0);
//        digitalWrite(stcp,1);
//        digitalWrite(stcp,0);
//  
//  delay(2000);
        
//        Serial.print("hello");
       }
   }
//  Serial.print('a');
//  digitalWrite(12,LOW);
//  delay(1000);
 }
