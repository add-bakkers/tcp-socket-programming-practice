#include "../TCPEchoServer/TCPEchoServer.h"
#include <sys/wait.h>

int main(int argc, char *argv[]){
    int servSock;
    int clntSock;
    unsigned short echoServPort;
    pid_t processID;
    unsigned int childProcCount = 0;

    if (argc != 2){
        fprintf(stderr, "Usage: %s <Server Port>\n", argv[0]);
        exit(1);
    }

    echoServPort = atoi(argv[1]);

    servSock = CreateTCPServerSocket(echoServPort);

    for (;;){
        clntSock = AcceptTCPConnection(servSock);
        if ((processID = fork()) < 0){
            DieWithError("fork() failed");
        }
        else if (processID == 0){
            close(servSock);
            HandleTCPClient(clntSock);

            exit(0);
        }

        printf("with child process: %d\n", (int)processID);
        childProcCount++;

        while (childProcCount){
            processID = waitpid((pid_t)-1, NULL, WNOHANG);
            if (processID < 0){
                DieWithError("waitpid() failed");
            }
            else if (processID == 0){
                break;
            }
            else{
                childProcCount--;
            }
        }
    }
}
