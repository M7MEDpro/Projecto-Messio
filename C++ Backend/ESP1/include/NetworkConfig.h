#ifndef NETWORK_CONFIG_H
#define NETWORK_CONFIG_H

#include <Arduino.h>

const char* const WIFI_SSID = "oppo reno 14 5G";
const char* const WIFI_PASSWORD = "1234567890";


const uint8_t LOCAL_IP[] = {10, 205, 248, 101};
const uint8_t GATEWAY_IP[] = {10, 205, 248, 70};
const uint8_t SUBNET_MASK[] = {255, 255, 255, 0};

const char* const SERVER_URL_PUT = "http://10.205.248.200:5000/esp1";
const char* const SERVER_URL_GET = "http://10.205.248.200:5000/esp1";

#endif
