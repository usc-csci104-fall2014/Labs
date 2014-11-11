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

#Directories
SRC_DIR = ???
LIB_DIR = ???
BIN_DIR = ???
OBJ_DIR = ???
TEST_DIR = ???
LIST_SRC_I = $(wildcard $(SRC_DIR)/*.cpp)
LIST_SRC = $(filter-out %main.cpp ???, $(LIST_SRC_I))
LIST_OBJ_I = $(LIST_SRC:.cpp=.o)
LIST_OBJ = $(subst $(???_DIR),$(???_DIR),$(LIST_OBJ_I))

# Test Cases
_TEST_CASES=$(patsubst $(TEST_DIR)/%,$(BIN_DIR)/%,$(wildcard $(TEST_DIR)/*.cpp))
TEST_CASES=$(patsubst %.cpp,%.test.o,$(_TEST_CASES))

#Compiler flags
CPPFLAGS = -Wall -g -I$(???_DIR) -std=c++11
GTEST_CPPFLAGS = -Wall -g -I$(???_DIR) -I$(SRC_DIR) -Wextra -pthread -std=gnu++0x

#Phony targets
.PHONY: clean
.PHONY: tests

all: $(BIN_DIR)/executable
	-@echo "--- All Built!---"


$(BIN_DIR)/executable: $(SRC_DIR)/myMain.cpp $(LIST_OBJ) $(BIN_DIR)/.dirstamp 
	$(CC) $(CPPFLAGS) $(filter-out $(BIN_DIR)/.dirstamp, $^) -o $@

$(OBJ_DIR)/foo.o: $(SRC_DIR)/foo.cpp $(OBJ_DIR)/.dirstamp 
	$(CC) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)/bar.o: $(SRC_DIR)/bar.cpp $(OBJ_DIR)/.dirstamp 
	$(CC) $(CPPFLAGS) -c $< -o $@

# Rules for compiling and running all test cases in 'test folder'

$(BIN_DIR)/%.test.o: $(TEST_DIR)/%.cpp $(SRC_DIR)/* $(OBJ_DIR)/* $(BIN_DIR)/.dirstamp
	$(CC) $(GTEST_CPPFLAGS) $(GTEST_LL) -c $< -o $@

$(BIN_DIR)/MyTest: $(TEST_CASES) $(LIST_OBJ)
	$(CC) $(GTEST_CPPFLAGS) $^ $(GTEST_LL) -o $@

# Rule to ensure the $(BIN_DIR) directory exist or it'll create it.
$(BIN_DIR)/.dirstamp:
	-@mkdir -p $(BIN_DIR) && touch $@
$(OBJ_DIR)/.dirstamp:
	-@mkdir -p $(OBJ_DIR) && touch $@

tests: ???
	-@???
	-@echo "--- All Tested!---"

clean:
	-@rm -rf $(BIN_DIR)
	-@rm -rf $(OBJ_DIR)
	-@echo "--- All Clean!---"
