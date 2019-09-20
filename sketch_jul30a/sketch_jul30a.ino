#include <SoftwareSerial.h>
void setup()
{
   Serial.begin(9600); 
}
void loop()
{
//  Serial.write("111");
  if(Serial.available()) // if data is coming
  { 
     
     char a=(int)Serial.read();
     Serial.write(a);
   }
//  Serial.print("1");
//  delay(10000);
 }
