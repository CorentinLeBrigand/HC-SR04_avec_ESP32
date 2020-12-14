/*/////////////////////////////////////////////////////////////////////////////////////////////////
* HC-SR04 avec ESP32
* Le Brigand Corentin
* 14-12-2020
/////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <Arduino.h>
#include "driver/gpio.h"

#define PIN_ECHO GPIO_NUM_5
#define PIN_TRIGGER GPIO_NUM_16
#define TEMPS_HAUT_US 10 
#define TEMPS_PAUSE 500000
#define DIVISEUR 2
#define VITESSE_SON 340
#define VITESSE_TRANSMISSION 9600

unsigned long tempsMesure = 1000000UL;

void setup() 
{
  Serial.begin(VITESSE_TRANSMISSION);
  gpio_set_direction(PIN_ECHO, GPIO_MODE_INPUT);
  gpio_set_direction(PIN_TRIGGER, GPIO_MODE_OUTPUT);
  gpio_set_level(PIN_ECHO,HIGH);
}

void loop() 
{
  gpio_set_level(PIN_TRIGGER,HIGH);
  usleep(TEMPS_HAUT_US);
  gpio_set_level(PIN_TRIGGER,LOW);
  float distance = pulseIn(PIN_ECHO, HIGH, tempsMesure/DIVISEUR*VITESSE_SON);
  Serial.print("distance : ");
  Serial.print(distance);
  Serial.println(" mm");
  usleep(TEMPS_PAUSE);
}