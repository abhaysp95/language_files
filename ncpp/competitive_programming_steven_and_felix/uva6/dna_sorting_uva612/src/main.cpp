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
using vd = vector<double>;
using vvd = vector<vd>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
using vvs = vector<vs>;
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

template<typename T>
void print_mat(const vector<vector<T>>& t) {
	if(0 == t.size()) {
		cout << "[WW] Empty Matrix!!!" << nl;
		return;
	}
	rep(i, t.size()) {
		rep(j, t[0].size()) cout << t[i][j] << " ";
		br;
	}
}

template<typename T>
void tokenize(const string& str, vector<T>& out, const char& delim) {
	stringstream ss(str);
	for(T i; ss >> i;) {
		out.pb(i);
		if(ss.peek() == delim) ss.ignore();
	}
}
template<>
void tokenize(const string& str, vs& out, const char& delim) {
	stringstream ss(str);
	string s;
	while(getline(ss, s, delim)) out.pb(s);
}

inline void ltrim(string& s) { s.erase(s.begin(), find_if(all(s), not1(ptr_fun<int, int>(isspace)))); }
inline void rtrim(string& s) { s.erase(find_if(rall(s), not1(ptr_fun<int, int>(isspace))).base(), s.end()); }
inline void trim(string& s) { ltrim(s); rtrim(s); }
inline string cltrim(string s) { ltrim(s); return s; }
inline string crtrim(string s) { rtrim(s); return s; }

void solvethetestcase();

signed main() {
	//comment when using scanf, printf
	//FAST_IO;

	//set the seed
	//srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	//comment for input through console
	fileI("input");

	int t = 1;
	//(uncomment for multiple test cases)
	//cin >> t;
	//cin.ignore();
	loopl (testcase, 1, t + 1) {
		//(uncomment for multiple test cases)
		//cout << "Case #" << testcase << ": ";
		//br;
		solvethetestcase();
	}
}

/** first approach
umap<string, int> ump;

int get_unsortedness(const string& a) {
	int sz = a.size();
	int count = 0;
	for(int i = 0; i < sz; i++) {
		if(a[i] != 'A') {
			for(int j = i + 1; j < sz; j++) if(a[i] > a[j]) count++;
		}
	}
	//if(find(ump.begin(), ump.end(), a) == ump.end()) ump[a] = count;
	ump[a] = count;
	return count;
}

bool comp(string& a, string& b) {
	int counta = get_unsortedness(a);
	int countb = get_unsortedness(b);
	return counta < countb;
}

void solvethetestcase() {
	int len = 0, n = 0;
	scanf("%d %d", &len, &n);
	getchar();
	vector<string> inputs;
	for(int i = 0; i < n; i++) {
		char arr[11];
		scanf("%s\n", arr);
		inputs.push_back(std::move(arr));
	}
	sort(inputs.begin(), inputs.end(), comp);
	for(const string& str: inputs) {
		printf("%s\n", str.c_str());
	}
	br;
	for(const auto& p: ump) {
		printf("%s -> %d\n", p.first.c_str(), p.second);
	}
} */

typedef struct {
	int v, i;
} Order;

int cmp(const void *i, const void *j) {
	Order *a = (Order *)i, *b = (Order *)j;
	if(a->v != b->v) return a->v - b->v;
	return a->i - b->i;
}

int sorts(const void *a, const void *b);

void solvethetestcase() {
	int t = 0;
	scanf("%d", &t);
	getchar();
	while(t--) {
		int n = 0, m = 0;
		scanf("%d %d", &n, &m);
		char dna[m][100];
		fgetc(stdin);  // because above input left '\n' in buffer
		Order D[m];
		for(int i = 0; i < m; i++) {
			fgets(dna[i], sizeof(dna[i]), stdin);
			int last = strlen(dna[i]) - 1;
			if(dna[i][last] == '\n') dna[i][last] = '\0';
			int sum = 0;
			for(int j = 0; j < n; j++) {
				if(dna[i][j] == 'A') while(j < n && dna[i][j] == 'A') j++;
				for (int k = j + 1; k < n; k++) {
					if(dna[i][j] > dna[i][k]) sum++;
				}
			}
			D[i].v = sum, D[i].i = i;
		}
		//qsort(D, m, sizeof(Order), cmp);
		//for(int i = 0; i < m; i++) {
			//puts(dna[D[i].i]);
		//}

		/** testing */
		qsort(dna, m, sizeof(dna[0]), sorts);
		for(int i = 0; i < m; i++) puts(dna[i]);
		if(t) puts("");
	}
}

/** testing */
int sorts(const void *a, const void *b) {
	char *x = (char *)a, *y = (char *)b;
	if(strlen(x) == strlen(y)) return strncmp(x, y, strlen(x));
	return strncmp(x, y, (strlen(x) < strlen(y) ? strlen(x) : strlen(y)));
}

#pragma GCC diagnostic pop