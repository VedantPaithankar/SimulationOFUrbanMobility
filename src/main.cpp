#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_spi_flash.h"
#include "tcp_client.h"
#include "tcp_server.h"
#include "wificonfiguration.h"
 
extern "C" {
   void app_main();
}

void app_main(void)
{
    //Initialization  
   ESP_ERROR_CHECK(nvs_flash_init());
   ESP_ERROR_CHECK(esp_netif_init());
   ESP_ERROR_CHECK(esp_event_loop_create_default());

   //Set Wifi Configuration 
   WifiConfiguration wifi_config;
   wifi_config.set_wifi_configuration(); 

   xTaskCreate(&TcpServer::tcp_server_task, "tcp_server", 4096, NULL, 5, NULL); 

   vTaskDelay(5000 / portTICK_PERIOD_MS);
   
   xTaskCreate(&TcpClient::tcp_client_task, "tcp_client", 4096, NULL, 5, NULL); 
    
}
