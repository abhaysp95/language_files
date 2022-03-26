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
		vector<vector<int>> levelOrder(TreeNode* root) {
			if(nullptr == root) return vector<vector<int>>();
			vector<vector<int>> vvi{};
			vector<int> vi{};
			queue<TreeNode*> q{};
			q.push(root);
			q.push(nullptr);

			while(!q.empty()) {
				TreeNode* temp = q.front();
				q.pop();
				if(temp) {
					vi.push_back(temp->val);
					if(temp->left) q.push(temp->left);
					if(temp->right) q.push(temp->right);
				}
				else if(!q.empty()) {
					vvi.push_back(vi);
					vi.clear();
					q.push(nullptr);
				}
				else vvi.push_back(vi);
			}
			return vvi;
		}
};
