# /* --- Makefile --- */

CC     = clang
CFLAG  = -Wall -std=c99
CDFLAG = -Wall -std=c99 -g
LD     = clang
LFLAG  = -lncurses
LDFLAG := ${LFLAG} -v


SRC_DIR   = src
OBJ_DIR   = obj
INC_DIR   = inc
BIN_DIR   = bin
DEBUG_DIR = debug
DIRS      = ${BIN_DIR} ${OBJ_DIR} ${DEBUG_DIR}


SRC       = $(wildcard ${SRC_DIR}/*.c)
OBJ       = $(addprefix ${OBJ_DIR}/, $(notdir ${SRC:.c=.o}))
BIN       = ${BIN_DIR}/$(notdir $(realpath .))
DEBUG_OBJ = $(addprefix ${DEBUG_DIR}/, $(notdir ${SRC:.c=.o}))
DEBUG_BIN = $(addprefix ${DEBUG_DIR}/, $(notdir $(realpath .)))


all: dir ${BIN}

dir:
	mkdir -p ${DIRS}


${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	-@echo "compiling $? -> $@"
	${CC} ${CFLAG} -I ${INC_DIR} -c -o $@ $^

${BIN}: ${OBJ}
	-@echo "Linking $? -> $@"
	${LD} ${LFLAG} -o $@ ${OBJ_DIR}/*.o
	-@echo "copied ${BIN} -> $(notdir $(realpath .))"
	cp -f ${BIN} .


debug: dir ${DEBUG_BIN}

${DEBUG_DIR}/%.o: ${SRC_DIR}/%.c
	-@echo "compiling $? -> $@"
	${CC} ${CDFLAG} -I ${INC_DIR} -c -o $@ $^

${DEBUG_BIN}: ${DEBUG_OBJ}
	-@echo "Linking to -> $@"
	${LD} ${LDFLAG} -o $@ ${DEBUG_DIR}/*.o


clean:
	rm -rf ${DIRS} $(notdir $(realpath .))

.SILENT:
.PHONY: all dir debug clean