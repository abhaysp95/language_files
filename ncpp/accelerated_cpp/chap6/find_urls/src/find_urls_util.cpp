// cpp file for "find_urls_util.hpp"

#include "../inc/find_urls_util.hpp"

#include <algorithm>
#include <cctype>

vec_str find_urls(const std::string& url) {
	vec_str urls_vec;
	str_const_iter b = url.begin(), e = url.end();
	// look through entire input
	while (b != e) {
		// find one or more letters followed by ://
		b = url_beg(b, e);
		// if we found it
		if (b != e) {
			// get the rest of the url
			str_const_iter after = url_end(b, e);
			// remember the url
			urls_vec.push_back(std::string(b, after));
			// advance b and check for more urls in the line
			b = after;
		}
	}
	return urls_vec;
}

str_const_iter url_beg(str_const_iter b, str_const_iter e) {
	static const std::string sep = "://";
	str_const_iter i;
	// i marks where seperator was found
	i = b;
	while ((i = std::search(i, e, sep.begin(), sep.end())) != e) {
		// make sure seperator isn't at the begining or end of the line
		if (i != b) {
			// beg marks the begining of the protocol name
			str_const_iter beg = i;
			while (beg != b) {
				/** change from book, with this you can also parse urls, which
				 * doesn't start at the begining of lines */
				if (!not_url_char(*beg)) {
					beg--;
				}
				else {
					beg++;
					break;
				}
				/** change upto here */
			}
			// is there atleast one appropriate character before and after the seperator
			if (beg != i) {
				return beg;
			}
		}
		// the seperator we found wasn't the part of URL
		i += sep.size();
	}
	return e;
}

str_const_iter url_end(str_const_iter b, str_const_iter e) {
	// unless the character after seperator is not URL character predicate will not give true.
	return std::find_if(b, e, not_url_char);
}

bool not_url_char(char c) {
	static const std::string url_chars = "~!-_@/?:=;.%";
	// see whether c can appear in URL and return negative
	return !(isalnum(c) || std::find(url_chars.begin(), url_chars.end(), c) != url_chars.end());
}