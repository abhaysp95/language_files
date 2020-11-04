# /*- Makefile -*/

.SILENT:
.PHONY: all dir debug clean help

CC    = clang
CFLAG = -std=c99
CDFLAG = -Wall -std=c99 -g
LD    = clang
LFLAG =

SRC_DIR = src
OBJ_DIR = obj
OBJD_DIR = debug
BIN_DIR = bin
INC_DIR = inc
DIRS = ${BIN_DIR} ${OBJ_DIR} ${OBJD_DIR}

BIN = ${BIN_DIR}/$(notdir $(realpath .))
SRC = $(wildcard ${SRC_DIR}/*.c)
OBJ = $(addprefix ${OBJ_DIR}/, $(notdir ${SRC:.c=.o}))
OBJ_DEBUG = $(addprefix ${OBJD_DIR}/, $(notdir ${SRC:.c=.o}))
OBJECT_DEBUG = ${OBJD_DIR}/$(notdir $(realpath .))

all: dir ${BIN}

dir:
	mkdir -p ${DIRS}


${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	-@echo "compiling ${?} -> ${@}"
	$(CC) ${CFLAG} -I ${INC_DIR} -c -o $@ $^  # $? is same to $^, check
	# -I adds directory to include search path


${BIN}: ${OBJ}
	-@echo "Linking objects -> ${@}"
	${LD} ${LFLAG} -o $@ ${OBJ_DIR}/*.o


debug: dir ${OBJECT_DEBUG}

${OBJD_DIR}/%.o: ${SRC_DIR}/%.c
	-@echo "compiling with debug ${?} -> ${@}"
	$(CC) ${CDFLAG} -I ${INC_DIR} -c -o $@ $^

${OBJECT_DEBUG}: ${OBJ_DEBUG}
	$(LD) ${LFLAG} -o $@ ${OBJD_DIR}/*.o

clean:
	rm -rf ${DIRS}

help:
	-@echo "source -> ${SRC}"
	-@echo "objects -> ${OBJ}"
	-@echo "object debug -> ${OBJ_DEBUG}"
	-@echo "binaries -> ${BIN}"

# also if using SILENT:  you can choose to not to use -@
