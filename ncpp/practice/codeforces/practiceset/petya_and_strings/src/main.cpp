// main file

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
	/* short status{};
	char str1[100], str2[100];
	scanf("%s %s", str1, str2);
	for (size_t i = 0; i < 100; ++i) {
		// both strings will have same length
		if (str1[i] != '\0') {
			// change to lowercase
			str1[i] = str1[i] >= 97 ? str1[i] - 32 : str1[i];
			str2[i] = str2[i] >= 97 ? str2[i] - 32 : str2[i];
			if (*(str1 + i) > *(str2 + i)) {
				status = 1;
				break;
			}
			else if (*(str1 + i) < *(str2 + i)) {
				status = -1;
				break;
			}
		}
	} */
	string s1{}, s2{};
	cin >> s1 >> s2;
	transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
	int status = s1.compare(s2);
	cout << (status != 0 ? ((status > 0) ? 1 : -1) : 0) << endl;
	return 0;
}