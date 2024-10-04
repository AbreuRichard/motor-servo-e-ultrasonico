#include <Arduino.h>
#include "saidas.h"
#include <U8g2lib.h>

// Definição dos pinos dos LEDs
#define LedBuiltInPin 2
#define LedExterno 25

// Definição dos pinos do OLED (I2C)
#define OLED_SDA 21
#define OLED_SCL 22

// Variáveis de controle dos LEDs
bool LedBuiltInState = LOW;
bool LedExternoState = LOW;

// Inicializa o display OLED (usando I2C com SDA e SCL definidos)
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, OLED_SCL, OLED_SDA);

// Inicializa as saídas digitais
void inicializa_saidas()
{
    pinMode(LedBuiltInPin, OUTPUT);
    pinMode(LedExterno, OUTPUT);

    // Inicializa o display OLED
    u8g2.begin();
}

// Atualiza as saídas digitais
void atualiza_saidas()
{
    digitalWrite(LedBuiltInPin, LedBuiltInState);
    digitalWrite(LedExterno, LedExternoState);

    // Exemplo de atualização do display OLED
    u8g2.clearBuffer();                 // Limpa o buffer interno
    u8g2.setFont(u8g2_font_ncenB08_tr); // Escolhe33e uma fonte
    u8g2.drawStr(0, 30, "Palmeiras sem mundial"); // Desenha uma string na posição (0,30)
    u8g2.sendBuffer();                  // Envia o buffer para o display
}
