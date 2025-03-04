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

  /* Initialize LCD object */
  lcdInit();

  /* Clear previous data on LCD */
  lcdClear();

  /* Custom text */
  char buffer[16] = "<<< LCD TEST >>>";
/*
  float version = 1.0;
  char initial[2] = {'J', 'M'};

  sprintf(buffer, "Hello World!", version, initial[0], initial[1]);
*/
     
  /* Set text */
  lcd_err_t ret = lcdSetText(buffer, 0, 0);
  
  /* create count variable */
  static int count = 0;
  int row = 1;
  while (1)
  {
    lcdSetInt(count, 0, row);
    count++;     
    /* 1 second delay */
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    if (count == 10) {
      lcdClear();
       count = 0;
      /* Custom text */
       char buffer[16] = "<<< LCD TEST >>>";
       lcd_err_t ret = lcdSetText(buffer, 0, row);
       if (row == 1){
          row = 0;
       }
       else {
          row = 1;
       }
    }   
  }
}

void app_main(void)
{
  /* Create LCD task */
  xTaskCreate(lcd_task, "LCD task", 2048, NULL, 4, NULL);
}
