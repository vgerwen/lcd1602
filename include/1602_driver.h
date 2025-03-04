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

/* LCD Error */
typedef int lcd_err_t;      /*!< LCD error type */

#define LCD_FAIL            -1  /*!< LCD fail error     */
#define LCD_OK               0  /*!< LCD success    */

void lcdInit(void);

lcd_err_t lcdSetText(char *text, int x, int y);

lcd_err_t lcdSetInt(int val, int x, int y);

lcd_err_t lcdClear(void);

void assert_lcd(lcd_err_t lcd_error);

#endif
