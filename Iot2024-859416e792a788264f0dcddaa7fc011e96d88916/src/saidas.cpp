#include <Arduino.h>
#include "saidas.h"
#define LedBuiltInPin 25

bool LedBuiltInState = LOW;

void inicializa_saidas()
{
    pinMode(LedBuiltInPin, OUTPUT);
}

void atualiza_saidas()
{
    digitalWrite(LedBuiltInPin, LedBuiltInState);
}