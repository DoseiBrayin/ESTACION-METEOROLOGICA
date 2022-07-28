/*
 *      -----TEST SENSORES DHT11/22 Y BMP180-----
 * 
 * Por "Ingeniero en Casa"
 * https://www.youtube.com/channel/UCurfoG9YbFyQmxCLlxZVArg
 * 
 * La distribución y/o modificación del código es totalmente libre.
 */


#include "DHT.h"
#include "Adafruit_BMP085.h"


#define pin1 18


DHT dht1(pin1, DHT11);    //El azul.


Adafruit_BMP085 bmp;

void setup() {
  Serial.begin(115200);
  Serial.println("Test de sensores:");

  dht1.begin();

  bmp.begin();
}

void loop() {

  delay(2000);
  leerdht1();

  delay(2000);
  leerbmp();
}

void leerdht1() {
  
  float t1 = dht1.readTemperature();
  float h1 = dht1.readHumidity();

  while (isnan(t1) || isnan(h1)){
    Serial.println("Lectura fallida en el sensor DHT11, repitiendo lectura...");
    delay(2000);
    t1 = dht1.readTemperature();
    h1 = dht1.readHumidity();
  }

  Serial.print("Temperatura DHT11: ");
  Serial.print(t1);
  Serial.println(" ºC.");

  Serial.print("Humedad DHT11: ");
  Serial.print(h1);
  Serial.println(" %."); 

  Serial.println("-----------------------");
}

void leerbmp() {

  float temp = bmp.readTemperature();
  float presion = bmp.readPressure();
  float altitud = bmp.readAltitude();

  Serial.print("Temperatura bmp: ");
  Serial.print(temp);
  Serial.println(" ºC.");

  Serial.print("Presión bmp: ");
  Serial.print(presion);
  Serial.println(" Pa.");

  Serial.print("Altitud bmp: ");
  Serial.print(altitud);
  Serial.println(" metros.");

  Serial.println("-----------------------");  
}
