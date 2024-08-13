//https://leetcode.cn/problems/sum-root-to-leaf-numbers/description/
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
    int ans = 0;
public:
    int sumNumbers(TreeNode* root) {
        process(root, 0);
        return ans;
    }
    void process(TreeNode* root, int cur) {
        cur = cur * 10 + root->val;
        if (!root->left && !root->right) {
            ans += cur;
            return;
        }
        if (root->left) {
            process(root->left, cur);
        }
        if (root->right) {
            process(root->right, cur);
        }
    }
};