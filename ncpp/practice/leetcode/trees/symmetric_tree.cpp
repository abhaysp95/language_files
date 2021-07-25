#include <bits/stdc++.h>

using namespace std;

/** check if tree is mirror symmetric to the root node of tree */

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val{0}, left{nullptr}, right{nullptr} {}
	TreeNode(int x): val{x}, left{nullptr}, right{nullptr} {}
	TreeNode(int x, TreeNode* left, TreeNode* right): val{x}, left{left}, right{right} {}
};

class Solution {
	public:
		bool isSymmetric(TreeNode* root) {
			return check_mirror(root->left, root->right);
		}
		bool check_mirror(TreeNode* left_node, TreeNode* right_node) {
			if(NULL == left_node && NULL == right_node) return true;
			if(NULL == left_node || NULL == right_node) return false;
			if(left_node->val != right_node->val) return false;
			return check_mirror(left_node->left, right_node->right)
				&& check_mirror(left_node->right, right_node->left);
		}
};
