#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include <iostream>
#include <string.h>
#include <sys/param.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "lwip/err.h"
#include "lwip/sockets.h"
#include "esp_log.h"
#include <sdkconfig.h>

//Server IP Address
#define HOST_IP_ADDR "127.0.0.1"

//Port Number for communication
#define PORT 7000

static const char *TAG = "Client :";
static const char *payload = "Hey Vedant here, TCP-IP Working As Expected";

using namespace std;

class TcpClient
{

public :
    static void tcp_client_task(void *pvParameter);

private :

};


#endif