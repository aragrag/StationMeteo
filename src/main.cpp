#include <SPI.h>
#include <Arduino.h>



const int del = 10000;

void setup() {
    Serial.begin(9600);

    Serial.println("Adafruit AHT10/AHT20 demo");
    Serial.println("AHT10 or AHT20 found");
}

void loop() {
    int temperature = random(10, 25);  // Remplacer par la lecture du capteur de température
    int relative_humidity = random(20, 80);  // Remplacer par la lecture du capteur d'humidité

    // Envoyer les données via la console série
    // Serial.print("T:");
    Serial.print(temperature);
    Serial.print(",");
    Serial.println(relative_humidity);

    delay(del);
}
