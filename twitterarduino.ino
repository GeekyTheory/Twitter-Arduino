#include <SPI.h> // Necesario en Arduino 0019 o posterior
#include <Ethernet.h>
#include <Twitter.h>

// Configuracion de la Ethernet Shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// Si no se especifica la IP, se utiliza DHCP (solo para Arduino 1.0 o superior).
byte ip[] = { 192, 168, 0, 250 };

Twitter twitter("INTRODUCIR TOKEN AQUI");

// Mensaje
char msg[] = "¡Publicando en Twitter desde #Arduino gracias a @geekytheory! Tutorial en http://goo.gl/VCFfz4";

void setup()
{
  delay(1000);
  Ethernet.begin(mac, ip);
  // Si usamos DHCP no hace falta incluir la IP.
  // Ethernet.begin(mac);
  Serial.begin(9600);
  
  Serial.println("Estableciendo conexion con Twitter ...");
  if (twitter.post(msg)) { // Publicamos el mensaje en Twitter. Devuelve true o false.
    int status = twitter.wait(&Serial);
    if (status == 200) { // Conexion exitosa
      Serial.println("OK.");
    } else { // Error en la conexion
      Serial.print("Error : code ");
      Serial.println(status);
    }
  } else {
    Serial.println("Conexion fallida.");
  }
}

void loop()
{
}
