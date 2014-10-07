# Detecting OS
UNAME_S=$(shell uname -s)
ifeq ($(UNAME_S),Linux)
    CC=g++-4.8
    GTEST_LL=-I /usr/local/opt/gtest/include/ -lgtest_main -lpthread
else
    ifeq ($(UNAME_S),Darwin)
        CC=g++
        GTEST_LL=-I /usr/local/opt/gtest/include/ -L /usr/local/opt/gtest/lib/ -lgtest_main -lgtest -lpthread
    else
        CC=g++
        GTEST_LL=-I /usr/local/opt/gtest/include/ -L /usr/local/lib/ -lgtest_main -lgtest -lpthread
    endif
endif

# Directories
SRC_DIR = code
HEADER_DIR = lib
BIN_DIR = bin
TEST_DIR = test

# Test Cases
_TEST_CASES=$(patsubst $(TEST_DIR)/%,$(BIN_DIR)/%,$(wildcard $(TEST_DIR)/*.cpp))
TEST_CASES=$(patsubst %.cpp,%.test.o,$(_TEST_CASES))

# Compiler flags
CPPFLAGS = -Wall -g -I$(HEADER_DIR) -I$(SRC_DIR) -std=c++11
GTEST_CPPFLAGS = -Wall -g -I$(HEADER_DIR) -I$(SRC_DIR) -Wextra -pthread -std=gnu++0x

# Rules for the actual program

all: $(BIN_DIR)/StackGame
	-@echo "--- All Built!---"

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/StackGame.h $(HEADER_DIR)/* $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c $< -o $@
	
$(BIN_DIR)/StackGame: $(BIN_DIR)/StackGame.o $(BIN_DIR)/ui.o
	$(CC) $(CPPFLAGS) $^ -o $@

# Rules for compiling and running all test cases in 'test folder'

$(BIN_DIR)/%.test.o: $(TEST_DIR)/%.cpp $(SRC_DIR)/* $(HEADER_DIR)/* $(BIN_DIR)/.dirstamp
	$(CC) $(GTEST_CPPFLAGS) $(GTEST_LL) -c $< -o $@

$(BIN_DIR)/GameTest: $(TEST_CASES) $(BIN_DIR)/StackGame.o
	$(CC) $(GTEST_CPPFLAGS) $^ $(GTEST_LL) -o $@

# Rule to ensure the $(BIN_DIR) directory exist or it'll create it.
$(BIN_DIR)/.dirstamp:
	-@mkdir -p $(BIN_DIR) && touch $@

# Phoney targets
.PHONY: clean
.PHONY: tests

tests: $(BIN_DIR)/GameTest
	-@$(BIN_DIR)/GameTest
	-@echo "--- All Tested!---"
	
clean:
	-@rm -rf $(BIN_DIR)
	-@echo "--- All Clean!---"
