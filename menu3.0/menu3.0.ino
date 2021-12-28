#include <M5Core2.h>
#include <Fonts/EVA_20px.h>
#include <stdio.h>
#include <stdlib.h>
#include <Arduino.h>
#include <WiFiMulti.h>
#include "CUF_24px.h"
#define USE_SERIAL Serial
const char *ssid = "ESP32test";
const char *password = "123456789";
const char *serverNameobjectTem = "http://192.168.4.1/objectTem";
String objectTem;
unsigned long previousMillis = 0;
const long interval = 5000;
#include <Wire.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "BluetoothSerial.h"
WiFiMulti wifiMulti;
int c,len;
uint8_t buff[64*1024] = { 0 };
BluetoothSerial SerialBT;
String name = "ESP32test";
bool connected;
int a;
String httpGETRequest(const char *serverName);
void initback()        // initialize background
{
  for(int i=0;i<=320;i++)
  {   
      int rx = random(320);
      int ry = random(60);
      for(int j=0;j<=240;j++)
      {
        if(j<20&&j%3==0)
        { 
          M5.Lcd.drawPixel(i,j,BLUE); 
          }
          else if(j<40)
          {
            M5.Lcd.drawPixel(rx,ry,BLUE);
          }
        else if(j>200)
        { M5.Lcd.drawPixel(i,j,GREEN);} 
      }
     m5.Lcd.setCursor(30,120);
     M5.Lcd.setTextSize(2);
     M5.Lcd.print("Remote  ⛨       ✙ rescue"); 
     m5.Lcd.setCursor(80,205);
     M5.Lcd.setTextSize(1);
     M5.Lcd.print("  ⛰       ⛳ "); 
   
  }

  
}

  void wemenu()     //welcome menu
  {
    M5.Lcd.clear();
    M5.Lcd.setTextColor(GREEN,BLACK);
    m5.Lcd.setCursor(50,110);
    m5.Lcd.setTextSize(1);
    m5.Lcd.print("Welcome To Menu!");
    delay(800);
  }


  
void menu()        //menu
  {
    int i=1,j=1,k=1,o=1,p=1;
    wemenu();
    M5.Lcd.clear();
    M5.Lcd.fillScreen(WHITE);
    for(i=1;i<= 120;i++)
    { 
      M5.Lcd.fillRect(20,20, i, j, BLACK);
      if(i%2==0)
      {
        j++;
      }
//      delay(3);
      if(i==120)
      {
        m5.Lcd.setCursor(42,62);
        m5.Lcd.setTextSize(1);
        m5.Lcd.print(" Car");   
      }  
    }

       for(i=1;i<= 120;i++)
    { 
      M5.Lcd.fillRect(180,20, i, k, BLACK);
      if(i%2==0)
      {
        k++;
      }
//      delay(3);
      if(i==120)
      {
        m5.Lcd.setCursor(202,62);
        m5.Lcd.setTextSize(1);
        m5.Lcd.print(" siren");//a burglar alarm
      }  
      }

   for(i=1;i<= 120;i++)
    { 
      M5.Lcd.fillRect(20,160, i, p, BLACK);
      if(i%2==0)
      {
        p++;
      }
//      delay(3);
      if(i==120)
      {
        m5.Lcd.setCursor(42,202);
        m5.Lcd.setTextSize(1);
        m5.Lcd.print("spolight");
      }  
    }   
    
    for(i=1;i<= 120;i++)
    { 
      M5.Lcd.fillRect(180,160, i, o, BLACK);
      if(i%2==0)
      {
        o++;
      }
      delay(3);
      if(i==120)
      {
        m5.Lcd.setCursor(202,202);
        m5.Lcd.setTextSize(1);
        m5.Lcd.print("carema");
      }  
      }

       M5.Lcd.fillEllipse(160, 120 , 50 , 75, random(0xFFFF));
       m5.Lcd.setCursor(142,140);
       M5.Lcd.setTextSize(2);
       M5.Lcd.print("⛨");
       while(1) 
     {   part1();
           part2();
         part3();
          part4();
     }
  }

  void reset() 
  {
      M5.Lcd.fillScreen(BLACK);  
  }
void vbutton()
  {
  M5.Lcd.setTextColor(GREEN,BLACK);
  M5.Lcd.setTextSize(2);
  m5.Lcd.setCursor(150,60);
  M5.Lcd.drawCircle(165,40,30,RED);
  M5.Lcd.print("☝");
  m5.Lcd.setCursor(50,170);
  M5.Lcd.drawCircle(70,155,30,RED);
  M5.Lcd.print("☜"); 
  m5.Lcd.setCursor(210,170);
  M5.Lcd.drawCircle(230,155,30,RED);
  M5.Lcd.print("☞"); 
  }
void vbutton2()
{
  M5.Lcd.setTextSize(3);
  m5.Lcd.setCursor(120,130);
  M5.Lcd.drawCircle(150,108,50,RED);
  M5.Lcd.print("⚠");
  }
    void vbutton3()
 {
  M5.Lcd.setTextSize(3);
  m5.Lcd.setCursor(120,130);
  M5.Lcd.fillCircle(147,118,50, random(0xFFFF));
  M5.Lcd.print("☀");
 }
 void part1()
  {
     TouchPoint_t pos= M5.Touch.getPressPoint(); 
    if (pos.x>20&&pos.x<120&&pos.y>20&&pos.y<80)
    {
       reset();
      vbutton();
      while(1)
      {
        TouchPoint_t pos= M5.Touch.getPressPoint();
     if (pos.x>135&&pos.x<195&&pos.y<70&&pos.y>10)
      {
            SerialBT.print("T");
              Serial.print("T");                 
      }
 if (pos.x>40&&pos.x<100&&pos.y<185&&pos.y>125)
      {
            SerialBT.print("L");
              Serial.print("L");                    
      }
   if (pos.x>200&&pos.x<260&&pos.y<185&&pos.y>125)
      {
            SerialBT.print("R");
              Serial.print("R");                   
      }
    if (pos.x<100&&pos.y>240)
        {
            menu();
            Serial.print('m');
          }
        }
    }
  }
 void part2()
  {
     TouchPoint_t pos= M5.Touch.getPressPoint(); 
    if (pos.x>180&&pos.x<360&&pos.y>20&&pos.y<80)
    {
         reset();
      vbutton2();
      while(1)
      {
     
      TouchPoint_t pos= M5.Touch.getPressPoint();
     if (pos.x>100&&pos.x<200&&pos.y<160&&pos.y>50)
      {
            SerialBT.print("P");
              Serial.print("P");
                    delay(300);
      }
     if (pos.x<100&&pos.y>240)
        {
            menu();
            Serial.print('m');
          }
        }
    }
  }
void part3()
  {
     TouchPoint_t pos= M5.Touch.getPressPoint(); 
    if (pos.x>20&&pos.x<120&&pos.y>160&&pos.y<240)
    {
         reset();
      vbutton3();
      while(1)
      {
            m5.update();
      if (M5.BtnB.wasReleased())
    {
      Serial.print('o');


      
    }
     else if (M5.BtnA.wasReleased())
    {
      menu();
      Serial.print('m');
    }
        }
    }
  }
 void part4()
  {
      Serial.println("cam");
     TouchPoint_t pos= M5.Touch.getPressPoint(); 
    if (pos.x>180&&pos.x<360&&pos.y>160&&pos.y<240)
    {
         reset();
      while(1)
      {
            TouchPoint_t pos= M5.Touch.getPressPoint(); 
   
             buff[64*1024] = { 0 };
              if((wifiMulti.run() == WL_CONNECTED)) {
          
                  HTTPClient http;
          
                  USE_SERIAL.print("[HTTP] begin...\n");
          
                  // configure server and url
                  http.begin("http://192.168.4.1/saved-photo");
                  //http.begin("192.168.1.12", 80, "/test.html");
          
                  USE_SERIAL.print("[HTTP] GET...\n");
                  // start connection and send HTTP header
                  int httpCode = http.GET();
                  if(httpCode > 0) {
                      // HTTP header has been send and Server response header has been handled
                      USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);
          
                      // file found at server
                      if(httpCode == HTTP_CODE_OK) {
          
                          // get length of document (is -1 when Server sends no Content-Length header)
                          len = http.getSize();
                          Serial.println(len);
                          // create buffer for read
          //                uint8_t buff[128] = { 0 };
          
                          // get tcp stream
                          WiFiClient * stream = http.getStreamPtr();
          
                          // read all data from server
                          while(http.connected() && (len > 0 || len == -1)) {
                              // get available data size
                              size_t size = stream->available();
          
                              if(size) {
                                  // read up to 128 byte
                                   c = stream->readBytes(buff, ((size > sizeof(buff)) ? sizeof(buff) : size));
          
                                  // write it to Serial
                                  
          //                       USE_SERIAL.write(buff, c);
                                  M5.Lcd.drawJpg(buff,len,80,60);
          //                          USE_SERIAL.print(buff, c);
                                  if(len > 0) {
                                      len -= c;
                                  }
                              }
                              delay(1);
                          }
                           M5.Lcd.drawJpg(buff,len,80,60);
                          USE_SERIAL.println();
                          USE_SERIAL.print("[HTTP] connection closed or file end.\n");
          
                      }
                  } else {
                      USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
                  }
           M5.Lcd.drawJpg(buff,len,80,60);
                  http.end();
              }
           M5.Lcd.drawJpg(buff,len,80,60);
            delay(1000);

 
  if (pos.x<100&&pos.y>240)
        {
            menu();
            Serial.print('m');
          }

        }
    }
  }  
void setup() {
   Serial.begin(115200);

  M5.begin();
        M5.lcd.setBrightness(255);
// M5.Lcd.fillScreen(WHITE);
    USE_SERIAL.println();
    USE_SERIAL.println();
    USE_SERIAL.println();
  M5.Lcd.setFreeFont(&unicode_24px);//设置要使用的GFX字体（#include "CUF_24px.h"）
  M5.Lcd.setTextDatum(TC_DATUM);//设置文本对齐方式为居中向上对齐
  M5.Lcd.setTextColor(GREEN,WHITE); 
  M5.Lcd.fillScreen(WHITE);
      for(uint8_t t = 4; t > 0; t--) {
        USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
        USE_SERIAL.flush();
        delay(1);
    }

    wifiMulti.addAP("M5cam", "123456789");


  initback();
//  SerialBT.begin("m5stacktest", true);
//        Serial.println("The device started in master mode, make sure remote BT device is on!");
//        connected = SerialBT.connect(name);
//        if (connected)
//        {
//            Serial.println("Connected Succesfully!");
//        }
//        else
//        {
//            while (!SerialBT.connected(10000))
//            {
//                Serial.println("Failed to connect. Make sure remote device is available and in range, then restart app.");
//            }
//        }
//        //   disconnect() may take upto 10 secs max
//        if (SerialBT.disconnect())
//        {
//            Serial.println("Disconnected Succesfully!");
//        }
//        // this would reconnect to the name(will use address, if resolved) or address used with connect(name/address).
//        SerialBT.connect();
}

void loop() {
      m5.update();
      if (M5.BtnA.isPressed())
    {
      delay(300);
      m5.update();
      if(!M5.BtnA.isPressed())
      {
        menu();
      }

    }
}
