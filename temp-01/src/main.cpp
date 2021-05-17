// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
logger::Logger *logger_logger;
web_server_base::WebServerBase *web_server_base_webserverbase;
captive_portal::CaptivePortal *captive_portal_captiveportal;
wifi::WiFiComponent *wifi_wificomponent;
ota::OTAComponent *ota_otacomponent;
api::APIServer *api_apiserver;
using namespace sensor;
using namespace api;
sensor::Sensor *sensor_sensor;
sensor::Sensor *sensor_sensor_2;
#include "hp303b.h"
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void setup() {
  // ===== DO NOT EDIT ANYTHING BELOW THIS LINE =====
  // ========== AUTO GENERATED CODE BEGIN ===========
  // async_tcp:
  // esphome:
  //   name: temp-01
  //   platform: ESP8266
  //   board: d1_mini
  //   libraries:
  //   - wemos/LOLIN_HP303B_Library
  //   - SPI
  //   includes:
  //   - hp303b.h
  //   arduino_version: platformio/espressif8266@2.6.2
  //   build_path: temp-01
  //   platformio_options: {}
  //   esp8266_restore_from_flash: false
  //   board_flash_mode: dout
  //   name_add_mac_suffix: false
  App.pre_setup("temp-01", __DATE__ ", " __TIME__, false);
  // logger:
  //   id: logger_logger
  //   baud_rate: 115200
  //   tx_buffer_size: 512
  //   hardware_uart: UART0
  //   level: DEBUG
  //   logs: {}
  //   esp8266_store_log_strings_in_flash: true
  logger_logger = new logger::Logger(115200, 512, logger::UART_SELECTION_UART0);
  logger_logger->pre_setup();
  App.register_component(logger_logger);
  // web_server_base:
  //   id: web_server_base_webserverbase
  web_server_base_webserverbase = new web_server_base::WebServerBase();
  App.register_component(web_server_base_webserverbase);
  // captive_portal:
  //   id: captive_portal_captiveportal
  //   web_server_base_id: web_server_base_webserverbase
  captive_portal_captiveportal = new captive_portal::CaptivePortal(web_server_base_webserverbase);
  App.register_component(captive_portal_captiveportal);
  // wifi:
  //   ap:
  //     ssid: Temp-01 Fallback Hotspot
  //     password: ZRExiYSHR4C8
  //     id: wifi_wifiap
  //     ap_timeout: 1min
  //   id: wifi_wificomponent
  //   domain: .local
  //   reboot_timeout: 15min
  //   power_save_mode: NONE
  //   fast_connect: false
  //   output_power: 20.0
  //   networks:
  //   - ssid: Croissant
  //     password: 0093699323
  //     id: wifi_wifiap_2
  //     priority: 0.0
  //   use_address: temp-01.local
  wifi_wificomponent = new wifi::WiFiComponent();
  wifi_wificomponent->set_use_address("temp-01.local");
  wifi::WiFiAP wifi_wifiap_2 = wifi::WiFiAP();
  wifi_wifiap_2.set_ssid("Croissant");
  wifi_wifiap_2.set_password("0093699323");
  wifi_wifiap_2.set_priority(0.0f);
  wifi_wificomponent->add_sta(wifi_wifiap_2);
  wifi::WiFiAP wifi_wifiap = wifi::WiFiAP();
  wifi_wifiap.set_ssid("Temp-01 Fallback Hotspot");
  wifi_wifiap.set_password("ZRExiYSHR4C8");
  wifi_wificomponent->set_ap(wifi_wifiap);
  wifi_wificomponent->set_ap_timeout(60000);
  wifi_wificomponent->set_reboot_timeout(900000);
  wifi_wificomponent->set_power_save_mode(wifi::WIFI_POWER_SAVE_NONE);
  wifi_wificomponent->set_fast_connect(false);
  wifi_wificomponent->set_output_power(20.0f);
  App.register_component(wifi_wificomponent);
  // ota:
  //   id: ota_otacomponent
  //   safe_mode: true
  //   port: 8266
  //   password: ''
  //   reboot_timeout: 5min
  //   num_attempts: 10
  ota_otacomponent = new ota::OTAComponent();
  ota_otacomponent->set_port(8266);
  ota_otacomponent->set_auth_password("");
  App.register_component(ota_otacomponent);
  if (ota_otacomponent->should_enter_safe_mode(10, 300000)) return;
  // api:
  //   id: api_apiserver
  //   port: 6053
  //   password: ''
  //   reboot_timeout: 15min
  api_apiserver = new api::APIServer();
  App.register_component(api_apiserver);
  // sensor:
  api_apiserver->set_port(6053);
  api_apiserver->set_password("");
  api_apiserver->set_reboot_timeout(900000);
  // sensor.custom:
  //   platform: custom
  //   lambda: !lambda |-
  //     auto hp_sensor = new HP303BSensor();
  //     App.register_component(hp_sensor);
  //     return {hp_sensor->pressure_sensor, hp_sensor->temperature_sensor};
  //   sensors:
  //   - name: Barometric Pressure
  //     icon: mdi:gauge
  //     unit_of_measurement: hPa
  //     accuracy_decimals: 1
  //     id: sensor_sensor
  //     force_update: false
  //   - name: Temperature
  //     icon: mdi:gauge
  //     unit_of_measurement: °C
  //     accuracy_decimals: 1
  //     id: sensor_sensor_2
  //     force_update: false
  //   id: custom_customsensorconstructor
  custom::CustomSensorConstructor custom_customsensorconstructor = custom::CustomSensorConstructor([=]() -> std::vector<sensor::Sensor *> {
      #line 33 "temp-01.yaml"
      auto hp_sensor = new HP303BSensor();
      App.register_component(hp_sensor);
      return {hp_sensor->pressure_sensor, hp_sensor->temperature_sensor};
  });
  sensor_sensor = custom_customsensorconstructor.get_sensor(0);
  App.register_sensor(sensor_sensor);
  sensor_sensor->set_name("Barometric Pressure");
  sensor_sensor->set_unit_of_measurement("hPa");
  sensor_sensor->set_icon("mdi:gauge");
  sensor_sensor->set_accuracy_decimals(1);
  sensor_sensor->set_force_update(false);
  sensor_sensor_2 = custom_customsensorconstructor.get_sensor(1);
  App.register_sensor(sensor_sensor_2);
  sensor_sensor_2->set_name("Temperature");
  sensor_sensor_2->set_unit_of_measurement("\302\260C");
  sensor_sensor_2->set_icon("mdi:gauge");
  sensor_sensor_2->set_accuracy_decimals(1);
  sensor_sensor_2->set_force_update(false);
  // =========== AUTO GENERATED CODE END ============
  // ========= YOU CAN EDIT AFTER THIS LINE =========
  App.setup();
}

void loop() {
  App.loop();
}
