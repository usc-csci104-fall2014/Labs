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

#Directories
SRC_DIR = src
HEADER_DIR = header
BIN_DIR = bin
LIST_LIB = $(HEADER_DIR)/array* $(HEADER_DIR)/linked* $(HEADER_DIR)/plus* $(HEADER_DIR)/ilist*

#Compiler flags
CPPFLAGS = -Wall -g -I$(HEADER_DIR) -std=c++11

#Phoney targets
.PHONY: clean

all: $(BIN_DIR)/arraylist_test $(BIN_DIR)/speed_test $(BIN_DIR)/boolean
	-@echo "--- All Built!---"

$(BIN_DIR)/arraylist_test: $(BIN_DIR)/.dirstamp $(SRC_DIR)/arraylist_test.cpp $(LIST_LIB)
	$(CC) $(CPPFLAGS) $(SRC_DIR)/arraylist_test.cpp -o $(BIN_DIR)/arraylist_test

$(BIN_DIR)/speed_test: $(BIN_DIR)/.dirstamp $(SRC_DIR)/speed_test.cpp $(LIST_LIB)
	$(CC) $(CPPFLAGS) $(SRC_DIR)/speed_test.cpp -o $(BIN_DIR)/speed_test

$(BIN_DIR)/boolean: $(BIN_DIR)/.dirstamp $(SRC_DIR)/boolean.cpp $(HEADER_DIR)/map* $(HEADER_DIR)/stack* $(HEADER_DIR)/linked*
	$(CC) $(CPPFLAGS) $(SRC_DIR)/boolean.cpp -o $(BIN_DIR)/boolean

# Rule to ensure the $(BIN_DIR) directory exist or it'll create it.
$(BIN_DIR)/.dirstamp:
	-@mkdir -p $(BIN_DIR) && touch $@

clean:
	-@rm -rf $(BIN_DIR)
	-@rm -r html
	-@rm *.doxy
	-@echo "--- All Clean!---"
