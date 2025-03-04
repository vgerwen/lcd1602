# 1602 LCD driver

This repository contains an ESP-IDF driver for LCD 1602 module with 4 bit data interface.This
module contains two rows of 16 characters each

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

## Example

An example is proved in the directory examples/lcd1602-examples
To run the provided example:

```
cd examples/lcd1602-example
idf.py build
```
And flash it to the board:
```
idf.py -p PORT flash monitor
```
The example code writes the string <<< LCD TEST >>> on the first row on the seconf row a counter from 0 incrementing every second till 10 is displayed
If the counter reaches 10 the counter resets to 0 and both rows are flipped. i.e. The string <<< LCD TEST >>> will be on on row 1 and the counter on row 0. This flipping repeats endless.

## License

This component is provided under Apache 2.0 license, see [LICENSE](LICENSE.md) file for details.

## Contributing

Please check for contribution guidelines.