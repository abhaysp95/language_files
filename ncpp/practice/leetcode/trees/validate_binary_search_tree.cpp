#include <bits/stdc++.h>

using namespace std;

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
		bool isValidateBST(TreeNode* root) {
			return dfs(root, LONG_MIN, LONG_MAX);
		}
		bool dfs(TreeNode* root, long lb, long ub) {
			if(NULL == root) return true;
			bool ls = dfs(root->left, lb, root->val);
			bool rs = dfs(root->right, root->val, ub);
			if(ls && rs && lb < root->val && ub > root->val) return true;
			return false;
		}
};
