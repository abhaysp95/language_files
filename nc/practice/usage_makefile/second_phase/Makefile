objects=a.o b.o c.o d.o  # implicit

multi_prog: multi.c $(objects)
	clang multi.c $(objects) -o multi_prog

clean:
	rm -r *.o; rm -f multi_prog
