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

template<typename Object>
class LinkedList {
	private:
		class Node {
			public:
				Object data;
				Node* prev;
				Node* next;
				Node(const Object& d = Object{}, Node* p = nullptr, Node* n = nullptr)
					: data{d}, prev{p}, next{n} {}
		};
		Node* _head;
		Node* _tail;
		size_t _size;
		void init() {
			this->_size = 0;
			this->_head = nullptr;
			this->_tail = nullptr;
		}
	public:
		LinkedList() { this->init(); }
		LinkedList(std::initializer_list<Object> lst) {
			this->init();
			for(const Object& x: lst) this->append_to_tail(x);
		}
		~LinkedList() {
			clear();
		}
		LinkedList(const LinkedList& rhs) {
			this->init();
			Node* ptr = rhs._head;
			while(nullptr != ptr) {
				this->append_to_tail(ptr->data);
				ptr = ptr->next;
			}
		}
		LinkedList(LinkedList&& rhs)
			:_head{rhs._head}, _tail{rhs._tail}, _size{rhs._size} {
			this->init();
		}
		LinkedList& operator=(const LinkedList& rhs) {
			LinkedList temp = rhs;

			// Question this ==>

			//std::swap(*this, temp);

			//swap(this->_head, temp._head);
			//swap(this->_tail, temp._tail);
			//swap(this->_size, temp._size);

			this->_head = temp._head;
			this->_tail = temp._tail;
			this->_size = temp._size;
			temp._head = nullptr;
			temp._tail = nullptr;
			return *this;
		}
		LinkedList& operator=(LinkedList&& rhs) {
			swap(*this, rhs);  // there's no need to save rhs here
			return *this;
		}
		void clear() {
			if(nullptr != this->_head) {
				Node* ptr = this->_head;
				while(ptr != this->_tail) {
					ptr->next->prev = nullptr;
					this->_head = ptr->next;
					delete ptr;
					ptr = nullptr;
					ptr = this->_head;
				}
				delete ptr;
			}
			this->_head = this->_tail = nullptr;
		}
		void append_to_tail(Object data) {
			if(nullptr == this->_head) {
				Node* new_node = new Node(data);
				this->_head = new_node;
				this->_tail = new_node;
			}
			else {
				Node* ptr = this->_head;
				while(ptr != this->_tail) ptr = ptr->next;
				ptr->next = new Node(data, ptr);
				this->_tail = ptr->next;
			}
			this->_size++;
		}
		/** if you don't want to use extra storage, you can use another Node*
		 * runner, which would start from current Node* pointer ptr, and would
		 * go to end of the list matching it's data with ptr's data and
		 * deleting duplicates, for every iterator of ptr until goes to end */
		void remove_duplicates() {
			if(nullptr == this->_head) return;
			uset<Object> ut;
			Node* ptr = this->_head;
			Node* temp = nullptr;
			while(ptr != nullptr) {  // go up to the end
				typename uset<Object>::const_iterator pos = ut.find(ptr->data);
				if(pos != ut.cend()) {  // data already exist
					/** delete this node:
					  * this node can either be between head and tail or
					  * this node could be tail node, but it can never be
					  * a head node */
					temp = ptr;
					if(nullptr != ptr->next) {  // it's not tail node
						ptr->next->prev = ptr->prev;
					}
					ptr->prev->next = ptr->next;
					if(nullptr == ptr->next)  // update tail
						this->_tail = ptr->prev;
					delete temp;
					temp = nullptr;
					this->_size--;
				}
				else ut.insert(ptr->data);
				ptr = ptr->next;
			}
		}
		void delete_node(Object data) {
			if(nullptr == this->_head) return;
			Node* ptr = this->_head;
			Node* temp{nullptr};
			while(ptr != this->_tail) {
				if(data == ptr->data) {
					temp = ptr;
					if(nullptr != ptr->prev) { // if it isn't the first node
						ptr->prev->next = ptr->next;
					}
					ptr->next->prev = ptr->prev;
					if(nullptr == ptr->prev) this->_head = ptr->next;
					ptr = ptr->next;

					delete temp;
					temp = nullptr;
					this->_size--;
				}
				else ptr = ptr->next;
			}
			// if it's the last node( or only node )
			if(data == ptr->data) {
				temp = ptr;
				this->_tail = ptr->prev;
				if(nullptr != ptr->prev) // if it isn't the first
					ptr->prev->next = ptr->next;
				if(nullptr == ptr->prev) // if it's the only element
					this->_head = ptr->prev;
				delete temp;
				temp = nullptr;
				this->_size--;
			}
		}
		Object kth_to_last(const size_t& k) const {
			if((k > this->_size) || (nullptr == this->_head)) return 0;
			size_t count{1};
			Node* ptr = this->_tail;
			while((k != count) && (nullptr != ptr->prev)) {
				ptr = ptr->prev;
				count++;
			}
			return ptr->data;
		}
		void delete_middle_node() {
			if(3 > this->_size) return;  // delete any node but first and last
			/** idx starting from one
			  * if list size is even, then delete "size / 2"
			  * if odd, then delete "(size + 1) / 2" */
			size_t idx = (0 == (this->_size & 1)
					? (this->_size / 2)
					: ((this->_size + 1) / 2));
			size_t count{1};
			Node* ptr = this->_head;
			while(count != idx) {
				ptr = ptr->next;
				count++;
			}
			// if there are duplicate elements in list, then write the logic to
			// delete element, else just call delete_node(), I'm gonna write
			// logic to delete, just to show
			ptr->next->prev = ptr->prev;
			ptr->prev->next = ptr->next;
			delete ptr;
			ptr = nullptr;
			this->_size--;
		}
		void partition(Object value) {
			if(nullptr == this->_head) return;
			Node* ptr = this->_head;
			while(nullptr != ptr) {
				if(value > ptr->data) { // put node in the begining of list
					/** check if this isn't the begining node of list, cause
					 * then we don't need to do anything for that node */
					if(nullptr != ptr->prev) {
						// complete this
					}
				}
			}
		}
		void sum_lists_reverse(const LinkedList& rhs) {
			if(0 == this->_size) {
				if(0 != rhs._size) *this = rhs;
				return;
			}
			else if(0 == rhs._size) return;
			LinkedList new_list;
			Node* ptr = this->_head;
			Node* rptr = rhs._head;
			Object carry{}, sum{}, res{};
			while((nullptr != ptr) && (nullptr != rptr)) {
				cout << "here" << nl;
				sum = ptr->data + rptr->data + carry;
				res = sum % 10;
				carry = sum / 10;
				new_list.append_to_tail(res);
				ptr = ptr->next;
				rptr = rptr->next;
			}
			/** I can just now change the node's pointers instead of looping,
			 * but looping is required to handle the carry */
			if(nullptr != ptr) {
				while(nullptr != ptr) {
					cout << "here 2" << nl;
					if(0 == carry) break;
					sum = ptr->data + carry;
					res = sum % 10;
					carry = sum / 10;
					new_list.append_to_tail(res);
					ptr = ptr->next;
				}
				/** if ptr still not equal to nullptr, then just change the
				 * pointers now */
				if(nullptr != ptr) {
					cout << "here 3" << nl;
					ptr->prev->next = nullptr;
					new_list._tail->next = ptr;
					ptr->prev = new_list._tail;
					new_list._tail = this->_tail;
					new_list._size += (this->_size - new_list._size);
				}
			}
			else if(nullptr != rptr) {
				while(nullptr != rptr) {
					cout << "here 4" << nl;
					if(0 == carry) break;
					sum = rptr->data + carry;
					res = sum % 10;
					carry = sum / 10;
					new_list.append_to_tail(res);
					rptr = rptr->next;
				}
				if(nullptr != rptr) {
					cout << "here 5" << nl;
					rptr->prev->next = nullptr;
					new_list._tail->next = rptr;
					rptr->prev = new_list._tail;
					new_list._tail = rhs._tail;
					new_list._size += (rhs._size - new_list._size);
				}
			}
			else if(0 != carry) {
				cout << "here 6" << nl;
				new_list.append_to_tail(carry);
			}
			*this = new_list;
		}
		bool is_palindrome() {
			if(nullptr == this->_head) return false;
			Node *ptr{this->_head}, *rptr{this->_tail};
			while((ptr != rptr) &&
					(ptr->next != rptr && rptr->prev != ptr)) {
				if(ptr->data != rptr->data) return false;
				ptr = ptr->next;
				rptr = rptr->prev;
			}
			return true;
		}
		/** there are other ways to also check for intersection(specially,
		 * since this implementation of linkedlist is doubly linkedlist, but
		 * this implemention will also work on singly linked list). Also for
		 * removal of intersection, either you can have second list end where
		 * the intersection was found or you can append the rest of the common
		 * items seperately to second list. I did the first one */
		bool remove_intersection(LinkedList<Object>& rhs) {
			if(nullptr == this->_head) return false;
			size_t diff{0};
			Node *ptr{this->_head}, *sptr{rhs._head};
			if(this->_size > rhs._size) {
				diff = this->_size - rhs._size;
				while(diff-- > 0) ptr = ptr->next;
			}
			else if(this->_size < rhs._size) {
				diff = rhs._size - this->_size;
				rhs._size = diff;
				while(diff-- > 0) sptr = sptr->next;
			}
			size_t count{};
			while((nullptr != ptr) && (nullptr != sptr)) {
				if((nullptr != ptr->next && nullptr != sptr->next)
						&& (ptr->next == sptr->next)) {  // intersection found
					rhs._tail = sptr;
					sptr->next = nullptr;
					rhs._size += (count + 1);
					break;
				}
				count++;
				ptr = ptr->next;
				sptr = sptr->next;
			}
			if(nullptr == ptr) return false;
			return true;
		}
		void print_nodes() const {
			if(nullptr == this->_head) return;
			Node* ptr = this->_head;
			cout << "( ";
			while(this->_tail != ptr) {
				cout << ptr->data << " -> ";
				ptr = ptr->next;
			}
			cout << ptr->data << " )";
			br;
		}
		void print_nodes_reverse() const {
			if(nullptr == this->_tail) return;
			Node* ptr = this->_tail;
			cout << "( ";
			while(this->_head != ptr) {
				cout << ptr->data << " -> ";
				ptr = ptr->prev;
			}
			cout << ptr->data << " )";
			br;
		}
		friend ostream& operator<<(ostream& os, const LinkedList& rhs) {
			if(nullptr != rhs._head) {
				Node* ptr = rhs._head;
				os << "( ";
				while(rhs._tail != ptr) {
					os << ptr->data << " -> ";
					ptr = ptr->next;
				}
				os << ptr->data << " )";
				br;
			}
			return os;
		}
		size_t size() const { return this->_size; }
		Node* get_head() const { return this->_head; }
		Node* get_tail() const { return this->_tail; }
		/** normally you shouldn't have these mutators(specially for size), but
		 * here it is because of question purpose */
		void set_size(size_t size) { this->_size = size; }
		void set_head(Node* head) { this->_head = head; }
		void set_tail(Node* tail) { this->_tail = tail; }
};

void initial_testing() {
	/** Initial testing working */
	LinkedList<int> llist = {10, 20, 30};
	llist.print_nodes();
	llist.delete_node(30);   // working
	llist.print_nodes();
}

/** Solution 1 */
void remove_dups() {
	LinkedList<int> llist = {10, 20, 30, 20, 40, 50, 30, 70, 40};
	cout << "Initial list: " << nl;
	llist.print_nodes();
	// remove duplicates
	llist.remove_duplicates();
	cout << "After removing duplicates: " << nl;
	llist.print_nodes();
	cout << "Size: " << llist.size() << nl;
}

/** Solution 2 */
void return_kth_to_last() {
	LinkedList<int> llist = {10, 20, 30, 40, 50, 60, 70, 80};
	cout << "List created: " << nl;
	llist.print_nodes();
	cout << "1st to last element: " << llist.kth_to_last(1) << nl;
	cout << "2nd to last element: " << llist.kth_to_last(2) << nl;
	cout << "3rd to last element: " << llist.kth_to_last(3) << nl;
	cout << "5th to last element: " << llist.kth_to_last(5) << nl;
	cout << "farthest element from last: "
		<< llist.kth_to_last(llist.size()) << nl;
}

/** Solution 3 */
void delete_middle_node_of_list() {
	LinkedList<int> llist = {10, 20, 30, 40, 50, 60, 70, 80};
	cout << "List created: " << nl;
	llist.print_nodes();
	llist.delete_middle_node();
	cout << "After removing middle element: " << nl;
	llist.print_nodes();
	cout << "Size: " << llist.size() << nl;
	llist.delete_middle_node();
	cout << "After removing middle element: " << nl;
	llist.print_nodes();
	cout << "Size: " << llist.size() << nl;
}

/** Solution 4 */
void partition_list() {
	LinkedList<int> llist = {3, 5, 8, 5, 10, 2, 1};
	cout << "List created: " << nl;
	llist.print_nodes();
	llist.partition(5);
	cout << "After partition, list: " << nl;
	llist.print_nodes();
}

/** Solution 5 */
void sum_two_lists_in_reverse() {
	LinkedList<int> llist = {7, 1, 6};
	cout << "Initial list: " << nl;
	llist.print_nodes();
	llist.sum_lists_reverse(LinkedList<int>{5, 9, 2});
	cout << "List after sum with (5->9->2) : " << nl;
	llist.print_nodes();
}

/** In the solution5, question has asked if the lists were used in forward to
 * sum, you just have to write function similar to,
 * LinkedList::sum_lists_reverse(LinkedList const&), with a change, you have to
 * start from "tail node" and go with "<node>.prev", and everything would be
 * similar */


/** Did operator overloading for ostream operator */

/** Solution 6 */
void is_list_palindrome() {
	LinkedList<int> llist1 = {2, 5, 4, 5, 2};
	LinkedList<int> llist2 = {2, 5, 6, 6, 5, 2};
	LinkedList<int> llist3 = {2, 1, 4, 9, 2};

	/** check to print "true" & "false" instead of 0 and 1(not saying for using ternary operator here */

	cout << "Is list " << llist1 << " palindrome? : "
		<< (llist1.is_palindrome() ? "true" : "false") << nl;
	cout << "Is list " << llist2 << " palindrome? : "
		<< (llist2.is_palindrome() ? "true" : "false") << nl;
	cout << "Is list " << llist3 << " palindrome? : "
		<< (llist3.is_palindrome() ? "true" : "false") << nl;
}

/** Solution 7 */
void are_list_intersecting() {
	/** doing settings for testing intersection between list */
	LinkedList<int> llist1 = {1, 2, 3, 4, 5, 6, 10};
	LinkedList<int> llist2 = {4, 5, 6, 7, 8, 9};
	llist2.get_tail()->next = llist1.get_head()->next->next->next;
	llist2.set_tail(llist1.get_tail());
	llist2.set_size(llist2.size() + (llist1.size() - 3));
	cout << "Initial first list: " << llist1;
	cout << "Initial second list: " << llist2;
	/** settings completed */
	bool status = llist1.remove_intersection(llist2);
	cout << "After dealing with intersection ==>" << nl;
	cout << "Intersection found? : " << (status ? "true" : "false") << nl;
	cout << "First list: " << llist1;
	cout << "Second list: " << llist2;
	/** NOTE: if you'll not call LinkedList::remove_intersection(LinkedList&),
	 * there will be memory leak present in program(because the way of testing
	 * prototype of two lists is implemented) */
}


void solvethetestcase() {
	are_list_intersecting();
}

#pragma GCC diagnostic pop