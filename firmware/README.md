---

# Wake Word Detection ESP32

Firmware for a DIY voice assistant on ESP32 using **PlatformIO**. SPIFFS upload is required for WAV feedback files.

---

## Wake Word

Default: `"Marvin"`.
To adjust sensitivity, edit `src/state_machine/DetectWakeWordState.cpp`:

```cpp
if (output > 0.95)  // lower value = more sensitive
```

---

## Code Overview

* `src/Application.cpp` – main state machine
* `src/state_machine/DetectWakeWordState.cpp` – wake word detection
* `src/state_machine/RecogniseCommandState.cpp` – command recognition

---

## Config (`config.h`)

### WiFi

```cpp
#define WIFI_SSID "your-ssid"
#define WIFI_PSWD "your-password"
```

### Microphone

**I2S:**

```cpp
#define USE_I2S_MIC_INPUT
#define I2S_MIC_CHANNEL I2S_CHANNEL_FMT_ONLY_LEFT
#define I2S_MIC_SERIAL_CLOCK GPIO_NUM_33
#define I2S_MIC_LEFT_RIGHT_CLOCK GPIO_NUM_26
#define I2S_MIC_SERIAL_DATA GPIO_NUM_25
```

**Analog:**

```cpp
//#define USE_I2S_MIC_INPUT
#define ADC_MIC_CHANNEL ADC1_CHANNEL_7  // GPIO35
```

### Speaker (optional)

```cpp
#define I2S_SPEAKER_SERIAL_CLOCK GPIO_NUM_14
#define I2S_SPEAKER_LEFT_RIGHT_CLOCK GPIO_NUM_12
#define I2S_SPEAKER_SERIAL_DATA GPIO_NUM_27
```

### Wit.ai

```cpp
#define COMMAND_RECOGNITION_ACCESS_KEY "YOUR_KEY"
```

---

