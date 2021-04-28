// main file

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcomment"

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define lD long double
#define PI 3.1415926535897932384626
#define INF 1e9
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repl(i, n) for (ll i = 0; i < (ll)n; i++)
#define repd(i, n) for (int i = n - 1; i >= 0; i--)
#define repld(i, n) for (ll i = n - 1; i >= 0; i--)
#define loop(i,a,b) for (int i = (int)a; i < (int)b; i++)
#define rloop(i,a,b) for (int i = (int)a; i <= (int)b; i++)
#define loopl(i,a,b) for (ll i = (ll)a; i < (ll)b; ++i)
#define rloopl(i,a,b) for (ll i = (ll)a; i <= (ll)b; ++i)
#define loopd(i,a,b) for (int i = (int)a; i > b; i--)
#define rloopd(i,a,b) for (int i = (int)a; i >= b; i--)
#define loopld(i,a,b) for (ll i = (ll)a; i > b; i--)
#define rloopld(i,a,b) for (ll i = (ll)a; i >= b; i--)
#define wl (t) while(t--)
#define pb push_back
#define eb emplace_back
#define ab(a) (a < 0)?(-1*a):a
#define mset(a,b,c) loop(i,0,b) a[i]=c
#define asum(a,b,c) { int i = 0; c = 0; repd(i, b) c+=a[(i)]; }
#define fe first
#define se second
#define mp make_pair
#define clr(x) x.clear()
#define itoc(c) ((char)(((int)'0')+c))
#define all(p) p.begin(),p.end()
#define rall(p) (p).rbegin(),(p).rend()
#define tr(c,it) for(__typeof__((c)).begin() it = (c).begin(); it != (c).end(); it++)
#define trr(c,it) for(__typeof__((c)).rbegin() it = (c).rbegin(); it != (c).rend(); it++)
#define present(c,x) ((c).find(x) != (c).end())  // container version, log(n) for set and map
#define cpresent(c,x) (find(all(c),x) != (c).end())  // works for all container
#define mx(x,y) ((x)>(y)?(x):(y))
#define mn(x,y) ((x)<(y)?(x):(y))
#define remax(a,b) (a = max(a,b))
#define remin(a,b) (a = min(a,b))
#define mid(s,e) (s+(e-s)/2)
#define mod(a,b) ((a)-((a)/(b))*(b))
#define pq(type) priority_queue<type>
#define pqd(type) priority_queue<type,vector<type>,greater<type>>
#define umap unordered_map
#define uset unordered_set
#define sz(x) ((int)(x).size())
#define inrange(i,a,b) ((i>=min(a,b)) && (i<=max(a,b)))
#define cfp(x) 	cout << fixed << showpoint; 	cout << setprecision(x);
#define nl "\n"
#define br cout << "\n";

#define fileI(name) \
	freopen(name".in", "r", stdin);
#define fileIO(name) \
	freopen(name".in", "r", stdin); \
	freopen(name".out", "w", stdout);
#define FAST_IO \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL); \
	cout.tie(NULL);

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rngi(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
double rngr(double lim) {
	uniform_real_distribution<double> urd(0,lim-1);
	return urd(rang);
}

template<typename T> T gcd(T a, T b) { return (b?__gcd(a,b):a); }
template<typename T> T lcm(T a, T b) { return (a*(b/gcd(a,b))); }

inline void tokenize(const string& str, vs& out, const char&& delim) {
	stringstream ss(str);
	string s;
	while (getline(ss, s, delim)) out.pb(s);
}
inline void tokenize(const string& str, vd& out, const char&& delim) {
	stringstream ss(str);
	for (double i; ss >> i;) { out.pb(i); if (ss.peek() == delim) ss.ignore(); }
}
inline void tokenize(const string& str, vi& out, const char&& delim) {
	stringstream ss(str);
	for (int i; ss >> i;) { out.pb(i); if (ss.peek() == ',') ss.ignore(); }
}
inline void ltrim(string& s) { s.erase(s.begin(), find_if(all(s), not1(ptr_fun<int, int>(isspace)))); }
inline void rtrim(string& s) { s.erase(find_if(rall(s), not1(ptr_fun<int, int>(isspace))).base(), s.end()); }
inline void trim(string& s) { ltrim(s); rtrim(s); }
inline string cltrim(string s) { ltrim(s); return s; }
inline string crtrim(string s) { rtrim(s); return s; }

void solvethetestcase();

signed main() {
	// comment when using scanf, printf
	FAST_IO

	// set the seed
	// srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	// comment for input through console
	fileI("input")

	int t = 1;
	// (uncomment for multiple test cases)
	cin >> t;
	loopl (testcase, 1, t + 1) {
		// (uncomment for multiple test cases)
		cout << "Case #" << testcase << ": ";
		solvethetestcase();
    }
}

bool subset_sum(vi& arr, int size, int target) {
	if (!target)
		return true;
	if (!size)
		return true;
	if (arr[size - 1] > target)
		return subset_sum(arr, size - 1, target);
	return subset_sum(arr, size - 1, target)
		|| subset_sum(arr, size - 1, target - arr[size -1]);
}

vvi t;
int ss_mem(vi& arr, int size, int target) {
	if (!target)
		return 1;
	if (!size)
		return 0;
	if (t[size][target] != -1)
		return t[size][target];
	if (arr[size - 1] > target)
		return ss_mem(arr, size - 1, target);
	t[size][target] = ss_mem(arr, size - 1, target)
		|| ss_mem(arr, size - 1, target - arr[size - 1]);
	return t[size][target];
}

int ss_tab(vi& arr, int size, int target) {
	rloop(i, 0, target)
		t[0][i] = 0;
	rloop(i, 0, size)
		t[i][0] = 1;
	rloop(i, 1, size) {
		rloop(j, 1, target) {
			if (arr[i - 1] > j)
				t[i][j] = t[i - 1][j];
			else
				t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
		}
	}
	return t[size][target];
}

void solvethetestcase() {
	int size{};
	cin >> size;
	vi arr{};
	string in{};
	cin >> in;
	tokenize(in, arr, ',');
	int sum = accumulate(all(arr), 0);
	int min_diff = INF;
	// this is the main logic for minimum subset sum difference
	/**
	  you find every number in range of accumulate(all(arr)), and then find
	  subset_sum on first half of these numbers, the one which will give true
	  can be treated as 's1' and the other part, which will (s2 - s1) or
	  ((range_sum - s1) - s1) => (range_sum - 2*s1), (since, s1 + s2 =
	  range_sum). Answer will be the minimum of (range_sum - 2 * s1)
	  */
	// this was the recursive approach, we can make it much better by memoization or tabulation
	/*rloop(i, 0, (sum / 2)) {
		if (subset_sum(arr, size, i))
			remin(min_diff, (sum - 2 * i));
	}*/
	t.clear();
	t.resize(size + 1, vi(sum + 1, -1));
	// it doesn't matter if subset_sum is return false here
	ss_tab(arr, size, sum);  // however, it'll not return false
	rloop(i, 0, (sum / 2)) {
		if (t[size][i])
			remin(min_diff, (sum - 2 * i));
	}
	cout << min_diff << nl;
}

#pragma GCC diagnostic pop