#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <SocketIOClient.h>
#include <ArduinoJson.h> 
//#include <SerialCommand.h>  
//include thu vi?n d? ki?m tra free RAM trên con esp8266
//extern "C" {
//  #include "user_interface.h"
//}
 
 
const byte RX = RX;
const byte TX = TX;
 
//SoftwareSerial mySerial = SoftwareSerial(RX, TX, false, 256); 
 
SocketIOClient client;
const char* ssid = "datphanhuu";        //Tên m?ng Wifi mà Socket server c?a b?n dang k?t n?i
const char* password = "huudat99"; //Pass m?ng wifi ahihi, anh em rãnh thì share pass cho mình v?i.
 
char host[] = "ledcube2019.herokuapp.com";  //Ð?a ch? IP d?ch v hãy thay d?i nó theo d?a ch? IP Socket server c?a b?n.
int port = 80;                  //C?ng d?ch v? socket server do chúng ta t?o!
 
//t? khóa extern: dùng d? #include các bi?n toàn c?c ? m?t s? thu vi?n khác. Trong thu vi?n SocketIOClient có hai bi?n toàn c?c
// mà chúng ta c?n quan tâm dó là
// RID: Tên hàm (tên s? ki?n
// Rfull: Danh sách bi?n (du?c dóng gói l?i là chu?i JSON)
extern String RID;
extern String Rfull;
 
 
void setup()
{d
    //B?t baudrate ? m?c 57600 d? giao ti?p v?i máy tính qua Serial
    Serial.begin(9600);
     WiFi.begin(ssid, password);
    //mySerial.begin(9600); //B?t software serial d? giao ti?p v?i Arduino, nh? d? baudrate trùng v?i software serial trên m?ch arduino
    delay(10);
//    if(WiFi.status() != WL_CONNECTED) { 
//        delay(500);}
     client.connect(host, port);
    if (!client.connect(host, port)) {
        client.connect(host, port);
    }
    
    //Vi?c d?u tiên c?n làm là k?t n?i vào m?ng Wifi
//    Serial.print("Ket noi vao mang ");************
//    Serial.println(ssid);
 
    //K?t n?i vào m?ng Wifi
 
//    Serial.println();
//    Serial.println(F("Da ket noi WiFi"));
//    Serial.println(F("Di chi IP cua ESP8266 (Socket Client ESP8266): "));
//    Serial.println(WiFi.localIP());

//    client.connect(host, port);
//    if (!client.connect(host, port)) {
////        Serial.println(F("Ket noi den socket server that bai!"));
//        return;
//    }
//    else{
////      Serial.print("ÐÃ K?T N?I V?I SERVER!!!");
//      }
      

}
void loop()
{
  //Khi b?t du?c b?t k? s? ki?n nào thì chúng ta có hai tham s?:
    //  +RID: Tên s? ki?n
    //  +RFull: Danh sách tham s? du?c nén thành chu?i JSON!
    if(!client.connected()) {
      
      client.reconnect(host, port);
      delay(1);
    }
    if (client.monitor()) {
        //in ra serial cho Arduino
      StaticJsonDocument<200> doc;
      DeserializationError err = deserializeJson(doc, Rfull);
      int dataMode = (int)doc["AR"];
      if(!err)
       {
          Serial.write(dataMode+48);
          Rfull = {""};
       }
//        Serial.print(dataMode);
        
    } 
    //K?t n?i l?i!
//    if(WiFi.status() != WL_CONNECTED) { 
//        delay(500);}
//    if (!client.connected()) {
//      client.connect(host, port);
//      delay(1000);
//    }
}
