#include <stdio.h>
#include "DHT.h"

DHT dht;

void setup()
{
  printf("\nStatus\tHumidity (%)\tTemperature (C)\t(F)\n");

  dht_setup(2); // data pin 2
}

void loop()
{
  delay(dht_getMinimumSamplingPeriod());

  float humidity = dht_getHumidity();
  float temperature = dht_getTemperature();

  printf("%s\t%.1f\t\t%.1f\t\t%.1f\n", dht_getStatusString(), humidity, temperature, dht_toFahrenheit(temperature));
}
