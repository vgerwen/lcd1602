# 1602 LCD driver

This repository contains an ESP-IDF driver for LCD 1602 device 4 bit connected.

## Connecting the component

The driver uses 6 GPIO pins of teh ESP32

Colons can be used to align columns.

| LCD PIn       | ESP driver    |
| ------------- |:-------------:| -----:|
| RS            | ESP_DRIVER_RS |  Register selected     |
| EN            | ESP_DRIVER_EN | Enable |
| D4            | ESP_GPIO_32   |    Data 4|

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