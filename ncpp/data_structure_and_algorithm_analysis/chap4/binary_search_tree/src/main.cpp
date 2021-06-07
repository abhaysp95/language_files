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
	//cin >> t;
	loopl (testcase, 1, t + 1) {
		//(uncomment for multiple test cases)
		//cout << "Case #" << testcase << ": ";
		//br;
		solvethetestcase();
	}
}

template<typename Object, typename Comparator=less<Object>>
class BinarySearchTree {
	private:
		struct BinaryNode {
			Object element;
			BinaryNode* left;
			BinaryNode* right;

			BinaryNode(const Object& ele, BinaryNode* lt, BinaryNode* rt):
				element{ele}, left{lt}, right{rt} {}
			BinaryNode(Object&& ele, BinaryNode* lt, BinaryNode* rt):
				element{std::move(ele)}, left{lt}, right{rt} {}
		};

		BinaryNode* _root;
		Comparator isLessThan;

		void insert( const Object& x, BinaryNode* & t ) {
			if( nullptr == t ) t = new BinaryNode{ x, nullptr, nullptr };
			else if( isLessThan( x, t->element ) ) insert( x, t->left );
			else if( isLessThan( t->element, x ) ) insert( x, t->right );
		}
		void insert( Object&& x, BinaryNode* & t ) {
			if( nullptr == t ) t = new BinaryNode{ std::move( x ), nullptr, nullptr };
			else if( isLessThan( x, t->element ) ) insert( x, t->left );
			else if( isLessThan( t->element, x ) ) insert( x, t->right );
		}

		void remove( const Object& x, BinaryNode* & t ) {
			if( nullptr == t ) return;  // Item not found
			if( isLessThan( x, t->element ) ) remove( x, t->left );
			else if( isLessThan( t->element, x ) ) remove( x, t->right );
			else if( nullptr != t->left && nullptr != t->right ) {  // two children
				BinaryNode* temp = findMin( t->right );
				t->element = temp->right;
				remove( t->element, t->right );
			}
			else {
				BinaryNode* oldNode = t;
				t = ( nullptr != t->left ) ? t->left : t->right;
				delete oldNode;
			}
		}

		// recursive way
		BinaryNode* findMin( BinaryNode* t ) const {
			if ( nullptr == t ) return nullptr;
			if ( nullptr == t->left ) return t;
			return findMin( t->left );
		}

		// non-recursive way
		BinaryNode* findMax( BinaryNode* t ) const {
			if ( nullptr != t ) while ( nullptr != t->right ) t = t->right;
			return t;
		}
		bool contains( const Object& x, BinaryNode* t ) const {
			if( nullptr == t ) return false;
			if ( isLessThan( x, t->element ) ) return contains( x, t->left );
			else if( isLessThan( t->element, x ) ) return contains( x, t->right );
			else return true;
		}
		void makeEmpty( BinaryNode* & t ) {
			if( nullptr != t ) {
				makeEmpty( t->left );
				makeEmpty( t->right );
				delete t;
			}
			t = nullptr;
		}
		void printTree( BinaryNode* t, ostream& out ) const {
			if( nullptr == t ) return;
			printTree( t->left, out );
			out << t->element << ' ';
			printTree( t->right, out );
		}
		BinaryNode* clone( BinaryNode* t ) const {
			if( nullptr == t ) return nullptr;
			else return new BinaryNode{ t->element, clone( t->left ), clone( t->right ) };
		}
	public:
		BinarySearchTree() {}
		BinarySearchTree(const BinarySearchTree& rhs): _root{ nullptr } {
			this->_root = clone( rhs._root );
		}
		BinarySearchTree(BinarySearchTree&& rhs);
		~BinarySearchTree() { makeEmpty(); }

		const Object& findMin() const { findMin( this->_root ); }
		const Object& findMax() const { findMax( this->_root ); }

		// return true if x is found in tree
		bool contains(const Object& x) const {
			return contains(x, this->_root);
		}
		bool isEmpty() const { return ( nullptr == this->_root ? true : false ); }
		void printTree(ostream& out = cout) const {
			printTree( this->_root, out );
			out << '\n';
		}

		void makeEmpty() { makeEmpty( this->_root ); }

		// insert x into tree, duplicates are ignored
		void insert(const Object& x) {
			insert(x, this->_root);
		}
		void insert(Object&& x) {
			insert(std::move( x ), this->_root);
		}
		void remove(const Object& x) {
			remove(x, this->_root);
		}

		BinarySearchTree& operator=(const BinarySearchTree& rhs) {
			BinarySearchTree copy = rhs;
			std::swap( *this, copy );
			return *this;
		}
		BinarySearchTree& operator=(BinarySearchTree&& rhs) {
			std::swap( this->_root, rhs._root );
			return *this;
		}
};


template<typename T>
class Comparator {
	public:
		bool operator()( const T& x1, const T& x2 ) { return x1 < x2; }
};

void solvethetestcase() {
	string str{};
	vi temp;
	getline(cin, str);
	tokenize(str, temp, ' ');


	BinarySearchTree<int, Comparator<int> > bst{};
	//BinarySearchTree<int> bst;


	for_each(temp.begin(), temp.end(), [&bst](const auto& x) { bst.insert(std::move(x)); });
	bst.printTree();
;}

#pragma GCC diagnostic pop