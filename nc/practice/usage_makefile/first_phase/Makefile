#default: hello

# works implicit because, target name is also file and pre-requisite is same file name present here
#hello: hello.c
	#cc hello.c -o hello  # this line is explicit


# let's look at default target

# hello:  # implicit rule "cc hello.c -o hello" is executed

#func.o:  # implicit compiling "cc -c -o func.o func.c"


# hello: hello.c func.o  # implicit rule for func.o and hello.c
# cc -c -o func.o func.c
# cc hello.c func.c -o hello
hello: hello.c func.o
	clang hello.c func.o -o our_program

func.o: func.c func.h
	clang -c func.c -o func.o
# we actually don't need to this explicitly for func.o

# now, since clean is not first target it'll not automatically be executed
clean:
	rm *.o; rm our_program
# to explicitly run target from Makefile, do `make target_name`
