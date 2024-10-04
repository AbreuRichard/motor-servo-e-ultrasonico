#include <WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h> //*consultar a hora no servidor
#include <TimeLib.h>   //*formatar a hora

const int fusoHorario = -10800;
const unsigned long atualizaNTP = 60000; //*em milisegundos

void setup_wifi();
void hora_certa();
unsigned long timeStamp();
void setup_time();
void atualiza_time();