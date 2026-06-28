# c-algorithms Makefile
CC      = gcc
CFLAGS  = -std=c99 -Wall -Wextra -Wpedantic -O2 -Iinclude
LDFLAGS = -lm

SRC     = src/sort.c src/search.c
OBJ     = $(SRC:.c=.o)
LIB     = libcalgorithms.a

DEMO_SRC = examples/demo.c
DEMO_BIN = build/demo

TEST_SRC = tests/test_calgorithms.c
TEST_BIN = build/test_calgorithms

.PHONY: all clean test demo

all: $(LIB)

$(LIB): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

demo: $(DEMO_BIN)

$(DEMO_BIN): $(DEMO_SRC) $(LIB)
	@mkdir -p build
	$(CC) $(CFLAGS) -Iinclude $< -L. -lcalgorithms $(LDFLAGS) -o $@

test: $(TEST_BIN)

$(TEST_BIN): $(TEST_SRC) $(LIB)
	@mkdir -p build
	$(CC) $(CFLAGS) -Iinclude $< -L. -lcalgorithms $(LDFLAGS) -o $@
	./$(TEST_BIN)

clean:
	rm -f $(OBJ) $(LIB)
	rm -rf build

run-demo: demo
	./$(DEMO_BIN)