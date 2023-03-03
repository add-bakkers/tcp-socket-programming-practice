#include "../TCPEchoServer/TCPEchoServer.h"
#include <sys/time.h>
#include <fcntl.h>

int main(int argc,char *argv[]){
    int *servSock;
    int maxDescriptor;
    fd_set sockSet;
    long timeout;
    struct timeval selTimeout;
    int running = 1;
    int noPorts;
    int port;
    unsigned short portNo;

    if (argc <3){
        fprintf(stderr, "Usage: %s <Timeout (secs.)> <Port 1> ...\n", argv[0]);
        exit(1);
    }

    timeout = atoi(argv[1]);
    noPorts = argc - 2;

    servSock = (int *)malloc(noPorts * sizeof(int));
    maxDescriptor = -1;


    for (port = 0; port < noPorts; port++){
        portNo = atoi(argv[port+2]);

        servSock[port] = CreateTCPServerSocket(portNo);

        if (servSock[port] > maxDescriptor){
            maxDescriptor = servSock[port];
        }
    }

    printf("Starting server : Hit return to shutdown\n");
    while (running){
        FD_ZERO(&sockSet);
        FD_SET(STDIN_FILENO, &sockSet);
        for (port = 0; port < noPorts; port++){
            FD_SET(servSock[port], &sockSet);
        }

        selTimeout.tv_sec = timeout;
        selTimeout.tv_usec = 0;

        if (select(maxDescriptor + 1, &sockSet, NULL, NULL, &selTimeout) == 0){
            printf("No echo requests for %ld secs... Server still alive\n", timeout);
        }
        else{
            if (FD_ISSET(STDIN_FILENO, &sockSet)){
                printf("Shutting down server\n");

                getchar();
                running = 0;
            }
        }

        for (port = 0; port < noPorts; port++){
            if (FD_ISSET(servSock[port], &sockSet)){
                printf("Request on port %d: ", port);
                HandleTCPClient(servSock[port]);
            }
        }
    }
    for (port = 0; port < noPorts; port++){
        close(servSock[port]);
    }
    free(servSock);
    exit(0);
}

