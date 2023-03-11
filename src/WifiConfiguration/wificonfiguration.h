#ifndef WIFICONFIGURATION_H
#define WIFICONFIGURATION_H

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "lwip/err.h"
#include "lwip/sys.h"
#include <sdkconfig.h>

#define EXAMPLE_ESP_WIFI_SSID      "Seezeit-MAC-Auth"
#define EXAMPLE_ESP_WIFI_PASS      "seezeit-mac-auth"
#define EXAMPLE_ESP_WIFI_CHANNEL   1
#define EXAMPLE_MAX_STA_CONN       4

static const char *WIFI_TAG = "Wifi Configurations: ";

class WifiConfiguration
{
public:
    
    static void wifi_event_handler(void* arg, esp_event_base_t event_base,
                                    int32_t event_id, void* event_data);
    void set_wifi_configuration(void);
private:

};

#endif