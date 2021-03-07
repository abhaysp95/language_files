// main file

#include <iostream>
#include <regex>
#include <string>

/** without iterator */
void print_matches(std::string& str, const std::regex& reg) {
	std::smatch matches;
	std::cout << std::boolalpha;  // print boolean(intead of number)
	while (std::regex_search(str, matches, reg)) {
		std::cout << "Is there any match: " << matches.ready() << "\n";
		std::cout << "Are there no match: " << matches.empty() << "\n";
		std::cout << "Number of matches: " << matches.size() << "\n";
		std::cout << matches.str(1) << "\n";
		str = matches.suffix().str();  // eliminate previous match
		std::cout << "\n";
	}
	std::cout << std::endl;
}

/** with iterator */
void print_matches2(const std::string& str, const std::regex& reg) {
	std::sregex_iterator currentMatch(str.begin(), str.end(), reg);
	std::sregex_iterator lastMatch;
	std::smatch matches;
	while (currentMatch != lastMatch) {
		matches = *currentMatch;
		std::cout << matches.str() << "\n";
		currentMatch++;
	}
	std::cout << std::endl;
}

int main(int argc, char **argv) {
	std::string str = "The ape was at the apex";
	std::regex reg("(ape[^ ]?)");
	print_matches(str, reg);
	std::string str2 = "I picked the pickle";
	std::regex reg2("(pick([^ ]+)?)");
	print_matches2(str2, reg2);

	// replace the match
	std::string str3 = "Cat rat mat fat pat";
	std::regex reg3("([Cr]at)");
	std::string owl_food = std::regex_replace(str3, reg3, "owl-food");
	std::cout << owl_food << "\n\n";
	std::string str4 = "F.B.I. I.R.S. CIA";
	std::regex reg4(R"([^ ]\..\..\.)");  // use raw string(R"") for regex
	print_matches2(str4, reg4);
	std::string str5 = "12345";
	std::regex reg5(R"(\d+)");
	print_matches2(str5, reg5);
	std::string str6 = "133 12345 1345 1234235";
	std::regex reg6(R"(\d{5,7})");
	std::string str7 = "1920 1945 1919 1982 2002 2000 2020";
	std::regex reg7(R"(^19[2-9][0-9]|200[0-2])");
	print_matches2(str7, reg7);
	std::string str8 = "150cm 60in 167cm 59in 138 145cm 23 210cm 78in 193cm 76in";
	std::regex reg8(R"((1[5-8][0-9]|19[0-3])cm|(59|6[0-9]|7[0-6])in)");
	print_matches2(str8, reg8);
	std::string str9 = "#abd234 234390 #282cedf #d90gad #ebdbb2";
	std::regex reg9(R"(#([a-f0-9A-F]){6})");
	print_matches2(str9, reg9);
	std::string str10 = "amb gtb blu brn stv gry grn dts hzl oth";
	std::regex reg10(R"(amb|g(ry|rn)|b(lu|rn)|hzl|oth)");
	print_matches2(str10, reg10);
	std::string str11 = "0000000009 000234430 00234290234 023490423 342094439";
	std::regex reg11(R"((^|\s)\d{9}(\s|$))");
	print_matches2(str11, reg11);
	return 0;
}