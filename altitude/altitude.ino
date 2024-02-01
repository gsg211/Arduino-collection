//afisare lcd shield pt altitudine

#include <LiquidCrystal.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

#define BMP280_ADDRESS 0x76
Adafruit_BMP280 bmp;
LiquidCrystal lcd(7,6,5,4,3,2);
float press=1012;//default value

int btn=8;

void setup() {
  Serial.begin(9600);
  unsigned status;
  status = bmp.begin(BMP280_ADDRESS);
  lcd.begin(16,2);
  pinMode(btn,INPUT);
}

void loop() {
    lcd.setCursor(0,0);
    lcd.print("Temp=");
    if(digitalRead(btn))
    {
      press=bmp.readPressure()/100;
    }
    lcd.print(bmp.readTemperature());
    lcd.println(" *C");
    lcd.setCursor(0, 1);
    lcd.print("Altitude=");
    
    lcd.print(bmp.readAltitude(press)); 
    Serial.println(" m");
    Serial.println();
    
    delay(1000);
}