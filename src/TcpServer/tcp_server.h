#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <string.h>
#include <sys/param.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_netif.h"

#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include <lwip/netdb.h>

#define PORT                        7000 
#define KEEPALIVE_IDLE              5
#define KEEPALIVE_INTERVAL          5
#define KEEPALIVE_COUNT             5

static const char *TAG_SERVER = "Server :";

using namespace std;

class TcpServer
{

public :
    static void tcp_server_task(void *pvParameter);
    static void do_retransmit(const int sock);

private :
   
};


#endif