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
// Handle what happens when you receive new messages 
void handleNewMessages(int numNewMessages) { 
 Serial.println("handleNewMessages");
 Serial.println(String(numNewMessages));
 for (int i=0; i<numNewMessages; i++) {
 // Chat id of the requester 
 String chat_id = String(bot.messages[i].chat_id);
 if (chat_id != CHAT_ID){ 
 bot.sendMessage(chat_id, "Unauthorized user", "");
 continue;
 } 
 
 // Print the received message 
 String text = bot.messages[i].text;
 Serial.println(text);
 String from_name = bot.messages[i].from_name;
 if (text == "/start") { 
 String welcome = "Welcome, " + from_name + ".\n";
 welcome += "Use the following commands to control your 
outputs.\n\n";
 welcome += "/led_on to turn GPIO ON \n";
 welcome += "/led_off to turn GPIO OFF \n";
 welcome += "/state to request current GPIO state \n";
 bot.sendMessage(chat_id, welcome, "");
 } 
 if (text == "/led_on") { 
 bot.sendMessage(chat_id, "LED state set to ON", "");
 ledState = HIGH;
 digitalWrite(ledPin, ledState);
 } 
 
 if (text == "/led_off") { 
 bot.sendMessage(chat_id, "LED state set to OFF", "");
 ledState = LOW;
 digitalWrite(ledPin, ledState);
 } 
 
 if (text == "/state") { 
 
 if (digitalRead(ledPin)){ 
 bot.sendMessage(chat_id, "LED is ON", "");
 } 
 else{ 
 bot.sendMessage(chat_id, "LED is OFF", "");
 } 
 } 
 } 
} 
void setup() { 
 Serial.begin(9600);
pinMode(ir,INPUT);
 #ifdef ESP8266 
 configTime(0, 0, "pool.ntp.org"); // get UTC time via NTP
 client.setTrustAnchors(&cert); // Add root certificate for 
api.telegram.org 
 #endif 
 pinMode(ledPin, OUTPUT);
 digitalWrite(ledPin, ledState);
 
 // Connect to Wi-Fi 
 WiFi.mode(WIFI_STA);
 WiFi.begin(ssid, password);
 #ifdef ESP32 
 client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root 
certificate for api.telegram.org 
 #endif 
 while (WiFi.status() != WL_CONNECTED) { 
 delay(1000);
 Serial.println("Connecting to WiFi..");
 } 
 // Print ESP32 Local IP Address 
 Serial.println(WiFi.localIP());
 delay(1000);
 bot.sendMessage(CHAT_ID, "BOT STARTED", "");
} 
void loop() { 
int ival=digitalRead(ir);
Serial.println(ival);
 if(ival==1) 
 { 
 bot.sendMessage(CHAT_ID, "FUEL THEFT ALERT AT", "");
 
bot.sendMessage(CHAT_ID,"https://www.google.com/maps/search/?api=1&quer
y=" + String(16.4963)+ "," + String(80.5007),"");
 } 
if (Serial.available()) 
{ 
 String rcv = Serial.readStringUntil('\n');
 StringCount=0;
 while (rcv.length() > 0) 
 { 
 int index = rcv.indexOf('^');
 if (index == -1) // No space found 
 { 
 
 strs[StringCount++] = rcv;
 break;
 } 
 else 
 { 
 strs[StringCount++] = rcv.substring(0, index);
 rcv = rcv.substring(index+1);
 } 
 Serial.println("Sending..");
 bot.sendMessage(CHAT_ID, strs[0], "");
 } 
 
 
 } 
 
 if (millis() > lastTimeBotRan + botRequestDelay) { 
 int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
 while(numNewMessages) { 
 Serial.println("got response");
 handleNewMessages(numNewMessages);
 numNewMessages = bot.getUpdates(bot.last_message_received + 1);
 } 
 lastTimeBotRan = millis();
 } 
}
