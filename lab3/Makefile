CC=g++
CFLAGS=-Wall -std=c++11 -g

OBJ = lab3.o

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

all: lab3

lab3: lab3.o
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	@rm -f *.o *~ lab3

me:
	@echo "I've been made!"

cake:
	@echo "The cake is a lie."