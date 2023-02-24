CC = gcc
CFLAGS = -O2 -Wall -Wextra -Werror -pedantic -std=c99 -Wno-sign-compare
SOURCES=UDPEchoServer.c ../DieWithError.c 
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=$(SOURCES:.c=)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)