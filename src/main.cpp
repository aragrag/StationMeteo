/*
  Titre      : DEMO TMP36 - MKR 1000 - Thingsboard
  Auteur     : Aragrag Ayoub
  Date       : 28/10/2023
  Description: lecture du TMP36 et envoie de cette valeur a une fréquences spécifique sur la plateforme IDO Thingsbaord
  Droits     : Reproduction permise pour usage pédagogique
  Version    : 0.0.4
*/

#include <SPI.h>
#include <Arduino.h>
#include <Adafruit_AHTX0.h>
#include "WIFIConnector_MKR1000.h" //inclusion d'un libairie pour la focntionnalite wifi
#include "MQTTConnector.h"         //inclusion d'un libairie pour la focntionnalite MQTT.h

Adafruit_AHTX0 aht;
const int del = 10000;

void setup()
{
    Serial.begin(9600);
    wifiConnect(); // Branchement au réseau WIFI
    MQTTConnect(); // Branchement au broker MQTT

    Serial.println("Adafruit AHT10/AHT20 demo!");

    if (!aht.begin())
    {
        Serial.println("Could not find AHT? Check wiring");
        while (1)
            delay(10);
    }
    Serial.println("AHT10 or AHT20 found");
}

void loop()
{
    sensors_event_t humidity, temp;
    aht.getEvent(&humidity, &temp); 

    Serial.print(temp.temperature);
    Serial.print(",");
    Serial.println(humidity.relative_humidity);
    
    delay(del);
}