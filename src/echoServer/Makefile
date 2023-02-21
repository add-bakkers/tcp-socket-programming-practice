CC = gcc
CFLAGS = -O2 -Wall -Wextra -Werror -pedantic -std=c99 -Wno-sign-compare
SOURCES=TCPEchoServer.c ../DieWithError.c ../HandleTCPClient.c 
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=echoServer

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)