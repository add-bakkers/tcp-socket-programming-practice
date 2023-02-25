CC = gcc
CFLAGS = -O2 -Wall -Wextra 
SOURCES=TCPEchoClient.c ../DieWithError.c ../HandleTCPClient.c 
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=$(SOURCES:.c=)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)