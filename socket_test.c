#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>

int main() {

    // string in C = array of characters
    char str[] = "This is how strings are defined in C.";
    printf("%s", str);

    // using the netinet struct to store socket address; data interface for Berkeley Socket API
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    

    return 0;
}
