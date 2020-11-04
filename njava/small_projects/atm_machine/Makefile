# /* - Makefile - */

.PHONY: all dir clean

CC    = javac
CFLAG = -d
CDFLAG = -g -d

SRC_DIR = src
PACKAGE = com/atm_machine
BIN_DIR = bin
DEBUG_DIR = debug
DIRS = ${BIN_DIR} ${DEBUG_DIR}


SRC = $(wildcard ${SRC_DIR}/${PACKAGE}/*.java)
CLASSES = $(notdir ${SRC:.java=.class})

all: dir compile

dir:
	mkdir -p ${DIRS}

compile: ${SRC}
	$(CC) $(CFLAG) ${BIN_DIR} ${SRC_DIR}/${PACKAGE}/*.java

debug: ${DIR} ${SRC}
	$(CC) $(CDFLAG) ${DEBUG_DIR} ${SRC_DIR}/${PACKAGE}/*.java

tags:
	ctags -R -f tags .

clean:
	rm -rf ${DIRS}

help:
	-@echo "Sources: ${SRC}"
	-@echo "Classes: ${CLASSES}"
