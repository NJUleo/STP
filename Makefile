CFLAGS := -I./include

all: sender receiver

sender: ./src/sender.c
	gcc $(CFLAGS) -o sender ./src/sender.c ./src/pld.c

receiver: ./src/receiver.c
	gcc -I./include -o receiver ./src/receiver.c 

clean:
	rm sender
	rm receiver
