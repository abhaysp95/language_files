CC=clang++
CFLAG=-Wall -std=c++14

main: main.o cube.o
	$(CC) $(CFLAG) -o $@ $^

cube.o: uiuc/cube.cpp
	$(CC) $(CFLAG) -c -o $@ $<

%.o: %.cpp
	$(CC) $(CFLAG) -c -o $@ $<

clean:
	rm -f *.o main
