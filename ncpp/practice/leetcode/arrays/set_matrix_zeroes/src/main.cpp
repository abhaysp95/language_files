//main file

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define lD long double
#define PI 3.1415926535897932384626
#define INF 1e9
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, n) for (int i = (n) - 1; i >= 0; i--)
#define repld(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define loop(i,a,b) for (int i = (int)(a); i < (int)(b); i++)
#define loops(i,a,b,s) for (int i = (int)(a); i < (int)(b); i+=(s))
#define rloop(i,a,b) for (int i = (int)(a); i <= (int)(b); i++)
#define rloops(i,a,b,s) for (int i = (int)(a); i <= (int)(b); i+=(s))
#define loopl(i,a,b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define loopls(i,a,b,s) for (ll i = (ll)(a); i < (ll)(b); i+=(s))
#define rloopl(i,a,b) for (ll i = (ll)(a); i <= (ll)(b); i++)
#define rloopls(i,a,b,s) for (ll i = (ll)(a); i <= (ll)(b); i+=(s))
#define loopd(i,a,b) for (int i = (int)(a); i > (b); i--)
#define loopds(i,a,b,s) for (int i = (int)(a); i > (b); i-=(s))
#define rloopd(i,a,b) for (int i = (int)(a); i >= (b); i--)
#define rloopds(i,a,b,s) for (int i = (int)(a); i >= (b); i-=(s))
#define loopld(i,a,b) for (ll i = (ll)(a); i > (b); i--)
#define looplds(i,a,b,s) for (ll i = (ll)(a); i > (b); i-=(s))
#define rloopld(i,a,b) for (ll i = (ll)(a); i >= (b); i--)
#define rlooplds(i,a,b,s) for (ll i = (ll)(a); i >= (b); i-=(s))
#define wl (t) while((t)--)
#define pb push_back
#define eb emplace_back
#define ab(a) (a < 0)?(-1*(a)):(a)
#define mset(a,b,c) loop(i,0,(b)) (a)[i]=(c)
#define asum(a,b,c) { int i = 0; (c) = 0; repd(i, b) (c)+=(a)[i]; }
#define fe first
#define se second
#define mp make_pair
#define clr(x) (x).clear()
#define itoc(c) ((char)(((int)'0')+(c)))
#define all(p) (p).begin(),(p).end()
#define rall(p) (p).rbegin(),(p).rend()
#define tr(c,it) for(__typeof__((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define trr(c,it) for(__typeof__((c).rbegin()) it = (c).rbegin(); it != (c).rend(); ++it)
#define present(c,x) ((c).find(x) != (c).end())  // container version, log(n) for set and map
#define cpresent(c,x) (find(all(c),(x)) != (c).end())  // works for all container
#define mx(x,y) ((x)>(y)?(x):(y))
#define mn(x,y) ((x)<(y)?(x):(y))
#define rmx(a,b) ((a) = mx((a),(b)))
#define rmn(a,b) ((a) = mn((a),(b)))
#define mid(s,e) ((s)+((e)-(s))/2)
#define mod(a,b) ((a)-((a)/(b))*(b))
#define pq(type) priority_queue<type>
#define pqd(type) priority_queue<type,vector<type>,greater<type>>
#define umap unordered_map
#define uset unordered_set
#define sz(x) ((int)(x).size())
#define inrange(i,a,b) (((i)>=mn(a,b)) && ((i)<=mx(a,b)))
#define cfp(x) 	cout << fixed << showpoint; 	cout << setprecision(x);
#define nl "\n"
#define br cout << "\n"

#define fileI(name) \
	freopen(name".in", "r", stdin)
#define fileIO(name) { \
	freopen(name".in", "r", stdin); \
	freopen(name".out", "w", stdout); \
}
#define FAST_IO { \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL); \
	cout.tie(NULL); \
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcomment"

using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using vvs = vector<vs>;
using vd = vector<double>;
using vvd = vector<vd>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vpii = vector<pii>;

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rngi(int lim) {
	uniform_int_distribution<int> uid(0,(lim)-1);
	return uid(rang);
}
double rngr(double lim) {
	uniform_real_distribution<double> urd(0,(lim)-1);
	return urd(rang);
}

template<typename T> T gcd(T a, T b) { return ((b)?__gcd(a,b):(a)); }
template<typename T> T lcm(T a, T b) { return ((a)*((b)/gcd(a,b))); }

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
	for (int i; ss >> i;) { out.pb(i); if (ss.peek() == delim) ss.ignore(); }
}
inline void print_mat(const vvi& t) {
	if(0 == t.size()) {
		cout << "[WW] Empty Matrix!!!" << nl;
		return;
	}
	rep(i, t.size()) {
		rep(j, t[0].size()) cout << t[i][j] << " ";
		br;
	}
}
inline void ltrim(string& s) { s.erase(s.begin(), find_if(all(s), not1(ptr_fun<int, int>(isspace)))); }
inline void rtrim(string& s) { s.erase(find_if(rall(s), not1(ptr_fun<int, int>(isspace))).base(), s.end()); }
inline void trim(string& s) { ltrim(s); rtrim(s); }
inline string cltrim(string s) { ltrim(s); return s; }
inline string crtrim(string s) { rtrim(s); return s; }

void solvethetestcase();

signed main() {
	//comment when using scanf, printf
	FAST_IO;

	//set the seed
	//srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	//comment for input through console
	fileI("input");

	int t = 1;
	//(uncomment for multiple test cases)
	cin >> t;
	cin.ignore();
	loopl (testcase, 1, t + 1) {
		//(uncomment for multiple test cases)
		cout << "Case #" << testcase << ": ";
		br;
		solvethetestcase();
	}
}

//#define ROW_ONLY 2
//#define COL_ONLY 1

//void do_zero(vvi& matrix, size_t i, size_t j, int flag) {
	//if(flag & ROW_ONLY) for(vector<int>::size_type x = 0; x < matrix[0].size(); x++) matrix[i][x] = 0;
	//if(flag & COL_ONLY) for(vector<vector<int>>::size_type x = 0; x < matrix.size(); x++) matrix[x][j] = 0;
//}

//void set_zeroes(vvi& matrix) {
	//vi czero(matrix[0].size(), 0);
	//for(vector<vector<int>>::size_type i = 0; i < matrix.size(); i++) {
		//bool row_have_zero{false};
		//for(vector<int>::size_type j = 0; j < matrix[0].size(); j++) {
			//int flag = 0;
			//if(!matrix[i][j]) {
				//if(!czero[j]) {
					//row_have_zero = true;
					//czero[j] = 1;
					//flag |= COL_ONLY;
					//do_zero(matrix, i, j, flag);
				//}
			//}
			//if(matrix[0].size() - 1 == j && row_have_zero) {
				//flag = 0;
				//flag |= ROW_ONLY;
				//do_zero(matrix, i, j, flag);
			//}
		//}
	//}
//}

void set_zeroes(vvi& matrix) {
	vector<bool> czero(matrix[0].size(), false), rzero(matrix.size(), false);
	for(size_t i = 0; i < matrix.size(); i++) {
		for(size_t j = 0; j < matrix[0].size(); j++) {
			if(matrix[i][j] == 0) {
				if(!rzero[i]) rzero[i] = true;
				if(!czero[j]) czero[j] = true;
			}
		}
	}

	for(size_t i = 0; i < matrix.size(); i++) if(rzero[i]) for(size_t j = 0; j < matrix[0].size(); j++) matrix[i][j] = 0;
	for(size_t i = 0; i < matrix[0].size(); i++) if(czero[i]) for(size_t j = 0; j < matrix.size(); j++) matrix[j][i] = 0;
}

void set_zeroes2(vvi& matrix) {
	bool row_zero{false};  // this will tell if orignal matrix have any zero in its first row
	size_t m{matrix.size()}, n{matrix[0].size()};
	for(size_t i = 0; i < m; i++) {
		for(size_t j = 0; j < n; j++) {
			if(matrix[i][j] == 0) {
				matrix[0][j] = 0;  // this will be mark for later on for setting zero to a column
				if(i > 0) matrix[i][0] = 0;  // mark for setting zero to a row
				else row_zero = true;
			}
		}
	}
	for(size_t i = 1; i < m; i++) {
		for(size_t j = 1; j < n; j++) {
			if(matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
		}
	}
	if(matrix[0][0] == 0) {  // it could be zero only it is originally zero
		for(size_t i = 1; i < m; i++) matrix[i][0] = 0;
	}
	if(row_zero) for(size_t i = 0; i < n; i++) matrix[0][i] = 0;
}

void solvethetestcase() {
	vvi matrix{};
	string input{};
	while(getline(cin, input)) {
		if (input.empty()) break;
		vi temp{};
		tokenize(input, temp, ',');
		matrix.push_back(move(temp));
	}
	cout << "Before: " << nl;
	print_mat(matrix);
	set_zeroes2(matrix);
	cout << "After: " << nl;
	print_mat(matrix);
}

#pragma GCC diagnostic pop