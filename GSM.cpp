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