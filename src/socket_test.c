#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {

    // using the netinet struct to store socket address; data interface for Berkeley Socket API
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    printf("socket fd: %d\n", server_socket);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    int new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen);


    char *hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
    write(new_socket, hello, strlen(hello));
        

    return 0;
}
