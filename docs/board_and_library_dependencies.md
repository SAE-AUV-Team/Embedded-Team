# Arduino IDE Environment Setup

## 1. Board Manager URLs
To compile this firmware, you must add the following URLs to your Arduino IDE Preferences (`File` > `Preferences` > `Additional Boards Manager URLs`):

* **ESP32 Core:** `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
* **STM32 Core:** `https://github.com/stm32duino/BoardManagerFiles/raw/main/package_stmicroelectronics_index.json`

## 2. Required Libraries
Install the following libraries strictly via the **Arduino Library Manager** (`Sketch` > `Include Library` > `Manage Libraries`). Ensure the exact versions are matched to prevent compilation errors.

* **CAN Communication:** `mcp_can` by coryjfowler (v1.5.0)
* **I2C Sensor Core:** `Adafruit Unified Sensor` (v1.1.13)
