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
	//cin.ignore();
	loopl (testcase, 1, t + 1) {
		//(uncomment for multiple test cases)
		cout << "Case #" << testcase << ": ";
		br;
		solvethetestcase();
	}
}

/** two robots starting from both sides of two sides, and they have to reach to
 * the bottom row of the grid
  1. movement can be down, digonally( both left and right side )
  2. robot at cell picks all and cell becomes 0
  3. when both robots are at same cell, only one takes the cherry
  */

void print_mat( const vvi& t ) {
	loop( i, 0, t.size() ) {
		loop( j, 0, t[0].size() ) cout << t[i][j] << ' ';
		br;
	}
}

umap<string, int> tmap;

int solve_umap( const vvi& t, int row, int aj, int bj ) {
	// base condition
	if( t.size() == row ) return 0;  // reached to end row

	// check safety
	if( 0 > aj || t[0].size() <= aj || 0 > bj || t[0].size() <= bj ) return -INF;

	// hypothesis + induction
	string mkey = to_string( row ) + " " + to_string( aj ) + " " + to_string( bj );

	umap<string, int>::iterator iter = tmap.find( mkey );
	if( iter != tmap.end() )  // key found
		return iter->second;

	int ans = -INF;
	int res = t[row][aj] + t[row][bj];
	if( aj == bj ) // if both the robots are in the same cell
		res -= t[row][aj];

	// robot1 moved left diagonal( and robot2 is following with its 3 movements )
	ans = mx( ans, res + solve_umap( t, row + 1, aj - 1, bj - 1 ) );
	ans = mx( ans, res + solve_umap( t, row + 1, aj - 1, bj ) );
	ans = mx( ans, res + solve_umap( t, row + 1, aj - 1, bj + 1 ) );
	// robot1 moved down( and robot2 following )
	ans = mx( ans, res + solve_umap( t, row + 1, aj, bj - 1 ) );
	ans = mx( ans, res + solve_umap( t, row + 1, aj, bj ) );
	ans = mx( ans, res + solve_umap( t, row + 1, aj, bj + 1 ) );
	// robot1 moved right diagonal( and robot 2 following )
	ans = mx( ans, res + solve_umap( t, row + 1, aj + 1, bj - 1  ) );
	ans = mx( ans, res + solve_umap( t, row + 1, aj + 1, bj ) );
	ans = mx( ans, res + solve_umap( t, row + 1, aj + 1, bj + 1 ) );

	return tmap[mkey] = ans;
}

vector<vvi> tmat;
int solve_mat( const vvi& t, int row, int aj, int bj ) {
	// base condition
	if( row == t.size() ) return 0;  // we reached last row

	// check safety
	if( 0 > aj || 0 > bj || t[0].size() <= aj || t[0].size() <= bj ) return -INF;

	if( tmat[row][aj][bj] != -1) return tmat[row][aj][bj];

	int ans = -INF;
	int res{ t[row][aj] };
	if( aj != bj ) res += t[row][bj];

	// robot1 moved left diagonal( and robot2 is following with its 3 movements )
	ans = mx( ans, res + solve_mat( t, row + 1, aj - 1, bj - 1 ) );
	ans = mx( ans, res + solve_mat( t, row + 1, aj - 1, bj ) );
	ans = mx( ans, res + solve_mat( t, row + 1, aj - 1, bj + 1 ) );
	// robot1 moved down( and robot2 following )
	ans = mx( ans, res + solve_mat( t, row + 1, aj, bj - 1 ) );
	ans = mx( ans, res + solve_mat( t, row + 1, aj, bj ) );
	ans = mx( ans, res + solve_mat( t, row + 1, aj, bj + 1 ) );
	// robot1 moved right diagonal( and robot 2 following )
	ans = mx( ans, res + solve_mat( t, row + 1, aj + 1, bj - 1  ) );
	ans = mx( ans, res + solve_mat( t, row + 1, aj + 1, bj ) );
	ans = mx( ans, res + solve_mat( t, row + 1, aj + 1, bj + 1 ) );

	return tmat[row][aj][bj] = ans;
}

void solve( string&& choice="hashmap" ) {
	size_t row{}, col{};
	cin >> row >> col;
	vvi t;
	rep( i, row ) {
		vi temp( col );
		rep( j, col ) cin >> temp[j];
		t.pb( std::move( temp ) );
	}
	if( 0 == choice.compare( "hashmap" ) ) {
		tmap.clear();
		int&& ans = solve_umap( t, 0, 0, col - 1 );
		cout << "max cherries picked: " << ans << nl;

		/** uncomment the below loop for debugging purpose */
		//for( umap<string, int>::const_iterator citer = tmap.begin(); citer != tmap.end(); citer++ )
			//cout << citer->first << " => " << citer->second << nl;
	}
	else if( 0 == choice.compare( "matrix" ) ) {
		tmat.clear();
		tmat.resize( t.size(), vvi( t[0].size(), vi( t[0].size(), -1 ) ) );
		int&& ans = solve_mat( t, 0, 0, col - 1 );
		cout << "max cherries picked: " << ans << nl;

		/** uncomment the below loop for debugging purpose */
		//rep( i, tmat.size() ) {
			//cout << "==> row " << ( i + 1 ) << ": " << nl;
			//print_mat( tmat[i] );
		//}
	}
}

void solvethetestcase() {
	string choice{};
	cin.ignore();
	getline( cin, choice );
	solve( std::move( choice ) );
}

#pragma GCC diagnostic pop