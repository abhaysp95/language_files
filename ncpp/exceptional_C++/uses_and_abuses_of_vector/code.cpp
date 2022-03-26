#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <iterator>

using namespace std;

void f(vector<int>& v)
{
	v[0];  // no bound checking
	v.at(0);  // range check(throws std::out_of_range)
}

void f2()
{
	vector<int> v;
	v.reserve(2);
	assert(v.capacity() == 2);
	v[0] = 1;
	v[1] = 2;
	for(vector<int>::iterator i = v.begin(); i < v.end(); i++)
		cout << *i << " this " << endl;

	cout << v[0] << " t ";
	v.reserve(100);
	assert(v.capacity() == 100);
	cout << v[0] << " d ";

	v[2] = 3;
	v[3] = 4;
	v[4] = 5;
	v[5] = 6;
	v[6] = 7;
	v[7] = 8;
	v[8] = 9;
	v[9] = 10;
	v[10] = 11;
	v[11] = 12;
	v[12] = 13;
	v[13] = 14;
	v[14] = 15;
	v[15] = 16;
	v[16] = 17;
	v[17] = 18;
	v[18] = 19;
	v[19] = 20;
	v[20] = 21;
	v[21] = 22;
	v[22] = 23;
	v[23] = 24;
	v[24] = 25;
	v[25] = 26;
	v[26] = 27;
	v[27] = 28;
	v[28] = 29;
	v[29] = 30;
	v[30] = 31;
	v[31] = 32;
	v[32] = 33;
	v[33] = 34;
	v[34] = 35;
	v[35] = 36;
	v[36] = 37;
	v[37] = 38;
	v[38] = 39;
	v[39] = 40;
	v[40] = 41;
	v[41] = 42;
	v[42] = 43;
	v[43] = 44;
	v[44] = 45;
	v[45] = 46;
	v[46] = 47;
	v[47] = 48;
	v[48] = 49;
	v[49] = 50;
	v[50] = 51;
	v[51] = 52;
	v[52] = 53;
	v[53] = 54;
	v[54] = 55;
	v[55] = 56;
	v[56] = 57;
	v[57] = 58;
	v[58] = 59;
	v[59] = 60;
	v[60] = 61;
	v[61] = 62;
	v[62] = 63;
	v[63] = 64;
	v[64] = 65;
	v[65] = 66;
	v[66] = 67;
	v[67] = 68;
	v[68] = 69;
	v[69] = 70;
	v[70] = 71;
	v[71] = 72;
	v[72] = 73;
	v[73] = 74;
	v[74] = 75;
	v[75] = 76;
	v[76] = 77;
	v[77] = 78;
	v[78] = 79;
	v[79] = 80;
	v[80] = 81;
	v[81] = 82;
	v[82] = 83;
	v[83] = 84;
	v[84] = 85;
	v[85] = 86;
	v[86] = 87;
	v[87] = 88;
	v[88] = 89;
	v[89] = 90;
	v[90] = 91;
	v[91] = 92;
	v[92] = 93;
	v[93] = 94;
	v[94] = 95;
	v[95] = 96;
	v[96] = 97;
	v[97] = 98;
	v[98] = 99;
	v[99] = 100;
	for(vector<int>::iterator i = v.begin(); i < v.end(); i++)
		cout << *i << " that " << endl;
}

void f2_fixed() {
	vector<int> v;
	v.reserve(2);

	// now, there's the difference with reserve/capacity and resize/size, reserve just reserves the space(and didn't add element)

	assert(v.capacity() >= 2);
	// this is because, reserve(2) could reserve more or equal to 2, though this assertion is redundant and shouldn't be used(because the standard already guarantees what is here being used)
	v[0] = 1;
	v[1] = 2;  // again, this is not right

	for(vector<int>::const_iterator i = v.cbegin(); i < v.cend(); ++i)
		cout << *i << '\n';
	cout << endl;

	// you can either use 'copy', 'for_each' etc.(try to use available algorithm if possible)
	for_each(v.cbegin(), v.cend(), [](const int& i) {
			cout << i << '\n';
			});
	// or copy, like
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\n"));

	// rest are about same(read chapter for more info)
}

int main(int argc, char** argv)
{
	vector<int> vec{};
	vector<int> vec2(10, 0);
	f(vec2);
	f2();
	return 0;
}
