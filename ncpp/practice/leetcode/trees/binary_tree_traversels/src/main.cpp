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
	//cin >> t;
	//cin.ignore();
	loopl (testcase, 1, t + 1) {
		//(uncomment for multiple test cases)
		//cout << "Case #" << testcase << ": ";
		//br;
		solvethetestcase();
	}
}

typedef struct _node {
	int val;
	_node *left, *right;
	_node(): val{}, left{nullptr}, right{nullptr} {}
	_node(int x): val{x}, left{nullptr}, right{nullptr} {}
	_node(int x, _node *l, _node *r): val{x}, left{l}, right{r} {}
} TreeNode;

vi inorder_iterative(TreeNode *root) {
	vector<int> res{};
	TreeNode *ptr{root};
	stack<TreeNode *> st;
	while(ptr != nullptr || !st.empty()) {
		while(ptr != nullptr) {
			st.push(ptr);
			ptr = ptr->left;
		}
		ptr = st.top();
		st.pop();
		res.push_back(ptr->val);
		ptr = ptr->right;
	}
	return res;
}

vi preorder_traversal(TreeNode *root) {
	vector<int> res{};
	stack<TreeNode *> st{};
	TreeNode *ptr{root};
	while(ptr != nullptr || !st.empty()) {
		while(ptr != nullptr) {
			res.push_back(ptr->val);
			st.push(ptr);
			ptr = ptr->left;
		}
		ptr = st.top();
		st.pop();
		ptr = ptr->right;
	}
	return res;
}

//template<typename T, class C>
//struct OpenStack: std::stack<T, C> {
	//using Stack = std::stack<T, C>;
	//using Stack::C;  // open C to public
//};

//template<typename T, class C>
//C& getContainer(std::stack<T, C>& s) {
	//return static_cast<OpenStack<T, C>&>(s).c;
//};

template<typename T, class C>
C& getProtectedContainer(std::stack<T, C>& s) {
	struct OpenStack: std::stack<T, C> {
		using std::stack<T, C>::c;
	};
	return static_cast<OpenStack&>(s).c;
}

vi postorder_two_stack(TreeNode *root) {
	stack<TreeNode *> st1{};
	stack<int> st2{};
	TreeNode *ptr{nullptr};
	st1.push(root);
	while(!st1.empty()) {
		ptr = st1.top(), st1.pop();
		st2.push(ptr->val);
		if(ptr->left != nullptr) st1.push(ptr->left);
		if(ptr->right != nullptr) st1.push(ptr->right);
	}
	auto& c = getProtectedContainer(st2);  // generally, stack is made up of 'deque'
	return vector<int>(c.rbegin(), c.rend());
}

vi postorder_one_stack(TreeNode *root) {
	vector<int> res;
	stack<TreeNode *> st{};
	TreeNode *ptr{root};
	do {
		if(!ptr) {  // ptr is nullptr
			ptr = st.top();
			st.pop();
			if(!st.empty()) {  // if stack empty then game over
				if(ptr->right && ptr->right == st.top()) {
					st.pop();
					st.push(ptr);
					ptr = ptr->right;
				}
				else {
					res.push_back(ptr->val);
					ptr = nullptr;
				}
			}
		}
		else {
			if(ptr->right) {
				st.push(ptr->right);
			}
			st.push(ptr);
			ptr = ptr->left;
		}
	} while(!st.empty());
	if(ptr) res.push_back(ptr->val);  // get root node
	return res;
}

vvi level_order_traversal(TreeNode *root)
{
	vector<vector<int>> res{};
	queue<TreeNode *> q{};
	q.push(root);
	q.push(nullptr);
	vector<int> temp{};
	while(!q.empty())
	{
		TreeNode *ptr = q.front();
		q.pop();
		if(ptr)
		{
			temp.push_back(ptr->val);
			if(ptr->left) q.push(ptr->left);
			if(ptr->right) q.push(ptr->right);
		}
		else
		{
			if(!temp.empty()) res.push_back(std::move(temp));
			if(!q.empty()) q.push(nullptr);
		}
	}
	return res;
}

vvi level_order_traversal_zigzag(TreeNode *root) {
	if(!root) return vector<vector<int>>{};
	vector<vector<int>> res{vector<int>{root->val}};
	vector<int> temp{};
	stack<TreeNode *> st{};
	queue<TreeNode *> q{};
	q.push(root);
	q.push(nullptr);
	bool cdir = false;  // correct direction(cdir): left to right, false: right to left
	while(!q.empty()) {
		TreeNode *ptr = q.front();
		q.pop();
		if(ptr) {
			if(ptr->left && ptr->right) {
				temp.push_back(cdir ? ptr->left->val : ptr->right->val);
				temp.push_back(cdir ? ptr->right->val : ptr->left->val);
				st.push(cdir ? ptr->left : ptr->right);
				st.push(cdir ? ptr->right : ptr->left);
			}
			else {
				if(ptr->left) {
					temp.push_back(ptr->left->val);
					st.push(ptr->left);
				}
				else if(ptr->right) {
					temp.push_back(ptr->right->val);
					st.push(ptr->right);
				}
			}
		}
		else {
			if(!temp.empty()) res.push_back(std::move(temp));
			if(!st.empty()) {
				while(!st.empty()) {
					q.push(st.top());
					st.pop();
				}
			}
			if(!q.empty()) q.push(nullptr);
			cdir = !cdir;
		}
	}
	return res;
}

void solvethetestcase() {
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(1);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(6);
	vi res = inorder_iterative(root);
	copy(res.begin(), res.end(), ostream_iterator<int>(cout, ", "));
	br;
	res = preorder_traversal(root);
	copy(res.begin(), res.end(), ostream_iterator<int>(cout, ", "));
	br;
	res = postorder_two_stack(root);
	copy(res.begin(), res.end(), ostream_iterator<int>(cout, ", "));
	br;
	vector<vector<int>> res_lot = level_order_traversal(root);
	for_each(res_lot.begin(), res_lot.end(), [](const vector<int>& vec) {
			copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, ", ")); });
	br;
	res_lot = level_order_traversal_zigzag(root);
	for_each(res_lot.begin(), res_lot.end(), [](const vector<int>& vec) {
			copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, ", ")); });
	br;
	res = postorder_one_stack(root);
	copy(res.begin(), res.end(), ostream_iterator<int>(cout, ", "));
	br;
}

#pragma GCC diagnostic pop