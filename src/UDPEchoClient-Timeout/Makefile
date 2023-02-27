CC = gcc
CFLAGS = -O2 -Wall -Wextra 
SOURCES=UDPEchoClient-Timeout.c ../DieWithError.c 
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=$(SOURCES:.c=)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)