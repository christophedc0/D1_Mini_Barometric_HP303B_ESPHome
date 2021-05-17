# D1_Mini_Barometric_HP303B_ESPHome
D1 Mini with HP303B shield for Home-Assistant with ESPHome

## Equipment
* [D1 Mini](https://www.wemos.cc/en/latest/d1/d1_mini.html)
* [Barometric Pressure Shield](https://www.wemos.cc/en/latest/d1_mini_shield/barometric_pressure.html)

Soldering skills to connect the shield to the microcontroller.

## Libraries & software used
* [Official Wemos repository](https://github.com/wemos/LOLIN_HP303B_Library)
* [Dmptrluke repository](https://github.com/dmptrluke/esphome_hp303b)
* [ESPHome](https://esphome.io)
* [Home-Assistant](https://www.home-assistant.io)


## Usage
1. I made a basic configuration to connect to the wireless network, with a local ESPHome instance over USB connection.
```bash
INFO Connecting to temp-01.local:6053 (X.X.X.X)
INFO Successfully connected to temp-01.local
[20:23:46][I][app:105]: ESPHome version 1.17.2 compiled on May 16 2021, 20:23:12
[20:23:46][C][wifi:443]: WiFi:
[20:23:46][C][wifi:303]:   SSID: 'XXXXXX'[redacted]
[20:23:46][C][wifi:304]:   IP Address: XXXXX
[20:23:46][C][wifi:306]:   BSSID: X:X:X:X:X:X[redacted]
[20:23:46][C][wifi:307]:   Hostname: 'temp-01'
[20:23:46][C][wifi:311]:   Signal strength: -53 dB ▂▄▆█
[20:23:46][C][wifi:315]:   Channel: 1
[20:23:46][C][wifi:316]:   Subnet: 255.255.255.0
[20:23:46][C][wifi:317]:   Gateway: X.X.X.X
[20:23:46][C][wifi:318]:   DNS1: X.X.X.X
[20:23:46][C][wifi:319]:   DNS2: (IP unset)
[20:23:46][C][logger:185]: Logger:
[20:23:46][C][logger:186]:   Level: DEBUG
[20:23:46][C][logger:187]:   Log Baud Rate: 115200
[20:23:46][C][logger:188]:   Hardware UART: UART0
[20:23:46][C][hp303b:025]: HP303B:
[20:23:46][C][hp303b:026]:   Custom Sensor Active
[20:23:46][C][captive_portal:169]: Captive Portal:
[20:23:46][C][ota:029]: Over-The-Air Updates:
[20:23:46][C][ota:030]:   Address: temp-01.local:8266
[20:23:46][C][api:095]: API Server:
[20:23:46][C][api:096]:   Address: temp-01.local:6053
```
3. I then uploaded the src directory and hp303b.h + temp-01.yaml to the ESPHome docker instance.
4. I pushed the new configuration over OTA to verify this works.
5. With the ESPHome integration activated in Home-Assistant, the D1 Mini is immediately detected with the pressure & temperature values (2 entities for each device).
6. you can adapt the sensor names in the temp-01.yaml file.


