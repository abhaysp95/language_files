CC=g++
CFLAGS=-Wall -std=c++14

main: main.o initLog.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f *.o main
