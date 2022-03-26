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

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcomment"

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
	for (double i; ss >> i;) {{ out.pb(i); if (ss.peek() == delim) ss.ignore(); }}
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
	//comment when using scanf, printf
	FAST_IO

	//set the seed
	//srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	//comment for input through console
	fileI("input")

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

void print_mat(const vvi& mat) {
	for (const vi& row: mat) {
		for (const int& x: row) cout << x << ' ';
		br;
	}
}

/*bool is_safe(const vvi& mat, int&& i, int&& j) {
	if (i < mat.size() && j < mat[0].size() && mat[i][j]) return true;
	return false;
}*/

/*bool solve(const vvi& gmat, vvi& tmat, int&& i, int&& j) {
	if (i == gmat.size() - 1
			&& j == gmat[0].size() - 1) {
		tmat[i][j] = 1;
		return true;
	}
	if (is_safe(gmat, std::move(i), std::move(j))) {
		tmat[i][j] = 1;
		if (solve(gmat, tmat, std::move(i + 1), std::move(j))) return true;
		if (solve(gmat, tmat, std::move(i), std::move(j + 1))) return true;
		tmat[i][j] = 0;
		return false;
	}
	return false;
}*/




/** One Way */

bool is_safe(const vvi& gmat, int&& i, int&& j) {
	if ((0 <= i && i < gmat.size()) && (0 <= j && j < gmat[0].size()) && gmat[i][j]) return true;
	return false;
}

/*bool is_safe(const vvi& gmat, const vvi& tmat, int&& i, int&& j) {
	// tmat represents visited matrix
	if ((0 <= i && i < gmat.size()) && (0 <= j && j < gmat[0].size()) && gmat[i][j] && !tmat[i][j]) return true;
	return false;
}*/

bool is_safe(const vvi& gmat, const vvi& tmat, int&& i, int&& j) {
	if (i < 0 || j < 0 || i >= gmat.size() || j >= gmat[0].size() || !gmat[i][j] || tmat[i][j]) return false;
	return true;
}

/*void solve(vvi& gmat, vs& vstr, int i, int j, string&& str) {
	if (i == gmat.size() - 1 && j == gmat[0].size() - 1) {
		vstr.pb(std::move(str));
		return;
	}
	if (is_safe(gmat, std::move(i), std::move(j))) {
		gmat[i][j] = 0;*/
		/** maybe sequence of calling these recursive calls matters to match
		 * output but it doesn't particularily matters if you just want to
		 * solve the question, what actually matters is that you mark the cell
		 * you visit, so that when coming back it will not create an infinte
		 * loop */
		/*solve(gmat, vstr, i + 1, j, str + 'D');
		solve(gmat, vstr, i - 1, j, str + 'U');
		solve(gmat, vstr, i, j + 1, str + 'R');
		solve(gmat, vstr, i, j - 1, str + 'L');
		gmat[i][j] = 1;
	}
}*/

/*void solvethetestcase() {
	string str{};
	vvi gmat;
	while (getline(cin, str)) {
		if (str == "") break;
		vi temp;
		tokenize(str, temp, ' ');
		gmat.pb(std::move(temp));
	}
	print_mat(gmat);
	cout << "-------------------------------" << nl;*/
	/*vvi tmat;
	tmat.resize(gmat.size(), vi(gmat[0].size(), 0));
	solve(gmat, tmat, 0, 0);
	print_mat(tmat);*/
	/*vs vstr;
	solve(gmat, vstr, 0, 0, "");
	cout << "size: " << vstr.size() << nl;
	for (const string& str: vstr) cout << str << nl;
}*/

// these both are essentially the same way

/** second way */

void solve(const vvi& gmat, vvi& tmat, int i, int j, string&& str) {
	if (i == gmat.size() - 1 && j == gmat[0].size() - 1) {
		if(is_safe(gmat, tmat, std::move(i), std::move(j))) cout << str << nl;
		return;
	}
	if (is_safe(gmat, tmat, std::move(i), std::move(j))) {
		tmat[i][j] = 1;
		solve(gmat, tmat, i - 1, j, str + 'U');
		solve(gmat, tmat, i + 1, j, str + 'D');
		solve(gmat, tmat, i, j - 1, str + 'L');
		solve(gmat, tmat, i, j + 1, str + 'R');
		tmat[i][j] = 0;
	}
}


void solvethetestcase() {
	string str{};
	vvi gmat;
	while (getline(cin, str)) {
		if (str == "") break;
		vi temp;
		tokenize(str, temp, ' ');
		gmat.pb(std::move(temp));
	}
	//print_mat(gmat);
	vvi tmat;
	tmat.resize(gmat.size(), vi(gmat[0].size(), 0));
	solve(gmat, tmat, 0, 0, "");
}

#pragma GCC diagnostic pop