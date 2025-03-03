/**
 * @file lcd1602_example.c
 * @author Aad van Gerwen
 * @brief Example code fro LCD 1602 driver
 * @version 0.1
 * @date 2025-03-02
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>
#include "1602_driver.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


esp_err_t return_value = ESP_OK;

void lcd_task(void *pvParameters)
{

  /* Create LCD object */
  lcd_t lcd;

  /* Set default pinout */
  lcdDefault(&lcd);

  /* Initialize LCD object */
  lcdInit(&lcd);

  /* Clear previous data on LCD */
  lcdClear(&lcd);

  /* Custom text */
  char buffer[16] = "Hello World!!";
/*
  float version = 1.0;
  char initial[2] = {'J', 'M'};

  sprintf(buffer, "Hello World!", version, initial[0], initial[1]);
*/
     
  /* Set text */
  lcd_err_t ret = lcdSetText(&lcd, buffer, 0, 0);
  
  /* create count variable */
  static int count = 0;

  while (1)
  {
       
    lcdSetInt(&lcd, count, 0, 1);
    count++;     
    /* 0,5 second delay */
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void app_main(void)
{
  /* Create LCD task */
  xTaskCreate(lcd_task, "LCD task", 2048, NULL, 4, NULL);
}
