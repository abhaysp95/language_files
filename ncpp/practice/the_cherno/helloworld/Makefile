CC=g++
CFLAGS=-Wall -std=c++14

hello_world: hello_world.o log.o
	$(CC) $(CFLAGS) -o $@ $^

hello_world.o: hello_world.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

log.o: log.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f hello_world hello_world.o log.o
