CC=clang
CFlAGS=

all: countsort

countsort: main.c util.o
	$(CC) $(CFlAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFlAGS) -c $^ -o $@

clean:
	rm -f countsort *.o
