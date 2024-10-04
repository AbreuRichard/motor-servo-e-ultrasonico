#include <Arduino.h>
#include <WiFi.h> 
#include <PubSubClient.h>
#include <U8g2lib.h>
#include <Wire.h>
#include "iot.h" 
#include "senhas.h"
#include "saidas.h" 
#include "atuadores.h"
#include <ArduinoJson.h> // Definição dos tópicos de inscrição 
#define mqtt_topic1 "projetoProfessor/dht1"
#define mqtt_topic2 "projetoProfessor/ledInterno" 
#define mqtt_topic3 "projetoKeizeer/servo" 
#define mqtt_topic4 "projetoKeizeer/ledExterno" 
#define mqtt_topic5 "projetoKeizeer/dht_para_oled" // Definição do ID do cliente MQTT randomico const String
 cliente_id = "ESP32Client" + String(random(0xffff), HEX);
 float umidade = 0;
 float temperatura = 0; 
unsigned long tempo_inicial = 0;
 const unsigned long pausa = 2000; // Definição dos dados de conexão 
WiFiClient espClient;
 PubSubClient client(espClient);
 U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE); // variaveis // Protótipos das funções 
void tratar_msg(char *topic, String msg); 
void callback(char *topic, byte *pa