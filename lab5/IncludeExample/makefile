CC=g++

# compiler flags for debug
CPPFLAGS=-std=c++11 -Wall -g -DDEBUG

# name of the binary
all: lab5example

# First we map every source code to its object file.
# We do this separately for each source file to better identify the header dependency.

A.o: A.cpp A.h
	$(CC) -c $< -o $@ $(CPPFLAGS)

B.o: B.cpp B.h
	$(CC) -c $< -o $@ $(CPPFLAGS)
#Why not $(CC) -c $^ -o $@ $(CPPFLAGS)?

LabExample.o: LabExample.cpp
	$(CC) -c $< -o $@ $(CPPFLAGS)

# Now it's time to link both objects.
lab5example: LabExample.o A.o B.o
	${CC} $^ -o $@ ${CPPFLAGS}

# Memory check rule. Depends on a fresh binary.
.PHONY: memcheck
memcheck: lab5example
	valgrind --tool=memcheck ./$<

# The clean rule
.PHONY: clean
clean:
	-@rm *.o lab5example
