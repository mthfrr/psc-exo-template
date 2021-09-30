CC=gcc
CFLAGS=-Wall -Wextra -Wall -pedantic -std=c99 -g

EX_F=test.c main.c
EXCLUDE=$(addprefix | grep -v , $(EX_F))

SRC=$(shell find . -name "*.c" $(EXCLUDE))

all:
	@echo "Usage (t | m)"
	@echo $(SRC)

t: test
	@./test_asan

m: main
	@./main_asan

test: test.c $(SRC)
	$(CC) $(CFLAGS) $^ -o test -lcriterion
	$(CC) $(CFLAGS) $^ -o test_asan -fsanitize=address -lcriterion

main: main.c $(SRC)
	$(CC) $(CFLAGS) $^ -o main
	$(CC) $(CFLAGS) $^ -o main_asan -fsanitize=address

.PHONY: clean

clean:
	$(RM) test
	$(RM) test_asan
	$(RM) main
	$(RM) main_asan
