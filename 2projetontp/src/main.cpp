#include <Arduino.h>
#include <iot.h>

void setup()
{
  Serial.begin(115200);
  setup_wifi();
  setup_time();
}

void loop()
{
  atualiza_time();
  hora_certa();
}