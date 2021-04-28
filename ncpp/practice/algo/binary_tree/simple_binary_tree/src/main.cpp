// main file

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

struct node {
	int _data;
	struct node* _left;
	struct node* _right;

	node(int val);
};

node::node(int val): _data{val}, _left{NULL}, _right{NULL} {}

void tokenize(const string& str, vector<int>& out, const char&& delim) {
	stringstream ss(str);
	string s;
	while (getline(ss, s, delim)) {
		out.push_back(stoi(s));
	}
}

void free(struct node* node) {
	if (node == NULL)
		return;
	free(node->_left);
	free(node->_right);
	cout << "deleting: " << node->_data << '\n';
	delete node;
}

void pre_order_traversal(struct node* ptr) {
	if (!ptr)
		return;
	cout << ptr->_data << ' ';
	pre_order_traversal(ptr->_left);
	pre_order_traversal(ptr->_right);
}

void in_order_traversal(struct node* ptr) {
	if (!ptr)
		return;
	in_order_traversal(ptr->_left);
	cout << ptr->_data << ' ';
	in_order_traversal(ptr->_right);
}

void post_order_traversal(struct node* ptr) {
	if (!ptr)
		return;
	post_order_traversal(ptr->_left);
	post_order_traversal(ptr->_right);
	cout << ptr->_data << ' ';
}

struct node* pre_in_tree(const vector<int>& in, const vector<int>& pre, int start, int end) {
	static size_t index{};
	if (start > end)
		return NULL;
	int curr = pre[index];
	struct node* ptr = new node{curr};
	index++;
	if (start == end) {
		return ptr;
	}
	vector<int>::const_iterator citer = find(in.cbegin(), in.cend(), curr);
	size_t pos = citer - in.cbegin();
	ptr->_left = pre_in_tree(in, pre, start, pos - 1);
	ptr->_right = pre_in_tree(in, pre, pos + 1, end);
	return ptr;
}

struct node* post_in_tree(const vector<int>& in, const vector<int>& post, int start, int end) {
	static int index{static_cast<int>(end)};
	if (start > end)
		return NULL;
	int curr = post[index];
	struct node* ptr = new node{curr};
	index--;
	if (start == end) {
		return ptr;
	}
	vector<int>::const_iterator citer = find(in.cbegin(), in.cend(), curr);
	size_t pos = citer - in.cbegin();
	ptr->_right = post_in_tree(in, post, pos + 1, end);
	ptr->_left = post_in_tree(in, post, start, pos - 1);
	return ptr;
}


// resolve the confustion between height and depth of the binary tree and height and depth of the node in binary tree
int height_binary_tree(struct node* ptr) {
	//if (!ptr || (!ptr->_left && !ptr->_right))
	if (!ptr)
		return 0;
	return 1 + max(height_binary_tree(ptr->_left), height_binary_tree(ptr->_right));
}

void level_order_traversal(struct node* ptr) {
	if (!ptr)
		return;
	queue<struct node*> q;
	q.push(ptr);
	q.push(NULL);

	while (!q.empty()) {
		struct node* pptr = q.front();
		q.pop();  // pop probably doesn't returns the popped element
		if (pptr) {
			cout << pptr->_data << ' ';
			if (pptr->_left)
				q.push(pptr->_left);
			if (pptr->_right)
				q.push(pptr->_right);
		}
		else if (!q.empty())
			q.push(NULL);
	}
}

int sum_at_kth_level(struct node* ptr, size_t level) {
	if (!ptr)
		return -1;
	queue<struct node*> q;
	q.push(ptr);
	q.push(NULL);

	size_t cur_level{};
	int sum{};
	while (!q.empty() && cur_level <= level) {
		struct node* pptr = q.front();
		q.pop();
		if (pptr) {
			if (cur_level == level)
				sum += pptr->_data;
			if (pptr->_left)
				q.push(pptr->_left);
			if (pptr->_right)
				q.push(pptr->_right);
		}
		else if (!q.empty()) {
			cur_level++;
			q.push(NULL);
		}
	}
	return sum;
}

int count_nodes_binary_tree(struct node* ptr) {
	// one simple idea could be to just traverse the tree with a static variable in function for counting purpose
	// this is another simple approach
	if (!ptr)
		return 0;
	return 1 + count_nodes_binary_tree(ptr->_left) + count_nodes_binary_tree(ptr->_right);
}

int sum_of_all_nodes_binary_tree(struct node* ptr) {
	// again a simple traversal and static variable would do it, but here's another simple way
	if (!ptr)
		return 0;
	return ptr->_data + sum_of_all_nodes_binary_tree(ptr->_left) + sum_of_all_nodes_binary_tree(ptr->_right);
}

int calculate_diameter(struct node* ptr) {
	// diameter of a node is height of it's left subtree + height of it's right subtree + 1
	if (!ptr)
		return 0;
	int cur_diameter = 1 + height_binary_tree(ptr->_left) + height_binary_tree(ptr->_right);
	return max(cur_diameter, max(calculate_diameter(ptr->_left), calculate_diameter(ptr->_right)));
}

// optimized calculate diamter
int calculate_diameter_optimized(struct node* ptr, int& height) {
	if (!ptr) {
		height = 0;
		return 0;
	}
	int lh{}, rh{};
	int left_diameter = calculate_diameter_optimized(ptr->_left, lh);
	int right_diameter = calculate_diameter_optimized(ptr->_right, rh);

	int cur_diameter = lh + rh + 1;
	height = max(lh, rh) + 1;
	return max(cur_diameter, max(left_diameter, right_diameter));
}

int sum_replacement_binary_tree(struct node* ptr) {
	if (!ptr)
		return 0;
	ptr->_data += (sum_replacement_binary_tree(ptr->_left) + sum_replacement_binary_tree(ptr->_right));
	return ptr->_data;
}

void sum_replacement_binary_tree_no_return(struct node* ptr) {
	if (!ptr)
		return;
	sum_replacement_binary_tree(ptr->_left);
	sum_replacement_binary_tree(ptr->_right);

	if (ptr->_left)
		ptr->_data += ptr->_left->_data;
	if (ptr->_right)
		ptr->_data += ptr->_right->_data;
}

bool is_balanced_binary_tree(struct node* ptr) {
	if (!ptr)
		return true;  // whether you make it true or false I think it doesn't matter, it's just for stoping recursion
	is_balanced_binary_tree(ptr->_left);
	is_balanced_binary_tree(ptr->_right);

	if ((int)fabs(height_binary_tree(ptr->_left) - height_binary_tree(ptr->_right)) <= 1)
		return true;
	return false;
}

bool is_balanced_binary_tree_another_approach(struct node* ptr) {
	if (!ptr)
		return true;  // here the true is necessary as base condition, or else it'll fail all below condition
	if (!is_balanced_binary_tree_another_approach(ptr->_left))
		return false;
	if (!is_balanced_binary_tree_another_approach(ptr->_right))
		return true;
	if (abs(height_binary_tree(ptr->_left) - height_binary_tree(ptr->_right)) <= 1)
		return true;
	return false;
}

// above two functions for this same task have quadratic time complexity, this one is going to be linear(O(n))
bool is_balanced_binary_tree_better_approach(struct node* ptr, int& height) {
	/** first approach */
	if (!ptr) {
		height = 0;
		return false;
	}
	int lh{}, rh{};
	is_balanced_binary_tree_better_approach(ptr->_left, lh);
	is_balanced_binary_tree_better_approach(ptr->_right, rh);
	height = max(lh, rh) + 1;
	if (abs(lh - rh) <= 1)
		return true;
	return false;

	// second approach
	/*if (!ptr) {
		height = 0;
		return true;
	}
	int lh{}, rh{};
	if (!is_balanced_binary_tree_better_approach(ptr->_left, lh))
		return false;
	if (!is_balanced_binary_tree_better_approach(ptr->_right, rh))
		return false;
	height = max(lh, rh) + 1;
	if (abs(lh - rh) <= 1)
		return true;
	return false;*/
}

int main(int argc, char **argv) {
	/*struct node* root = new node{1};
	root->_left = new node{2};
	root->_right = new node{3};

	root->_left->_left = new node{4};
	root->_left->_right = new node{5};
	root->_right->_left = new node{6};
	root->_right->_right = new node{7};
	pre_order_traversal(root);
	cout << endl;
	in_order_traversal(root);
	cout << endl;
	post_order_traversal(root);
	cout << endl;
	free(root);*/

	/**
	  preorder & inorder tree building
	  postorder & inorder tree building
	*/
	string prestr{};
	string instr{};
	string poststr{};
	vector<int> pre{};
	vector<int> in{};
	vector<int> post{};
	getline(cin, prestr);
	getline(cin, instr);
	getline(cin, poststr);
	tokenize(instr, in, ',');
	tokenize(prestr, pre, ',');
	tokenize(poststr, post, ',');
	struct node* root = pre_in_tree(in, pre, 0, in.size() - 1);
	//struct node* root = post_in_tree(in, post, 0, in.size() - 1);
	cout << "done\n";
	//pre_order_traversal(temp);
	//cout << endl;
	pre_order_traversal(root);
	cout << endl;
	int height = height_binary_tree(root);
	cout << "height: " << height << endl;
	level_order_traversal(root);
	cout << endl;
	cout << "sum at 2nd level: " << sum_at_kth_level(root, 2) << endl;
	cout << "count of nodes in tree: " << count_nodes_binary_tree(root) << endl;
	cout << "sum of nodes of binary tree: " << sum_of_all_nodes_binary_tree(root) << endl;
	struct node* tptr = new node{1};
	tptr->_left = new node{2};
	tptr->_right = new node{3};
	int diameter{};
	cout << "diameter of tree: " << calculate_diameter_optimized(tptr, diameter) << endl;
	//cout << "final node sum: " << sum_replacement_binary_tree(root) << endl;
	sum_replacement_binary_tree_no_return(root);
	level_order_traversal(root);
	cout << endl;
	//cout << (is_balanced_binary_tree(root) ? "Tree is balanced" : "Tree in not balanced") << endl;
	int temp_height{};
	cout << (is_balanced_binary_tree_better_approach(root, temp_height) ? "Tree is balanced" : "Tree in not balanced") << endl;
	free(root);
	free(tptr);
	return 0;
}