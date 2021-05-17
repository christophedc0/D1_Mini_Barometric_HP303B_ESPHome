#include "esphome.h"
#include "LOLIN_HP303B.h"

static const char *TAGhp = "hp303b";

using namespace esphome;

class HP303BSensor : public PollingComponent, public Sensor {
 public:
  LOLIN_HP303B hp;
  Sensor *pressure_sensor = new Sensor();
  Sensor *temperature_sensor = new Sensor();

  int32_t pressure;
  int32_t temperature;

  HP303BSensor() : PollingComponent(100000) { }

  void setup() override {
    ESP_LOGCONFIG(TAGhp, "Setting up HP303B...");
    hp.begin();
  }

  void dump_config() override {
    ESP_LOGCONFIG(TAGhp, "HP303B:");
    ESP_LOGCONFIG(TAGhp, "  Custom Sensor Active");
  }

  void update() override {
    hp.measurePressureOnce(pressure); // library returns value in in Pa, which equals 1/100 hPa
    float hPa = pressure / 100.0;
    pressure_sensor->publish_state(hPa);

    ESP_LOGD(TAGhp, "Got pressure=%.1f hPa", hPa);
//    publish_state(hPa); 
    Serial.print("Pressure is: ");
    Serial.println(hPa);  

    hp.measureTempOnce(temperature); // library returns value in in Pa, which equals 1/100 hPa
    float C = temperature;
    temperature_sensor->publish_state(C);

    ESP_LOGD(TAGhp, "Got temperature=%.1f C", C);
//    publish_state(C);
    Serial.print("Temperature is: ");
    Serial.println(C);
  }
};
