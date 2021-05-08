//main file

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcomment"

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define lD long double
#define PI 3.1415926535897932384626
#define INF 1e9
#define rep(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)
#define repl(i, n) for (ll (i) = 0; (i) < (ll)(n); (i)++)
#define repd(i, n) for (int (i) = (n) - 1; (i) >= 0; (i)--)
#define repld(i, n) for (ll (i) = (n) - 1; (i) >= 0; (i)--)
#define loop(i,a,b) for (int (i) = (int)(a); (i) < (int)(b); (i)++)
#define rloop(i,a,b) for (int (i) = (int)(a); (i) <= (int)(b); (i)++)
#define loopl(i,a,b) for (ll (i) = (ll)(a); (i) < (ll)(b); (i)++)
#define rloopl(i,a,b) for (ll (i) = (ll)(a); (i) <= (ll)(b); ++(i))
#define loopd(i,a,b) for (int (i) = (int)(a); (i) > (b); (i)--)
#define rloopd(i,a,b) for (int (i) = (int)(a); (i) >= (b); (i)--)
#define loopld(i,a,b) for (ll (i) = (ll)(a); (i) > (b); (i)--)
#define rloopld(i,a,b) for (ll (i) = (ll)(a); (i) >= (b); (i)--)
#define wl (t) while((t)--)
#define pb push_back
#define eb emplace_back
#define ab(a) (a < 0)?(-1*(a)):(a)
#define mset(a,b,c) loop(i,0,b) (a)[(i)]=(c)
#define asum(a,b,c) { int (i) = 0; (c) = 0; repd(i, b) (c)+=(a)[(i)]; }
#define fe first
#define se second
#define mp make_pair
#define clr(x) (x).clear()
#define itoc(c) ((char)(((int)'0')+(c)))
#define all(p) (p).begin(),(p).end()
#define rall(p) (p).rbegin(),(p).rend()
#define tr(c,it) for(__typeof__((c)).begin() (it) = (c).begin(); (it) != (c).end(); (it)++)
#define trr(c,it) for(__typeof__((c)).rbegin() (it) = (c).rbegin(); (it) != (c).rend(); (it)++)
#define present(c,x) ((c).find(x) != (c).end())  // container version, log(n) for set and map
#define cpresent(c,x) (find(all(c),(x)) != (c).end())  // works for all container
#define mx(x,y) ((x)>(y)?(x):(y))
#define mn(x,y) ((x)<(y)?(x):(y))
#define rmx(a,b) ((a) = mx(a,b))
#define rmn(a,b) ((a) = mn(a,b))
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
	//cin >> t;
	loopl (testcase, 1, t + 1) {
		//(uncomment for multiple test cases)
		//cout << "Case #" << testcase << ": ";
		solvethetestcase();
    }
}

typedef struct node {
	int data;
	struct node* next;
} node;

class linkedlist {
	private:
		node* _head;
		node* _tail;
	public:
		linkedlist(): _head{NULL}, _tail{NULL} {}
		node* get_head() const { return this->_head; }
		node* get_tail() const { return this->_tail; }
		void set_head(node* head) { this->_head = head; }
		void set_tail(node* tail) { this->_tail = tail; }
		void reset_tail() {
			node* ptr = this->_head;
			while (ptr->next)
				ptr = ptr->next;
			this->_tail = ptr;
		}
		void insert_node(int data) {
			if (!this->_head) {
				this->_head = new node;
				this->_head->data = data;
				this->_head->next = NULL;
				this->_tail = this->_head;
			}
			else {
				node* ptr = this->_head;
				while (ptr != this->_tail)
					ptr = ptr->next;
				ptr->next = new node;
				this->_tail = ptr->next;
				this->_tail->data = data;
				this->_tail->next = NULL;
			}
		}
		void print_ll() {
			node* ptr = this->_head;
			while (ptr) {
				cout << ptr->data;
				if (ptr->next)
					cout << "->";
				ptr = ptr->next;
			}
			br;
		}
		void reverse_ll() {
			node* ptr = this->_head;
			node* prev = NULL;
			node* curr = this->_head;
			node* next = this->_head->next;
			while (curr) {
				curr->next = prev;
				prev = curr;
				curr = next;
				if (next)
					next = next->next;
			}
			this->_head = prev;
			this->_tail = ptr;
		}
		// create a cycle in linked list(necessary for floyd algo)
		void create_cycle(int num) {
			node* ptr = this->_head;
			int count{};
			while (ptr) {
				count++;
				if (count == num)
					break;
				ptr = ptr->next;
			}
			this->_tail->next = ptr;
		}
		void free_ll() {
			node* ptr = this->_head;
			while (ptr) {
				node* pptr = ptr;
				ptr = ptr->next;
				delete pptr;
			}
		}
};

/**
  recursive linked list reversal
  use it as seperate method
node* rev_ll_rec(node* root) {
	if (!root || !root->next)
		return root;
	node* new_root = rev_ll_rec(root->next);
	root->next->next = root;
	root->next = NULL;
	return new_root;
}
*/

node* reverse_k_nodes(node* root, int k) {
	if (!root || !root->next)
		return root;
	node* prev = NULL;
	node* curr = root;
	node* next;

	int count{};
	while (curr && count < k) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}
	if (next)
		root->next = reverse_k_nodes(next, k);
	return prev;
}

// floyd algo(hare & tortoise algo)

/**
  distance moved by fast pointer = m + n + l * i
  distance moved by slow pointer = m + n + l * j
  where m is distance from head upto the node where loop starts
  n is the distance where fast and slow pointer meet in the loop from the
  starting of the loop
  l is the length of the loop
  i is the iteration done by fast pointer of loop
  j is the iteration done by slow pointer of loop

  distance moved by fast pointer = 2 * distance moved by slow pointer
  so, from above 3 equations, we get: m + n = l * (i - 2 * j)
  or m = l * (i - 2 * j) - n

  so, basically it's m = l * <some_integer> - n, so after first meet of both
  the pointers, when we reset fast pointer to head, both the pointer will move
  save distance from there upto meet point(where the cycle starts, i.e., m = l
  - n)
  */
bool detect_cycle(node* root) {
	node* fptr = root;
	node* sptr = root;
	bool cycle_present{false};
	while ((fptr) && (sptr && sptr->next)) {
		fptr = fptr->next;
		sptr = sptr->next->next;
		if (fptr == sptr) {
			cycle_present = true;
			break;
		}
	}
	return cycle_present;
}

/* to remove cycle, we have to also get the meeting point of fast and slow ptr
 * */
void remove_cycle(node* root) {
	node* fptr = root;
	node* sptr = root;
	bool cycle_present{false};
	while (fptr && (sptr && sptr->next)) {
		fptr = fptr->next;
		sptr = sptr->next->next;
		if (fptr == sptr) {
			cycle_present = true;
			break;
		}
	}
	if (!cycle_present)
		cout << "No cycle present in linked list" << nl;
	else {
		fptr = root;
		while (fptr && sptr) {
			fptr = fptr->next;
			sptr = sptr->next;
			if (fptr->next == sptr->next) {
				break;
			}
		}
		sptr->next = NULL;
	}
}

void solvethetestcase() {
	string in{};
	vi arr{};
	cin >> in;
	tokenize(in, arr, ',');
	linkedlist llist;
	rep(i, (arr.size()))
		llist.insert_node(arr[i]);
	llist.print_ll();
	llist.reverse_ll();
	llist.print_ll();
	llist.reverse_ll();  // get back to original state
	llist.set_head(reverse_k_nodes(llist.get_head(), 3));
	llist.reset_tail();
	llist.print_ll();
	llist.create_cycle(4);
	//llist.print_ll();
	// use create_cycle() method to create the cycle first in linkedlist for checking
	cout << "cycle present: " <<
		(detect_cycle(llist.get_head()) ? "true" : "false") << nl;
	remove_cycle(llist.get_head());
	llist.print_ll();
	llist.free_ll();
}

#pragma GCC diagnostic pop