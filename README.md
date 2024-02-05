# ESPWiFiConfig
a wrapper library over ESPAsyncWiFiManager to provide the user with a single function call to configure the wifi credentials through web Access Point

# Usage
simple
```c++
#include <ESPWiFiConfig.h>
void setup() {
    wifi_setup();
}
void loop() {
  delay(10000);
}
```
secure
```c++
#include <ESPWiFiConfig.h>
#include <ESPRandom.h>

void setup() {
    Serial.begin(115200);
    String Password = String(ESPRandom::get());
    Serial.println("AP= 'ESP-Test' Password='"+Password+"'");
    wifi_setup_secret("ESP-Test",Password);
}
void loop() {
  delay(10000);
}

```

for more details see the examples directory
