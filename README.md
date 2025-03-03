# 1602 LCD driver

This repository contains an ESP-IDF driver for LCD 1602 device 4 bit connected.

## Connecting the component

The driver uses 6 GPIO pins of the ESP32

| LCD PIN   | ESP driver         | Default GPIO
| ---------:|:------------------:| :-----------:|
| RS        | ESP_DRIVER_RS      | 23          |
| EN        | ESP_DRIVER_EN      | 22          |
| D3        | CONFIG_DATA_3_PIN  | 16          |
| D2        | CONFIG_DATA_2_PIN  | 17          |
| D1        | CONFIG_DATA_1_PIN  | 18          |
| D0        | CONFIG_DATA_0_PIN  | 19          |

These connections are made using idf.py menuconfig and chose the settings is app_menu

## Example

To run the provided example, create it as follows:


Then build as usual:

cd examples/lcd1602-example
idf.py build
```

And flash it to the board:
```bash
idf.py -p PORT flash monitor
```

## License

This component is provided under Apache 2.0 license, see [LICENSE](LICENSE.md) file for details.

## Contributing

Please check for contribution guidelines.