#include "tcp_client.h"

void TcpClient::tcp_client_task(void *pvParameter)
{
    ESP_LOGI(TAG,"TCP Client Started");

    char rx_buffer[128];
    char host_ip[] = HOST_IP_ADDR;
    int addr_family = 0;
    int ip_protocol = 0;

    //  while (1) {

        struct sockaddr_in dest_addr;

        //AF_INET: Address format is host and port number
        //AF_INET : IPV4 Address
        dest_addr.sin_addr.s_addr = inet_addr(host_ip);
        dest_addr.sin_family = AF_INET;
        dest_addr.sin_port = htons(PORT);
        addr_family = AF_INET;
        ip_protocol = IPPROTO_IP;

        //int sockfd = socket(domain, type, protocol)
        //sockfd: socket descriptor, an integer (like a file-handle)
        //Domain: integer, specifies communication domain. Here AF_INET means IPV4
        //Type: communication type, SOCK_STREAM: TCP,SOCK_DGRAM: UDP 
        //Protocol: Protocol value for Internet Protocol(IP), which is 0
        int sock =  socket(addr_family, SOCK_STREAM, ip_protocol);
        if (sock < 0) {
            ESP_LOGE(TAG, "Unable to create socket: errno %d", errno);
           // break;
        }
        ESP_LOGI(TAG, "Socket created, connecting to %s:%d", host_ip, PORT);

        //int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
        //Connect the socket to the defined Port
        int err = connect(sock, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr_in6));
        if (err != 0) {
            ESP_LOGE(TAG, "Socket unable to connect: errno %d", errno);
            //break;
        }
        else
        {
            ESP_LOGI(TAG, "Successfully connected");
        }

        #if 1
        while (1) {

            int err = send(sock, payload, strlen(payload), 0);
            if (err < 0) {
                ESP_LOGE(TAG, "Error occurred during sending: errno %d", errno);
                //break;
            }

            int len = recv(sock, rx_buffer, sizeof(rx_buffer) - 1, 0);
            // Error occurred during receiving
            if (len < 0) {
                ESP_LOGE(TAG, "recv failed: errno %d", errno);
                //break;
            }
            // Data received
            else {
                rx_buffer[len] = 0; // Null-terminate whatever we received and treat like a string
                ESP_LOGI(TAG, "Received %d bytes from %s:", len, host_ip);
                ESP_LOGI(TAG, "%s", rx_buffer);
            }

            vTaskDelay(2000 / portTICK_PERIOD_MS);
            break;
        }
        #endif

        if (sock != -1) {
            //ESP_LOGE(TAG, "Shutting down socket and restarting...");
            shutdown(sock, 0);
            close(sock);
        }

    //}
    vTaskDelete(NULL);

}