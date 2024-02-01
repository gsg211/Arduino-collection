//program de test pentru senzorul bmp280

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#define BMP280_ADDRESS 0x76
Adafruit_BMP280 bmp;

void setup() {
  Serial.begin(9600);
  unsigned status;
  status = bmp.begin(BMP280_ADDRESS);
}

void loop() {
    Serial.print(F("Temperatura = "));
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");
    Serial.print(F("Presiune = "));
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");
    Serial.print(F("Altitudine (aproximativa) = "));
    Serial.print(bmp.readAltitude(1012.53));//presiunea la nivelul marii (hPa) 
    Serial.println(" m");
    Serial.println();
    delay(2000);
}