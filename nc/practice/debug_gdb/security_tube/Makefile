CC=gcc
CFLAG=-Wall -lm -std=c99


default: main

main: main.o
	$(CC) $(CFLAG) -o $@ $<

%.o: %.c
	$(CC) $(CFLAG) -c -o $@ $<

main_with_debug: main.c
	$(CC) $(CFLAG) -g -o $@ $<

.PHONY: clean

clean:
	rm -f *.o main main_with_debug
