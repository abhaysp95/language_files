CC     = clang
CFLAG  = -Wall -std=c99
CDFLAG = -Wall -std=c99 -g
LD     = clang
LFLAG  =

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
BIN_DIR = bin
DEBUG_DIR = debug
DIR = ${OBJ_DIR} ${BIN_DIR} ${DEBUG_DIR}

SRC = $(wildcard ${SRC_DIR}/*.c)
OBJ = $(addprefix ${OBJ_DIR}/, $(notdir ${SRC:.c=.o}))
BIN = ${BIN_DIR}/$(notdir $(realpath .))
DEBUG = $(addprefix ${DEBUG_DIR}/, $(notdir ${SRC:.c=.o}))
DEBUG_BIN = $(addprefix ${DEBUG_DIR}/, $(notdir $(realpath .)))

all: dir ${BIN}

dir:
	mkdir -p ${DIR}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	-@echo "compiling $? -> $@"
	$(CC) $(CFLAG) -I ${INC_DIR} -c -o $@ $^

${BIN}: ${OBJ}
	-@echo "Linking -> $@"
	$(LD) $(LFLAG) -o $@ ${OBJ_DIR}/*.o

debug: ${DEBUG_BIN}

${DEBUG_DIR}/%.o: ${SRC_DIR}/%.c
	-@echo "compiling $? -> $@"
	$(CC) $(CDFLAG) -I ${INC_DIR} -c -o $@ $^

${DEBUG_BIN}: ${DEBUG}
	-@echo "Linking -> $@"
	$(LD) $(LFLAG) -o $@ ${DEBUG_DIR}/*.o

clean:
	rm -rf ${DIR}

.PHONY: all dir debug clean
