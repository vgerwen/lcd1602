# 1602 LCD driver

This repository contains an ESP-IDF driver for LCD 1602 module with 4 bit data interface.This
module contains two rows of 16 characters each. It runs on a ESP32 processor and is buidl using the ESP-IDF build system

## Connecting the component

The driver uses 6 GPIO output pins of the ESP32.


| LCD PIN   | ESP driver                 | Default GPIO
| ---------:|:--------------------------:| :-----------:|
| RS        | CONFIG_REGISTER_SELECT_PIN | 23           |
| EN        | CONFIG_ENABLE_PIN          | 22           |
| D3        | CONFIG_DATA_3_PIN          | 16           |
| D2        | CONFIG_DATA_2_PIN          | 17           |
| D1        | CONFIG_DATA_1_PIN          | 18           |
| D0        | CONFIG_DATA_0_PIN          | 19           |

These connections are made using **idf.py menuconfig** and choose the settings in the menu under **Component config --->App main**

## LCD1602 library

The libary only support the LCD Module 1602 with a 4 bits interface.
It uses the ```esp_driver_gpio component```.

# Usage

## API
The API of the driver is located in the include directory ```include/1602_driver.h``` and has the following functions:

```C
- void lcdInit(void);
- lcd_err_t lcdSetText(char *text, int x, int y);
- lcd_err_t lcdSetInt(int val, int x, int y);
- lcd_err_t lcdClear(void);
- void assert_lcd(lcd_err_t lcd_error);
```
The driver does not use interrupt handlers and runs on the calling task.

# Example

An example is proved in the directory examples/lcd1602-examples
To run the provided example:

```shell
cd examples/lcd1602-example
idf.py build
```
And flash it to the board:
``` shell
idf.py -p PORT flash monitor
```
The example code writes the string <<< LCD TEST >>> on the first row on the seconf row a counter from 0 incrementing every second till 10 is displayed
If the counter reaches 10 the counter resets to 0 and both rows are flipped. i.e. The string <<< LCD TEST >>> will be on on row 1 and the counter on row 0. This flipping repeats endless.

# License

This component is provided under Apache 2.0 license, see [LICENSE](LICENSE.md) file for details.

# Contributing

Please check for contribution guidelines.