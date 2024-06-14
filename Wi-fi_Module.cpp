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