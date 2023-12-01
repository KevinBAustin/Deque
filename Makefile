CC=g++

CFLAGS=-g -Wall -Wextra

TARGET=deque

all:$(TARGET)

$(TARGET): main.o deque.o
	$(CC) $(CLFAGS) -o $(TARGET) main.o deque.o

main.o: main.cpp deque.h
	$(CC) $(CFLAGS) -c main.cpp

deque.o: deque.cpp deque.h
	$(CC) $(CFLAGS) -c deque.cpp

clean:
	$(RM) $(TARGET) *.o *~
