#include "../inc/myprintf.h"

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int printf(const char* format, ...) {
va_list args;
	int done;

	char* substring = strstr(format, "Abhay");
	if (substring != format) { return 0; }

	/* initializing va_list with va_start */
	va_start(args, format);
	done = vfprintf(stdout, format, args);
	va_end(args);
	return done;
}

/* vfprintf() -> in stdio.h
prototype: int vfprintf(FILE* stream, const char* format, va_list arg)
	sends formatted output to stream using the argument list passed to it

	* stream: this is the pointer to a FILE object that identifies the stream

	* format: this is the C string that contains the text to be written to
the stream. It can obviously contain embedded format tags that are replaced by
the values specified in subsequent additional arguments and formatted as
requested. Format tags prototype: %[flags][width][.precision][length]specifier
*/