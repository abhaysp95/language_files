// cpp file for "gen_sen_util.hpp"

#include "../inc/gen_sen_util.hpp"

#include <algorithm>
#include <stdexcept>
#include <cstdlib>  // srand, rand
#include <ctime>  // time

using namespace std;

vector<string>
split(const string& input_str)
{
	vector<string> ret{};
	string::const_iterator first{input_str.cbegin()}, second{input_str.cbegin()};
	while (first != input_str.cend()) {
		first = find_if(first, input_str.cend(), [](const char& c) {
				return !isspace(c);
				});
		second = find_if(first, input_str.cend(), [](const char& c) {
				return isspace(c);
				});
		if (first != input_str.cend()) {
			ret.push_back(string{first, second});
		}
		first = second;
	}
	return ret;
}

Grammer
read_grammer(istream& in)
{
	Grammer ret_grammer{};
	string get_rule{};

	while (getline(in, get_rule)) {
		Rule entry = split(get_rule);
		if (!entry.empty()) {
			// pushing Rule to Rules which will be the value for key(first entry)
			// pushed element could just be the single Rule instead of Rules, but the value will be of type Rules
			ret_grammer[entry.at(0)].push_back(Rule{entry.cbegin() + 1, entry.cend()});
		}
	}
	return ret_grammer;
}

vector<string>
gen_sentence(const Grammer& grammer)
{
	vector<string> ret_str{};
	// from Grammer 'g', start generating sentence from Rule "<sentence>" and concatenate(push_back) to ret_str
	gen_aux(grammer, "<sentence>", ret_str);
	return ret_str;
}

bool
is_rule(const string& str)
{
	// if <...>/<> then str is a rule, else just a word
	return str.size() >= 2 && str.at(0) == '<' && str.at(str.size() - 1) == '>';
}

void
gen_aux(const Grammer& grammer, const string& str, vector<string>& make_str)
{
	if (!is_rule(str)) {
		// if it's just a word
		make_str.push_back(str);
	}
	else {
		Grammer::const_iterator it = grammer.find(str);
		if (it == grammer.cend()) {
			throw logic_error("empty rule");
		}

		// get set of possible rule for that key
		const Rules& rules = it->second;

		// get random rule from rules
		//const Rule& rule = rules.at(rand() % rules.size());
		const Rule& rule = rules.at(nrand(rules.size()));

		for (Rule::const_iterator it = rule.cbegin(); it != rule.cend(); ++it) {
			gen_aux(grammer, *it, make_str);
		}
	}
}

// better randomization ?
size_t
nrand(size_t n)
{
	if (n <= 0 || n > RAND_MAX) {
		throw domain_error("Argument to nrand is out of range");
	}

	// bucket which will contain equal numbers
	const size_t bucket_size = RAND_MAX / n;

	size_t random{};

	do {
		random = rand() / bucket_size;
	} while (random >= n);
	return random;
}