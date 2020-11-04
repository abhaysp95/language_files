//#pragma once // pre-processor directive, this basically is header guard
//only include this file once, so basically, this file is just included once in one translation unit

//#ifndef LOG_H
//#define LOG_H

//void log(const char* msg);
//void initLog();

//#endif
//struct player{};

// so, if no "#pragma once" and we include this header file twice in a
// translation unit, we'll get error: redifination of 'struct player'



// there's another way for header guard, this will look for symbol _LOG_H, if
// it's not defined it'll put whole ifndef block syntax in translation unit

#ifndef _LOG_H
#define _LOG_H

void log(const char* msg);
void initLog();

struct player{};
#endif
