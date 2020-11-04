JFLAGS = -g -d
BINPATH = src/bin
CLASSPATH = ".:./src/bin"
MAIN = ChainRunner

all:
	@-mkdir -p $(BINPATH)
	@-javac $(JFLAGS) $(BINPATH) src/*.java
	@-java -cp $(CLASSPATH) $(MAIN)

run: ./src/bin
	@javac $(JFLAGS) $(BINPATH) src/*.java
	@-java -cp $(CLASSPATH) $(MAIN)

clean: ./src/bin
	@rm $(BINPATH)/*
	@rmdir $(BINPATH)
