#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc , char *argv[]) {
    // Create a socket with IPv4 domain and TCP protocol
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Fail to create a socket.");
    }

    struct sockaddr_in server_address, client_address;
    unsigned int addr_len = sizeof(client_address);
    bzero(&server_address, sizeof(server_address));

    // Bind the socket with the values address and port from the sockaddr_in structure
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8700);
    bind(sockfd, (struct sockaddr *)&server_address, sizeof(server_address));

    // listen on specified port with a maximum of 5 requests
    listen(sockfd, 5);

    char input_buffer[256] = {};
    char message[] = {"Hi, client!"};

    while (1) {
        // Accept connection signals from the client
        int client_sockfd = accept(sockfd, (struct sockaddr*)&client_address, &addr_len);

        // Receive data sent by the client
        recv(client_sockfd, input_buffer, sizeof(input_buffer), 0);
        printf("[2] Recv: %s\n",input_buffer);

        sleep(1);

        // Send data to the client
        send(client_sockfd, message, sizeof(message), 0);
        printf("[3] Send: %s\n", message);

        sleep(1);

        // Terminate the socket connection
        close(client_sockfd);
        printf("[6] Close Socket\n");
    }
    return 0;
}
