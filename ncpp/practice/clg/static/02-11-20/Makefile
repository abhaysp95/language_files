CC=clang++
CFLAG=-Wall -std=c++14

main: main.o util.o
	$(CC) $(CFLAG) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAG) -c -o $@ $^

main_debug: main.cpp util.cpp
	$(CC) $(CFLAG) -g -o $@ $^

clean:
	rm -f *.o main main_debug
