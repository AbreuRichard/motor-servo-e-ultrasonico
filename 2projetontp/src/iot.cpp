#include <Arduino.h>
#include <iot.h>
#include <senha.h>	

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", fusoHorario, atualizaNTP);

void setup_wifi()
{
 WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED);
  {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println();
  Serial.println("Conectado ao WiFi com successo no IP:");
  Serial.println(WiFi.localIP());
}

 void hora_certa()
 {
  unsigned long epochTime = timeClient.getEpochTime();
  //Serial.println(epochTime);
  
  setTime(epochTime);
  //* hour();, minute();, second();, day();, month();, year(); weekday(); *//

  Serial.printf("%02d:%02d:%02d %02d/%02d/%04d\n", hour(), minute(), second(), day(), month(), year());
}
unsigned long timeStamp()
{
 return timeClient.getEpochTime();
}
void setup_time()
{
  timeClient.begin();
}
void atualiza_time()
{
  timeClient.update();
}