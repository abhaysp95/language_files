
// task to perform
#define io(v) std::cin >> v
#define foreach(vec, i) for (int i = 0; i < vec.size(); ++i)
// #define INF INFINITY
#define INF (unsigned)!((int)0)
#define FUNCTION(fun, op) \
	void fun(int& current, int candidate) { \
		if (!(current op candidate))  { \
			current = candidate; \
		} \
	}
//#define FUNCTION(fun, op) inline void fun(int& current, int candidate) { !(current op candidate) ? current = candidate : false; }
#define toStr(gotStr) #gotStr

// inline function is just put there litterly in the place of calling with no modification


// declaration was not added in question, if using inline in the FUNCTION
// macro, then you don't need these
//void minimum(int, int);
//void maximum(int, int);



#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

	int main(){
		int n; cin >> n;
		vector<int> v(n);
		foreach(v, i) {
			io(v)[i];
		}
		int mn = INF;
		int mx = -INF;
		foreach(v, i) {
			minimum(mn, v[i]);
			maximum(mx, v[i]);
		}
		int ans = mx - mn;
		cout << toStr(Result =) <<' '<< ans;
		return 0;

	}
