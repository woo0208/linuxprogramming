
CC = gcc
CFLAGS = -g -Wall
OBJS = main.o mylib.o
TARGET = adder

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c mylib.h
	$(CC) $(CFLAGS) -c main.c

mylib.o: mylib.c mylib.h
	$(CC) $(CFLAGS) -c mylib.c

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)
