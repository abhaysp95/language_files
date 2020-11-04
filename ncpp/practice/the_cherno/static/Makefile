CC=clang++
CFLAGS=-Wall -std=c++14

main: main.o static.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

clean:
	rm -f *.o main
