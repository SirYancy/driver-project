CC = gcc

CFLAGS = -pthread

OBJECTS = consumer.o producer.o main.o

default: clean
default: driver

debug: CFLAGS += -g -o0
debug: clean
debug: driver

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

producer.o: producer.c
	$(CC) $(CFLAGS) -c producer.c -o producer.o

consumer.o: consumer.c
	$(CC) $(CFLAGS) -c consumer.c -o consumer.o

driver: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o driver


clean:
	rm -f *.o driver core
