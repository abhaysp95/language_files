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

template<typename Object, typename Comparable=less<Object>>
class avl_tree {
	private:
		struct avl_node {
			Object element;
			avl_node* left;
			avl_node* right;
			int height;

			avl_node( const Object& ele, avl_node* lt, avl_node* rt ): element{ ele }, left{ lt }, right{ rt }, height{ 0 } {  }
			avl_node( Object&& ele, avl_node* lt, avl_node* rt ): element{ ele }, left{ lt }, right{ rt }, height{ 0 } {  }
		};

		avl_node* _root;
		Comparable is_less_than;

		int height( avl_node* t ) const {
			return ( nullptr == t ) ? -1 : t->height;
		}

		void insert( const Object& x, avl_node* & t ) {
			if( nullptr == t ) t = new avl_node{ x, nullptr, nullptr };
			else if( is_less_than( x, t->element ) ) insert( x, t->left );
			else if( is_less_than( t->element, x ) ) insert( x, t->right );
			balance( t );
		}
		void insert( Object&& x, avl_node* & t ) {
			if( nullptr == t ) t = new avl_node{ std::move(x), nullptr, nullptr };
			else if( is_less_than( x, t->element ) ) insert( x, t->left );
			else if( is_less_than( t->element, x ) ) insert( x, t->right );
			balance( t );
		}

		static const int ALLOWED_IMBALANCE = 1;

		void balance( avl_node* & t ) {
			if( nullptr == t ) return;
			if ( height( t->left ) - height( t->right ) > ALLOWED_IMBALANCE ) {
				if( height( t->left->left ) >= height( t->left->right ) ) rotate_with_left_child( t );
				else drotate_with_left_child( t );
			}
			else if( height( t->right ) - height( t->left ) > ALLOWED_IMBALANCE ) {
				if ( height( t->right->right ) >= height( t->right->left ) ) rotate_with_right_child( t );
				else drotate_with_right_child( t );
			}
			t->height = max( height( t->left ), height( t->right ) ) + 1;
		}

		/** we pass k2 and then k1 is made it's parent. Update heights, and set
		 * the new root */
		void rotate_with_left_child( avl_node* & t ) {  // right rotation
			avl_node* tl = t->left;
			t->left = tl->right;
			tl->right = t;
			t->height = max( height( t->left ), height( t->right ) ) + 1;
			t = tl;  // so that the upper level node can know that it's child has been changed
		}
		void rotate_with_right_child( avl_node* & t ) {  // left rotation
			avl_node* tr = t->right;
			t->right = tr->left;
			tr->left = t;
			t->height = max( height( t->left ), height( t->right ) ) + 1;
			t = tr;
		}

		/** Double rotation:
		 * first left child(k1) with its right child(k2), and then node
		 * k3(GrandParent initially) with new left child, so atlast, k2 becomes
		 * root and k1 its left subtrees root and k3 its right subtrees root,
		 * inshort it's an LR rotation */
		void drotate_with_left_child( avl_node* & t ) {
			rotate_with_right_child( t->left );  // left rotation
			rotate_with_left_child( t );  // right rotation
		}
		/** RL rotation, mirror symmetric of LR rotation */
		void drotate_with_right_child( avl_node* & t ) {
			rotate_with_left_child( t->right );  // right rotation
			rotate_with_right_child( t );  // left rotation
		}

		void remove( const Object& x, avl_node* & t ) {
			if( nullptr == t ) return;
			if( is_less_than( x, t->element ) ) remove( x, t->left );
			else if( is_less_than( t->element, x ) ) remove( x, t->right );
			else if( nullptr != t->left && nullptr != t->right ) {
				avl_node* temp = find_min( t->right );
				t->element = temp->element;
				remove( t->element, t->right );
			}
			else {
				avl_node* old_node = t;
				t = ( nullptr != t->left ) ? t->left : t->right;
				delete old_node;
			}
			balance( t );
		}

		avl_node* find_min( avl_node* t ) const {
			if( nullptr != t ) while( nullptr != t->left ) t = t->left;
			return t;
		}
		avl_node* find_max( avl_node* t ) const {
			if (nullptr != t) while ( nullptr != t->right ) t = t->right;
			return t;
		}

		bool contains( const Object& x, avl_node* t ) const {
			if( nullptr == t ) return false;
			if( is_less_than( x, t->element ) ) return contains( x, t->left );
			else if( is_less_than( t->element, x ) ) return contains( x, t->right );
			else return true;
		}
		avl_node* clone( avl_node* t ) const {
			if( nullptr == t ) return nullptr;
			return new avl_node{ t->element, clone( t->left ), clone( t->right ) };
		}
		void make_empty( avl_node* t ) {
			if( nullptr != t ) {
				make_empty( t->left );
				make_empty( t->right );
				delete t;
			}
			t = nullptr;
		}
		void print_tree( avl_node* t, ostream& out ) const {
			if( nullptr == t ) return;
			print_tree( t->left, out );
			out << t->element << ' ';
			print_tree( t->right, out );
		}

	public:
		avl_tree(): _root{ nullptr } {}
		avl_tree( const avl_tree& rhs ): _root{ nullptr } {
			this->_root = clone( rhs._root );
		}
		avl_tree( avl_tree&& rhs ): _root{ nullptr } {
			this->_root = clone( std::move(rhs._root) );  // not too sure
		}
		avl_tree& operator=( const avl_tree& rhs ) {
			avl_tree copy = rhs;
			std::swap( *this, copy );
			return *this;
		}
		avl_tree& operator=( avl_tree& rhs ) {
			std::swap( *this, std::move(rhs) );
			return *this;
		}
		~avl_tree() {
			make_empty();
		}

		void insert( const Object& x ) { insert( x, this->_root ); }
		void insert( Object&& x ) { insert( std::move(x), this->_root ); }

		void remove( const Object& x ) { remove( x, this->_root ); }
		void remove( Object&& x ) { remove( std::move(x), this->_root ); }

		void is_empty() { return ( nullptr == this->_root ) ? true : false; }
		void make_empty() { make_empty( this->_root ); }

		const Object& find_min() const { find_min( this->_root ); }
		const Object& find_max() const { find_max( this->_root ); }

		void print_tree( ostream& out=cout ) const {
			if( nullptr == this->_root ) cout << "No node created!!!\n";
			else {
				print_tree( this->_root, out );
				out << '\n';
			}
		}
		void height() const { height( this->_root ); }
};

template<typename Object>
class comparator {
	public:
		bool operator()( const Object& x1, const Object& x2 ) { return x1 < x2; }
};

void solvethetestcase() {
	string input{};
	getline(cin, input);
	vi values{};
	tokenize(input, values, ' ');

	avl_tree<int, comparator<int> > tree;
	for_each( values.begin(), values.end(), [ &tree ]( const auto& x ){ tree.insert( std::move(x) ); } );
	// you don't need to have std::move(x), because x is int
	tree.print_tree();
}

#pragma GCC diagnostic pop