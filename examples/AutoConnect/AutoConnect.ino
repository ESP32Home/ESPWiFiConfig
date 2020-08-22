//a single file include without header pollutions, all dependencies will be managed by the library
#include <ESPWiFiConfig.h>

void setup() {
    //important to see the log of the wifi manager in case of issues
    Serial.begin(115200);

    //single line of code that covers the wifi credentials config with autoconnect
    //first time a web server configuration access point will be provided
    //for more advanced use cases please check the dependency library "ESPAsyncWiFiManager"
    wifi_setup();

    //enjoy connected ESP at this point

}

void loop() {
  delay(10000);
  //cyclic execution code goes here
}
