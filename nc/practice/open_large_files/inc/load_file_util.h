#ifndef _LOAD_FILE_UTIL_H_
#define _LOAD_FILE_UTIL_H_

#include <stdio.h>

static const size_t STEPSIZE = 100;

char** load_file1(char* filename, size_t* len);
char** load_file2(char* filename, size_t* len);
char** load_file3(char* filename);

#endif
