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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(): val{0}, next{nullptr} {}
	ListNode(int x): val{x}, next{nullptr} {}
	ListNode(int x, ListNode* n): val{x}, next{n} {}
};

void print_lst(ListNode *lst) {
	ListNode *ptr = lst;
	while(ptr != nullptr) {
		cout << ptr->val << ' ';
		ptr = ptr->next;
	}
	br;
}

// I'm not doing any sort of checks here, just simple entry
void insert_vec(ListNode* & lst, const vi& vec) {
	ListNode *ptr{lst};
	for(const int& x: vec) {
		if(nullptr == lst) {
			lst = new ListNode(x);
			ptr = lst;
		}
		else {
			ptr->next = new ListNode(x);
			ptr = ptr->next;
		}
	}
}

void insert_node(ListNode* & lst, int data) {
	if(lst == nullptr) lst = new ListNode(data);
	else {
		ListNode *ptr{lst};
		while(ptr->next != nullptr) ptr = ptr->next;
		ptr->next = new ListNode(data);
	}
}

ListNode* add_two_numbers(ListNode *l1, ListNode *l2) {
	ListNode *res{}, *p1{l1}, *p2{l2};
	int carry{};
	while(p1 != nullptr && p2 != nullptr) {
		int sum = p1->val + p2->val + carry;
		carry = sum / 10;
		insert_node(res, sum % 10);
		p1 = p1->next, p2 = p2->next;
	}
	ListNode *p{nullptr};
	if(p1 != nullptr) p = p1;
	else if(p2 != nullptr) p = p2;
	if (p != nullptr) {
		while(p != nullptr) {
			int sum = p->val + carry;
			carry = sum / 10;
			insert_node(res, sum % 10);
			p = p->next;
		}
	}
	if(carry != 0) insert_node(res, carry);
	return res;
}

// better
ListNode* add_two_numbers2(ListNode *l1, ListNode *l2) {
	int carry{};
	// you can try to get length first(for less node creation)
	ListNode *p1{l1}, *p2{l2}, *mxp{nullptr}, *mnp{nullptr};
	size_t sz1{}, sz2{};
	while(p1 != nullptr) sz1++, p1 = p1->next;
	while(p2 != nullptr) sz2++, p2 = p2->next;
	if(sz1 >= sz2) mxp = l1, mnp = l2;
	else mxp = l2, mnp = l1;
	ListNode *res{mxp};
	while(mnp != nullptr) {
		int sum = mnp->val + mxp->val + carry;
		carry = sum / 10;
		mxp->val = (sum % 10);
		mxp = mxp->next, mnp = mnp->next;
	}
	if(carry) {
		while(carry && mxp != nullptr) {
			int sum = mxp->val + carry;
			carry = sum / 10;
			mxp->val = (sum % 10);
			mxp = mxp->next;
		}
		if(carry) {  // that means mxp is done
			insert_node(res, carry);
		}
	}
	return res;
}

void solvethetestcase() {
	string input{};
	vi in1{}, in2{};
	getline(cin, input);
	tokenize(input, in1, ',');
	getline(cin, input);
	tokenize(input, in2, ',');
	ListNode *l1{nullptr}, *l2{nullptr};
	insert_vec(l1, in1);
	insert_vec(l2, in2);
	print_lst(l1);
	print_lst(l2);
	print_lst(add_two_numbers2(l1, l2));
}

#pragma GCC diagnostic pop