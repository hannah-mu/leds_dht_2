#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);

#include <Adafruit_NeoPixel.h>
#define LED_PIN 6
#define LED_COUNT 10

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int r(float t)
{
  if(t<20) return 0;
  if(t>30) return 255;

  return map(t, 20, 30, 0, 255);
}

int g(float t)
{
  if(t<10) return 0;
  if(t>30) return 0;

  return map(t, 10, 20, 0, 255);
  return map(t, 20, 30, 255, 0);
}

int b(float t)
{
  if(t<10) return 255;
  if(t>20) return 0;

  return map(t, 10, 20, 255, 0);
}



void setup() {
  
  Serial.begin(9600);
  dht.begin();
  
  strip.begin();
  strip.show();
  strip.setBrightness(100);

}

void loop() {
  delay(2000);

  float t = dht.readTemperature();
  Serial.print(" Temperature: ");
  Serial.print(t);
  Serial.println("°C");
  delay(100);

  int red = r(t);
  int green = g(t);
  int blue = b(t);

  Serial.println(red);
  Serial.println(green);
  Serial.println(blue);

  

  strip.fill(strip.Color(red, green, blue), 0, 10);

  strip.show();
  

}
