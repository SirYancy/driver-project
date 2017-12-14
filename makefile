CC = gcc

CFLAGS = -pthread

OBJECTS = producer.o main.o

default: clean
default: driver

debug: CFLAGS += -g -o0
debug: clean
debug: driver

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

producer.o: producer.c
	$(CC) $(CFLAGS) -c producer.c -o producer.o

driver: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o driver


clean:
	rm -f *.o driver core
