#ifdef ESP32 
 #include <WiFi.h> 
#else 
 #include <ESP8266WiFi.h> 
#endif 
#include <WiFiClientSecure.h> 
#include <UniversalTelegramBot.h> 
#include <ArduinoJson.h> 
// Replace with your network credentials 
const char* ssid = "project";
const char* password = "12345678";
int ir=D7;
// Initialize Telegram BOT 
#define BOTtoken "6117143050:AAFa6eWsBGVxHx5Nu3o-M2y9Go4mU_35-j8" // 
your Bot Token (Get from Botfather) 
String strs[8]={"0","0","0","0","0","0","0","0"};
int StringCount = 0;
// Use @myidbot to find out the chat ID of an individual or a group 
// Also note that you need to click "start" on a bot before it can 
// message you 
 
#define CHAT_ID "1199036963" 
#ifdef ESP8266 
 X509List cert(TELEGRAM_CERTIFICATE_ROOT);
#endif 
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);
// Checks for new messages every 1 second. 
int botRequestDelay = 1000;
unsigned long lastTimeBotRan;
const int ledPin = 2;
bool ledState = LOW;