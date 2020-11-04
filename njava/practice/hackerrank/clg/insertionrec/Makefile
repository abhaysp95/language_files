JFLAGS = -g
JC = javac

.SUFFIXES: .java .class

.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
		  Solution.java

default: classes

classes: $(CLASSES:.java=.class)

# $(RM) is pre-defined with make(RM = rm -f)
clean:
	$(RM) *.class
