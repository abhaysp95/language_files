CC=clang++
CFLAG=-Wall -std=c++14

main: main.o
	$(CC) $(CFLAG) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAG) -c $^ -o $@

clean:
	rm -f *.o main
