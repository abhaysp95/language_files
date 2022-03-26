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
		br;
		solvethetestcase();
	}
}

/** I'm not going to write the code for tree creation here. First, let's understand the basic concept of dp with tree. There are 3 main elements:
	int func(---i/p---) {
		-----------------
		|base condition;|
		-----------------
		-------------
		|hypothesis;|
		-------------
		------------
		|induction;|
		------------
	}
	We write base condtion like if `root == nullptr` etc.
	Next, we right hypothesis, which means that we would get result for the
	node's left subtree and right subtree, we don't question hypothesis
	Next, we right induction, which basically means to calculate the problem.
	Generally, it's for the lowest(last) element etc.

	"Induction", has 3 parts,
	temp = <something>;  in temp, we consider if the current node doesn't thinks itself of as answer and tries to pass the value to next level(above or below etc.)
	ans = <some relation with temp and some calculation>;  in ans, current node considers itself, of as answer and performs some calculation with temp and with some relationship it may get from it's left subtree, right subtree etc.(basically, temp and relation are to be solved)
	finally, we updated the `result`, which we got as `call by reference` in our function from the caller function
*/

typedef struct node {
	int data;
	struct node* left = nullptr;
	struct node* right = nullptr;
} node;

class node_not_found: public exception {
	public:
		virtual const char* what() const throw() {
			return "Node can't be created, destroying tree\n";
		}
};

node* pre_in_tree(vi& preorder, vi& inorder, int i, int j) {
	static int count{};
	if (!i && (j == preorder.size() - 1))
		count = 0;  // this can only happen, when fn isn't called recursively
	if (i > j)
		return nullptr;
	int curr_data = preorder[count++];
	int k = -1;
	vi::iterator iter = find(all(inorder), curr_data);
	if (iter != inorder.end())
		k = distance(inorder.begin(), iter);
	else {
		cout << "count: " << count << nl;
		throw node_not_found();
	}
	node* temp = new node;
	temp->data = curr_data;
	if (i == j)
		return temp;
	temp->left = pre_in_tree(preorder, inorder, i, k - 1);
	temp->right = pre_in_tree(preorder, inorder, k + 1, j);
	return temp;
}

bool is_node_leaf_node(node* root) {
	if (!root)
		throw node_not_found();
	return !(root->left || root->right);
}

void inorder_traverse(node* root) {
	if (!root)
		return;
	inorder_traverse(root->left);
	cout << root->data << " ";
	inorder_traverse(root->right);
}

int get_diameter(node* root, int& res) {
	// base condition
	if (!root)
		return 0;
	// hypothesis
	int left = get_diameter(root->left, res);
	int right = get_diameter(root->right, res);
	// induction
	int temp = 1 + mx(left, right);  // pass max of it's subtrees + 1 to above
	int ans = mx(temp, (1 + left + right));
	rmx(res, ans);
	return temp;
}

/** this function will give path some from any node of tree to any node of
 * tree, whichever will be maximun */
int get_max_path_sum(node* root, int& res) {
	// base condition
	if (!root)
		return 0;
	// hypothesis
	int left = get_max_path_sum(root->left, res);
	int right = get_max_path_sum(root->right, res);
	// induction
	int temp = mx(root->data, (mx(left, right) + root->data));
	int ans = mx(temp, (root->data + left + right));
	rmx(res, ans);
	return temp;
}

/** this function will give maximum path sum starting from a leaf node to
 * another leaf node */
int get_max_path_sum_l2l(node* root, int& res) {
	// base condition
	if (!root)
		return 0;
	// hypothesis
	int left = get_max_path_sum_l2l(root->left, res);
	int right = get_max_path_sum_l2l(root->right, res);
	// induction
	int temp = root->data + mx(left, right);
	if (is_node_leaf_node(root))
		rmx(temp, root->data);
	int ans = mx(temp, root->data + left + right);
	rmx(res, ans);
	return temp;
}

void free_tree(node* root) {
	if (!root)
		return;
	free_tree(root->left);
	free_tree(root->right);
	delete root;
	root = nullptr;
}

void solvethetestcase() {
	vi preorder, inorder;
	string p{}, i{};
	cin >> p >> i;
	tokenize(p, preorder, ',');
	tokenize(i, inorder, ',');
	node* root;
	try {
		root = pre_in_tree(preorder, inorder, 0, preorder.size() - 1);
		inorder_traverse(root);
		br;
		int diameter_of_tree{};
		get_diameter(root, diameter_of_tree);
		cout << "diameter of binary tree: " << diameter_of_tree << nl;
		int max_path_sum{};
		get_max_path_sum(root, max_path_sum);
		cout << "maximum path sum of given tree: " << max_path_sum << nl;
		int max_path_sum_l2l{};
		get_max_path_sum_l2l(root, max_path_sum_l2l);
		cout << "maximum path sum from leaf node to leaf node of given tree: "
			<< max_path_sum_l2l << nl;
		free_tree(root);
	}
	catch (node_not_found& nnf) {
		cout << nnf.what() << nl;
		free_tree(root);  // still have to fix this
	}
}

#pragma GCC diagnostic pop