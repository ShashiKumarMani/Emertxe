CC = gcc
SOURCES = file.c udp.c tftp.c

all: client server

server:
	$(CC) server.c $(SOURCES) -o server
client: 
	$(CC) client.c $(SOURCES) -o client

clean:
	rm client
	rm server

