# /*- Makefile -*/


.SILENT:
.PHONY: all dir clean help

CC    = clang
CFLAG = -Wall -std=c99
LD    = clang
LFLAG =

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = inc
DIRS = ${BIN_DIR} ${OBJ_DIR}

BIN = ${BIN_DIR}/$(notdir $(realpath .))
SRC = $(wildcard ${SRC_DIR}/*.c)
OBJ = $(addprefix ${OBJ_DIR}/, $(notdir ${SRC:.c=.o}))

all: dir ${BIN}

dir:
	mkdir -p ${DIRS}


# ${OBJ}: ${SRC}  # this can't work,
# it's mulitple output file at once, while below one is one at a time,
# see %

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	-@echo "compiling ${?} -> ${@}"
	$(CC) ${CFLAG} -I ${INC_DIR} -c -o $@ $^  # $? is same to $^, check
	# -I adds directory to include search path


${BIN}: ${OBJ}
	-@echo "Linking objects -> ${@}"
	${LD} ${LFLAG} -o $@ ${OBJ_DIR}/*.o

clean:
	rm -rf ${DIRS}

help:
	-@echo "source -> ${SRC}"
	-@echo "objects -> ${OBJ}"
	-@echo "binaries -> ${BIN}"

# also if using SILENT:  you can choose to not to use -@
