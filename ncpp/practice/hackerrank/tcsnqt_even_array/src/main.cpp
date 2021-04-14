// main file

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
	string input{};
	cin >> input;
	cout << "input: " << input << '\n';
	size_t count{};
	for (string::iterator iter = input.begin(); iter <= input.end(); ++iter) {
		if ((iter + 2) < input.end()) {
			if (*iter == 'O' && *(iter + 1) == 'O' && *(iter + 2) == 'O') {
				while ((*iter == 'O') && (iter != input.end())) {
					*iter = 'E';
					iter++;
				}
				count++;
			}
		}
		if (*iter == 'O') {
			*iter = *(iter + 1) = 'E';
			count++;
			iter++;
		}
	}
	cout << count << endl;
	return 0;
}

/**
Question:
  You are given an array A of N integers. You need to make all the elements of
  the array even. Now, to make an element even, you can add 1 to any element of
  the array. Also, when any element of the array is converted to even, any
  neighbouring element which is odd, can also be made even without adding 1
  yourself. For example, 4,5,7,6 If you add 1 to 2nd element, i.e. 5, the
  neighbouring 7 can also be made even without adding anything. To make it easy
  for you, the array is given in the form of a string S( of length N ) of O's
  and E's, where O stands for "odd" integer and E stands for "even" integer.
  Find the minimum number of 1's you need to add in order to make the array
  even.

Logic:
  Twist in the question is that, say there are 'OOOO', so you answer would not
  be 2(because you'll change O at 1 to E and the O at 0 and 2 will become E too
  and then you'll change O at 2, so total 2 changes), but if you change O at 1
  it'll change O at 0 and 2 too and since O at 2 is changed to E, it's
  neighbour(which is O at 3) will also change to E, so you should get only 1 as
  count
  */