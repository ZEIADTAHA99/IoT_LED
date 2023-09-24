
#include <FirebaseESP32.h>
#include  <WiFi.h>
#include "Arduino.h"


#define WIFI_SSID "Ziad" // Change the name of your WIFI
#define WIFI_PASSWORD "Zea200299@" // Change the password of your WIFI
#define FIREBASE_Authorization_key "9cjBzxlXCWQSGHbtjRsO2oexGeHd01oOnibd4pAX"
#define FIREBASE_HOST "iot-led-d6c0a-default-rtdb.firebaseio.com"

WiFiClient  client;
FirebaseData firebaseData;
FirebaseData ledData;
FirebaseJson json;


#define led   2 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  Firebase.begin(FIREBASE_HOST, FIREBASE_Authorization_key);
  Firebase.reconnectWiFi(true);


  pinMode(led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

    if (Firebase.getString(ledData, "/led/led"))
    {
        Serial.println(ledData.stringData());
        Serial.println("hii");
         
        String ledoutput = ledData.stringData();
    
        if (ledoutput.substring(1, 2) == "1") 
        {
           digitalWrite(led, HIGH);
           Serial.println("yes");
        }
      else if (ledoutput.substring(1, 2) == "0")
      {
          digitalWrite(led, LOW);
          Serial.println("no");
      }
     
       else
       {
           digitalWrite(led, HIGH);
           delay(1000);
           digitalWrite(led, LOW);
           delay(1000);
        
        }
        

     }
 
 


 
}
