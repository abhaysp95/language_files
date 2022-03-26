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

/**
struct Team {
	string name{};
	int points, wins, loss, ties, goal, agoal;
	void init() {
		points = wins = loss = ties = goal = agoal = 0;
	}
	void record(int a, int b) {
		if(a > b) points += 3, wins++;
		else if(b > a) loss++;
		else ties++, points++;
		goal += a, agoal += b;
	}
}; */

struct Team {
	char name[105];
	int points, wins, loss, ties, goal, agoal;
	void init() {
		points = wins = loss = ties = goal = agoal = 0;
	}
	void record(int a, int b) {
		if(a > b) points += 3, wins++;
		else if(b > a) loss++;
		else ties++, points++;
		goal += a, agoal += b;
	}
};

bool comp(Team a, Team b) {
	if(a.points != b.points) return a.points > b.points;
	if(a.wins != b.wins) return a.wins > b.wins;
	if(a.goal - a.agoal != b.goal - b.agoal)
		return a.goal - a.agoal > b.goal - b.agoal;
	if(a.goal != b.goal) return a.goal > b.goal;
	if(a.wins + a.loss + a.ties != b.wins + b.loss + b.ties)
		return a.wins + a.loss + a.ties < b.wins + b.loss + b.ties;
	//return strcasecmp(a.name.c_str(), b.name.c_str()) < 0;
	return strcasecmp(a.name, b.name) < 0;
}

/** first approach
void solvethetestcase() {
	int N{}, T{}, G{}, count{};
	cin >> N;
	cin.ignore();
	while(N--) {
		string tname{};
		getline(cin, tname);
		cin >> T;
		cin.ignore();
		if(count++) br;
		cout << tname << nl;
		umap<string, int> team_table{};
		vector<Team> team_details(T);
		for(int i = 0; i < T; i++) {
			getline(cin, team_details[i].name);
			team_table[team_details[i].name] = i;
			team_details[i].init();
		}
		cin >> G;
		cin.ignore();
		while(G--) {
			string details{};
			getline(cin, details);
			string aname{}, bname{};
			int agoal{}, bgoal{};
			string::iterator first = details.begin();
			string::iterator second = first;
			second = find(first, details.end(), '#');
			if(second != details.end()) aname = string(first, second);
			first = second;
			agoal = *(++first) - '0';
			first += 2;
			bgoal = *first - '0';
			first += 2;
			if(first == details.end()) exit(1);
			bname = string(first, details.end());
			team_details[team_table[aname]].record(agoal, bgoal);
			team_details[team_table[bname]].record(bgoal, agoal);
		}
		sort(team_details.begin(), team_details.end(), comp);
		for(int i = 0; i < T; i++) {
			cout << i + 1 << ") " << team_details[i].name << " "
				<< team_details[i].points << "p, " <<
				team_details[i].wins + team_details[i].loss + team_details[i].ties
				<< "g (" << team_details[i].wins << "-"
				<< team_details[i].ties << "-"
				<< team_details[i].loss << "), "
				<< team_details[i].goal - team_details[i].agoal << "gd "
				<< team_details[i].goal << "-" << team_details[i].agoal
				<< ")" << nl;
		}
	}
} */

/** second approach */
void solvethetestcase() {
	scanf("%*d ");  // don't need N
	int G{}, T{}, cases{};
	char name[101], buf[101];
	while(fgets(name, sizeof(name), stdin)) {
		scanf("%d", &T);
		getchar();
		umap<string, int> R;
		Team A[T];
		if(cases) puts("");
		puts(name);
		for(int i = 0; i < T; i++) {
			fgets(A[i].name, sizeof(A[i].name), stdin);
			R[A[i].name] = i;
			A[i].init();
		}
		scanf("%d", &G);
		getchar();
		while(G--) {
			fgets(buf, sizeof(buf), stdin);
			char name1[100], name2[100];
			int g1{}, g2{};
			sscanf(buf, "%[^#]#%d@%d#%[^\n]", name1, &g1, &g2, name2);
			A[R[name1]].record(g1, g2);
			A[R[name2]].record(g2, g1);
		}
		sort(A, A + T, comp);
		for(int i = 0; i < T; i++) {
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
					i + 1, A[i].name, A[i].points,
					A[i].wins + A[i].loss + A[i].ties,
					A[i].wins, A[i].ties, A[i].loss,
					A[i].goal - A[i].agoal,
					A[i].goal, A[i].agoal);
		}
	}
}

#pragma GCC diagnostic pop