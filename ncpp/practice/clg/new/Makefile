main: main.o
	clang++ -Wall -std=c++14 $^ -o $@

%.o: %.cpp
	clang++ -Wall -std=c++14 -c $^ -o $@

clean:
	rm -f *.o main
