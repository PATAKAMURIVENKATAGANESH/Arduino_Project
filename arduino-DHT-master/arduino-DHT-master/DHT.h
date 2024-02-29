#ifndef DHT_H
#define DHT_H

#include <stdint.h>

typedef enum {
    AUTO_DETECT,
    DHT11,
    DHT22,
    AM2302,
    RHT03
} DHT_MODEL_t;

typedef enum {
    ERROR_NONE = 0,
    ERROR_TIMEOUT,
    ERROR_CHECKSUM
} DHT_ERROR_t;

typedef struct {
    float temperature;
    float humidity;
} DHT_DATA_t;

void dht_setup(uint8_t pin, DHT_MODEL_t model);
void dht_resetTimer();
void dht_readSensor(DHT_DATA_t* data);
float dht_getTemperature();
float dht_getHumidity();
DHT_ERROR_t dht_getStatus();
const char* dht_getStatusString();
DHT_MODEL_t dht_getModel();
int dht_getMinimumSamplingPeriod();
int8_t dht_getNumberOfDecimalsTemperature();
int8_t dht_getLowerBoundTemperature();
int8_t dht_getUpperBoundTemperature();
int8_t dht_getNumberOfDecimalsHumidity();
int8_t dht_getLowerBoundHumidity();
int8_t dht_getUpperBoundHumidity();
float dht_toFahrenheit(float fromCelsius);
float dht_toCelsius(float fromFahrenheit);

#endif /* DHT_H */
