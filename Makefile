CC=gcc
CFLAGS=-g -Wall -Wextra
SRC_DIR=src
OBJ_DIR=obj
BIN_DIR=bin
SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
BIN=$(BIN_DIR)/chess-mini0.1
TEST_DIR=tests
TESTS=$(wildcard $(TEST_DIR)/*.c)
TEST_OBJS=$(subst $(OBJ_DIR)/main.o,,$(OBJS))
TEST_BIN_DIR=$(TEST_DIR)/bin
TEST_BIN=$(patsubst $(TEST_DIR)/%.c, $(TEST_BIN_DIR)/%, $(TESTS))
TEST_LINK=-lcriterion

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	
$(TEST_BIN_DIR)/%: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) $< $(TEST_OBJS) -o $@ $(TEST_LINK)


test: $(TEST_BIN)
	for test in $(TEST_BIN) ; do ./$$test ; done

clean:
	rm $(OBJ_DIR)/*.o $(BIN_DIR)/* $(TEST_BIN_DIR)/*

