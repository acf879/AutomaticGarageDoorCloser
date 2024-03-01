#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sdkconfig.h"

void app_main(void)
{
  
  for (;;) { // infinite loop
  ESP_LOGI("MY APP: ", "Hello, world!\n"); // print hello, world out to serial monitor
  }
}
