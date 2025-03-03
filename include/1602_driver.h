/**
 * @file 1602_driver.h
 * @author Aad van Gerwen       
 * @brief LCD driver for LCD 1602 4 bit control
 * @version 0.1
 * @date 2025-03-03
 * @copyright Copyright (c) 2025
 *
 */
#ifndef _1602_DRIVER_H_
#define _1602_DRIVER_H_

#include "driver/gpio.h"

/* LCD Error */
typedef int lcd_err_t;      /*!< LCD error type */

#define LCD_FAIL            -1  /*!< LCD fail error     */
#define LCD_OK               0  /*!< LCD success    */


#define LCD_DATA_LINE 4 /*!< 4-Bit data line */

/******************************************************************
 * \enum lcd_state esp_lcd.h 
 * \brief LCD state enumeration
 *******************************************************************/
typedef enum {
    LCD_INACTIVE = 0,   /*!< LCD inactive */
    LCD_ACTIVE = 1,     /*!< LCD active   */
}lcd_state_t;

/******************************************************************
 * \struct lcd_t esp_lcd.h 
 * \brief LCD object
 * 
 * ### Example
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.c
 * typedef struct {
 *      gpio_num_t data[LCD_DATA_LINE];
 *      gpio_num_t en;
 *      gpio_num_t regSel;
 *      lcd_state_t state;
 * }lcd_t;
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *******************************************************************/
typedef struct
{
    gpio_num_t data[LCD_DATA_LINE]; /*!< LCD data line  */
    gpio_num_t en;                  /*!< LCD enable pin */
    gpio_num_t regSel;              /*!< LCD register select */
    lcd_state_t state;              /*!< LCD state  */
} lcd_t;

void lcdDefault(lcd_t *const lcd);

void lcdInit(lcd_t *const lcd);

void lcdCtor(lcd_t *lcd, gpio_num_t data[LCD_DATA_LINE], gpio_num_t en, gpio_num_t regSel);

lcd_err_t lcdSetText(lcd_t *const lcd, char *text, int x, int y);

lcd_err_t lcdSetInt(lcd_t *const lcd, int val, int x, int y);

lcd_err_t lcdClear(lcd_t *const lcd);

void lcdFree(lcd_t * const lcd);

void assert_lcd(lcd_err_t lcd_error);

#endif
