CC=clang++
CFLAG=-std=c++14 -Wall
CDFLAG=-std=c++14 -Wall -g
LD=clang++
LFLAG=

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
BIN_DIR =  bin
DEBUG_DIR = debug
DIR = ${OBJ_DIR} ${BIN_DIR} ${DEBUG_DIR}

SRC=$(wildcard ${SRC_DIR}/*.cpp)
BIN=${BIN_DIR}/$(notdir $(realpath .))
OBJ=$(addprefix ${OBJ_DIR}/, $(notdir ${SRC:.cpp=.o}))
OBJ_DEBUG = $(addprefix ${DEBUG_DIR}/, $(notdir ${SRC:.cpp=.o}))
OBJECT_DEBUG = ${DEBUG_DIR}/$(notdir $(realpath .))

all: dir ${BIN}

dir:
	mkdir -p ${DIR}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp
	-@echo "compiling ${?} -> ${@}"
	$(CC) $(CFLAG) -c -I ${INC_DIR} -o $@ $^

${BIN}: ${OBJ}
	-@echo "linking objects -> ${@}"
	$(LD) $(LFLAG) -o $@ ${OBJ_DIR}/*.o

debug: dir ${OBJECT_DEBUG}

${DEBUG_DIR}/%.o: ${SRC_DIR}/%.cpp
	-@echo "compiling ${?} -> ${@}"
	$(CC) $(CDFLAG) -c -I ${INC_DIR} -o $@ $^

${OBJECT_DEBUG}: ${OBJ_DEBUG}
	-@echo "linking objects -> ${@}"
	$(LD) $(LFLAG) -o $@ ${DEBUG_DIR}/*.o

clean:
	rm -rf ${DIR}

.PHONY: all dir debug clean
