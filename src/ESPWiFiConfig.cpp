#include <Arduino.h>
#include <DNSServer.h>
#include <ESPAsyncWebServer.h>
#include <ESPAsyncWiFiManager.h>         //https://github.com/tzapu/WiFiManager


void configModeCallback(AsyncWiFiManager *myWiFiManager) {
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());
  //if you used auto generated SSID, print it
  Serial.println(myWiFiManager->getConfigPortalSSID());
}


void wifi_setup(){
  AsyncWebServer server(80);
  DNSServer dns;
  AsyncWiFiManager wifiManager(&server,&dns);

  wifiManager.setAPCallback(configModeCallback);

  if(!wifiManager.autoConnect()) {
    Serial.println("failed to connect and hit timeout");

    ESP.restart();
    delay(1000);
  }
  Serial.println("WiFi connected");

}
