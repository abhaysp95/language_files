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
	//comment when using scanf, printf
	FAST_IO

		//set the seed
		//srand(chrono::high_resolution_clock::now().time_since_epoch().count());

		//comment for input through console
		fileI("input")

		int t = 1;
	//(uncomment for multiple test cases)
	cin >> t;
	loopl (testcase, 1, t + 1) {
		//(uncomment for multiple test cases)
		cout << "Case #" << testcase << ": ";
		//br;
		solvethetestcase();
	}
}

int expr_val(string& in, int k, bool bt, int lt, int rt, int lf, int rf) {
	int ans{};
	if (in[k] == '&') {
		if (bt)
			ans += (lt * rt);
		else
			ans += ((lt * rf) + (lf * rt) + (lf * rf));
	}
	else if (in[k] == '|') {
		if (bt)
			ans += ((lt * rt) + (lt * rf) + (lf * rt));
		else
			ans += (lf * rf);
	}
	else if (in[k] == '^') {
		if (bt)
			ans += ((lt * rf) + (lf * rt));
		else
			ans += ((lt * rt) + (lf * rf));
	}
	return ans;
}

int true_bp(string& in, int i, int j, bool bt) {
	if (i > j)
		return false;
	if (i == j) {
		if (bt)
			return in[i] == 'T';
		else
			return in[i] == 'F';
	}
	int ans{};
	loops (k, (i + 1), j, 2) {
		int lt = true_bp(in, i, k - 1, true);
		int rt = true_bp(in, k + 1, j, true);
		int lf = true_bp(in, i, k - 1, false);
		int rf = true_bp(in, k + 1, j, false);
		ans += expr_val(in, k, bt, lt, rt, lf, rf);
	}
	return ans;
}

/** Since, in this problem, there are three things which are changing with
 * every call, i, j and bt. So, you have to make a 3D-matrix. Now, making(and
 * visualizing) a 3d-matrix could be difficult, so another way is to use a
 * map(I'm using unordered_map here), where the key would "i j bt" string */
umap<string, int> ump;
int true_bp_mem_ump(string& in, int i, int j, bool bt) {
	if (i > j)
		return false;
	if (i == j) {
		if (bt)
			return in[i] == 'T';
		else
			return in[i] == 'F';
	}
	string akey = to_string(i) + " " + to_string(j) + " ";
	if (bt)
		akey += "T";
	else
		akey += "F";
	umap<string, int>::iterator iter = ump.find(akey);
	if (iter != ump.end())
		return iter->second;
	int ans{};
	loops(k, (i + 1), j, 2) {
		int lt = true_bp_mem_ump(in, i, k - 1, true);
		int rt = true_bp_mem_ump(in, k + 1, j, true);
		int lf = true_bp_mem_ump(in, i, k - 1, false);
		int rf = true_bp_mem_ump(in, k + 1, j, false);
		ans += expr_val(in, k, bt, lt, rt, lf, rf);
	}
	return ump[akey] = ans;
}

void print_umap() {
	for (pair<const string, int>& p: ump)
		cout << p.first << " => " << p.second << nl;
}


/**This is the solution with the help of 3d-matrix. Let's try to visualize it.
 * Since, there are 3 variable changing everytime in a function call, we'll
 * need a 3d-matrix type ds to do memoization. Now, This will be cube like
 * structure, say with `l x b x h`, now, here l will be "string size + 1", b
 * will "string size + 1" and h will be "2"(for true and false(0/1)(boolean
 * value)). Let's try to understand it a bit more. Say, example string length
 * is 5. There will total of 6 block(say we'll use on to iterate over). Now,
 * every ith block will contain another 6 block container(iterated by j). This
 * will be a 2d-matrix. Now, for every jth block in every ith block, there will
 * be a container of 2 blocks of int(or bool) which will either store 0 or
 * 1(T/F). Thus, in total, a 2d-matrix of string size 5 will have 36 blocks to
 * do memoization and for the same string, that matrix will have 72 blocks to
 * do memoization */
vector<vvi> t;
int true_bp_mem(string& in, int i, int j, int bt) {
	if (i > j)
		return false;
	if (i == j) {
		if (bt)
			return in[i] == 'T';
		else
			return in[i] == 'F';
	}
	if (t[i][j][bt] != -1)
		return t[i][j][bt];
	int ans{};
	loops(k, (i + 1), j, 2) {
		int lt = true_bp_mem(in, i, k - 1, true);
		int rt = true_bp_mem(in, k + 1, j, true);
		int lf = true_bp_mem(in, i, k - 1, false);
		int rf = true_bp_mem(in, k + 1, j, false);
		ans += expr_val(in, k, bt, lt, rt, lf, rf);
	}
	return t[i][j][bt] = ans;
}

void print_mat(string& in) {
	rep(i, (in.size() + 1)) {
		cout << "row #" << i << nl;
		rep(j, (in.size() + 1)) {
			cout << "{";
			rep(k, 2) {
				cout << t[i][j][k];
				if (k < 1)
					cout << ", ";
			}
			cout << "}" << nl;
		}
	}
}


void solvethetestcase() {
	string in{};
	cin >> in;
	/*ump.clear();
	  cout << true_bp_mem_ump(in, 0, in.size() - 1, true) << nl;
	  print_umap();*/
	t.clear();
	t.resize(in.size() + 1);
	rep(i, (in.size() + 1)) {
		vvi& temp = t[i];
		temp.resize(in.size() + 1, vi(2, -1));
	}
	cout << true_bp_mem(in, 0, in.size() - 1, true) << nl;
	print_mat(in);
}

#pragma GCC diagnostic pop