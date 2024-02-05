//a single file include without header pollutions, all dependencies will be managed by the library
#include <ESPWiFiConfig.h>
//This file is optional in case a random password is needed
//required to add a dependency mulmer89/ESPRandom@^1.5.0
#include <ESPRandom.h>

void setup() {
    //important to see the log of the wifi manager in case of issues
    Serial.begin(115200);

    //for high security it is possible to generate a random passowrd and print it to the user or use a display to show it
    String Password = String(ESPRandom::get());
    Serial.println("AP= 'ESP-Test' Password='"+Password+"'");
    //single line of code that covers the wifi credentials config with autoconnect
    //first time a web server configuration access point will be provided
    //for more advanced use cases please check the dependency library "ESPAsyncWiFiManager"
    wifi_setup_secret("ESP-Test",Password);

    //enjoy connected ESP at this point

}

void loop() {
  delay(10000);
  //cyclic execution code goes here
}
