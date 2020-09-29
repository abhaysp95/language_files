
# hierarichal nesting


objects=a.o b.o c.o d.o b_nested.o
# objects file will be compiled implicitly here(so, that means while creating
# variable object files given above are implicitly compiled ?)

nested: nested.c $(objects)
	clang $^ -o $@

clean:
	rm *.o; rm -f nested
