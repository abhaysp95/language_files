CC=clang
CFLAG=

all: bst_operation

bst_operation: main.c util.o
	$(CC) $(CFLAG) $^ -o $@

%.o: %.c
	$(CC) $(CFLAG) -c -o $@ $^

clean:
	rm -f *.o bst_operation
