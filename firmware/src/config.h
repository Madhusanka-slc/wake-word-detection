#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// =====================
// WiFi Credentials
// =====================
#define WIFI_SSID     ""
#define WIFI_PSWD     ""

// =====================
// Microphone Settings (INMP441)
// =====================
#define USE_I2S_MIC_INPUT
#define I2S_MIC_CHANNEL   I2S_CHANNEL_FMT_ONLY_LEFT  // Use LEFT channel
#define I2S_SCK           GPIO_NUM_12                // I2S Serial Clock (BCK)
#define I2S_WS            GPIO_NUM_11                // I2S Word Select (LRCK)
#define I2S_SD            GPIO_NUM_10                // I2S Serial Data (DATA)

// =====================
// LED / Bulb Output
// =====================
#define LED_PIN           GPIO_NUM_13

// =====================
// Speaker Settings (if needed)
// =====================
#define I2S_SPEAKER_SERIAL_CLOCK      GPIO_NUM_14
#define I2S_SPEAKER_LEFT_RIGHT_CLOCK  GPIO_NUM_12
#define I2S_SPEAKER_SERIAL_DATA       GPIO_NUM_27

// =====================
// Command Recognition / Wit.ai
// =====================
#define COMMAND_RECOGNITION_ACCESS_KEY  "3UO3PWX7KST5RCXDW7E24OD43LOBJWOR"

#endif // CONFIG_H
