# Detecting OS
UNAME_S=$(shell uname -s)
ifeq ($(UNAME_S),Linux)
    CC=g++-4.8
else
    ifeq ($(UNAME_S),Darwin)
        CC=g++-4.8
    else
        CC=g++
    endif
endif

# compiler flags for debug
CPPFLAGS=-std=c++11 -Wall -g -DDEBUG

# compiler flags for release. treat warnings as errors and also optimize code.
# CPPFLAGS=-std=c++11 -Werror=all -O2 

# folder for source code
SRC_DIR=src
# folder for header files
HEADER_DIR=header
# folder for generated object files
OBJ_DIR=obj

# all objects in a variable. The makefile automatically figures out 
# all object files based on source files in SRC_DIR directory.
# If you replicate this also for header files, it'll be one smart makefile ;)
_OBJS=$(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(wildcard $(SRC_DIR)/*.cpp))
OBJS=$(patsubst %.cpp,%.o,$(_OBJS))

# name of the binary
all: lab4

# First we map every source code to its object file.
# We do this separately for each source file to better identify the header dependency.

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(HEADER_DIR)/BoundedList.h $(OBJ_DIR)/.dirstamp $(HEADER_DIR)/BoundedListImpl.h
	$(CC) -c $< -o $@ $(CPPFLAGS) -I${HEADER_DIR}/

$(OBJ_DIR)/Data.o: $(SRC_DIR)/Data.cpp $(HEADER_DIR)/Data.h $(OBJ_DIR)/.dirstamp
	$(CC) -c $< -o $@ $(CPPFLAGS) -I${HEADER_DIR}/

# Now it's time to link both objects. No need for -I argument anymore.
lab4: $(OBJS)
	${CC} $^ -o $@ ${CPPFLAGS}

# this rule insures the obj directory exist or it'll create it.
$(OBJ_DIR)/.dirstamp:
	-@mkdir -p $(OBJ_DIR) && touch $@

# Memory check rule. Depends on a fresh binary.
.PHONY: memcheck
memcheck: lab4
	valgrind --tool=memcheck ./$<

# The clean rule
.PHONY: clean
clean:
	-@rm ${OBJ_DIR}/*.o lab4 *~ $(SRC_DIR)/*~ $(HEADER_DIR)/*~ 2>/dev/null || true
