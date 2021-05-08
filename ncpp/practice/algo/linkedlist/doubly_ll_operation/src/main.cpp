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
	struct node* prev;
	struct node* next;
} node;

class circular_ll {
	private:
		node* _head;
		node* _tail;
	public:
		circular_ll(): _head{NULL}, _tail{NULL} {}
		node* get_head() const { return this->_head; }
		node* get_tail() const { return this->_tail; }
		void set_head(node* head) { this->_head = head; }
		void set_tail(node* tail) { this->_tail = tail; }
		void init_head(int data) {
			this->_head = new node;
			this->_head->data = data;
			this->_head->prev = NULL;
			this->_head->next = NULL;
			this->_tail = this->_head;
		}
		void insert_node_tail(int data) {
			if (!this->_head)
				this->init_head(data);
			else {
				node* ptr = this->_head;
				while (ptr->next)
					ptr = ptr->next;
				ptr->next = new node;
				ptr->next->data = data;
				ptr->next->next = NULL;
				ptr->next->prev = ptr;
				this->_tail = ptr->next;
			}
		}
		void insert_node_head(int data) {
			if (!this->_head)
				this->init_head(data);
			else {
				node* ptr = new node;
				this->_head->prev = ptr;
				ptr->data = data;
				ptr->prev = NULL;
				ptr->next = this->_head;
				this->_head = ptr;
			}
		}
		void delete_at_head() {
			if (!this->_head) {
				cerr << "No linked list to delete node" << nl;
				exit(1);
			}
			else {
				node* ptr = this->_head;
				this->_head = ptr->next;
				this->_head->prev = NULL;
				delete ptr;
			}
		}
		void delete_at_tail() {
			if (!this->_head) {
				cerr << "No linked list to delete node" << nl;
				exit(1);
			}
			else {
				node* ptr = this->_tail;
				this->_tail = ptr->prev;
				this->_tail->next = NULL;
				delete ptr;
			}
		}
		void delete_by_pos(int pos) {
			if (!this->_head) {
				cerr << "No linked list to delete node" << nl;
				exit(1);
			}
			else {
				int count{};
				node* ptr = this->_head;
				while (ptr) {
					count++;
					if (count == pos)
						break;
					ptr = ptr->next;
				}
				if (count <= pos) {
					if (!ptr->prev)
						this->delete_at_head();
					else if (!ptr->next)
						this->delete_at_tail();
					else {
						ptr->prev->next = ptr->next;
						ptr->next->prev = ptr->prev;
						delete ptr;
					}
				}
				else {
					cerr << "Provided position exceeds the size of linked \
						list" << nl;
					exit(1);
				}
			}
		}
		void delete_by_value(int val) {
			bool val_found{false};
			if (!this->_head) {
				cerr << "No linked list to delete node" << nl;
				exit(1);
			}
			else {
				node* ptr = this->_head;
				while (ptr) {
					if (ptr->data == val) {
						val_found = true;
						break;
					}
					ptr = ptr->next;
				}
				if (!val_found) {
					cerr << "Provided value not found in linked list" << nl;
					exit(1);
				}
				else {
					if (!ptr->prev)
						this->delete_at_head();
					else if (!ptr->next)
						this->delete_at_tail();
					else {
						ptr->next->prev = ptr->prev;
						ptr->prev->next = ptr->next;
						delete ptr;
					}
				}
			}
		}
		void print_ll() const {
			node* ptr = this->_head;
			while (ptr) {
				cout << ptr->data;
				if (ptr->next)
					cout << "->";
				ptr = ptr->next;
			}
			br;
		}
		int get_length() const {
			node* ptr = this->_head;
			int count{};
			while (ptr) {
				count++;
				ptr = ptr->next;
			}
			return count;
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

/** Note: These below operations are done by treating doulby linked list as
 * singly linked list, so for doulby linked list, you can do added change in
 * these functions */
void merge_two_lls(node* r1, node* r2, int pos) {
	int count{};
	node* ptr1 = r1;
	while ((count < pos - 1) && ptr1) {
		count++;
		ptr1 = ptr1->next;
	}
	node* ptr2 = r2;
	while (ptr2->next)
		ptr2 = ptr2->next;
	ptr2->next = ptr1;
}

bool get_lls_intersection_value(node* r1, node* r2, int l1, int l2) {
	int ldiff{};
	node* ptr1, *ptr2;
	if (l1 > l2) {
		ldiff = l1 - l2;
		ptr1 = r1;
		while (ldiff--)
			ptr1 = ptr1->next;
		ptr2 = r2;
	}
	else {
		ldiff = l2 - l1;
		ptr2 = r2;
		while (ldiff--)
			ptr2 = ptr2->next;
		ptr1 = r1;
	}
	bool cpf{false};
	while (ptr1 && ptr2) {
		if (ptr1 == ptr2) {
			cpf = true;
			break;
		}
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}
	return cpf;
}

bool remove_intersection(node* r1, node* r2, int l1, int l2) {
	int ldiff{};
	node *ptr1, *ptr2;
	if (l1 > l2) {
		ldiff = l1 - l2;
		ptr1 = r1;
		while (ldiff--)
			ptr1 = ptr1->next;
		ptr2 = r2;
	}
	else {
		ldiff = l2 - l1;
		ptr2 = r2;
		while (ldiff--)
			ptr2 = ptr2->next;
		ptr1 = r1;
	}
	bool cpf{false};
	while (ptr1->next && ptr2->next) {
		if (ptr1->next == ptr2->next) {
			cpf = true;
			break;
		}
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	if (!cpf)
		cout << "No intersection point found between linked lists" << nl;
	else {
		ptr2->next = NULL;
	}
	return cpf;
}

void merge_sorted_linked_list(circular_ll& cll1, circular_ll& cll2) {
	node *pptr, *ptr1, *ptr2;
	pptr = ptr1 = cll1.get_head();
	ptr2 = cll2.get_head();
	while (ptr1 && ptr2) {
		if (ptr1->data < ptr2->data) {
			pptr =  ptr1;
			ptr1 = ptr1->next;
		}
		else {
			if (ptr1 == cll1.get_head()) {
				node* pptr2 = ptr2;
				ptr2 = ptr2->next;
				pptr2->next = pptr;
				pptr = pptr2;
				cll1.set_head(pptr);
			} else {
				pptr->next = ptr2;
				ptr2 = ptr2->next;
				pptr = pptr->next;
				pptr->next = ptr1;
			}
		}
	}
}

void even_after_odd(node* r1, node* r2) {

}

void solvethetestcase() {
	string in{};
	vi arr{};
	cin >> in;
	tokenize(in, arr, ',');
	circular_ll cll{};
	rep(i, (arr.size()))
		cll.insert_node_tail(arr[i]);
	/*cll.print_ll();
	cll.delete_at_head();
	cll.delete_at_tail();
	cll.delete_by_pos(2);
	cll.delete_by_value(3);*/
	cll.print_ll();
	// second ll
	cin >> in;
	arr.clear();
	tokenize(in, arr, ',');
	circular_ll cll2{};
	rep(i, (arr.size()))
		cll2.insert_node_tail(arr[i]);
	merge_two_lls(cll.get_head(), cll2.get_head(), 5);
	cll2.print_ll();
	cout << "intersection present: " << (get_lls_intersection_value(
				cll.get_head(), cll2.get_head(), cll.get_length(), cll2.get_length()) ? "true" : "false") << nl;
	cout << "removed intersection: " << (remove_intersection(
				cll.get_head(), cll2.get_head(), cll.get_length(), cll2.get_length()) ? "yes" : "no") << nl;
	cll2.print_ll();

	// merge two sorted linked lists
	cin >> in;
	arr.clear();
	tokenize(in, arr, ',');
	circular_ll cll3{};
	rep(i, (arr.size()))
		cll3.insert_node_tail(arr[i]);
	cll3.print_ll();
	merge_sorted_linked_list(cll2, cll3);
	cll2.print_ll();
	cll3.print_ll();

	cll.free_ll();
	cll2.free_ll();  // if the above two linked lists are merged then don't do this, to free this linked list, first remove intersection
}

#pragma GCC diagnostic pop