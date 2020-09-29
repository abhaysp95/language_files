
CC=clang
CFLAGS=

all: testmain

testmain: main.c util.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f tesmain *.o
