# Detecting OS
CC=g++

#Compiler flags
CPPFLAGS=-std=c++11 -Wall -g

#Directories
SRC_DIR=src
HEADER_DIR=header
BIN_DIR=bin

#Phony targets
.PHONY: clean ccversion

all: $(BIN_DIR)/shapes $(BIN_DIR)/rectangle $(BIN_DIR)/triangle

$(BIN_DIR)/shapes: $(BIN_DIR)/.dirstamp $(SRC_DIR)/main.cpp $(HEADER_DIR)/*.h $(HEADER_DIR)/*.hpp
	$(CC) $(SRC_DIR)/main.cpp -o $@ $(CPPFLAGS) -I$(HEADER_DIR)/

$(BIN_DIR)/rectangle: $(BIN_DIR)/.dirstamp $(SRC_DIR)/rectangle.cpp $(HEADER_DIR)/rectangle.h $(HEADER_DIR)/rectangleImpl.hpp
	$(CC) $(SRC_DIR)/rectangle.cpp -o $@ $(CPPFLAGS) -I$(HEADER_DIR)/

$(BIN_DIR)/triangle: $(BIN_DIR)/.dirstamp $(SRC_DIR)/triangle.cpp $(HEADER_DIR)/triangle.h $(HEADER_DIR)/triangleImpl.hpp
	$(CC) $(SRC_DIR)/triangle.cpp -o $@ $(CPPFLAGS) -I$(HEADER_DIR)/

# Rule to ensure the $(BIN_DIR) directory exist or it'll create it.
$(BIN_DIR)/.dirstamp:
	-@mkdir -p $(BIN_DIR) && touch $@

#Check $(CC) version
ccversion:
	@$(CC) --version

#The clean rule
clean:
	-@rm -Rf $(BIN_DIR)
