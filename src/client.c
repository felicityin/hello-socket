#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc , char *argv[]) {
    // Create a socket with IPv4 domain and TCP protocol
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Fail to create a socket.");
    }

    struct sockaddr_in info;
    bzero(&info, sizeof(info));

    // Connect to the server
    info.sin_family = AF_INET;
    info.sin_addr.s_addr = inet_addr("127.0.0.1");
    info.sin_port = htons(8700);
    int err = connect(sockfd, (struct sockaddr *)&info, sizeof(info));
    if (err == -1) {
        printf("Connection error");
    }

    // Send message to the server
    char message[] = {"Hi, server! I'm client."};
    send(sockfd, message, sizeof(message), 0);
    printf("[1] Send: %s\n", message);

    // Receive a message from the server
    char receiveMessage[100] = {};
    recv(sockfd, receiveMessage, sizeof(receiveMessage), 0);
    printf("[4] Recv: %s\n", receiveMessage);

    // Terminate the socket connection
    close(sockfd);
    printf("[5] Close Socket\n");
    return 0;
}
