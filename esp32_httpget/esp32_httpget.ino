/*
  Rui Santos
  Complete project details at Complete project details at https://RandomNerdTutorials.com/esp32-http-get-post-arduino/

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/


#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>


const char* ssid = "SSID";
const char* password = "SSID_Password";

//Your Domain name with URL path or IP address with path
//String serverName =    "http://192.168.1.39/esp32_motor/temp_test.php";
String serverName =    "https://ephyzics.com/temp_test.php";
unsigned long lastTime = 0;
unsigned long timerDelay = 5000;

float temperature =31.1;

void setup() 
{

  Serial.begin(115200); 
  //Serial.setDebugOutput(true);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");

  while(WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
 
  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
}

void loop() 
{
  //Send an HTTP POST request every 10 minutes
  if ((millis() - lastTime) > timerDelay) 
  {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED)
    {
      HTTPClient http;
      String httpRequestData = "?temperature=" + String(temperature) +"";

      String serverPath = serverName + httpRequestData;
       Serial.println(serverPath);
      // Your Domain name with URL path or IP address with path
      http.begin(serverPath.c_str());
      
      // Send HTTP GET request
      int httpResponseCode = http.GET();
      
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
        Serial.println(http.errorToString(httpResponseCode).c_str());
      }
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}
