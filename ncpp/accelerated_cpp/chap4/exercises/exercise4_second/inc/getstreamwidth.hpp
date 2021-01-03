// header file

#ifndef _GUARD_GETSTREAMWIDTH_HPP_
#define _GUARD_GETSTREAMWIDTH_HPP_

#include <iomanip>

std::streamsize get_stream_width(double number);
std::streamsize get_stream_width(double number, const std::streamsize& num_decimals);

#endif