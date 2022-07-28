# ESTACION-METEOROLOGICA
Estación meteorologica usando sensores DHT11, BMP180 a traves de la placa programadora ESP-32 ,Arduino y la API ThingSpeak

## Conexiones
Usamos un cable micro-usb para alimentar nuestro ESP-32, con esta alimentacion usaremos el pin de 3.3v del dispositivo para alimentar nuestros sensores BMP180 y DTH11 y al igual usaremos el punto GND para las conexiones GND de nuestro dispositivo, a continuacion usaremos los pines 21 y 22 a las conexiones SDA y SCL del BMP180 para la comunicacion del BMP180 con el ESP32, de la misma forma usaremos el pin 18 para la data del DTH11 y asi capturar los datos de los sensores

### ![WhatsApp Image 2022-07-27 at 8 54 04 AM](https://user-images.githubusercontent.com/79883410/181587844-3aaa47c1-16fe-4009-ac55-99eacb687c69.jpeg)

## Obtencion de los datos
Con nuestras conexiones ya listas, usaremos una funcion para extraer estos datos de nuestros sensores

void leerdht1() {
  
  float t1 = dht1.readTemperature(); //Lee la temperatura
  float h1 = dht1.readHumidity(); //Lee la humedad

  while (isnan(t1) || isnan(h1)){ //Ciclo en caso de que se pierda la comunicacion, reintentar recuperarlo
    Serial.println("Lectura fallida en el sensor DHT11, repitiendo lectura...");
    delay(2000);
    t1 = dht1.readTemperature();
    h1 = dht1.readHumidity();
  }
  // Obtenemos feedback a traves de la consola para asegurarnos que los datos sean recibidos
  Serial.print("Temperatura DHT11: ");
  Serial.print(t1);
  Serial.println(" ºC.");

  Serial.print("Humedad DHT11: ");
  Serial.print(h1);
  Serial.println(" %."); 

  Serial.println("-----------------------");
}

Ahora haremos lo mismo para el BMP180:

void leerbmp() {

  float presion = bmp.readPressure(); //Lee la presion atmosferica de la zona
  float altitud = bmp.readAltitude(); //Lee la altitud de la zona

  //Imprimimos en pantalla los datos
  Serial.print("Presión bmp: ");
  Serial.print(presion);
  Serial.println(" Pa.");

  Serial.print("Altitud bmp: ");
  Serial.print(altitud);
  Serial.println(" metros.");

  Serial.println("-----------------------");  
}

Con los sensores ya probados y asegurandonos de que el ESP32 recibe los datos, ahora implementaremos la conexion Wi-fi y la conexion al ThingSpeak

const char* ssid = "ssid";       //Nombre de la red wi-fi                
const char* password = "pass";     //Contraseña de la red          

unsigned long channelID = 1810676;  //Canal de nuestro ThingSpeak              
const char* WriteAPIKey = "CTWB0FZWKJ21FKCF"; //Nuestra llave para el canal     

WiFiClient cliente; //Objeto del cliente

Y posteriormente con las funciones anteriores añaridemos al final la siguiente linea para cada tipo de información que sera enviada a nuestro canal de ThingSpeak

ThingSpeak.setField (Numero_Grafica,Variable);

Con esa linea podemos enviar nuestros datos que seran registrados

## Visualización de los datos
Para la visualización del grafico para todo publico puede hacerse desde este link: https://thingspeak.com/channels/1810676

## Mayores dificultades
Las conexiones a la API de ThingSpeak, al igual que el intento de portar el codigo a python.















