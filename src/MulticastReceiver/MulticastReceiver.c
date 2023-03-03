#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXRECVSTRING 255

void DieWithError(char *errorMessage);

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in multicastAddr;
    char *multicastIP;
    unsigned short multicastPort;
    char recvString[MAXRECVSTRING+1];
    int recvStringLen;
    struct ip_mreq multicastRequest;

    if (argc != 3){
        fprintf(stderr, "Usage: %s <Multicast IP> <Multicast Port>\n", argv[0]);
    }

    multicastIP = argv[1];
    multicastPort = atoi(argv[2]);

    if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0){
        DieWithError("socket() failed");
    }

    memset(&multicastAddr, 0, sizeof(multicastAddr));
    multicastAddr.sin_family = AF_INET;
    multicastAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    multicastAddr.sin_port = htons(multicastPort);

    if (bind(sock, (struct sockaddr *)&multicastAddr, sizeof(multicastAddr)) < 0){
        DieWithError("bind() failed");
    }

    multicastRequest.imr_multiaddr.s_addr = inet_addr(multicastIP);
    multicastRequest.imr_interface.s_addr = htonl(INADDR_ANY);

    if (setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *)&multicastRequest, sizeof(multicastRequest)) < 0){
        DieWithError("setsockopt() failed");
    }

    recvString[recvStringLen] = printf("Received: %s\n", recvString);

    close(sock);    
    exit(0);
}