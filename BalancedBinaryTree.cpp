//https://leetcode.cn/problems/balanced-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	//节点信息-是否平衡、高度
	struct Info {
		bool isBalanced;
		int height;
		Info(bool isbal, int heigh) {
			isBalanced = isbal;
			height = heigh;
		}
	};
	bool isBalanced(TreeNode* root) {
		if (root == nullptr) return true;
		return getHeight(root) == -1 ? false : true;
		return process(root).isBalanced;
	}
	Info process(TreeNode* root) {
		if (root == nullptr) return Info(true, 0);
		Info left = process(root->left);
		Info right = process(root->right);
		if (!left.isBalanced || !right.isBalanced) return Info(false, 0);
		if (abs(left.height - right.height) > 1) return Info(false, 0);
		return Info(true, max(left.height, right.height) + 1);
	}
	int getHeight(TreeNode* root) {
		if (root == nullptr) return 0;
		int left = getHeight(root->left);
		int right = getHeight(root->right);
		if (left == -1 || right == -1 || abs(left - right) > 1) return -1;
		return max(left, right) + 1;
	}
};