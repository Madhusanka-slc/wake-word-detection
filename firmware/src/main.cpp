#include <Arduino.h>
#include <driver/i2s.h>
#include <esp_task_wdt.h>
#include "I2SMicSampler.h"
#include "I2SOutput.h"
#include "config.h"
#include "Application.h"
#include "SPIFFS.h"
#include <ESP32Servo.h>

#define SERVO_PIN 13
Servo s1;
extern volatile bool moveServoFlag;

#define USE_I2S_MIC_INPUT  // Use I2S microphone

// =====================
// I2S Microphone Config
// =====================
i2s_config_t i2sConfig = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = 16000,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,
    .channel_format = I2S_MIC_CHANNEL,
    .communication_format = I2S_COMM_FORMAT_STAND_I2S,
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 4,
    .dma_buf_len = 64,
    .use_apll = false,
    .tx_desc_auto_clear = false,
    .fixed_mclk = 0
};

i2s_pin_config_t i2sPins = {
    .bck_io_num   = I2S_SCK,
    .ws_io_num    = I2S_WS,
    .data_out_num = I2S_PIN_NO_CHANGE,
    .data_in_num  = I2S_SD
};

// =====================
// Application Task
// =====================
void applicationTask(void* param)
{
    Application* application = static_cast<Application*>(param);
    const TickType_t xMaxBlockTime = pdMS_TO_TICKS(100);

    while (true)
    {
        uint32_t notification = ulTaskNotifyTake(pdTRUE, xMaxBlockTime);
        if (notification > 0)
            application->run();
    }
}

// =====================
// Setup
// =====================
void setup()
{
    Serial.begin(115200);
    delay(1000);
    Serial.println("Starting wake word detection...");

    // Attach servo
    s1.attach(SERVO_PIN, 500, 2500);

    // Start SPIFFS for local files
    SPIFFS.begin();

    // Prevent watchdog reset
    esp_task_wdt_init(10, false);

    // Initialize I2S sampler
#ifdef USE_I2S_MIC_INPUT
    I2SSampler* i2sSampler = new I2SMicSampler(i2sPins, false);
#else
    // For ADC microphone: I2SSampler* i2sSampler = new ADCSampler(...);
#endif

    // Initialize application (wake word detection)
    Application* application = new Application(i2sSampler);

    // Create FreeRTOS task
    TaskHandle_t appTaskHandle;
    xTaskCreate(applicationTask, "Application Task", 8192, application, 1, &appTaskHandle);

    // Start I2S sampling
#ifdef USE_I2S_MIC_INPUT
    i2sSampler->start(I2S_NUM_0, i2sConfig, appTaskHandle);
#endif
}

// =====================
// Loop
// =====================
void loop()
{
    // Move servo if wake word detected
    if (moveServoFlag)
    {
        moveServoFlag = false;

        Serial.println("Moving servo...");
        s1.write(90);
        delay(500);
        s1.write(0);
        delay(500);

        Serial.println("Servo movement complete.");
    }

    vTaskDelay(pdMS_TO_TICKS(1000));
}
