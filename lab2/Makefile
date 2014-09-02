CC=g++
CFLAGS= -std=c++11 -ggdb

all: shape1 shape2

shape.o: shape.cpp shape.h
	$(CC) -c -o shape.o shape.cpp $(CFLAGS)

shape1.o: shape1.cpp shape.o
	$(CC) -c -o shape1.o shape1.cpp $(CFLAGS)

shape2.o: shape2.cpp shape.o
	$(CC) -c -o shape2.o shape2.cpp $(CFLAGS)

shape1: shape1.o shape.o
	$(CC) -o shape1 shape1.o shape.o $(CFLAGS)

shape2: shape2.o shape.o
	$(CC) -o shape2 shape2.o shape.o $(CFLAGS)

clean:
	rm -f *.o *~ shape1 shape2

